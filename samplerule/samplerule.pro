TEMPLATE        = lib
CONFIG         += plugin
QT             += core
INCLUDEPATH    += ../main
HEADERS         = \
    samplerule.h
SOURCES         = \
    samplerule.cpp
TARGET          = samplerule
DESTDIR         = ../main/plugins

OTHER_FILES += \
    samplerule.json \
    samplerule.json

