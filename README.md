# Graphics Simulation

A C++ graphical simulation project using OpenGL/GLFW and the Eigen matrix library. This project demonstrates real-time graphics rendering and matrix-based state management.

## Features

- Real-time graphical rendering using OpenGL/GLFW
- Matrix-based world state management with Eigen
- Interactive controls for simulation reset
- Configurable world dimensions
- Smooth color transitions and intensity visualization

## Dependencies

- GLFW3
- OpenGL
- Eigen3
- C++ compiler with C++11 support
- Make

## Building

To build the project:

```bash
make
```

## Usage

After building, run the executable to start the simulation. The space bar can be used to reset the simulation state.

## Implementation Details

The project is structured into three main components:

- Graphics handling (`graphics.cpp`): Manages OpenGL initialization, window creation, and rendering
- Logic (`logic.cpp`): Handles the simulation state and step calculations
- Main program (`main.cpp`): Ties everything together and manages the main loop

## License

This project is open source and available under the MIT License.
