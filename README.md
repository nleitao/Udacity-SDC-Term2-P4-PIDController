# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

As explained in the lecture videos, the P (proportional) controller makes the car steer in a magnitude proportional to the car's CTE (Cross track error or "distance to the lane center"). The way I see it: is the normal controller of the car, that makes the car steer right if we are too much to the left, and steer left if we are too much to the right.

The D controller (differential) counteracts the last/current movement of the car (caused by P) preventing this movement to overshoot the "correct" position. The way I see it: "Is how often/frequent should I react? Or did I see this situation (a deviation from the centre of the lane) before and I can chill?"

The last controller is the I controller (integral). Like explained in the videos is the controller that counteracts the bias of the P/D controller to always try to go to the centre of the line very fast. The way I see it: in case the car not being in the centre of the lane due to the last/current steering, how much should I react to try to put it right? "It's a metric of how much should I react".

## Hyperparameters tuning
The parameters (P, I, D coefficients) were tuned manually.
I've started all of them equal to 1 and observed the car's behaviour.

P=1 , I=1, D=1
1. Car was too harand reacted too much to any deviation -> I need to reduce the "I" coefficient. I coefficient reduced by 0.5. Car seemed to be (on average) on the centre of the lane so no need to tune P.

P=1, I=0.5, D=1
2. Car was less harsh but way too "nervous", any deviation would make the car steer back to the centre -> need to make the car more "chilled" by increasing the D coefficient. I've done 0.5 increments and I stopped in P=6.

Final parameters:
P=1, I=0.5, D=6.

I ran the simulator with these parameters and the car drives very well (in some parts even better than in the previous module!).
Since there was no minimum speed, I've reduced the speed to 20mpg (I've remembered that I had much better results with a reduced velocity in the machine learning module)



## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
