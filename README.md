# QuickDownload
Easy way to download files with Qt QML and C++

## Install
```
git clone git@github.com:Larpon/QuickDownload.git
```

### Plugin
Open `quickdownload.pro` in QtCreator and build

### Linked
Include `quickdownload.pri` in your project `.pro` file
```
include(vendor/QuickDownload/quickdownload.pri)
```

Include `register_quickdownload.h` in your `main.cpp`
```
#include "register_quickdownload.h"
```

## Usage

```
import QtQuick 2.0
import com.blackgrain.qml.quickdownload 1.0

Item {

    Download {
        id: download1

        url: "http://placehold.it/350x150"
        destination: "file:///tmp/test.png"

        running: true

        followRedirects: true
        onRedirected: console.log('Redirected',url,'->',redirectUrl)

        onStarted: console.log('Started download',url)
        onError: console.error(errorString)
        onProgressChanged: console.log(url,'progress:',progress)
        onFinished: console.info(url,'done')

    }

    Download {
        id: download2

        url: "ftp://speedtest.tele2.net/5MB.zip"
        destination: "file:///tmp/QuickDownload_test.zip"

        overwrite: true
        running: !download1.running

        onStarted: console.log('Started download',url)
        onError: console.error(errorString)
        onProgressChanged: console.log(url,'progress:',progress)
        onFinished: console.info(url,'done')
    }

    Download {
        id: download3

        url: "ftp://demo:password@test.rebex.net/readme.txt"
        destination: "file:///tmp/QuickDownload_test_readme.txt"

        overwrite: true
        running: true

        onStarted: console.log('Started download',url)
        onError: console.error(errorString)
        onProgressChanged: console.log(url,'progress:',progress)
        onFinished: console.info(url,'done')
    }

}
```
