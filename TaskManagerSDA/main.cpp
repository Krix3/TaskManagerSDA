#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

// Структура задачи
struct Task {
    string title;
    string date; // В формате "YYYY-MM-DD"
};

// Класс менеджера задач
class TaskManager {
private:
    vector<Task> tasks;

public:
    // Добавление задачи
    void addTask(const string& title, const string& date)
    {
        Task newTask = { title, date };
        tasks.push_back(newTask);
    }

    // Удаление задачи по индексу
    void deleteTask(size_t index)
    {
        if (index >= tasks.size())
        {
            cerr << "Неверный индекс задачи." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index);
    }

    // Вывод всех задач
    void printAllTasks() const
    {
        if (tasks.empty())
        {
            cout << "Задача не найдена." << endl;
            return;
        }
        cout << "Все задачи:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << "Задача " << i + 1 << ": " << tasks[i].title << ", Date: " << tasks[i].date << endl;
        }
    }

    // Вывод задач на сегодня
    void printTasksForToday(const string& today) const
    {
        cout << "Задачи на сегодня (" << today << "):" << endl;
        bool foundTodayTasks = false;
        for (const auto& task : tasks)
        {
            if (task.date == today)
            {
                cout << "Задача: " << task.title << endl;
                foundTodayTasks = true;
            }
        }
        if (!foundTodayTasks)
        {
            cout << "На сегодня никаких задач не запланировано." << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TaskManager manager;

    // Пример добавления задач
    manager.addTask("Полное проектное решение", "2024-06-21");
    manager.addTask("Подготовьте слайды для презентации", "2024-06-22");
    manager.addTask("Обзор заметок о встрече", "2024-06-21");

    // Вывод всех задач
    manager.printAllTasks();

    // Удаление задачи (например, второй задачи)
    manager.deleteTask(1);

    // Вывод обновленного списка задач
    manager.printAllTasks();

    // Вывод задач на сегодня
    string today = "2024-06-21";
    manager.printTasksForToday(today);

    return 0;
}