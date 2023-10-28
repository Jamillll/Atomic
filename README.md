# Atomic
Atomic is a cellular automata engine created in C++, using OpenGL, GLFW, GLEW and Dear IMGUI.

It will consist of a renderer that can take a vertex buffer and a simulation handler that will update the grid by the rules set by the user. There will be multiple presets that the user can select susch as Conway's game of life and wolfram that the user can select, or they will be able to make and use their own presets.

Current features implimented:
  -Simple renderer

ToDo:
  -Impliment the simulation handler
  -Optimise the renderer to take in an index buffer to optimise how much space the verticies use
  -Fix the bug that limits the grid size
  -Impliment the UI with IMGUI
