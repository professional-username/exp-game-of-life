# Graphics Simulation

A C++ graphical simulation project using OpenGL/GLFW and the Eigen matrix library. This project demonstrates real-time graphics rendering and matrix-based state management.

![Simulation Preview](images/preview.png)

## Features

- Real-time graphical rendering using OpenGL/GLFW
- Matrix-based world state management with Eigen
- Interactive controls for simulation reset
- Configurable world dimensions
- Smooth color transitions and intensity visualization

## Development Setup

This project uses [devenv.sh](https://devenv.sh) for development environment management. This ensures consistent development environments with all required dependencies.

### Prerequisites

1. Install Nix package manager
2. Enable Flakes and install direnv (follow [devenv.sh installation guide](https://devenv.sh/getting-started/))

### Getting Started

1. Clone the repository:
```bash
git clone <repository-url>
cd <repository-name>
```

2. Allow direnv:
```bash
direnv allow
```

3. Your development environment will be automatically set up with all required dependencies!

### Development Commands

- `project-compile`: Compile the project
- `project-run`: Run the compiled executable
- `project-clean`: Clean build artifacts
- `project-init`: Initialize project directories

Example workflow:
```bash
devenv shell
project-compile
project-run
```

## Implementation Details

The project is structured into these main components:

- `src/graphics.cpp`: Manages OpenGL initialization, window creation, and rendering
- `src/logic.cpp`: Handles the simulation state and step calculations
- `src/main.cpp`: Ties everything together and manages the main loop

### Visualization Examples

Here's how the simulation looks in action:

![Color Transitions](images/colors.png)
![State Visualization](images/state.png)

## License

This project is open source and available under the MIT License.
