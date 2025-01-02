#include <bits/stdc++.h>

using namespace std;

class User {
public:
    string name;
    int age;

    User(string n, int a) : name(n), age(a) {}
};

class UserView {
public:
    void printUserDetails(std::string name, int age) {
        cout << "User: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

class UserController {
private:
    User user;
    UserView view;

public:
    UserController(User u, UserView v) : user(u), view(v) {}

    void setUserName(string name) {
        user.name = name;
    }

    string getUserName() {
        return user.name;
    }

    void View(UserView v) {
        view = v;
    }

    void display() {
        view.printUserDetails(user.name, user.age);
    }
};

int main() {
    User user("John Doe", 25);
    UserView view;
    UserController controller(user, view);

    controller.display();

    controller.setUserName("Jane Doe");
    controller.display();

    return 0;
}
