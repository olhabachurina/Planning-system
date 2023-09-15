#include "TaskList.h"
#include <fstream>
#include <sstream>

TaskList& TaskList::getInstance() {//Этот метод реализует шаблон Singleton, обеспечивающий доступ к единственному экземпляру TaskList
    static TaskList instance;
    return instance;
}

void TaskList::addTask(const Task& task) {//Метод добавления задачи в список задач. Он использует название задачи
    tasks[task.getTitle()] = task;
}

void TaskList::removeTask(const std::string& title) {//Метод переноса из списка задач по ее названию 
    tasks.erase(title);
}

void TaskList::updateTask(const std::string& title, const Task& newTask) {//Метод обновляет задачу в списке задач. Он использует название задачи для обнаружения задач, которые необходимо обновить, и заменяет ее новое соединение.
    tasks[title] = newTask;
}

std::vector<Task> TaskList::searchByDueDate(const std::string& due_date) const {//Метод выполнения задачи поиска по дате выполнения и получения вектора найденных задач
    std::vector<Task> result;
    for (const auto& pair : tasks) {
        if (pair.second.getDueDate() == due_date) {
            result.push_back(pair.second);
        }
    }
    return result;
}

std::vector<Task> TaskList::searchByTag(const std::string& tag) const {//Метод выполнения задач поиска по тегу и возврат вектора найденных задач. 
    std::vector<Task> result;
    for (const auto& pair : tasks) {
        if (std::find(pair.second.getTags().begin(), pair.second.getTags().end(), tag) != pair.second.getTags().end()) {
            result.push_back(pair.second);
        }
    }
    return result;
}

std::vector<Task> TaskList::searchByPriority(int priority) const {//Метод выполнения задач поиска по приоритету и возврат векторов найденных задач.
    std::vector<Task> result;
    for (const auto& pair : tasks) {
        if (pair.second.getPriority() == priority) {
            result.push_back(pair.second);
        }
    }
    return result;
}

void TaskList::saveToFile(const std::string& filename) const {//Метод сохранения списка задач в файл.
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : tasks) {
            file << pair.second.getTitle() << ","
                << pair.second.getPriority() << ","
                << pair.second.getDueDate() << ",";
            const std::vector<std::string>& tags = pair.second.getTags();
            for (size_t i = 0; i < tags.size(); ++i) {
                file << tags[i];
                if (i < tags.size() - 1) {
                    file << ",";
                }
            }
            file << "\n";
        }
        file.close();
    }
}

void TaskList::loadFromFile(const std::string& filename) {//Метод загружает список задач из файла. Он открывает файл для чтения, анализирует каждый текст файла, 
    std::ifstream file(filename);//создает объекты Taskна основе информации в файле и добавляет их в список задач.
    tasks.clear(); // Очистить существующие задачи
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, due_date, tag;
            int priority;
            std::vector<std::string> tags;
            getline(ss, title, ',');
            ss >> priority;
            getline(ss, due_date, ',');
            while (getline(ss, tag, ',')) {
                tags.push_back(tag);
            }
            Task task(title, priority, due_date, tags);
            addTask(task);
        }
        file.close();
    }
}