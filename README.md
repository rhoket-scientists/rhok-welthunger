# Team Rhoket Scientists for Welthungerhilfe

This software analyzes a given set of landsat satellite images to show how the land is used. It visualizes the different surface patterns with different colors.
 
It should help Welthungerhilfe to have strong arguments for disputing with the government of Sierra Leone about shifting land usage patterns.

T	he project got startet at the 3. Random Hacks of Kindness in Berlin from 2012-06-02 to 2012-06-03. We plan to hack on it further in july.

* The problem page: http://www.rhok.org/problems/shifting-patterns-land-use-and-availability-land-pujehun-district-southern-sierra-leone

* The solution page: http://www.rhok.org/solutions/vegetation-analyzer

##Dependencies
* OpenCV for image processing
* QT for the GUI

##Get Satellite images

* http://landsat.usgs.gov/LandsatLookImages.php
* http://www.uni-kiel.de/forum-erdkunde/unterric/material/einf_fe/* kapitel_4_landsat_typ.htm
* http://www.crwr.utexas.edu/gis/gishydro99/class/gomez/termproj.htm
* http://www.isprs.org/proceedings/XXXV/congress/yf/papers/951.pdf
* http://landsat.usgs.gov/documents/June_2010_Vierling%20-%20Idaho%20Remote%20Sensing%20Activities%20-%20Change%20Assessments.pdf


##Get OpenCV running

To check if OpenCV is running just compile the hello world:

`g++ $(pkg-config --cflags opencv) hello_world.cpp -o hello-world $(pkg-config --libs opencv)`

Include the images into an img/ folder and run the program:

`make && ./app img/img1 img/img2 img/img3`

=======
Compile the hello world by hand:
`g++ -I/usr/include/opencv hello_world.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui`


To run under Linux:
export LD_LIBRARY_PATH=/usr/local/lib



________________________________
install opencv from ppa
$ sudo add-apt-repository ppa:gijzelaar/opencv2
$ sudo apt-get update
$ sudo apt-get install opencv
