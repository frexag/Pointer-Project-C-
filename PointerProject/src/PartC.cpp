#include <iostream>
#include "TaskManager.h"

using namespace std;

int main() {

	TaskManager manager(5); // Initialize TaskManager with capacity of 5 tasks

	while (true) {
		cout << "\nTask Manager Menu:\n";
		cout << "1. Add Task\n";
		cout << "2. Remove Task\n";
		cout << "3. List Tasks\n";
		cout << "4. Toggle Task Completion\n";
		cout << "5. Exit\n";
		cout << "Choose an option: ";
		int choice;
		cin >> choice;

		cin.ignore(); // Clear newline character from input buffer
		if (choice == 1) {
			string desc;
			cout << "Enter task description: ";
			getline(cin, desc);
			manager.addTask(desc);
			continue;
		}
		else if (choice == 2) {
			int id;
			cout << "Enter task ID to remove: ";
			cin >> id;
			manager.removeTask(id);
			continue;
		}
		else if (choice == 3) {
			manager.listTasks();
			continue;
		}
		else if (choice == 4) {
			int id;
			cout << "Enter task ID to toggle completion: ";
			cin >> id;
			manager.toggleTaskCompletion(id);
			continue;
		}
		else if (choice == 5) {
			cout << "Exiting Task Manager." << endl;
			break;
		}
		else {
			cout << "Invalid option. Please try again." << endl;
			continue;
		}

		return 0;

}
}