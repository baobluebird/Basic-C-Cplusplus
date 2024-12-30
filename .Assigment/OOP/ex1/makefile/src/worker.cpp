#include <worker.h>

Worker::Worker() : level(0) {}
Worker::Worker(string name, int age, string gender, string address, int level)
    : Employee(name, age, gender, address), level(level) {}

void Worker::enterInformation()
{
    Employee::enterInformation();
    cout << "Enter level (1-10): ";
    cin >> level;
    while (level < 1 || level > 10)
    {
        cout << "Level must be between 1 and 10. Please re-enter: ";
        cin >> level;
    }
}

void Worker::displayInformation()
{
    cout << "---------- Worker Information ----------" << endl;
    Employee::displayInformation();
    cout << "Level: " << this->level << endl;
}
