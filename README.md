# PID_controller
# Proportional Differential Integral(PID) 

PID without twiddle. Twiddle is the coolest thing about this project. I plan to fix this at a later date. Any suggestions are appreciated.
(Twiddle is an algorithm that helps PID get to the desired trajectory much quicker.)

This project uses the same simulator as in the Behavioral Cloning Project. I ran the simulator in Windows 8.1 and built and ran the code in a VM running Ubuntu 16.04. This appears to be the main environmental solution that works. Windows has too many problems to run uWS under. If you have a solution for Windows 8.1 I'd be curious to hear it.

Hints for setting this up. In VM VirtualBox Manager go to your VM->settings->network->advanced->Port Forwarding->Port Forwarding Rules. Enter a rule (Rule 1 in my case) with the host port and guest port set to 4567.

Most of main.cpp is for connecting to the simulator. All of the h.onMessage commands make the connection. You probably want to leave them alone.

PID.cpp sets the variables for the PID controller.

Twiddle.cpp implements the twiddle algorithm (currently not working.)







# Udacity Original README below:
CarND-Controls-PID

Self-Driving Car Engineer Nanodegree Program
Dependencies

    cmake >= 3.5
    All OSes: click here for installation instructions
    make >= 4.1
        Linux: make is installed by default on most Linux distros
        Mac: install Xcode command line tools to get make
        Windows: Click here for installation instructions
    gcc/g++ >= 5.4
        Linux: gcc / g++ is installed by default on most Linux distros
        Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
        Windows: recommend using MinGW
    uWebSockets
        Run either ./install-mac.sh or ./install-ubuntu.sh.
        If you install from source, checkout to commit e94b6e1, i.e.

        git clone https://github.com/uWebSockets/uWebSockets 
        cd uWebSockets
        git checkout e94b6e1

        Some function signatures have changed in v0.14.x. See this PR for more details.
    Simulator. You can download these from the project intro page in the classroom.

There's an experimental patch for windows in this PR
Basic Build Instructions

    Clone this repo.
    Make a build directory: mkdir build && cd build
    Compile: cmake .. && make
    Run it: ./pid.

Editor Settings

We've purposefully kept editor configuration files out of this repo in order to keep it as simple and environment agnostic as possible. However, we recommend using the following settings:

    indent using spaces
    set tab width to 2 spaces (keeps the matrices in source code aligned)

Code Style

Please (do your best to) stick to Google's C++ style guide.
Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using cmake and make!

More information is only accessible by people who are already enrolled in Term 2 of CarND. If you are enrolled, see the project page for instructions and the project rubric.
Hints!

    You don't have to follow this directory structure, but if you do, your work will span all of the .cpp files here. Keep an eye out for TODOs.

Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice. If you've created a profile for an IDE that you think other students would appreciate, we'd love to have you add the requisite profile files and instructions to ide_profiles/. For example if you wanted to add a VS Code profile, you'd add:

    /ide_profiles/vscode/.vscode
    /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it, and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles before. I believe the best way to handle this would be to keep them out of the repo root to avoid clutter. My expectation is that most profiles will include instructions to copy files to a new location to get picked up by the IDE, but that's just a guess.

One last note here: regardless of the IDE used, every submitted project must still be compilable with cmake and make./
How to write a README

A well written README file can enhance your project and portfolio. Develop your abilities to create professional README files by completing this free course.
