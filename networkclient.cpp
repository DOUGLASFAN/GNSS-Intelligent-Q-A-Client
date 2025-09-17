#include "networkclient.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>

NetworkClient::NetworkClient(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkClient::onFinished);

    streamTimer = new QTimer(this);
    streamTimer->setInterval(20);
    connect(streamTimer, &QTimer::timeout, this, [this]() {
        if (!streamingBuffer.isEmpty()) {
            QString ch = streamingBuffer.left(1);
            streamingBuffer.remove(0,1);
            emit streamUpdate(ch);
        } else {
            streamTimer->stop();
            emit replyFinished();
        }
    });
}

void NetworkClient::askQuestion(const QString &question) {
    conversation.append({"user", question});

    QUrl url("http://127.0.0.1:8000/ask");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonArray array;
    for (const auto &msg : conversation) {
        QJsonObject m;
        m["role"] = msg.role;
        m["content"] = msg.content;
        array.append(m);
    }

    QJsonObject json;
    json["conversation"] = array;
    QJsonDocument doc(json);

    manager->post(request, doc.toJson());
}

void NetworkClient::onFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        streamingBuffer = "请求失败：" + reply->errorString();
        startStreamingDisplay(streamingBuffer);
    } else {
        QByteArray resp = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(resp);
        QJsonObject obj = jsonDoc.object();
        QString answer = obj["answer"].toString();

        conversation.append({"assistant", answer});
        startStreamingDisplay(answer);
    }
    reply->deleteLater();
}

void NetworkClient::startStreamingDisplay(const QString &fullText) {
    streamingBuffer = fullText;
    emit streamUpdate(""); // 清空 QTextEdit
    streamTimer->start();
}
