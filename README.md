# Team Rhoket Scientists for Welthungerhilfe

This software analyzes a given set of landsat satellite images to show how the land is used. It visualizes the different surface patterns with different colors.
 
It should help Welthungerhilfe to have strong arguments for disputing with the government of Sierra Leone about shifting land usage patterns.

The project got startet at the 3. Random Hacks of Kindness in Berlin from 2012-06-02 to 2012-06-03. We are currently rebuilding and extending the application in python. 

* The problem page: http://www.rhok.org/problems/shifting-patterns-land-use-and-availability-land-pujehun-district-southern-sierra-leone

* The solution page: http://www.rhok.org/solutions/vegetation-analyzer

##Dependencies
* `OpenCV` for image processing
* `Qt` for the GUI
* `Python` for the code
	* `pyqt` as a binding for Qt
	* `oktest` for the unit tests (only for developers)

To install the python dependencies, simple run `make req_stable`. 

##Run the application
To run the application, simply execute `make run`.

###get help
Run `python main.py -h` to see all avaliable command line options.

##Get Satellite images

* http://landsat.usgs.gov/LandsatLookImages.php
* http://www.uni-kiel.de/forum-erdkunde/unterric/material/einf_fe/* kapitel_4_landsat_typ.htm
* http://www.crwr.utexas.edu/gis/gishydro99/class/gomez/termproj.htm
* http://www.isprs.org/proceedings/XXXV/congress/yf/papers/951.pdf
* http://landsat.usgs.gov/documents/June_2010_Vierling%20-%20Idaho%20Remote%20Sensing%20Activities%20-%20Change%20Assessments.pdf


##Get OpenCV running

To check if OpenCV is running just compile the hello world:

`g++ $(pkg-config --cflags opencv) hello_world.cpp -o hello-world $(pkg-config --libs opencv)`

###install opencv from ppa
    
    $ sudo add-apt-repository ppa:gijzelaar/opencv2
    $ sudo apt-get update
    $ sudo apt-get install opencv
    
    
#For developers

Any help is eally appreciated. If you have an idea, great. Just start coding and send us a pull request. 

As a developer, you should install the requirements for developers. Simple run `make req_developer`. If you want to regenerate the UI files after editing the a Qt ui file, run `make generate_pyqt`. This will generate `.py` files for all ui files. 

If you want to have isolated Python environments, we recommend to use [virtualenvwrapper](http://www.doughellmann.com/projects/virtualenvwrapper/).
