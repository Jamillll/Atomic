#pragma once
#include "../Logic/SimulationHandler.h"
#include "../Logic/Presets.h"
#include "imgui.h"
#include "imgui_stdlib.h"

class Editor
{
private:
	SimulationHandler* simulation = nullptr;
	int selectedPreset = 0;

public:
	void InitEditor(SimulationHandler* inputSimulation)
	{
		simulation = inputSimulation;
	}

	void ShowEditor()
	{
		ImGui::Begin("Editor");

		ImGui::Text("Generation: %d", simulation->generation);

		ImGui::Text("Presets:");
		int currentPreset = selectedPreset;
		ImGui::Combo(" ", &selectedPreset, "GameofLife\0AntiLife\0Geology\0Island\0Gliders\0Infestation\0Decay\0MazeRunner\0SquareFractal\0\0");
		if (selectedPreset != currentPreset) Presets::SetPreset(simulation, selectedPreset);

		Colour deadColour;
		Colour aliveColour;
		
		simulation->GetStateColours(&aliveColour, &deadColour);

		float deadColourArray[3] = {deadColour.r, deadColour.g, deadColour.b};
		float aliveColourArray[3] = { aliveColour.r, aliveColour.g, aliveColour.b };

		float currentDeadColourArray[3] = { deadColour.r, deadColour.g, deadColour.b };
		float currentAliveColourArray[3] = { aliveColour.r, aliveColour.g, aliveColour.b };

		ImGui::ColorEdit3("dead colour", deadColourArray);
		ImGui::ColorEdit3("alive colour", aliveColourArray);

		if (deadColourArray[0] != currentDeadColourArray[0] || aliveColourArray[0] != currentAliveColourArray[0] ||
			deadColourArray[1] != currentDeadColourArray[1] || aliveColourArray[1] != currentAliveColourArray[1] ||
			deadColourArray[2] != currentDeadColourArray[2] || aliveColourArray[2] != currentAliveColourArray[2])
		{
			//simulation->pauseSimulation = true;
			simulation->SetStateColours({ aliveColourArray[0], aliveColourArray[1], aliveColourArray[2] }, { deadColourArray[0], deadColourArray[1], deadColourArray[2] });
		}

		ImGui::End();
	}
};