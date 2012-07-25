# -*- coding: utf-8 -*-

from PyQt4.QtCore import QString, Qt, SIGNAL, SLOT, QRectF, QPointF, QStringList, QRectF, QTimer, QObject
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

	def handle_button(self):
		filenames = QFileDialog.getOpenFileNames(self, 'Open file')
		imagemerge.merge_images(*[str(f) for f in filenames])