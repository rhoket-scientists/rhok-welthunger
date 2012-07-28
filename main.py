#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import logging
import argparse
import threading
from lib import imagemerge

class Application:

	def __init__(self):
		self.parser = self.init_parser()
		self.register_cli_arguments()
		self.args = self.parser.parse_args()
		self.logger = self.init_logger()


	def dispatch(self):
		"""This is the place where the app does something
		depending on its cli arguments"""

		if self.args.debug:
			self.logger.debug("=== DEBUG MODE ===")
			self.logger.debug("command line arguments:")
			for k in vars(args):
				logger.debug('{0}: {1}'.format(k,vars(args)[k]))

		if not self.args.nogui:
			show_gui(self.args)

		if self.args.images:
			threading.Thread(target=imagemerge.merge_to_file,
				args=((self.args.images[0], self.args.images[1], self.args.images[2],
					'/tmp/foo.tiff'))).start()


	def init_parser(self):
		return argparse.ArgumentParser(prog='Vegetation Analyzer',
				description='Does stuff.', epilog='Let us do the work.')


	def register_cli_arguments(self):
		self.parser.add_argument('-c','--commandline', action='store_true',
				dest='nogui',
				help="don't use a graphical user interface")
		self.parser.add_argument('-d','--debug', action='store_true',
				help="print debug information to stdout")
		self.parser.add_argument('-o','--output', nargs=1,
				type=argparse.FileType('w'),
				default=sys.stdout,
				help='write results to FILE (default is stdout)')
		self.parser.add_argument('-i','--input', nargs=3,
				default=None, metavar=('image1.tif'),
				help="input images", dest='images')
		self.parser.add_argument('--version', action='version',
				version='%(prog)s 0.0.1')


	def init_logger(self):
		logger = logging.getLogger('vegetation')
		if self.args.debug:
			logger.setLevel(logging.DEBUG)
		else:
			logger.setLevel(logging.INFO)

		formatter = logging.Formatter("%(relativeCreated)s %(name)s %(levelname)s: %(message)s")
		stderrHandler = logging.StreamHandler(sys.stderr)
		stderrHandler.setFormatter(formatter)
		logger.addHandler(stderrHandler)
		return logger


	def show_gui(self):
		from PyQt4 import QtCore, QtGui
		from gui.mainwindow import MainWindow

		QtCore.QCoreApplication.setOrganizationName('Rhoket Scientists');
		QtCore.QCoreApplication.setOrganizationDomain('');
		QtCore.QCoreApplication.setApplicationName('Vegetation Analyzer');

		app = QtGui.QApplication(sys.argv)
		window = MainWindow(args = self.args)
		#window.setWindowState(QtCore.Qt.WindowMaximized)
		window.show()
		window.raise_()
		return app.exec_()


if __name__ == '__main__':
	Application().dispatch()



