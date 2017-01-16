// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "GeneticAlgorithm.h"


namespace AutoMixAI
{
	namespace GeneticAlgorithm
	{
		void sortTrackByGeneticAlgorithm(TrackCollection^ trackCollection)
		{
			
		}

		int computeTracksDistance(Track^ track1, Track^ track2)
		{
			return 0;
		}

		void createInitialPopulation(TrackCollection^ trackCollection, population^ pop)
		{
			pop = gcnew population();
			for (int k = 0;k<POPULATION_SIZE;k++)
			{
				TrackCollection^ individual = gcnew TrackCollection();
				for (int i = 0; i<trackCollection->Count; i++)
				{
					individual->Add(trackCollection[i]);
				}
				for (int i = 0;i<individual->Count;i++)
				{
					System::Random^ rand = gcnew System::Random();
					Track^ track = individual[i];
					individual->Remove(track);
					individual->Insert(rand->Next(individual->Count), track);
				}
				pop->Add(individual);
			}
		}

		int computeIndividualEvaluation(TrackCollection^ individual)
		{
			int result = 0;
			for (int k = 0;k<(individual->Count)-1;k++)
			{
				result = result + computeTracksDistance(individual[k], individual[k + 1]);
			}
			return result;
		}

		void sortPopulation(population^ population, int begin, int end)
		{
			
		}
	}
}
