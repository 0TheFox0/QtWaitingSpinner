CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(qtwaitingspinnerplugin)
TEMPLATE    = lib

HEADERS     = qtwaitingspinnerplugin.h
SOURCES     = qtwaitingspinnerplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

DEFINES+= SHAREDLIB_LIBRARY
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(qtwaitingspinner.pri)
