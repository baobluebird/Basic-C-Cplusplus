#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "../model/user.h"
#include "../views/views.h"

class UserController {
private:
    User user;
    UserView view;

public:
    UserController(User u, UserView v) : user(u), view(v) {}

    void setUserName(std::string name) {
        user.name = name;
    }

    std::string getUserName() {
        return user.name;
    }

    void View(UserView v) {
        view = v;
    }

    void display() {
        view.printUserDetails(user.name, user.age);
    }
};

#endif
