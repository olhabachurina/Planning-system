#pragma once
#include <string>
#include <vector>

class Task {
public:
public:
    Task() = default; // Конструктор по умолчанию

    Task(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags);

    std::string getTitle() const;//это метод, который возвращает названия задачи
    int getPriority() const;//это метод, который возвращает приоритетные задачи.
    std::string getDueDate() const;//это метод, который возвращает выполнение задачи.
    std::vector<std::string> getTags() const;//это метод класса, который возвращает векторные строки с тегами

private:
    std::string title;//название задачи
    int priority;//приоритетная задача, обозначает дополнительную задачу
    std::string due_date;//дата, когда задачу нужно выбрать
    std::vector<std::string> tags;//векторная строка, представляющая теги
};
