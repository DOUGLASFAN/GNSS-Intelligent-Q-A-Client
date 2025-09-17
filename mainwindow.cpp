#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("GNSS 智能问答");
    resize(600, 400);

    auto layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("问题："));
    questionInput = new QLineEdit();
    layout->addWidget(questionInput);

    askButton = new QPushButton("提问");
    layout->addWidget(askButton);

    layout->addWidget(new QLabel("答案："));
    answerDisplay = new QTextEdit();
    answerDisplay->setReadOnly(true);
    layout->addWidget(answerDisplay);

    client = new NetworkClient(this);
    connect(askButton, &QPushButton::clicked, this, &MainWindow::onAskButtonClicked);
    connect(client, &NetworkClient::streamUpdate, this, &MainWindow::onStreamUpdate);
    connect(client, &NetworkClient::replyFinished, this, &MainWindow::onReplyFinished);
}

void MainWindow::onAskButtonClicked() {
    QString question = questionInput->text().trimmed();
    if (question.isEmpty()) return;

    answerDisplay->append("\n用户：" + question + "\nAI：");
    client->askQuestion(question);
}

void MainWindow::onStreamUpdate(const QString &text) {
    answerDisplay->moveCursor(QTextCursor::End);
    answerDisplay->insertPlainText(text);
}

void MainWindow::onReplyFinished() {
    answerDisplay->append("\n"); // 回答结束后换行
}
