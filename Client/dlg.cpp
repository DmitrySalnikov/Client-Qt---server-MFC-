#include "dlg.h"
#include "ui_dlg.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <sstream>

dlg::dlg(QWidget * parent) : QWidget(parent), ui(new Ui::dlg) {
    host = "localhost";
    port = 10000;
    client = new QTcpSocket(this);
    isCorrect = false;
    off = 0;
    ui->setupUi(this);
    hw = new QAxWidget(ui->widget);
    hw->setControl("AXH Control");
    hw->setHidden(true);

    QObject::connect(client, SIGNAL(connected()), this, SLOT(OnConnect()));
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(OnRead()));
    QObject::connect(client, SIGNAL(disconnected()), this, SLOT(OnDisconnect()));
    QObject::connect(ui->ModelPushButton, SIGNAL(clicked()), this, SLOT(on_ModelPushButton_clicked()));
    QObject::connect(client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError()));
}

dlg::~dlg() {
    delete ui;
}

void dlg::OnConnect() {
    struct {
        int i[6];
    } param;

    param.i[0] = ui->NumberSpinBox->value();
    param.i[1] = ui->Come1SpinBox->value() * 24;
    param.i[2] = ui->Come2SpinBox->value() * 24;
    param.i[3] = ui->Service1SpinBox->value();
    param.i[4] = ui->Service2SpinBox->value();
    param.i[5] = ui->DaysSpinBox->value() * 24;

    int size = sizeof(param);
    while (off < size) {
        int n = client->write((char *)(&param) + off, size - off);
        if (n < 0)
            return;
        off += n;
    }
    off = 0;    
}

void dlg::OnRead() {
  for(;;)
  { off = client->read(buf, SZ - 1);
    if (off <= 0)
        return;
    buf[off] = 0;
    str += buf;
    if (buf[off - 1] == 0)
    {  isCorrect = true;
      break;
    }
    off = 0;
 }
}

void dlg::OnDisconnect() {
    if (isCorrect) {
        std::stringstream ss(str.toStdString());
        int n = 0;
        ss >> n;
        QVector<int> hist(n);
        for (int i = 0; i < n; ++i)
            ss >> hist[i];
        if (n <= 8) {
            for(int i = 0; i < n; ++i)
                hw->dynamicCall("SetVal(int, int)", i, hist[i]);
            for(int i = n; i < 8; ++i)
                hw->dynamicCall("SetVal(int, int)", i, 0);
        }
        else {
            for(int i = 0; i < 8; ++i) {
                int s = 0;
                for (int p = (i * n) / 8; p < ((i + 1) * n) / 8; ++p)
                    s += hist[p];
                hw->dynamicCall("SetVal(int, int)", i, s);
            }
        }
        double mean = 0.;
        int s = 0;
        for (int i =0; i < n; ++i) {
            mean += hist[i] * i;
            s += hist[i];
        }
        mean /= s;
        hw->dynamicCall("SetMean(double)", mean);
        hw->dynamicCall("SetVal(int, int)", 8, n);
        hw->dynamicCall("Update(void)");
        hw->setHidden(false);
        ui->ModelPushButton->setEnabled(true);
    }
    else {
        QLabel * isError = new QLabel;
        isError->setText("Connection error");
        isError->setHidden(false);
    }
    str.clear();
    isCorrect = false;
}

void dlg::OnError() {
    off = 0;
    isCorrect = false;
    str.clear();
    ui->ModelPushButton->setEnabled(true);
}

void dlg::on_ModelPushButton_clicked() {
    ui->ModelPushButton->setEnabled(false);
    client->connectToHost(host, port);
}
