# -*- coding: utf-8 -*-

from PyQt4.QtCore import *
from PyQt4.QtGui import *
import logging

from gen.mainwindow import Ui_MainWindow
from lib import imagemerge, analysis_strategy

class MainWindow(QMainWindow, Ui_MainWindow):
	def __init__(self, parent = None, args = []):
		QMainWindow.__init__(self, parent)
		self.setupUi(self)

		self.logger = logging.getLogger('vegetation')

		self.actionQuit.setShortcut(QKeySequence.Quit)
		self.actionOpen_Images.setShortcut(QKeySequence.Open)
		self.actionExport.setShortcut(QKeySequence.SaveAs)
		self.actionPrint.setShortcut(QKeySequence.Print)

		self.actionOpen_Images.triggered.connect(self.handle_merge_files)

		self.lawnGrassButton.clicked.connect(self.handle_lawn_grass_button)
		self.dryGrassButton.clicked.connect(self.handle_dry_grass_button)
		self.ndviButton.clicked.connect(self.handle_ndvi_button)

		self.IMG_WIDTH = round(7771/2)
		self.IMG_HEIGHT = round(6971/2)

		self.show()


	def handle_ndvi_button(self):
		analysis_strategy.ndvi_to_file('img/2001-03-24/B30.TIF', 'img/2001-03-24/B40.TIF')
		self.render_in_scene(self.load_and_resize_pixmap('tmp/ndvi.tiff'))


	def handle_lawn_grass_button(self):
		img = 'img/2001-03-24/B40.TIF'
		logging.getLogger('vegetation').info("Lawn: "+
				str(analysis_strategy.count_lawn_grass(img)))


	def handle_dry_grass_button(self):
		img = 'img/2001-03-24/B30.TIF'
		logging.getLogger('vegetation').info("Dry: " +
				str(analysis_strategy.count_dry_grass(img)))


	def handle_merge_files(self):
		filenames = QFileDialog.getOpenFileNames(self, 'Select 3 files')
		if not filenames:
			return

		files = [str(f) for f in filenames]
		if len(files) == 3:
			imagemerge.merge_to_file(files[0], files[1], files[2], 'tmp/foo.tiff')
			self.render_in_scene(self.load_and_resize_pixmap('tmp/foo.tiff'))

		else:
			QMessageBox.information(self, 'Error',
			'Please select exactly 3 pictures', QMessageBox.Ok)


	def render_in_scene(self, pix):
		self.scene = QGraphicsScene()
		self.scene.clear()
		self.scene.addPixmap(pix)
		self.imageView.setScene(self.scene)
		self.scene.update()

	def load_and_resize_pixmap(self, file_name):
		return QPixmap(file_name) .scaled(self.IMG_WIDTH, self.IMG_HEIGHT,
				Qt.KeepAspectRatio, Qt.FastTransformation)

