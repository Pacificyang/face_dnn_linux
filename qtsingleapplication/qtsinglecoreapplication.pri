INCLUDEPATH	+= $$PWD
DEPENDPATH      += $$PWD
HEADERS		+= $$PWD/qtsinglecoreapplication.h $$PWD/qtlocalpeer.h \
    $$PWD/qtlockedfile.h
SOURCES		+= $$PWD/qtsinglecoreapplication.cpp $$PWD/qtlocalpeer.cpp \
    $$PWD/qtlockedfile.cpp

QT *= network

win32:contains(TEMPLATE, lib):contains(CONFIG, shared) {
    DEFINES += QT_QTSINGLECOREAPPLICATION_EXPORT=__declspec(dllexport)
}