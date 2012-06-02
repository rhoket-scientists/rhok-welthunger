rhok-welthunger
===============

To check if OpenCV is running just compile the hello world like so:

g++ -I/usr/include/opencv hello_world.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui

g++ hello_world.cpp $(pkg-config opencv –libs –cflags)
