# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui/mainwindow.ui'
#
# Created: Sat Jul 28 21:16:15 2012
#      by: PyQt4 UI code generator 4.9.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        MainWindow.setDocumentMode(True)
        MainWindow.setUnifiedTitleAndToolBarOnMac(True)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.imageView = ImageView(self.centralwidget)
        self.imageView.setRenderHints(QtGui.QPainter.Antialiasing|QtGui.QPainter.HighQualityAntialiasing|QtGui.QPainter.SmoothPixmapTransform|QtGui.QPainter.TextAntialiasing)
        self.imageView.setDragMode(QtGui.QGraphicsView.ScrollHandDrag)
        self.imageView.setTransformationAnchor(QtGui.QGraphicsView.AnchorUnderMouse)
        self.imageView.setResizeAnchor(QtGui.QGraphicsView.AnchorUnderMouse)
        self.imageView.setObjectName(_fromUtf8("imageView"))
        self.verticalLayout.addWidget(self.imageView)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.dryGrassButton = QtGui.QPushButton(self.centralwidget)
        self.dryGrassButton.setObjectName(_fromUtf8("dryGrassButton"))
        self.horizontalLayout.addWidget(self.dryGrassButton)
        self.lawnGrassButton = QtGui.QPushButton(self.centralwidget)
        self.lawnGrassButton.setObjectName(_fromUtf8("lawnGrassButton"))
        self.horizontalLayout.addWidget(self.lawnGrassButton)
        self.verticalLayout.addLayout(self.horizontalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        self.menuHelp = QtGui.QMenu(self.menubar)
        self.menuHelp.setObjectName(_fromUtf8("menuHelp"))
        self.menuEdit = QtGui.QMenu(self.menubar)
        self.menuEdit.setObjectName(_fromUtf8("menuEdit"))
        MainWindow.setMenuBar(self.menubar)
        self.actionOpen_Images = QtGui.QAction(MainWindow)
        self.actionOpen_Images.setObjectName(_fromUtf8("actionOpen_Images"))
        self.actionQuit = QtGui.QAction(MainWindow)
        self.actionQuit.setObjectName(_fromUtf8("actionQuit"))
        self.actionAbout = QtGui.QAction(MainWindow)
        self.actionAbout.setObjectName(_fromUtf8("actionAbout"))
        self.actionCredits = QtGui.QAction(MainWindow)
        self.actionCredits.setObjectName(_fromUtf8("actionCredits"))
        self.actionPrint = QtGui.QAction(MainWindow)
        self.actionPrint.setObjectName(_fromUtf8("actionPrint"))
        self.actionExport = QtGui.QAction(MainWindow)
        self.actionExport.setObjectName(_fromUtf8("actionExport"))
        self.menuFile.addAction(self.actionOpen_Images)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionExport)
        self.menuFile.addAction(self.actionPrint)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionQuit)
        self.menuHelp.addAction(self.actionAbout)
        self.menuHelp.addAction(self.actionCredits)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuEdit.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QObject.connect(self.actionQuit, QtCore.SIGNAL(_fromUtf8("toggled(bool)")), MainWindow.close)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
        self.dryGrassButton.setText(QtGui.QApplication.translate("MainWindow", "Dry Grass", None, QtGui.QApplication.UnicodeUTF8))
        self.lawnGrassButton.setText(QtGui.QApplication.translate("MainWindow", "Lawn Grass", None, QtGui.QApplication.UnicodeUTF8))
        self.menuFile.setTitle(QtGui.QApplication.translate("MainWindow", "File", None, QtGui.QApplication.UnicodeUTF8))
        self.menuHelp.setTitle(QtGui.QApplication.translate("MainWindow", "Help", None, QtGui.QApplication.UnicodeUTF8))
        self.menuEdit.setTitle(QtGui.QApplication.translate("MainWindow", "Edit", None, QtGui.QApplication.UnicodeUTF8))
        self.actionOpen_Images.setText(QtGui.QApplication.translate("MainWindow", "Open Images", None, QtGui.QApplication.UnicodeUTF8))
        self.actionQuit.setText(QtGui.QApplication.translate("MainWindow", "Quit", None, QtGui.QApplication.UnicodeUTF8))
        self.actionAbout.setText(QtGui.QApplication.translate("MainWindow", "About", None, QtGui.QApplication.UnicodeUTF8))
        self.actionCredits.setText(QtGui.QApplication.translate("MainWindow", "Credits", None, QtGui.QApplication.UnicodeUTF8))
        self.actionPrint.setText(QtGui.QApplication.translate("MainWindow", "Print", None, QtGui.QApplication.UnicodeUTF8))
        self.actionExport.setText(QtGui.QApplication.translate("MainWindow", "Export", None, QtGui.QApplication.UnicodeUTF8))

from gui.imageview import ImageView
