#include <iostream>
#include "TaskManager.h"

using namespace std;

TaskManager::TaskManager(int initialCapacity)
	: size(0), capacity(initialCapacity) {
	tasks = make_unique<Task[]>(capacity); // Allocate array of Tasks
}

void TaskManager::addTask(const string& desc) {
	if (size >= capacity) {
		cout << "Task list is full." << endl;
	return;
	}
	tasks[size] = Task(size + 1, desc); // Create new Task
	size++;
}

void TaskManager::removeTask(int id) {
	for (int i = 0; i < size; ++i) {
		if (tasks[i].getId() == id) {
			// Shift tasks to fill the gap
			for (int j = i; j < size - 1; ++j) {
				tasks[j] = tasks[j + 1];
			}
			size--;
			cout << "Task " << id << " removed." << endl;
			return;
		}
	}
	cout << "Task " << id << " not found." << endl;
}

void TaskManager::listTasks() const {
	if (size == 0) {
		cout << "No tasks available." << endl;
		return;
	}
	for (int i = 0; i < size; ++i) {
		cout << "Task ID: " << tasks[i].getId()
			<< ", Description: " << tasks[i].getDescription()
			<< ", Completed: " << (tasks[i].isCompleted() ? "Yes" : "No") << endl;
	}
}

void TaskManager::toggleTaskCompletion(int id) {
	for (int i = 0; i < size; ++i) {
		if (tasks[i].getId() == id) {
			if (tasks[i].isCompleted()) {
				cout << "Task " << id << " is already completed." << endl;
			}
			else {
				tasks[i].markCompleted();
				cout << "Task " << id << " marked as completed." << endl;
			}
			return;
		}
	}
	cout << "Task " << id << " not found." << endl;
}