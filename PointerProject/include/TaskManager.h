#pragma once
#include <memory>
#include <string>
#include "Class_Definition.h"

using namespace std;

class TaskManager {
private:
	unique_ptr<Task[]> tasks;
	int capacity;
	int size;

public:
	TaskManager(int initialCapacity);

	void addTask(const string& desc);

	void removeTask(int id);

	void listTasks() const;

	void toggleTaskCompletion(int id);
};