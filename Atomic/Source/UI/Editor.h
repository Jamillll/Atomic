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
		ImGui::Combo(" ", &selectedPreset, "GameofLife\0Island\0Gliders\0Decay\0AntiLife\0MazeRunner\0SquareFractal\0Geology\0Infestation\0\0");
		if (selectedPreset != currentPreset) Presets::SetPreset(simulation, selectedPreset);

		ImGui::End();
	}
};