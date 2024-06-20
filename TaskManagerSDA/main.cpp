#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

// ��������� ������
struct Task {
    string title;
    string date; // � ������� "YYYY-MM-DD"
};

// ����� ��������� �����
class TaskManager {
private:
    vector<Task> tasks;

public:
    // ���������� ������
    void addTask(const string& title, const string& date)
    {
        Task newTask = { title, date };
        tasks.push_back(newTask);
    }

    // �������� ������ �� �������
    void deleteTask(size_t index)
    {
        if (index >= tasks.size())
        {
            cerr << "�������� ������ ������." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index);
    }

    // ����� ���� �����
    void printAllTasks() const
    {
        if (tasks.empty())
        {
            cout << "������ �� �������." << endl;
            return;
        }
        cout << "��� ������:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << "������ " << i + 1 << ": " << tasks[i].title << ", Date: " << tasks[i].date << endl;
        }
    }

    // ����� ����� �� �������
    void printTasksForToday(const string& today) const
    {
        cout << "������ �� ������� (" << today << "):" << endl;
        bool foundTodayTasks = false;
        for (const auto& task : tasks)
        {
            if (task.date == today)
            {
                cout << "������: " << task.title << endl;
                foundTodayTasks = true;
            }
        }
        if (!foundTodayTasks)
        {
            cout << "�� ������� ������� ����� �� �������������." << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TaskManager manager;

    // ������ ���������� �����
    manager.addTask("������ ��������� �������", "2024-06-21");
    manager.addTask("����������� ������ ��� �����������", "2024-06-22");
    manager.addTask("����� ������� � �������", "2024-06-21");

    // ����� ���� �����
    manager.printAllTasks();

    // �������� ������ (��������, ������ ������)
    manager.deleteTask(1);

    // ����� ������������ ������ �����
    manager.printAllTasks();

    // ����� ����� �� �������
    string today = "2024-06-21";
    manager.printTasksForToday(today);

    return 0;
}