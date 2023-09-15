#pragma once
#include "TaskList.h"
class TaskManager {
public:
    TaskManager(TaskList& taskList);

    void addTask(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags);
    void removeTask(const std::string& title);
    void updateTask(const std::string& title, int newPriority, const std::string& newDueDate, const std::vector<std::string>& newTags);
    std::vector<Task> searchByDueDate(const std::string& due_date) const;
    std::vector<Task> searchByTag(const std::string& tag) const;
    std::vector<Task> searchByPriority(int priority) const;
    void saveTasksToFile(const std::string& filename) const;
    void loadTasksFromFile(const std::string& filename);

private:
    TaskList& taskList;
};
