// Planning system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Task.h"
#include "TaskList.h"

int main() {
    TaskList& taskList = TaskList::getInstance();

    Task task1("Pass the exam", 2, "2023-09-23", { "studies" });
    Task task2("Finish project", 1, "2023-09-16", { "studies", "project" });
    Task task3("Visit the theater with your family", 3, "2023-09-27", { "family" });

    taskList.addTask(task1);
    taskList.addTask(task2);
    taskList.addTask(task3);

    
    std::vector<Task> highPriorityTasks = taskList.searchByPriority(1);// Поиск задач по приоритету
    for (const Task& task : highPriorityTasks) {
        std::cout << task.getTitle() << ", Priority: " << task.getPriority() << ", Due Date: " << task.getDueDate() << std::endl;
    }

    
    taskList.saveToFile("tasks.txt");// Сохранение задач в файл

    
    TaskList& loadedTaskList = TaskList::getInstance();// Загрузка задач из файла
    loadedTaskList.loadFromFile("tasks.txt");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
