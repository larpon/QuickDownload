#include "quickdownload_plugin.h"
#include "quickdownload.h"

#include <qqml.h>

void QuickDownloadPlugin::registerTypes(const char *uri)
{
    // @uri com.blackgrain.qml
    qmlRegisterType<QuickDownload>(uri, 1, 0, "Download");
}

