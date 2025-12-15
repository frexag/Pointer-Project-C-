#pragma once

#include <string>
using namespace std;

class Task {
private:
    int id;
    string description;
    bool completed;

public:
    Task();
    Task(int id, const string& desc);

    void markCompleted();
    bool isCompleted() const;
    int getId() const;
    string getDescription() const;
};
