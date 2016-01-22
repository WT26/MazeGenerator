TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    maze_generator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    maze_generator.h

