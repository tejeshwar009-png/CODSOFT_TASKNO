#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Task {
    std::string title;
    bool completed = false;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "\nNo tasks in the list.\n";
        return;
    }

    std::cout << "\n=== Your Tasks ===\n";
    for (std::size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].completed ? 'X' : ' ')
                  << "] " << tasks[i].title
                  << (tasks[i].completed ? " (Completed)" : " (Pending)")
                  << '\n';
    }
}

bool readTaskNumber(const std::vector<Task>& tasks, const std::string& action,
                    std::size_t& index) {
    if (tasks.empty()) {
        std::cout << "There are no tasks to " << action << ".\n";
        return false;
    }

    std::size_t number = 0;
    std::cout << "Enter the task number to " << action << ": ";
    if (!(std::cin >> number) || number < 1 || number > tasks.size()) {
        std::cout << "Invalid task number.\n";
        clearInput();
        return false;
    }

    index = number - 1;
    return true;
}

int main() {
    std::vector<Task> tasks;
    int choice = 0;

    std::cout << "=== To-Do List Manager ===\n";

    while (choice != 6) {
        std::cout << "\n1. Add task\n"
                  << "2. View tasks\n"
                  << "3. Mark task as completed\n"
                  << "4. Remove task\n"
                  << "5. Clear all tasks\n"
                  << "6. Exit\n"
                  << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice.\n";
            clearInput();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string title;
                std::cout << "Enter the task: ";
                std::getline(std::cin, title);
                if (title.empty()) {
                    std::cout << "Task cannot be empty.\n";
                } else {
                    tasks.push_back({title, false});
                    std::cout << "Task added successfully.\n";
                }
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                displayTasks(tasks);
                std::size_t index = 0;
                if (readTaskNumber(tasks, "complete", index)) {
                    tasks[index].completed = true;
                    std::cout << "Task marked as completed.\n";
                }
                break;
            }
            case 4: {
                displayTasks(tasks);
                std::size_t index = 0;
                if (readTaskNumber(tasks, "remove", index)) {
                    tasks.erase(tasks.begin() + static_cast<std::ptrdiff_t>(index));
                    std::cout << "Task removed successfully.\n";
                }
                break;
            }
            case 5:
                tasks.clear();
                std::cout << "All tasks cleared.\n";
                break;
            case 6:
                break;
            default:
                std::cout << "Please choose an option from 1 to 6.\n";
        }
    }

    std::cout << "To-do list closed.\n";
    return 0;
}
