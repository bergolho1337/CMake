#include <string>

using namespace std;

class Student
{
private:
    string name;
public:
    Student (string name);
    virtual void display ();
};