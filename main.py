#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import logging
import argparse
import threading

from lib import imagemerge


def dispatch(args):
	"""This is the place where the app does something
	depending on its cli arguments"""

	if not args.nogui:
		show_gui(args)

	if args.images:
		threading.Thread(target=imagemerge.merge_to_file,
			args=((args.images[0], args.images[1], args.images[2],
				'/tmp/foo.tiff')))


def main():
	parser = init_parser()
	register_cli_arguments(parser)
	args = parser.parse_args()

	global debug
	debug = args.debug

	logger = init_logger(args)

	dispatch(args)


def init_parser():
	return argparse.ArgumentParser(prog='Vegetation Analyzer',
			description='Does stuff.', epilog='Let us do the work.')


def register_cli_arguments(parser):
	parser.add_argument('-c','--commandline', action='store_true',
			dest='nogui',
			help="don't use a graphical user interface")
	parser.add_argument('-d','--debug', action='store_true',
			help="print debug information to stdout")
	parser.add_argument('-o','--output', nargs=1,
			type=argparse.FileType('w'),
			default=sys.stdout,
			help='write results to FILE (default is stdout)')
	parser.add_argument('-i','--input', nargs=2,
			type=argparse.FileType('rb'),
			default=None, metavar=('image1.png'),
			help="input images", dest='images')
	parser.add_argument('--version', action='version',
			version='%(prog)s 0.0.1')


def init_logger(args):
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

	return logger


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
