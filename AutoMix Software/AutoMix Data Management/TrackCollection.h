// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "Track.h"
#include "TracksComparison.h"

namespace AutoMixDataManagement {

	typedef System::Collections::Generic::List<Track^> track_collection;

	public ref class TrackCollection : public track_collection
	{
	public:
		void safeAdd(Track^);
		bool search(Track^ track);

		void sortByName();
		void sortByDescendingName();
		void sortByDuration();
		void sortByDescendingDuration();
		void sortByBPM();
		void sortByDescendingBPM();

		void purge();

		void exportToMP3(System::String^ outputFile);
	};

}