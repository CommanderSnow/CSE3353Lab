TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sort.cpp \
    bubble.cpp \
    insertion.cpp \
    datasets.cpp \
    sortingalgorithm.cpp \
    merge.cpp \
    documentation.cpp

HEADERS += \
    algorithm.h \
    sort.h \
    bubble.h \
    insertion.h \
    datasets.h \
    sortingalgorithm.h \
    merge.h \
    documentation.h
