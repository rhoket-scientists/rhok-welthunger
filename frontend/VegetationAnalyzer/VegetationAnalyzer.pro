# -------------------------------------------------
# Project created by QtCreator 2012-06-03T09:41:10
# -------------------------------------------------
TARGET = VegetationAnalyzer
TEMPLATE = app

QT += webkit
SOURCES += main.cpp \
    vegetationanalyzer.cpp \
    Application.cpp\
    imageprocessor.cpp
HEADERS += vegetationanalyzer.h \
    Application.h\
    imageprocessor.h
FORMS += vegetationanalyzer.ui


# 1st solution
CONFIG += link_pkgconfig
PKGCONFIG += opencv

# 2nd solution
# LIBS += `pkg-config --libs opencv`

