# -*- coding: utf-8 -*-

from PyQt4.QtCore import QString, Qt, SIGNAL, SLOT, QRectF, QPointF, QStringList, QRectF, QTimer
from PyQt4.QtGui import *
from gen.mainwindow import Ui_MainWindow
import logging

class MainWindow(QMainWindow, Ui_MainWindow):
	def __init__(self, parent = None, args = []):
		QMainWindow.__init__(self, parent)

		self.logger = logging.getLogger('vegetation')

		self.setUnifiedTitleAndToolBarOnMac(True)
