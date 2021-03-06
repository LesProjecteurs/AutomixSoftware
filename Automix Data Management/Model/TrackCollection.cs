﻿// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using Automix_Data_Management.Exportation;

namespace Automix_Data_Management.Model
{
    public class TrackCollection : List<Track>
    {
        public static TrackCollection CopyFrom(TrackCollection old)
        {
            var newCollection = new TrackCollection();
            foreach (var t in old)
            {
                newCollection.Add(Track.CopyFrom(t));
            }
            return newCollection;
        }

        public void ExportToMp3(BackgroundWorker bw, string outputFile)
        {
            IExportation exportEngine = new SmoothMix();
            exportEngine.ExportMix(bw, this, outputFile);
        }

        public void ExportToText(string outputFile)
        {
            AudioIO.TextExport(this, outputFile);
        }

        public void SafeAdd(Track track)
        {
            if (!IsPresent(track) && !string.IsNullOrEmpty(track.Checksum))
            {
                Add(track);
            }
        }

        public bool IsPresent(Track track)
        {
            return this.Any(t => track.Checksum.Equals(t.Checksum) || track.Checksum.Equals(t.Checksum));
        }

        public Track Search(string name)
        {
            return this.FirstOrDefault(t => t.Name.Equals(name));
        }

        public void Remove(string name)
        {
            var tempTrack = Search(name);
            if (tempTrack != null)
            {
                Remove(tempTrack);
            }
        }

        public void Purge()
        {
            RemoveAll(t => t.Duration == 0 || string.IsNullOrEmpty(t.Checksum));
        }

        public void Concat(TrackCollection original)
        {
            foreach (var track in original)
            {
                SafeAdd(track);
            }
        }

        public void SortByName()
        {
            Sort((t1, t2) => string.Compare(t1.Name, t2.Name, StringComparison.Ordinal));
        }

        public bool Equals(TrackCollection other)
        {
            if (Count != other.Count) { return false;  }
            for (var k = 0; k < Count; k++)
            {
                if ( !(this[k].Equals(other[k])) ) { return false; }
            }
            return true;
        }

        public int computeTotalTime()
        {
            var sum = 0;
            for (var i = 0; i < Count; i++)
            {
                sum += this[i].Duration;
            }
            return sum;
        }
    }
}
