#include "Task.h"
Task::Task(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags)
    : title(title), priority(priority), due_date(due_date), tags(tags) {}//����������� �������������� ������ Task � ��������� �����������

std::string Task::getTitle() const {//��� �����, ������� ���������� �������� ������. ����� �����������
    return title;
}

int Task::getPriority() const {//��� �����, ������� ���������� ��������� ������.���������� �����������.
    return priority;
}

std::string Task::getDueDate() const {// ����� , ������� ���������� ���������� ������.�����������
    return due_date;
}

std::vector<std::string> Task::getTags() const {// ��� �����, ������� ���������� ��������� ������ � ������ �����
    return tags;
}