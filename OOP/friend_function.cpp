#include <iostream>

class MyClass {
private:
    int privateData;

public:
    MyClass(int data) : privateData(data) {}

    friend void displayPrivateData(MyClass& obj);
};

void displayPrivateData(MyClass& obj) {
    obj.privateData = 35;
    std::cout << "Private data: " << obj.privateData << std::endl;
}

int main() {
    MyClass myObj(42);
    displayPrivateData(myObj);

    return 0;
}