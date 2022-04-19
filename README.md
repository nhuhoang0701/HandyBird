# HandyBird
HandyBird is the classic game Flappy Bird written in C++ using OpenCV4 and SFML libraries with real-time hand gesture detection to fly the bird instead of using keyboards.

## Prerequisites
* C++ compiler (gcc, g++, ...)
* [OpenCV](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)
* Cmake
* SFML

For C++ compiler, Cmake, SFML and their dependencies, use following command:
```
sudo apt-get install cmake g++ libsfml-dev
```

## Installation
```
mkdir build && cd build && cmake .. && cd ..
cmake -S . -B build
cmake --build build
```

Then you can run the program:
```
build/HandyBird
```
## Principles

### Hand Detection
* Initialy, we need to remove background behind the user so that the program can find it easier to detect user's hand. After running the program, 2 windows _camera_ and _foreground_ show up. The _camera_ is the main window for you to track yourself while playing. The _foreground_ window is used to guarantee the background is removed properly. To start removing the background, without showing hand on the camera, press `b`, the _foreground_ window will show images of removal of the background and user's face. If it's not done properly, press `b` and repeat the step.


* Then, we will find user's color skin. In order to do that, user need to place their hand in the sample area and press `s` key. The _foreground_ window will disappear and the contour of user's hand will be shown on the _camera_ window.

## How to play

* To start playing game, we move the cursor to the _Handy Bird_ window and press `space`. To fly up the bird, open your hand widely which is equal to press `space` in Flappy Bird game. To stop flying, close your hand like a fist (equal to release `space`). When the game is over, press `c` to continue and repeat pressing `space` key and continuing to play.
