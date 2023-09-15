#pragma once
#include <map>
#include <string>
#include "Task.h"

class TaskList {
public:
    static TaskList& getInstance();//обеспечивает доступ к единственному экземпляру класса TaskList.

    void addTask(const Task& task);//Метод добавления задачи в список задач 
    void removeTask(const std::string& title);//Метод удаления задачи из списка задач по ее названию.
    void updateTask(const std::string& title, const Task& newTask);// Метод обновления задачи в списке.
    std::vector<Task> searchByDueDate(const std::string& due_date) const;//Метод обеспечивает поиск задачи по дате выполнения. 
    std::vector<Task> searchByTag(const std::string& tag) const;//поиска задачи в списке задач, который содержит заданный тег.
    std::vector<Task> searchByPriority(int priority) const;// выполнения поиска задач в списке задач по их приоритету.
    void saveToFile(const std::string& filename) const;//метод сохранения списка задач в текстовом файле.
    void loadFromFile(const std::string& filename);//Метод предоставляет указанный файл для записей 

private:
    TaskList() {} // Приватный конструктор для Singleton
    TaskList(const TaskList&) = delete;// объявление конструктора копирования и затем устанавливает его в состояние «удалено».Это означает, что нельзя создавать копии объектов 
    TaskList& operator=(const TaskList&) = delete;//определяет оператор присвоения класса  состоянии "удалено". 

    std::map<std::string, Task> tasks; // Карта для хранения задач с названием в качестве ключа
};
