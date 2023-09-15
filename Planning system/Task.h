#pragma once
#include <string>
#include <vector>

class Task {
public:
public:
    Task() = default; // ����������� �� ���������

    Task(const std::string& title, int priority, const std::string& due_date, const std::vector<std::string>& tags);

    std::string getTitle() const;//��� �����, ������� ���������� �������� ������
    int getPriority() const;//��� �����, ������� ���������� ������������ ������.
    std::string getDueDate() const;//��� �����, ������� ���������� ���������� ������.
    std::vector<std::string> getTags() const;//��� ����� ������, ������� ���������� ��������� ������ � ������

private:
    std::string title;//�������� ������
    int priority;//������������ ������, ���������� �������������� ������
    std::string due_date;//����, ����� ������ ����� �������
    std::vector<std::string> tags;//��������� ������, �������������� ����
};
