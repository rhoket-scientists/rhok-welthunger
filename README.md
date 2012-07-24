# Team Rhoket Scientists for Welthungerhilfe

This software analyzes a given set of landsat satellite images to show how the land is used. It visualizes the different surface patterns with different colors.

It should help Welthungerhilfe to have strong arguments for disputing with the government of Sierra Leone about shifting land usage patterns.

The project got startet at the 3. Random Hacks of Kindness in Berlin from
2012-06-02 to 2012-06-03. We are currently rebuilding and extending the
application in Python.

* The problem page: http://www.rhok.org/problems/shifting-patterns-land-use-and-availability-land-pujehun-district-southern-sierra-leone

* The solution page: http://www.rhok.org/solutions/vegetation-analyzer


##Run the Application
To run the application, simply execute `make run`.

###Get Help
Run `python main.py -h` to see all avaliable command line options.

##Get Satellite Images

* http://landsat.usgs.gov/LandsatLookImages.php
* http://www.uni-kiel.de/forum-erdkunde/unterric/material/einf_fe/* kapitel_4_landsat_typ.htm
* http://www.crwr.utexas.edu/gis/gishydro99/class/gomez/termproj.htm
* http://www.isprs.org/proceedings/XXXV/congress/yf/papers/951.pdf
* http://landsat.usgs.gov/documents/June_2010_Vierling%20-%20Idaho%20Remote%20Sensing%20Activities%20-%20Change%20Assessments.pdf


#For developers

Any help is really appreciated. If you have an idea, great. Just start coding
or drop us a line and send us a pull request.

As a developer, you should install the requirements for developers. Just run
`make req_stable`.
If you want to regenerate the UI files after editing the a Qt ui file, run
`make generate_pyqt`.
This will generate `.py` files for all ui files.

If you want to have isolated Python environments, we recommend to use [virtualenvwrapper](http://www.doughellmann.com/projects/virtualenvwrapper/).


## Setup on Linux (tested on Ubuntu)
1 `sudo apt-get install pip-python` for Python dependencies
1. QT for the GUI
1. OpenCV for image processing


##Setup on MacOS X
1. `brew install opencv`
1. `brew install pyqt`
1. `easy_install pip`
1. `make req_stable`


##Dependencies
* `OpenCV` for image processing
* `Qt` for the GUI
* `Python` for the code
	* `pyqt` as a binding for Qt
	* `oktest` for the unit tests (only for developers)

To install the Python dependencies, simply run `make req_stable`.
