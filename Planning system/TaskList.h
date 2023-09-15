#pragma once
#include <map>
#include <string>
#include "Task.h"

class TaskList {
public:
    static TaskList& getInstance();//������������ ������ � ������������� ���������� ������ TaskList.

    void addTask(const Task& task);//����� ���������� ������ � ������ ����� 
    void removeTask(const std::string& title);//����� �������� ������ �� ������ ����� �� �� ��������.
    void updateTask(const std::string& title, const Task& newTask);// ����� ���������� ������ � ������.
    std::vector<Task> searchByDueDate(const std::string& due_date) const;//����� ������������ ����� ������ �� ���� ����������. 
    std::vector<Task> searchByTag(const std::string& tag) const;//������ ������ � ������ �����, ������� �������� �������� ���.
    std::vector<Task> searchByPriority(int priority) const;// ���������� ������ ����� � ������ ����� �� �� ����������.
    void saveToFile(const std::string& filename) const;//����� ���������� ������ ����� � ��������� �����.
    void loadFromFile(const std::string& filename);//����� ������������� ��������� ���� ��� ������� 

private:
    TaskList() {} // ��������� ����������� ��� Singleton
    TaskList(const TaskList&) = delete;// ���������� ������������ ����������� � ����� ������������� ��� � ��������� ��������.��� ��������, ��� ������ ��������� ����� �������� 
    TaskList& operator=(const TaskList&) = delete;//���������� �������� ���������� ������  ��������� "�������". 

    std::map<std::string, Task> tasks; // ����� ��� �������� ����� � ��������� � �������� �����
};
