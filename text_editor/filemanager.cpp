#include "filemanager.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

// Конструктор
FileManager::FileManager(QObject* parent)
    : QObject(parent), currentFile("") {}

// Открыть файл
bool FileManager::openFile(QWidget* parent)
{
    QString fileName = QFileDialog::getOpenFileName(parent,
                                                    tr("Open File"),
                                                    "",
                                                    tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return false;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(parent, tr("Error"), tr("Cannot open file: ") + file.errorString());
        return false;
    }

    QTextStream in(&file);
    fileContent = in.readAll();
    file.close();
    currentFile = fileName;
    return true;
}

// Сохранить файл
bool FileManager::saveFile(QWidget* parent)
{
    if (currentFile.isEmpty())
        return saveFileAs(parent);

    QFile file(currentFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(parent, tr("Error"), tr("Cannot save file: ") + file.errorString());
        return false;
    }

    QTextStream out(&file);
    out << fileContent;
    file.close();
    return true;
}

// Сохранить файл как
bool FileManager::saveFileAs(QWidget* parent)
{
    QString fileName = QFileDialog::getSaveFileName(parent, tr("Save File As"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return false;

    currentFile = fileName;
    return saveFile(parent);
}

// Закрыть файл
void FileManager::closeFile()
{
    currentFile.clear();
    fileContent.clear();
}

// Получить содержимое файла
QString FileManager::getFileContent() const
{
    return fileContent;
}

// Установить содержимое файла
void FileManager::setFileContent(const QString& content)
{
    fileContent = content;
}
