#ifndef DLG_H
#define DLG_H

#include <QWidget>
#include <QLabel>
#include <QTcpSocket>
#include <QString>
#include <ActiveQt/QAxWidget>
#include "windows.h"

namespace Ui {
class dlg;
}

class dlg : public QWidget {
    Q_OBJECT
    
public:
    explicit dlg(QWidget *parent = 0);
    ~dlg();

private slots:
    void on_ModelPushButton_clicked();
    void OnConnect();
    void OnRead();
    void OnDisconnect();
    void OnError();

private:
    static int const SZ = 256;
    char buf[SZ];
    int off;
    Ui::dlg *ui;
    QString host;
    int port;
    QTcpSocket *client;
    QString str;
    QAxWidget * hw;
    bool isCorrect;
};

#endif // DLG_H
