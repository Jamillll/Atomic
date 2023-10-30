# Atomic
Atomic is a cellular automata engine created in C++, using OpenGL, GLFW, GLEW and Dear IMGUI.

It will consist of a renderer that can take a vertex buffer and a simulation handler that will update the grid by the rules set by the user. There will be multiple presets that the user can select such as Conway's game of life and wolfram that the user can select, or they will be able to make and use their own presets.

Current features implimented: <br>
  -Simple renderer <br>
  -Impliment the simulation handler <br>
  -Moore and Neumann neighbourhood rules implimented <br>
  -rulestrings implimented <br>
  -Presets system implimented along with 3 presets: Game of Life, Islands and Gliders <br>

ToDo: <br>
  -Optimise the renderer to take in an index buffer to optimise how much space the verticies use <br>
  -Impliment the UI with IMGUI <br>
  -Impliment user interaction with the grid <br>
