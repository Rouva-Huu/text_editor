#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tabledialog.h>
#include "editor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_17_triggered();

    void on_action_18_triggered();

    void on_action_16_triggered();

    void on_action_15_triggered();

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
    Ui::TableDialog *uiTD;
    TableDialog *tableDialog;
    Editor *editor;
    FileManager *fileManager;

};
#endif // MAINWINDOW_H
