# -*- coding: utf-8 -*-

from PyQt4.QtCore import QString, Qt, SIGNAL, SLOT, QRectF, QPointF, QStringList, QRectF, QLineF, qAbs, QSizeF, qrand
from PyQt4.QtGui import *
from PyQt4.QtOpenGL import *
import math

class ImageView(QGraphicsView):

	def __init__(self, parent=None):
		QGraphicsView.__init__(self, parent)
		self.setViewport(QGLWidget())

	def resizeEvent(self, evt=None):
		self.emit(SIGNAL("resize()"))

	def wheelEvent(self, evt):
		self.scaleView(math.pow(2.0, -evt.delta() / 240.0))

	def scaleView(self, scaleFactor):
		factor = self.matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width()

		if factor < 0.07 or factor > 150:
			return

		self.scale(scaleFactor, scaleFactor)