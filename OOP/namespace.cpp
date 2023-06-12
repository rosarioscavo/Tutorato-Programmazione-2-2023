#include <iostream>

namespace MyNamespace {
    int age = 10;
    
    void printMessage() {
        std::cout << "Hello from MyNamespace!" << age << std::endl;
    }
};

void printMessage() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    MyNamespace::printMessage();
    printMessage();
    return 0;
}