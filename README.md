# Atomic
Atomic is a cellular automata engine created in C++, using OpenGL, GLFW, GLEW and Dear IMGUI.

Atomic consists of a renderer that can take a vertex buffer and a simulation handler that will update the grid by the rules set by the user. There are multiple presets that the user can select such as Conway's game of life and geology that the user can select, or they will be able to make and use their own presets.

Current features implimented: <br>
  -Simple renderer <br>
  -Impliment the simulation handler <br>
  -Moore and Neumann neighbourhood rules implimented <br>
  -rulestrings implimented <br>
  -Presets system implimented along with a Variety of Presets <br>
  -Impliment the UI with IMGUI <br>
  -Allow the user to type custom rulestrings <br>
  -Allow the user to select state colour <br>
  -Basic UI completed <br>

ToDo: <br>
  -Optimise the renderer to take in an index buffer to optimise how much space the verticies use <br>
  -Impliment user interaction with the grid <br>
  -Impliment Preset creation and saving <br>
  -Impliment support for any amount of states <br>
  -Impliment custom seed input <br>
