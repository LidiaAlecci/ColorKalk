
TEMPLATE = app
TARGET = ColorKalk

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += calculator.h \
           color.h \
           colorbutton.h \
           colortype.h \
           newcolorwindow.h \
           paneldetails.h \
           primary.h \
           secondary.h \
           tertiary.h
SOURCES += calculator.cpp \
           color.cpp \
           colorbutton.cpp \
           colortype.cpp \
           funzioni_ausiliari.cpp \
           main.cpp \
           newcolorwindow.cpp \
           paneldetails.cpp \
           primary.cpp \
           secondary.cpp \
           tertiary.cpp

RESOURCES += \
    images.qrc
