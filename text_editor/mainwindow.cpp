#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "tabledialog.h"
#include "declarations.h"
#include "editor.h"

#include <QStandardPaths>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileManager = new FileManager(ui->tabWidget, NULL);
    editor = new Editor(fileManager);
    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
}

MainWindow::~MainWindow()
{
    delete editor;
    delete fileManager;
    delete ui;
}

void MainWindow::on_CreateFile_triggered()
{
    fileManager->createNewFile("txt");
}

void MainWindow::on_OpenFile_triggered()
{
    fileManager->openFile();
}

void MainWindow::on_Save_triggered()
{
    fileManager->saveFile();
}

void MainWindow::on_SaveAs_triggered()
{
    fileManager->saveFileAs();
}

void MainWindow::on_CreateTable_triggered()
{
    tableDialog = new TableDialog(this);
    tableDialog->setModal(true);
    tableDialog->exec();

    fileManager->createNewFile("csv", tableDialog->getRows(), tableDialog->getColumns());
}

void MainWindow::on_CustomizeFont_triggered()
{
    QTextCursor cursor = fileManager->getCurrentTextEdit()->textCursor();

    if (!cursor.hasSelection()) {
        return;
    }

    bool ok;
    QFont selectedFont = QFontDialog::getFont(&ok, fileManager->getCurrentTextEdit()->font(), fileManager->getCurrentTextEdit());

    if (ok) {
        QTextCharFormat format;
        format.setFont(selectedFont);
        cursor.mergeCharFormat(format);
        fileManager->getCurrentTextEdit()->mergeCurrentCharFormat(format);
    }
}

void MainWindow::on_TextColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        QTextCursor cursor = fileManager->getCurrentTextEdit()->textCursor();
        cursor.mergeCharFormat(format);
        fileManager->getCurrentTextEdit()->mergeCurrentCharFormat(format);
    }
}

void MainWindow::on_Clear_triggered()
{
    this->editor->clearContent();
}

void MainWindow::on_Redo_triggered()
{
    this->editor->restoreContent();
}

void MainWindow::on_Palette_triggered()
{
    QColor textColor = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    if (textColor.isValid()) {
        fileManager->setTextColor(textColor);
    }

    QColor backColor = QColorDialog::getColor(Qt::white, this, "Выберите цвет фона");
    if (backColor.isValid()) {
        fileManager->setBackColor(backColor);
    }
}


void MainWindow::on_SaveTable_triggered()
{
    fileManager->saveFile();
}

void MainWindow::on_OpenTable_triggered()
{
    fileManager->openFile();
}

void MainWindow::on_SaveTableAs_triggered()
{
    fileManager->saveFileAs();
}

void MainWindow::closeTab(int index)
{
    QWidget *widget = ui->tabWidget->widget(index);

    if (widget) {
        // Попытка преобразования в QTextEdit
        QTextEdit* editor = qobject_cast<QTextEdit*>(widget);
        QTableWidget* table = qobject_cast<QTableWidget*>(widget);
        QString filePath = ui->tabWidget->tabToolTip(index);

        // Проверка для QTextEdit
        if (editor && !editor->document()->isModified()) {
            ui->tabWidget->removeTab(index);
            delete widget;
        }
        // Проверка для QTableWidget (примерный способ, можно усовершенствовать)
        else if (table) {
            ui->tabWidget->removeTab(index);
            delete widget;
        }
        else {
            // Диалоговое окно для подтверждения действий
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Закрыть файл",
                                          "В этом файле есть несохраненные изменения. Хотите сохранить их перед закрытием?",
                                          QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

            if (reply == QMessageBox::Yes) {
                fileManager->saveFile();
                ui->tabWidget->removeTab(index);
                delete widget;
            } else if (reply == QMessageBox::No) {
                ui->tabWidget->removeTab(index);
                delete widget;
            }
        }
    }
}

