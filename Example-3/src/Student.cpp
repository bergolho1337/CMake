#include <iostream>
#include "../include/Student.h"

// Implement the Student constructor using an initialization list
Student::Student (string name) : name(name) { }

// Simple display function that prints out the name of the Student
void Student::display ()
{
    cout << "A student with name " << this->name << endl;
}

