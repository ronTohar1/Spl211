#include <iostream>
#include "Session.h"

int main() {

    Session session("../config4.json");
    session.simulate();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
