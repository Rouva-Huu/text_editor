#include "FileManager.h"

FileManager::FileManager(QTabWidget* tabWidget, QWidget* parent)
    : QWidget(parent), m_tabWidget(tabWidget) {
    connect(m_tabWidget, &QTabWidget::tabCloseRequested, this, &FileManager::closeTab);
}

void FileManager::createNewFile() {
    QTextEdit* textEdit = new QTextEdit();
    QString tabName = "Новый файл";
    m_tabWidget->addTab(textEdit, tabName);
    m_tabWidget->setCurrentWidget(textEdit);
    m_currentFileName.clear(); // сброс имени текущего файла
}

void FileManager::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;

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
    m_currentFileName = fileName; // сохранить имя файла
}

void FileManager::saveFile() {
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

void FileManager::saveFileAs() {
    if (m_tabWidget->count() == 0) { // нечего сохранять
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;

    m_currentFileName = fileName; // обновить текущее имя файла
    saveFile(); // сохранить файл

}

void FileManager::closeTab(int index) {
    if (index >= 0) {
        m_tabWidget->removeTab(index);
    }
}
