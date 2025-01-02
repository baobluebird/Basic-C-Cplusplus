#include "model/user.h"
#include "controller/controller.h"
#include "views/views.h"

int main() {
    User user("John Doe", 25);
    UserView view;
    UserController controller(user, view);

    controller.display();

    controller.setUserName("Jane Doe");
    controller.display();

    return 0;
}
