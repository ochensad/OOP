#include "error_code.h"

#include <QMessageBox>

void error_message(const error_code_t error)
{
    switch (error)
    {
        case ERROR_OPENING_FILE:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка открытия файла.");
            break;
        case ERROR_CLOSING_FILE:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка закрытия файла.");
            break;
        case ERROR_READING_FILE:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка чтения файла.");
            break;
        case ERROR_NO_LOADING_FIGURE:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка. Фигура не загружена.");
            break;
        case ERROR_UNKNOWN_COMAND:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка.");
            break;
        case ERROR_POINTS_SIZE:
            QMessageBox::critical(NULL, "Ошибка", "Количество точек в файле не положительное.");
            break;
        case ERROR_MEMORY:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка во время выделения памяти.");
            break;
        case ERROR_CONECTIONS_SIZE:
            QMessageBox::critical(NULL, "Ошибка", "Количество связей должно быть положительным.");
            break;
        case ERROR_SCENE:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка при отчистке холста.");
            break;
        case OK:
            break;
    }
}
