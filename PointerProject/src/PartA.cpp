#include <iostream>
#include "Class_Definitions.h"
#include <string>

using namespace std;

void completeTask(Task* t) { // Function to mark task as completed using pointer
		t->markCompleted(); 
	}

int main() {
	Task t1(1, "Finish Project"); // Create Task object
	Task t2(2, "Study for Exam"); // Create another Task object

	Task* p1 = &t1; // Pointer to first Task p1 maps to t1
	Task* p2 = &t2; // Pointer to second Task p2 maps to t2

	cout << "Is Task 1 completed? (y/n): ";
	char response;
	cin >> response;
	if (response == 'y' || response == 'Y') {
		completeTask(p1); // Mark task 1 as completed if user inputs 'y'
	}

	cout << "Is Task 2 completed? (y/n): ";
	cin >> response;
	if (response == 'y' || response == 'Y') {
		completeTask(p2); // Mark task 2 as completed if user inputs 'y'
	}

	cout << "Task 1: " << p1->getDescription() << ", Completed: "
		<< (p1->isCompleted() ? "Yes" : "No") << endl; //Describe task 1, then check if completed, use ternary operator to print Yes or No

	cout << "Task 2: " << p2->getDescription() << ", Completed: "
		<< (p2->isCompleted() ? "Yes" : "No") << endl; //Same for task 2

	return 0;
	}