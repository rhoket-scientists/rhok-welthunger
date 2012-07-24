#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import logging
import argparse
from lib import imagemerge

def main():

	parser = argparse.ArgumentParser(prog='Vegetation Analyzer', description='Does stuff.', epilog='Let us do the work.')
	parser.add_argument('-c','--commandline', action='store_true', dest='nogui',
				   help="don't use a graphical user interface")
	parser.add_argument('-d','--debug', action='store_true',
				   help="print debug information to stdout")
	parser.add_argument('-o','--output', nargs=1, type=argparse.FileType('w'),
				   default=sys.stdout, help='write results to FILE (default is stdout)')
	parser.add_argument('-i','--input', nargs=2, type=argparse.FileType('rb'), default=None, metavar=('image1.png'),
				   help="input images", dest='images')
	parser.add_argument('--version', action='version', version='%(prog)s 0.0.1')

	args = parser.parse_args()

	global debug
	debug = args.debug

	logger = logging.getLogger('vegetation')
	if args.debug:
		logger.setLevel(logging.DEBUG)
	else:
		logger.setLevel(logging.INFO)

	formatter = logging.Formatter("%(relativeCreated)s %(name)s %(levelname)s: %(message)s")
	stderrHandler = logging.StreamHandler(sys.stderr)
	stderrHandler.setFormatter(formatter)
	logger.addHandler(stderrHandler)

	if args.debug:
		logger.debug("=== DEBUG MODE ===")
		logger.debug("command line arguments:")
		for k in vars(args):
			logger.debug('{0}: {1}'.format(k,vars(args)[k]))

	if not args.nogui:
		show_gui(args)
	
	if args.images:
		imagemerge.merge_images(args.images)

def show_gui(args):
	from PyQt4 import QtCore, QtGui
	from gui.mainwindow import MainWindow

	QtCore.QCoreApplication.setOrganizationName('Rhoket Scientists');
	QtCore.QCoreApplication.setOrganizationDomain('');
	QtCore.QCoreApplication.setApplicationName('Vegetation Analyzer');

	app = QtGui.QApplication(sys.argv)
	window = MainWindow(args = args)
	#window.setWindowState(QtCore.Qt.WindowMaximized)
	window.show()
	return app.exec_()

if __name__ == '__main__':
	main()