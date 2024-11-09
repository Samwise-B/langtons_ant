# Langton's Ant Simulation in C

This project is a C-based implementation of **Langton's Ant**, showcasing my proficiency in systems programming, algorithm design, and efficient memory management in a low-level language. Built with CMake, this project simulates the emergent behavior of a two-dimensional Turing machine known as Langton's Ant—a simple yet complex system that demonstrates principles of computational theory and emergent behavior in cellular automata.

## Project Overview

**Langton's Ant** is a cellular automaton developed by Chris Langton in 1986, running on a square grid of black and white cells with very simple rules:

- **Movement**: An "ant" moves based on the color of the cell it occupies:
  - On a **white cell**: The ant turns **right** 90°, changes the cell to black, and moves forward.
  - On a **black cell**: The ant turns **left** 90°, changes the cell to white, and moves forward.
- **Emergent Behavior**: Despite the simplicity of these rules, Langton's Ant displays complex, emergent patterns after a certain number of moves, including a "highway" structure that extends indefinitely.

Through this project, I created a **text-based simulation** that highlights the evolution of Langton’s Ant over time and demonstrates efficient coding practices in C. This simulation allows users to view a step-by-step evolution of the ant's path on the grid.

## Key Skills Demonstrated

### 1. **C Programming and Memory Management**
   - **Efficient Array Handling**: Utilized dynamic memory allocation to manage the grid state efficiently, demonstrating knowledge of pointers and memory operations in C.
   - **Algorithm Optimization**: Implemented the Turing machine rules with minimal overhead, ensuring the simulation runs smoothly even with large grid sizes.
   - **Low-Level Debugging**: Used C debugging techniques to troubleshoot memory management and ensure the program is free of leaks and undefined behavior.

### 2. **Algorithm Design and Emergent Behavior Modeling**
   - **State Machine Implementation**: Modeled the Turing machine state transitions, simulating the ant's rule-based movements and toggling cell states.
   - **Emergent Complexity**: Captured Langton’s Ant's emergent behavior, demonstrating an understanding of complex system modeling through simple algorithms.
   - **Cellular Automata**: Showcased knowledge of cellular automata and two-dimensional state transitions, which are foundational in simulations and game development.

### 3. **Cross-Platform Build Configuration with CMake**
   - **CMake Project Setup**: Built a flexible CMake configuration to compile and run the project on various platforms, illustrating experience with build automation and cross-platform compatibility.
   - **Modular Code Structure**: Organized code into modular components, allowing for straightforward extensions and modifications.

## How to Build and Run

### Prerequisites
- **CMake** version 3.10 or higher
- **C Compiler** (e.g., GCC or Clang)

### Building the Project
1. Clone the repository:
   ```
   git clone https://github.com/yourusername/langtons-ant-c.git
   cd langtons-ant-c
2. Build the project using CMake:
  ```
  mkdir build
  cd build
  cmake ..
  make

## Running the Simulation
After building, run the executable generated in the build directory:
`./langtons_ant`
The simulation will display a text-based rendering of Langton's Ant evolving on a grid, updating in real-time to show the ant's movement and the changing grid states.

# Future Extensions and Potential Enhancements
This project serves as a foundation for exploring more advanced concepts, such as:
- Multi-Ant Simulations: Introducing multiple ants to observe how their interactions affect emergent behavior.
- Colored Turmites: Extending Langton’s Ant to support multiple colors and states, which adds complexity and visual diversity.
- Graphical Rendering: Integrating a graphical library (such as SDL or OpenGL) to display the grid visually, creating a more engaging and dynamic user experience.

