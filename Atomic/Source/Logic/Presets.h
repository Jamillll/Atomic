#pragma once
#include "SimulationHandler.h"
#include "../Utilities/DataTypes.h"

namespace Presets
{
	void GameofLifePreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B3/S23", Moore);
		simulation->SetStateColours({1, 1, 1}, {0, 0, 0});
		simulation->RandomGrid();
	}

	void AntiLifePreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B0123478/S01234678", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0, 0, 0 });
		simulation->RandomGrid();
	}

	void IslandPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B5678/S45678", Moore);
		simulation->SetStateColours({ 0, 1, 0 }, { 0, 0, 1 });
		simulation->RandomGrid();
	}

	void GlidersPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B2/S", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0, 0, 0 });

		simulation->baseGrid->SetCoordColour(400, 400, {1, 1, 1});
		simulation->baseGrid->SetCoordColour(401, 400, {1, 1, 1});
	}

	void DecayPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B35/S2467", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0.38, 0.15, 0.42 });
		simulation->RandomGrid();
	}

	void MazeRunnerPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B2/S0123", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0, 0, 0 });
		simulation->RandomGrid();
	}

	void SquareFractalPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B1/S012345678", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0, 0, 0 });
		simulation->baseGrid->SetCoordColour(simulation->baseGrid->axisLength / 2, simulation->baseGrid->axisLength / 2, {1, 1, 1});
	}

	void GeologyPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B3578/S24678", Moore);
		simulation->SetStateColours({ 0, 1, 0 }, { 0, 0, 1 });
		simulation->RandomGrid();
	}

	void InfestationPreset(SimulationHandler* simulation)
	{
		simulation->SetRuleString("B37/S04567", Moore);
		simulation->SetStateColours({ 1, 1, 1 }, { 0, 0, 0 });
		simulation->RandomGrid();
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