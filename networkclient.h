#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QTimer>

struct Message {
    QString role; // "user" 或 "assistant"
    QString content;
};

class NetworkClient : public QObject {
    Q_OBJECT
public:
    explicit NetworkClient(QObject *parent = nullptr);
    void askQuestion(const QString &question);

    QList<Message> conversation; // 对话历史

signals:
    void streamUpdate(const QString &text); // 每次追加字符
    void replyFinished();                   // 回答完成

private slots:
    void onFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString streamingBuffer;
    QTimer *streamTimer;
    void startStreamingDisplay(const QString &fullText);
};
