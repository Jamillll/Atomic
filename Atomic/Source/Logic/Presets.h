#pragma once
#include "SimulationHandler.h"
#include "../Utilities/DataTypes.h"

namespace Presets
{
	void GameofLifePreset(SimulationHandler* simulation) 
	{
		simulation->setRuleString("B3/S23", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void IslandPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B5678/S45678", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void GlidersPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B2/S", Moore);
		
		simulation->baseGrid->SetCoordColour(400, 400, 1.0f);
		simulation->baseGrid->SetCoordColour(401, 400, 1.0f);
	}

	void SetPreset(SimulationHandler* simulation, PresetNames preset)
	{
		switch (preset)
		{
		case GameofLife:
			GameofLifePreset(simulation);
			break;

		case Island:
			IslandPreset(simulation);
			break;

		case Gliders:
			GlidersPreset(simulation);
			break;
		}
	}
}