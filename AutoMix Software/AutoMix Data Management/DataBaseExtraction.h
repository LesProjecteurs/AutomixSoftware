// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class DataBaseExtraction : public IExtraction
	{
	public:
		DataBaseExtraction(DataBase^);
		void extractData(System::ComponentModel::BackgroundWorker^, int, System::Threading::CancellationTokenSource^, Track^) override;
		
	private:
		DataBase^ _dataBase;
	};

}