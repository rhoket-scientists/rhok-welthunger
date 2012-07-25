# -*- coding: utf-8 -*-

from PyQt4.QtCore import *
from PyQt4.QtGui import *
from gen.mainwindow import Ui_MainWindow
import logging
from lib import imagemerge

class MainWindow(QMainWindow, Ui_MainWindow):
	def __init__(self, parent = None, args = []):
		QMainWindow.__init__(self, parent)
		self.setupUi(self)

		self.logger = logging.getLogger('vegetation')
		self.setUnifiedTitleAndToolBarOnMac(True)

		self.openFileButton.clicked.connect(self.handle_button)
		self.show()


	def handle_button(self):
		filenames = QFileDialog.getOpenFileNames(self, 'Select 3 files')
		if not filenames:
			return
		try:
			files = [str(f) for f in filenames]
			imagemerge.merge_to_file(files[0], files[1], files[2], '/tmp/foo.tiff')
			self.show_merged_image('/tmp/foo.tiff')
		except TypeError:
			QMessageBox.information(self, 'Error',
			'Please select exactly 3 pictures', QMessageBox.Ok)


	def show_merged_image(self, image):
		pix = QPixmap(image).scaled(
				self.mergedImage.size(),
				Qt.KeepAspectRatio, Qt.FastTransformation)
		self.mergedImage.setPixmap(pix)

