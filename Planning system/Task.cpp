#include "Task.h"
Task::Task(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags)
    : title(title), priority(priority), due_date(due_date), tags(tags) {}//Конструктор инициализирует объект Task с заданными параметрами

std::string Task::getTitle() const {//это метод, который возвращает название задачи. Метод константный
    return title;
}

int Task::getPriority() const {//это метод, который возвращает приоритет задачи.объявлялся константным.
    return priority;
}

std::string Task::getDueDate() const {// метод , который возвращает выполнение задачи.константный
    return due_date;
}

std::vector<std::string> Task::getTags() const {// это метод, который возвращает векторные строки с тегами задач
    return tags;
}