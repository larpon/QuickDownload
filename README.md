# QuickDownload
Easy way to download files with Qt QML and C++

## Features
* Asynchronous downloads
* Supports Qt URL schemes (http, https, ftp, custom)
* Uses QSaveFile = no corrupt or partial file downloads.
* Possible to set custom NetworkAccessManager via C++
* Self-register QML type. Plug'n'play.

## Install

### qpm
Setup [qpm](https://github.com/Cutehacks/qpm) as described in the [Usage for App Developers](https://github.com/Cutehacks/qpm#usage-for-app-developers) section
```
qpm install com.blackgrain.qml.quickdownload
```

### Manual install

#### Plugin
```
cd /path/to/projects
git clone git@github.com:Larpon/QuickDownload.git
```
Open `quickdownload.pro` in QtCreator and build.
The result should be a `*.so` plugin file.

#### Linked

Clone from github
```
cd /path/to/your/qt/project/vendor/folder
git clone git@github.com:Larpon/QuickDownload.git
```

Include `quickdownload.pri` in your projects `.pro` file
```
include(<path to extensions/vendor folder>/QuickDownload/quickdownload.pri)
```

**NOTE**
`quickdownload.pri` auto-register the QML type `Download` via the `Q_CORE_STARTUP_FUNCTION` macro.


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
