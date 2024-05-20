
# Ants-vs-Doodlebugs

The purpose of this programming assignment is to create a simple 2D simulation of the predator-prey relationship. 
The prey are ants and the predator are beetles. These creatures live in a grid of cells with dimensions 20x20. 
Each cell can contain only one creature at a time. The grid is bounded so that no creature can move beyond its limits.

Time is expressed in steps. Each creature can perform certain actions at each time step.

🐜 Ants behave according to the following model:

•Move: At each time step, ants attempt to move randomly up, down, left, or right. If the neighboring cell in the chosen 
direction is occupied by a doodlebug or leads the ant outside the grid, the ant remains in its current cell.

•Reproduce: If an ant survives for three consecutive time steps, at the end of the step (after movement), the ant 
will reproduce. In the simulation, this is expressed by creating a new ant in an adjacent cell (up, down, left, or right) 
that is empty. If no empty cell is available, reproduction does not occur. Once an offspring is created, the ant cannot 
reproduce again until it survives for three consecutive time steps again.

🪲Beetles behave according to the following model:

•Move: At each time step, a beetle moves to an adjacent cell that contains an ant and consumes the ant. If there are no ants 
in neighboring cells, the beetle moves according to the same rules as ants. Note that a beetle cannot eat other beetles.

•Reproduce: If a beetle survives for eight consecutive time steps, it will produce a new beetle at the end of the step, following 
the same rules as reproduction for ants.

• Starvation: If a beetle hasn't eaten any ants within three time steps, then at the end of the third step, it will die 
from starvation. In the simulation, this is expressed by removing the beetle from the grid of cells.

During each round, all beetles must move before the ants.

Write a program to implement this simulation and visualize the world using ASCII characters "O" for ants and "X" for beetles. 
Create a class named Organism that contains the basic data common to ants and beetles. This class should have a virtual 
function named move, which will be defined in the derived classes Ant and Beetle. You may need additional data structures 
to track which organisms have moved.

Start the world with 5 beetles and 100 ants. After each time step, prompt the user to press the Enter key to proceed to 
the next time step. Ideally, you should observe a cyclic evolution between the populations of predators and prey, although 
random disturbances may lead to the disappearance of one or both species.

This is an exercise from Savitch's Absolute C++, chapter 15 (Exercise 3).
