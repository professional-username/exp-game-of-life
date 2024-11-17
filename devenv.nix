{ pkgs, lib, config, inputs, ... }:

{
  # https://devenv.sh/basics/
  env = {
    GREET = "devenv";
  };

  # Required packages for C++ development with GLFW and Eigen
  packages = with pkgs; [
    # Build tools
    gcc
    cmake
    gnumake
    
    # Libraries
    glfw
    eigen
    
    # Development tools
    gdb
    valgrind
    
    # Version control
    git
  ];

  # Configure compiler flags if needed
  env.CPATH = "${pkgs.eigen}/include/eigen3:${pkgs.glfw}/include";
  env.LIBRARY_PATH = "${pkgs.glfw}/lib";

  enterShell = ''
    echo "C++ Development Environment Ready"
    echo "GLFW version: $(pkg-config --modversion glfw3)"
    echo "GCC version: $(gcc --version | head -n1)"
  '';

  # Basic test to ensure environment is working
  enterTest = ''
    echo "Running environment tests..."
    gcc --version
    pkg-config --exists glfw3 && echo "GLFW found"
    test -d ${pkgs.eigen}/include/eigen3 && echo "Eigen found"
  '';
}
