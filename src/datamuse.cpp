/***********************************************************************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * See http://www.gnu.org/licenses/ for a look at the GNU general public
 * license.
 ***********************************************************************/

#include "datamuse.h"

Datamuse::Datamuse(QString w)
{
    // setup NetworkAccessManager
    net = new QNetworkAccessManager;
    // lambda function was used because connecting the abstract class QNetworkReply through
    // pointers was difficult and produced several problems. This should work for now.
    //QObject::connect(net, &QNetworkAccessManager::finished, [&](QNetworkReply* reply)
    //{

        //}
    //});
    QUrl url;
    url.setScheme("https");
    url.setHost("api.datamuse.com");
    url.setPath("/words");
    QUrlQuery query;
    w.replace(' ','+');
    query.addQueryItem("ml", w);
    url.setQuery(query);
    //qDebug() << url.toString();
    //qDebug() << url.hasQuery();
    //qDebug() << url.query();
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = net->get(request); // GET request

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    if (reply->error() != QNetworkReply::NoError)
        net->clearAccessCache();
    else
    {
        qDebug() << "signal connected";
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        // Datamuse returns their API in an array
        QJsonArray arr = doc.array();
        //synList = new QStringList;
        for (const QJsonValue &i : arr)
        {
            synList.append(i["word"].toString());
            //qDebug() << i["word"].toString();
        }
        reply->deleteLater();
        returnSynList();
    }
}

Datamuse::Datamuse(int index1, QString w1)
{
    net = new QNetworkAccessManager;
    QUrl url;
    url.setScheme("https");
    url.setHost("api.datamuse.com");
    url.setPath("/words");
    QUrlQuery query;
    if (!w1.isEmpty())
    {
        QString param = setSearchParam(index1);
        query.addQueryItem(param, w1);
    }

//    if (!w2.isEmpty())
//    {
//        QString param = setSearchParam(index2);
//        query.addQueryItem(param, w2);
//    }

//    if (!w3.isEmpty())
//    {
//        QString param = setSearchParam(index3);
//        query.addQueryItem(param, w3);
//    }

    url.setQuery(query);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = net->get(request); // GET request

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    if (reply->error() != QNetworkReply::NoError)
        net->clearAccessCache();
    else
    {
        qDebug() << "signal connected";
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        // Datamuse returns their API in an array
        QJsonArray arr = doc.array();
        //synList = new QStringList;
        for (const QJsonValue &i : arr)
        {
            synList.append(i["word"].toString());
            qDebug() << i["word"].toString();
        }
        reply->deleteLater();
        returnSynList();
    }
}

QStringList Datamuse::returnSynList()
{
    return this->synList;
}

QString Datamuse::setSearchParam(int index)
{
    QString param;
    switch(index)
    {
    case 0:
        param = "ml";
        return param;
    case 1:
        param = "rel_par";
        return param;
    case 2:
        param = "rel_ant";
        return param;
    case 3:
        param = "rel_topics";
        return param;
    case -1:
        param = "";
        return param;
    }
}



