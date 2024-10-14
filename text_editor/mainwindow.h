#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tabledialog.h>

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

private:
    Ui::MainWindow *ui;
    Ui::TableDialog *uiTD;
    TableDialog *tableDialog;

};
#endif // MAINWINDOW_H
