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

	void AntiLifePreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B0123478/S01234678", Moore);
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

	void DecayPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B35/S2467", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void MazeRunnerPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B2/S0123", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void SquareFractalPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B1/S012345678", Moore);
		simulation->baseGrid->SetCoordColour(simulation->baseGrid->axisLength / 2, simulation->baseGrid->axisLength / 2, 1.0f);
	}

	void GeologyPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B3578/S24678", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void InfestationPreset(SimulationHandler* simulation)
	{
		simulation->setRuleString("B37/S04567", Moore);
		simulation->baseGrid->RandomGrid();
	}

	void SetPreset(SimulationHandler* simulation, PresetNames preset)
	{
		switch (preset)
		{
		case GameofLife:
			GameofLifePreset(simulation);
			break;

		case AntiLife:
			AntiLifePreset(simulation);
			break;

		case Island:
			IslandPreset(simulation);
			break;

		case Gliders:
			GlidersPreset(simulation);
			break;

		case Decay:
			DecayPreset(simulation);
			break;

		case MazeRunner:
			MazeRunnerPreset(simulation);
			break;

		case SquareFractal:
			SquareFractalPreset(simulation);
			break;

		case Geology:
			GeologyPreset(simulation);
			break;

		case Infestation:
			InfestationPreset(simulation);
			break;
		}
	}
}