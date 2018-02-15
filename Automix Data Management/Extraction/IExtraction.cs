﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.Threading;
using System.ComponentModel;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Extraction
{
    internal interface IExtraction
    {
        void ExtractData(BackgroundWorker backgroundWorker, int nbTracks, CancellationTokenSource cancellationTokenSource, Track track);
    }
}