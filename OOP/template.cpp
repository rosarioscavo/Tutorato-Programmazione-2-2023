#include <iostream>
using namespace std;

template <typename T>
T massimo(T a, T b)
{
    cout << "Template" << endl;
    return a > b ? a : b;
}

template <>
int massimo<int>(int a, int b)
{
    cout << "Template int" << endl;
    return a > b ? a : b;
}

//provare a rimuovere
int massimo(int a, int b)
{
    cout << "Int" << endl;
    return a > b ? a : b;
}

char massimo(char a, char b)
{
    cout << "Char" << endl;
    return a > b ? a : b;
}

template <typename T, typename U>
class MyClass
{
    private:
        T x;
        U y;
    
    public:
        MyClass(T x, U y) : x(x), y(y) {}
        
        T getX();
        U getY();
};

template <typename T, typename U>
T MyClass<T, U>::getX()
{
    return x;
}

template <typename T, typename U> 
U MyClass<T, U>::getY()
{
    return y;
}


int main()
{
    cout << massimo(1, 2) << endl;
    cout <<endl;
    cout << massimo(25.2, 30.1) << endl;
    cout <<endl;
    cout << massimo('a', 'b') << endl;
    cout <<endl;

    MyClass<int,char> *myClass = new MyClass<int, char>(5, 'a');
    MyClass<int,char> temp(3,'z');
    
    cout << myClass->getX() << endl;
    cout << temp.getY() << endl;

    return 0;
}