#include "FileManager.h"

FileManager::FileManager(QTabWidget* tabWidget, QWidget* parent)
    : QWidget(parent), m_tabWidget(tabWidget) {
}

void FileManager::createNewFile(QString file_type, int rows, int columns) {
    if (file_type == "txt")
    {
        QTextEdit* textEdit = new QTextEdit();
        QString tabName = "Новый файл";
        m_tabWidget->addTab(textEdit, tabName);
        m_tabWidget->setCurrentWidget(textEdit);
        m_currentFileName.clear();
    }
    else if (file_type == "csv")
    {
        QTableWidget* table = new QTableWidget(rows, columns);
        QString tabName = "Новая таблица";
        m_tabWidget->addTab(table, tabName);
        m_tabWidget->setCurrentWidget(table);
        m_currentFileName.clear();
    }
}

void FileManager::openFile() {

    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("All Files (*);;CSV files (*.csv);;Text Files (*.txt);;"));

    if (!fileName.isEmpty()) {

        QFileInfo fileInfo(fileName);
        QString extension = fileInfo.suffix().toLower();

        if (extension == "txt") {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось открыть файл"));
                return;
            }
            QTextEdit* textEdit = new QTextEdit();
            textEdit->setPlainText(file.readAll());
            file.close();

            QString tabName = QFileInfo(fileName).fileName(); // получить имя файла без пути
            m_tabWidget->addTab(textEdit, tabName);
            m_tabWidget->setCurrentWidget(textEdit);
            m_currentFileName = fileName;
        }
        else if (extension == "csv") {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось открыть файл"));
                return;
            }
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd()) {
                lines.append(in.readLine());
            }
            file.close();

            int rows = lines.size();
            int columns = !lines.isEmpty() ? lines.first().split(";").size() : 0;

            if (rows == 0 || columns == 0) {
                QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Файл CSV пуст или имеет неправильный формат"));
                return;
            }

            QTableWidget* tableWidget = new QTableWidget(rows, columns);
            if (!tableWidget) {
                QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Не удалось создать таблицу"));
                return;
            }

            for (int i = 0; i < rows; ++i) {
                QStringList cells = lines.at(i).split(";");
                if (cells.size() != columns) {
                    QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Некорректный CSV файл: строки содержат разное количество столбцов"));
                    delete tableWidget;
                    return;
                }

                for (int j = 0; j < cells.size(); ++j) {
                    tableWidget->setItem(i, j, new QTableWidgetItem(cells.at(j)));
                }
            }

            QString tabName = QFileInfo(fileName).fileName();
            m_tabWidget->addTab(tableWidget, tabName);
            m_tabWidget->setCurrentWidget(tableWidget);
            m_currentFileName = fileName;
        }
    }
    else return;
}

void FileManager::saveFile()
{
    QWidget* currentWidget = m_tabWidget->currentWidget();

    QTextEdit* textEdit = dynamic_cast<QTextEdit*>(currentWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentWidget);

    if (textEdit)
    {
        if (m_tabWidget->count() == 0) { // нечего сохранять
            return;
        }

        if (m_currentFileName.isEmpty()) {
            saveFileAs(); // если файла нет, вызвать сохранение как
            return;
        }

        QTextEdit* currentTextEdit = qobject_cast<QTextEdit*>(m_tabWidget->currentWidget());
        if (currentTextEdit) {
            QFile file(m_currentFileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сохранить файл"));
                return;
            }
            file.write(currentTextEdit->toPlainText().toUtf8());
            file.close();
        }

        int currentIndex = m_tabWidget->currentIndex();
        if (currentIndex != -1) {
            QString newTabName = QFileInfo(m_currentFileName).baseName(); // Получаем имя файла без пути
            m_tabWidget->setTabText(currentIndex, newTabName); // Обновляем заголовок вкладки
        }
    }
    else if (tableWidget) {
        if (m_tabWidget->count() == 0) {
            return;
        }

        if (m_currentFileName.isEmpty()) {
            saveFileAs();
            return;
        }

        QTableWidget* currentTable = qobject_cast<QTableWidget*>(m_tabWidget->currentWidget());
        if (currentTable) {
            QFile file(m_currentFileName);
            QAbstractItemModel *model =  getCurrentTable()->model();
            if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сохранить файл"));
                return;
            }
            else
            {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->rowCount(); i++) {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++) {

                        if (model->data(model->index(i, j)).toString().length() > 0)
                            strList.append(model->data(model->index(i, j)).toString());
                        else
                            strList.append("");
                    }
                    data << strList.join(";") + "\n";
                }
                file.close();
            }
        }

        int currentIndex = m_tabWidget->currentIndex();
        if (currentIndex != -1) {
            QString newTabName = QFileInfo(m_currentFileName).baseName();
            m_tabWidget->setTabText(currentIndex, newTabName);
        }
    }
}

void FileManager::saveFileAs() {
    QWidget* currentWidget = m_tabWidget->currentWidget();

    QTextEdit* textEdit = dynamic_cast<QTextEdit*>(currentWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentWidget);

    if (textEdit)
    {
        if (m_tabWidget->count() == 0) {
            return;
        }

        QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), "", tr("Text Files (*.txt);;All Files (*)"));
        if (fileName.isEmpty()) return;

        m_currentFileName = fileName;
        saveFile();
    }
    else if (tableWidget) {
        if (m_tabWidget->count() == 0) {
            return;
        }

        QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), "", tr("CSV files (*.csv);;All Files (*)"));
        if (fileName.isEmpty()) return;

        m_currentFileName = fileName;
        saveFile();
    }
}

void FileManager::setTextColor(QColor color)
{

    QList<QTableWidgetItem*> selectedItems = getCurrentTable()->selectedItems();
    for (QTableWidgetItem *item : selectedItems) {
        item->setForeground(color);
    }
}

void FileManager::setBackColor(QColor color)
{
    QList<QTableWidgetItem*> selectedItems = getCurrentTable()->selectedItems();
    for (QTableWidgetItem *item : selectedItems) {
        item->setBackground(color);
    }
}

QTextEdit* FileManager::getCurrentTextEdit() {
    QTextEdit *textEdit = qobject_cast<QTextEdit *>(m_tabWidget->currentWidget());
    return textEdit;
}

QTableWidget* FileManager::getCurrentTable() {
    QTableWidget *table = qobject_cast<QTableWidget *>(m_tabWidget->currentWidget());
    return table;
}
