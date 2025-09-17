#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include "networkclient.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAskButtonClicked();
    void onStreamUpdate(const QString &text);
    void onReplyFinished();

private:
    QLineEdit *questionInput;
    QPushButton *askButton;
    QTextEdit *answerDisplay;
    NetworkClient *client;
};
