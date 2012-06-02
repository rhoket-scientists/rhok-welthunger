rhok-welthunger
===============

To check if OpenCV is running just compile the hello world like so:

g++ `pkg-config --cflags opencv` hello_world.cpp -o hello-world `pkg-config --libs opencv`

Maybe as an alernative:
g++ hello_world.cpp $(pkg-config opencv –libs –cflags)
