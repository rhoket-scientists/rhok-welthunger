rhok-welthunger
===============

To check if OpenCV is running just compile the hello world like so:

g++ `pkg-config --cflags opencv` hello_world.cpp -o hello-world `pkg-config --libs opencv`

Maybe as an alernative:
g++ hello_world.cpp $(pkg-config opencv –libs –cflags)


Include the images into an img/ folder and run the program:

make && ./app img/p201r055_7dt20010302_z28_20.tif img/p201r055_7dt20010302_z28_30.tif img/p201r055_7dt20010302_z28_40.tif && open outImg.tif

=======
by hand:
g++ -I/usr/include/opencv hello_world.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui

=============================================================================
to run under Linux:
export LD_LIBRARY_PATH=/usr/local/lib
====================================
Am 28.05.2012 12:49, schrieb Jochen.Moninger@welthungerhilfe.de:
Hier ist der earth explorer: http://earthexplorer.usgs.gov/
Dort kann man die Bilderzeitreihen runterladen

Hier Ressourcenmaterial:

http://landsat.usgs.gov/LandsatLookImages.php
http://www.uni-kiel.de/forum-erdkunde/unterric/material/einf_fe/kapitel_4_landsat_typ.htm
http://www.crwr.utexas.edu/gis/gishydro99/class/gomez/termproj.htm
http://www.isprs.org/proceedings/XXXV/congress/yf/papers/951.pdf
http://landsat.usgs.gov/documents/June_2010_Vierling%20-%20Idaho%20Remote%20Sensing%20Activities%20-%20Change%20Assessments.pdf

De facto muss man sich da reinarbeiten. Daher werden ja auch Spezialisten normalerweise fürstlich bezahlt.
Sie wissen bestimmt besser, ob sich aus der Sache fuer Ihre Gruppe etwas machen lässt. 

