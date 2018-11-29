TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    search.cpp \
    documentation.cpp \
    ts_brute.cpp \
    point.cpp \
    ts_dp.cpp \
    ts_genetic.cpp \
    ts_tabu.cpp

HEADERS += \
    algorithm.h \
    search.h \
    documentation.h \
    ts_brute.h \
    point.h \
    ts_dp.h \
    ts_genetic.h \
    ts_tabu.h
