#ifndef QUICKDOWNLOAD_H
#define QUICKDOWNLOAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QSaveFile>
#include <QFileInfo>
#include <QDir>

#include "qqml.h"

#if defined(qQuickDownloadMaster)
#undef qQuickDownloadMaster
#endif
#define qQuickDownloadMaster (static_cast<QuickDownloadMaster *>(QuickDownloadMaster::instance()))

class QuickDownloadMaster : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool ready READ ready NOTIFY readyChanged)

public:
    explicit QuickDownloadMaster(QObject* parent = 0);
    ~QuickDownloadMaster();

    static QuickDownloadMaster *instance();

    bool ready();

    bool checkInstance(const char *function);

    QNetworkAccessManager *networkAccessManager();
    void setNetworkAccessManager(QNetworkAccessManager *networkAccessManager);

signals:
    void readyChanged();

private:
    static QuickDownloadMaster *self;
    Q_DISABLE_COPY(QuickDownloadMaster)

    bool _ready;

    bool _ownNetworkAccessManager;
    QNetworkAccessManager *_networkAccessManager;

};


class QuickDownload : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_DISABLE_COPY(QuickDownload)

    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(qreal progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(QUrl destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(bool followRedirects READ followRedirects WRITE setFollowRedirects NOTIFY followRedirectsChanged)
    Q_PROPERTY(bool overwrite READ overwrite WRITE setOverwrite NOTIFY overwriteChanged)

public:
    enum Error
    {
        ErrorUnknown,
        ErrorUrl,
        ErrorDestination,
        ErrorNetwork
    };
    Q_ENUM(Error)

    QuickDownload(QObject *parent = 0);
    ~QuickDownload();

    QUrl url() const;
    void setUrl(const QUrl &url);

    bool running() const;
    void setRunning(bool running);

    qreal progress() const;

    QUrl destination() const;
    void setDestination(const QUrl &destination);

    bool followRedirects() const;
    void setFollowRedirects(bool followRedirects);

    bool overwrite() const;
    void setOverwrite(bool overwrite);

    void classBegin() {}
    void componentComplete();

signals:
    void urlChanged();
    void cancelChanged();
    void runningChanged();
    void progressChanged();
    void destinationChanged();
    void followRedirectsChanged();
    void overwriteChanged();

    void started();
    void finished();
    void redirected(QUrl redirectUrl);
    void update(int kiloBytesReceived, int kiloBytesTotal);
    void error(int errorCode, QString errorString);
    void networkAccessManagerChanged();

public slots:
    void start(QUrl url);
    void start();
    void stop();

private slots:
    void onReadyRead();
    void onFinished();
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    void setProgress(qreal progress);
    QUrl _url;
    bool _running;
    qreal _progress;
    QUrl _destination;
    bool _followRedirects;
    bool _overwrite;

    QNetworkReply *_networkReply;
    void shutdownNetworkReply();

    QSaveFile *_saveFile;
    void shutdownSaveFile();

    bool _componentComplete;
};

#endif // QUICKDOWNLOAD_H
