#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabledialog.h"
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
    void on_CreateFile_triggered();
    void on_OpenFile_triggered();
    void on_Save_triggered();
    void on_SaveAs_triggered();
    void on_CreateTable_triggered();
    void on_CustomizeFont_triggered();
    void on_TextColor_triggered();
    void on_Clear_triggered();
    void on_Redo_triggered();
    void on_Palette_triggered();
    void on_SaveTable_triggered();
    void on_OpenTable_triggered();
    void on_SaveTableAs_triggered();
    void on_Find_triggered();
    void on_Replace_triggered();
    void on_Copy_triggered();
    void on_Paste_triggered();
    void closeTab(int index);

private:
    Ui::MainWindow *ui;
    TableDialog *tableDialog;
    Editor *editor;
    FileManager *fileManager;
};
#endif // MAINWINDOW_H
