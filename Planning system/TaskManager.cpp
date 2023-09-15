#include "TaskManager.h"
TaskManager::TaskManager(TaskList& taskList) : taskList(taskList) {}

void TaskManager::addTask(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags) {
    Task task(title, priority, due_date, tags);
    taskList.addTask(task);
}

void TaskManager::removeTask(const std::string& title) {
    taskList.removeTask(title);
}

void TaskManager::updateTask(const std::string& title, int newPriority, const std::string& newDueDate, const std::vector<std::string>& newTags) {
    Task task(title, newPriority, newDueDate, newTags);
    taskList.updateTask(title, task);
}

std::vector<Task> TaskManager::searchByDueDate(const std::string& due_date) const {
    return taskList.searchByDueDate(due_date);
}

std::vector<Task> TaskManager::searchByTag(const std::string& tag) const {
    return taskList.searchByTag(tag);
}

std::vector<Task> TaskManager::searchByPriority(int priority) const {
    return taskList.searchByPriority(priority);
}

void TaskManager::saveTasksToFile(const std::string& filename) const {
    taskList.saveToFile(filename);
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    taskList.loadFromFile(filename);
}