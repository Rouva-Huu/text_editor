#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QTextEdit>
#include <QTabWidget>
#include <QTableWidget>

class FileManager : public QWidget {
    Q_OBJECT

public:
    explicit FileManager(QTabWidget* tabWidget, QWidget* parent = nullptr);

public slots:
    void createNewFile(QString file_type, int rows = 0, int columns = 0);
    void openFile();
    void saveFile();
    void saveFileAs();
    void setTextColor(QColor color);
    void setBackColor(QColor color);

    QTableWidget* getCurrentTable();
    QTextEdit* getCurrentTextEdit();

private:
    QTabWidget* m_tabWidget;
    QString m_currentFileName; // имя открытого файла
};

#endif // FILEMANAGER_H
