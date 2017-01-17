﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AudioDataExtraction.h"

#undef GetTempPath

using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Concurrency;

namespace AutoMixDataManagement {

	AudioDataExtraction::AudioDataExtraction()
	{
		String^ extractorpath = System::IO::Directory::GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";
		String^ temppath = Path::GetTempPath() + "AutomixSoftware";
		if (!Directory::Exists(temppath)) {
			_tempDirectory = Directory::CreateDirectory(temppath);
		}
		_startInfo = gcnew ProcessStartInfo(extractorpath);
		_startInfo->UseShellExecute = false;
		_startInfo->WorkingDirectory = _tempDirectory->FullName;
		_startInfo->WindowStyle = ProcessWindowStyle::Hidden;

		String^ profileName = _tempDirectory->FullName + "\\profile.yaml";
		StreamWriter^ sw = gcnew StreamWriter(profileName);
		sw->Write("outputFormat: json\noutputFrames: 0\nlowlevel:\n    stats: [ \"mean\" ]\n    mfccStats: [\"mean\"]\n\
			gfccStats : [\"mean\"]\nrhythm :\n    stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]\ntonal :\n\
			stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]");
		sw->Close();
	}

	AudioDataExtraction::~AudioDataExtraction()
	{
		_tempDirectory->Delete();
	}

	void AudioDataExtraction::extractData(Track^ track)
	{
		String^ parameters = track->Path + " " + track->Name + ".json " + _tempDirectory->FullName + "\\profile.yaml ";
		_startInfo->Arguments = parameters;
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
	}

	void AudioDataExtraction::extractData(TrackCollection^ trackCollection)
	{
		TrackCollection::Enumerator i = trackCollection->GetEnumerator();
		Track^ last = gcnew Track();
		while (i.MoveNext())
		{
			last = i.Current;
		}
		i.Reset();
		i.MoveNext();
		parallel_for_each(i.Current, last, [&](Track^ track) {
			extractData(track);
			i.MoveNext();
		});
	}
}