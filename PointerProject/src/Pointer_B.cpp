#include <iostream>
#include "Class_Definition.h"
#include <string>

using namespace std;

void addTask(Task* tasks, int& size, int capacity, int id, const string& desc) { // Function to add a new task to the dynamic array
	if (size >= capacity) {
		cout << "Task list is full." << endl;
		return;
	}
	tasks[size] = Task(size + 1, desc); // Add new Task object to the array
	size++;
}

void removeTask(Task* tasks, int& size, int id) { // Function to remove a task by id
	for (int i = 0; i < size; i++) { // Find task with matching id
		if (tasks[i].getId() == id) { // Task found
			for (int j = i; j < size - 1; j++) {
				tasks[j] = tasks[j + 1]; // Shift tasks left to fill the gap
			}
			size--; // Decrease size
			return;
		}
	}
	cout << "Task with ID " << id << " not found." << endl;
}

void listTasks(Task* tasks, int size) { // Function to list all tasks
	for (int i = 0; i < size; i++) {
		cout << "Task " << tasks[i].getId() << ": " << tasks[i].getDescription()
			<< ", Completed: " << (tasks[i].isCompleted() ? "Yes" : "No") << endl;
	}
}

int main() {
	int capacity = 5; // Maximum number of tasks
	int size = 0; // Current number of tasks
	Task* tasks = new Task[capacity]; // Dynamically allocate array of Task objects

	while(true) {
		cout << "\nTask Manager Menu:\n";
		cout << "1. Add Task\n";
		cout << "2. Remove Task\n";
		cout << "3. List Tasks\n";
		cout << "4. Mark Task as Completed or Incompleted\n";
		cout << "5. Exit\n";
		cout << "Choose an option: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			string desc;
			cout << "Enter task description: ";
			cin.ignore(); // Clear newline character from input buffer
			getline(cin, desc);
			addTask(tasks, size, capacity, size + 1, desc);
		}
		else if (choice == 2) {
			int id;
			cout << "Enter task ID to remove: ";
			cin >> id;
			removeTask(tasks, size, id);
		}
		else if (choice == 3) {
			listTasks(tasks, size);
		}
		else if (choice == 4) {
			if (size == 0) {
				cout << "No tasks available to mark." << endl;
				continue;
			}
			cout << "Tasks ID List:" << endl;
			for (int i = 0; i < size; i++) {
				cout << tasks[i].getId() << ": " << tasks[i].getDescription()
					<< ", Completed: " << (tasks[i].isCompleted() ? "Yes" : "No") << endl;
			}
			int id;
			cout << "Enter task ID to toggle completion status: ";
			cin >> id;
			bool found = false;
			for (int i = 0; i < size; i++) {
				if (tasks[i].getId() == id) {
					if (tasks[i].isCompleted()) {
						tasks[i] = Task(tasks[i].getId(), tasks[i].getDescription()); // Reset to incompleted
					}
					else {
						tasks[i].markCompleted(); // Mark as completed
					}
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "Task with ID " << id << " not found." << endl;
			}
		}
		else if (choice == 5) {
			break; // Exit the loop
		}
		else {
			cout << "Invalid option. Please try again." << endl;
		}
	}


	delete[] tasks; // Free allocated memory (if not then memory leak occurs)
	return 0;
	}
