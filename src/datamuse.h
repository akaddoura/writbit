#ifndef DATAMUSE_H
#define DATAMUSE_H
#include <QtNetwork>
#include <QObject>
#include <QDebug>
#include <QIODevice>
#include <QSslSocket>
#include <QNetworkAccessManager>

class Datamuse : public QObject
{
public:
    Datamuse(QString w);

    Datamuse(int index1, int index2, int index3, QString w1, QString w2, QString w3);

    QStringList returnSynList();

private:
    QString setSearchParam(int w);

    QNetworkAccessManager *net;

    QStringList synList;
};

#endif // DATAMUSE_H
