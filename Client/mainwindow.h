#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MdiChild;
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;

namespace Ui {
class MainWindow;
}

class CClient;
class CServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
