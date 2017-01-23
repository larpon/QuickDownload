#ifndef REGISTER_QUICKDOWNLOAD_H
#define REGISTER_QUICKDOWNLOAD_H

#include <QQmlEngine>
#include <QJSEngine>

#include "src/quickdownload.h"
#include "qqml.h"

class RegisterQuickDownload {

public:
    RegisterQuickDownload() {
        qmlRegisterType<QuickDownload>("com.blackgrain.qml.quickdownload", 1, 0, "Download");
    }
};

static RegisterQuickDownload registerQuickDownload;

#endif // REGISTER_QUICKDOWNLOAD_H

