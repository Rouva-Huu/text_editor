#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "tabledialog.h"
#include "tablemanager.h"
#include "declarations.h"
#include "editor.h"

#include <QStandardPaths>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileManager = new FileManager(ui->tabWidget, NULL);
    tableManager = new TableManager(ui->tabWidget, NULL);
    editor = new Editor(fileManager);
}

MainWindow::~MainWindow()
{
    delete editor;
    delete fileManager;
    delete tableManager;
    delete ui;
}

void MainWindow::on_CreateFile_triggered()
{
    fileManager->createNewFile();
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

    tableManager->createNewTable(tableDialog->getRows(), tableDialog->getColumns());
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
        tableManager->setTextColor(textColor);
    }

    QColor backColor = QColorDialog::getColor(Qt::white, this, "Выберите цвет фона");
    if (backColor.isValid()) {
        tableManager->setBackColor(backColor);
    }
}


void MainWindow::on_SaveTable_triggered()
{
    tableManager->saveTable();
}


void MainWindow::on_OpenTable_triggered()
{
    tableManager->openTable();
}


void MainWindow::on_SaveTableAs_triggered()
{
    tableManager->saveTableAs();
}

void MainWindow::on_Find_triggered()
{
    bool ok;
    QTextEdit *textEdit = fileManager->getCurrentTextEdit();
    QString searchText = QInputDialog::getText(this, "Найти текст", "Введите текст для поиска:", QLineEdit::Normal, "", &ok);
    if (ok && !searchText.isEmpty()) {
        QTextDocument::FindFlags options;
        if (textEdit->find(searchText, options)) {
        } else {
            QMessageBox::information(this, "Результат поиска", "Текст не найден.");
        }
    }
}

void MainWindow::on_Replace_triggered()
{
    bool ok;
    QTextEdit *textEdit = fileManager->getCurrentTextEdit();
    QString searchText = QInputDialog::getText(this, "Заменить текст", "Введите текст для замены:", QLineEdit::Normal, "", &ok);
    if (ok && !searchText.isEmpty()) {
        QString replaceText = QInputDialog::getText(this, "Заменить текст", "Введите новый текст:", QLineEdit::Normal, "", &ok);
        if (ok) {
            QString content = textEdit->toPlainText();
            content.replace(searchText, replaceText);
            textEdit->setPlainText(content);
        }
    }
}

void MainWindow::on_Copy_triggered()
{
    QTextEdit *textEdit = fileManager->getCurrentTextEdit();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(textEdit->textCursor().selectedText());
}

void MainWindow::on_Paste_triggered()
{
    QTextEdit *textEdit = fileManager->getCurrentTextEdit();
    QClipboard *clipboard = QApplication::clipboard();
    textEdit->insertPlainText(clipboard->text());
}

