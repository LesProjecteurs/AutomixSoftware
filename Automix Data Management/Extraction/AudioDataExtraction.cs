﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Diagnostics;
using System.IO;
using System.ComponentModel;
using System.Threading;
using System.Threading.Tasks;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;

namespace Automix_Data_Management.Extraction
{
    internal class AudioDataExtraction : IAudioDataExtraction
    {
        private DirectoryInfo _tempDirectory;
        public static int ExploredTracks;

        public AudioDataExtraction()
        {
            new DataBase();
            InitExecConfiguration();
            ExploredTracks = 0;
        }

        public void ExtractData(BackgroundWorker backgroundWorker, TrackCollection trackCollection)
        {
            var cancellationTokenSource = new CancellationTokenSource();
            var options = new ParallelOptions
            {
                CancellationToken = cancellationTokenSource.Token,
                MaxDegreeOfParallelism = (int)Math.Ceiling(Environment.ProcessorCount / 2.0)
            };
            ExploredTracks = 0;

            try
            {
                Parallel.ForEach(trackCollection, options, (track) =>
                {
                    if (cancellationTokenSource.IsCancellationRequested)
                    {
                        return;
                    }

                    IExtraction extraction;
                    var dataBase = new DataBase();

                    if (dataBase.IsInDataBase(track))
                    {
                        extraction = new DataBaseExtraction(dataBase);
                    }
                    else
                    {
                        extraction = new ExecutableExtraction(_tempDirectory);
                    }
                    if (!backgroundWorker.CancellationPending)
                    {
                        extraction.ExtractData(backgroundWorker, trackCollection.Count, cancellationTokenSource, track);
                    }
                    else
                    {
                        cancellationTokenSource.Cancel();
                    }
                });
            }
            catch (OperationCanceledException)
            {
                //TODO log file
            }
        }

        private void InitExecConfiguration()
        {
            var tempPath = Path.GetTempPath() + "AutomixSoftware";

            if (!Directory.Exists(tempPath))
            {
                _tempDirectory = Directory.CreateDirectory(tempPath);
            }
            else
            {
                Directory.Delete(tempPath, true);
                _tempDirectory = Directory.CreateDirectory(tempPath);
            }

            try
            {
                var profileName = _tempDirectory.FullName + "\\profile.yaml";
                var sw = new StreamWriter(profileName);
                sw.Write("outputFormat: json\noutputFrames: 0\nlowlevel:\n    stats: [ \"mean\" ]\n    mfccStats: [\"mean\"]"
                    + "\n    gfccStats: [\"mean\"]\nrhythm :\n    stats : [\"mean\"]\ntonal :\n    stats: [\"mean\"]");
                sw.Close();
            }
            catch (IOException e)
            {
                Debug.WriteLine(e.Message);
            }
        }
    }
}