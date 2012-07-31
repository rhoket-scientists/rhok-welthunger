#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import threading

import logging
import argparse

from lib import imagemerge, analysis_strategy


class Application:

	def __init__(self):
		self.parser = self.init_parser()
		self.register_cli_arguments()
		self.args = self.parser.parse_args()
		self.logger = self.init_logger()
		if not self.args.output_image:
			self.args.output_image = 'tmp/foo.tiff'
		else:
			self.args.output_image = self.args.output_image[0]


	def dispatch(self):
		"""This is the place where the app does something
		depending on its cli arguments.
		Add functionality here (please oneliners to keep things tidy)"""

		if self.args.debug:
			global debug
			debug = True
			self.log_arguments()

		if not self.args.nogui:
			self.show_gui()

		if self.args.merge_images:
			self.merge_in_new_thread()

		if self.args.lawn_grass:
			self.count_lg_in_new_thread()

		if self.args.dry_grass:
			self.count_dg_in_new_thread()

		if self.args.rvi:
			self.rvi_in_new_thread()

		if self.args.ndvi:
			self.ndvi_in_new_thread()


	def merge_in_new_thread(self):
		img = self.args.merge_images
		threading.Thread(target = lambda: imagemerge.merge_to_file(\
				img[0], img[1], img[2], self.args.output_image)).start()


	def count_lg_in_new_thread(self):
		threading.Thread(target = lambda: analysis_strategy.count_lawn_grass(\
				self.args.lawn_grass[0])).start()


	def count_dg_in_new_thread(self):
		threading.Thread(target = lambda: analysis_strategy.count_dry_grass(\
				self.args.dry_grass[0])).start()


	def rvi_in_new_thread(self):
		bands = self.args.rvi
		threading.Thread(target=lambda: \
				analysis_strategy.rvi_to_file(bands[0], bands[1],
					self.args.output_image)).start()


	def ndvi_in_new_thread(self):
		bands = self.args.ndvi
		threading.Thread(target=lambda: \
				analysis_strategy.ndvi_to_file(bands[0], bands[1],
					self.args.output_image)).start()


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
		self.parser.add_argument('-oimg', '--output-image', nargs=1,
				default=None, metavar=('outputimage.tif'),
				help="Write resulting image into a file", dest='output_image')
		self.parser.add_argument('-mi', '--merge-images', nargs=3,
				default=None, metavar=('image1.tif'),
				help="Merge images in rgb order", dest='merge_images')
		self.parser.add_argument('-lg', '--lawn-grass', nargs=1,
				default=None, metavar=('image1.tif'),
				help="Count pixels which are lawn grass", dest='lawn_grass')
		self.parser.add_argument('-dg', '--dry-grass', nargs=1,
				default=None, metavar=('image1.tif'),
				help="Count pixels which are dry grass", dest='dry_grass')
		self.parser.add_argument('-rvi', nargs=2,
				default=None, metavar=('bandx.tif'),
				help="Writes an image with the ratio vegetation index\
				(band4/band3) into the output image given with -oimg", dest='rvi')
		self.parser.add_argument('-ndvi', nargs=2,
				default=None, metavar=('bandx.tif'),
				help="Writes an image with the normalized difference vegetation index\
				(band4-band3)/(band4+band3) into output image given with -oimg", dest='ndvi')
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


	def log_arguments(self):
		self.logger.debug("=== DEBUG MODE ===")
		self.logger.debug("command line arguments:")
		for k in vars(self.args):
			self.logger.debug('{0}: {1}'.format(k,vars(self.args)[k]))


if __name__ == '__main__':
	Application().dispatch()
