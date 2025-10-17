# CPPND: Capstone Snake Game Example
# 
The starter code has been enhanced to have a speed selection screen. The initial logic would only increase the speed automatically during game play. Now there is an independent screen to make this change. 

* Clicking Up and Down allows you to change the speed in the top top title.
* Pressing enter will advance you to the next screen.
* During gameplay pressing backspace will pause the game


For the criteria of 
"The project demonstrates an understanding of C++ functions and control structures."
1. This is shown with void Controller::HandleInput

2. The project accepts user input and processes the input.
   For void Controller::HandleInput, the pause input was added.
   
One or more classes are added to the project with appropriate access specifiers for class members.
1.  Game_Mode was added to the project


The project makes use of references in function declarations.
At least two variables are defined as references, or two functions use pass-by-reference in the project code.
1.    controller.HandleInput(running, snake, current_mode, snake.speedMultiplier, isPaused) was updated to have two pass by reference;


The project uses multithreading.

The project uses multiple threads or async tasks in the execution.
Member data that is subject to an invariant is hidden from the user and accessed via member methods.
1.  There two threads one for renderring one for handling input

A mutex or lock is used in the project.
1.  There is a   std::atomic<bool> isPaused{false};



The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.s

1. snake.h/renderer.h,game.h and controller.h do not use new, malloc, delete or raw points. Objects are created and destroyed by their respective constructors/destructors or done at compile time.  So it is following RAII. 

plementation details from their interfaces.

All class member functions document their effects, either through function names, comments, or formal documentation.

Member functions do not change the program state in undocumented ways.
1. Doxygen has been added to the project.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
