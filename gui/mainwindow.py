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

		self.actionOpen_Images.triggered.connect(self.handle_button)

		self.lawnGrassButton.clicked.connect(self.handle_lawn_grass_button)
		self.dryGrassButton.clicked.connect(self.handle_dry_grass_button)

		self.show()


	def handle_lawn_grass_button(self):
		img = 'img/2001-03-24/B40.TIF'
		logging.getLogger('vegetation').info("Lawn: "+
				str(analysis_strategy.count_lawn_grass(img)))


	def handle_dry_grass_button(self):
		img = 'img/2001-03-24/B30.TIF'
		logging.getLogger('vegetation').info("Dry: " +
				str(analysis_strategy.count_dry_grass(img)))


	def handle_button(self):
		filenames = QFileDialog.getOpenFileNames(self, 'Select 3 files')
		if not filenames:
			return

		files = [str(f) for f in filenames]
		if len(files) == 3:
			imagemerge.merge_to_file(files[0], files[1], files[2], 'tmp/foo.tiff')
			self.show_merged_image('tmp/foo.tiff')
		else:
			QMessageBox.information(self, 'Error',
			'Please select exactly 3 pictures', QMessageBox.Ok)


	def show_merged_image(self, image):
		pix = QPixmap(image)
		#.scaled(
	#			self.mergedImage.size(),
#				Qt.KeepAspectRatio, Qt.FastTransformation)
		#self.mergedImage.setPixmap(pix)

		self.scene = QGraphicsScene()
		self.scene.clear()
		self.scene.addPixmap(pix)
		self.imageView.setScene(self.scene)
		self.scene.update()
