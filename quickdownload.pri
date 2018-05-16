QT += qml quick network
CONFIG += c++11

QML_IMPORT_PATH +=

!contains(QUICKDOWNLOAD_CONFIG,"noautoregister") {
    DEFINES += QUICKDOWNLOAD_AUTO_REGISTER
}

INCLUDEPATH += \
    $$PWD \
    $$PWD/src

HEADERS += \
    $$PWD/register_quickdownload.h \
    $$PWD/src/quickdownload.h

SOURCES += \
    $$PWD/src/quickdownload.cpp

DISTFILES += \
    $$PWD/README.md \
    $$PWD/LICENSE

exists(.git) {
    unix {
        GIT_BRANCH_NAME = $$system(git rev-parse --abbrev-ref HEAD)
        message("QuickDownload branch $$GIT_BRANCH_NAME")
    }
}
