#include <iostream>
#include <vector>
#include <string>

// Task structure
struct Task {
    int id;
    std::string description;
    bool completed;
};

// Function to add a new task
void addTask(std::vector<Task>& tasks, const std::string& description) {
    static int taskId = 1;
    tasks.push_back({taskId++, description, false});
}

// Function to mark a task as completed
void markCompleted(std::vector<Task>& tasks, int taskId) {
    for (auto& task : tasks) {
        if (task.id == taskId) {
            task.completed = true;
            break;
        }
    }
}

// Function to display tasks
void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "Current Tasks:\n";
    for (const auto& task : tasks) {
        std::cout << "[" << task.id << "] ";
        std::cout << (task.completed ? "[X] " : "[ ] ");
        std::cout << task.description << "\n";
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. View Tasks\n";
        std::cout << "4. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::cin.ignore(); // Clear newline from previous input
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2: {
                std::cout << "Enter task ID to mark as completed: ";
                int taskId;
                std::cin >> taskId;
                markCompleted(tasks, taskId);
                break;
            }
            case 3: {
                displayTasks(tasks);
                break;
            }
            case 4:
                std::cout << "Exiting. Have a productive day!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}