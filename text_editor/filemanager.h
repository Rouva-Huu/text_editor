#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject* parent = nullptr);

    bool openFile(QWidget* parent);     // Открыть файл
    bool saveFile(QWidget* parent);     // Сохранить файл
    bool saveFileAs(QWidget* parent);   // Сохранить файл как
    void closeFile();                   // Закрыть файл

    QString getFileContent() const;     // Получить содержимое файла
    void setFileContent(const QString& content);  // Установить содержимое файла

private:
    QString currentFile;    // Путь к текущему открытому файлу
    QString fileContent;    // Содержимое файла
};

#endif // FILEMANAGER_H
