#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sockets.h"
#include "dlg.h"
#include <QMdiSubWindow>
#include <ActiveQt/QAxWidget>

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_action_triggered() {
   dlg *mod = new dlg();
   QMdiSubWindow * mysub = ui->mdiArea->addSubWindow(mod, Qt::Dialog);
   mysub->show();
}
