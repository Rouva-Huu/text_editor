#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QTextEdit>
#include <QTabWidget>

class FileManager : public QWidget {
    Q_OBJECT

public:
    explicit FileManager(QTabWidget* tabWidget, QWidget* parent = nullptr);

public slots:
    void createNewFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void closeTab(int index);
    QTextEdit* getCurrentTextEdit();

private:
    QTabWidget* m_tabWidget;
    QString m_currentFileName; // имя открытого файла
};

#endif // FILEMANAGER_H
