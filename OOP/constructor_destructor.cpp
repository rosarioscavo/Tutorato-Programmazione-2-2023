#include <iostream>
using namespace std;

class Madre {
public:
    Madre() {
        cout << "Costruttore di Madre" << endl;
    }

    ~Madre() {
        cout << "Distruttore di Madre" << endl;
    }
};

class Figlia : public Madre {
public:
    Figlia() {
        cout << "Costruttore di Figlia" << endl;
    }

    ~Figlia() {
        cout << "Distruttore di Figlia" << endl;
    }
};

int main() {
    cout << "Creo un puntatore di tipo Figlia" << endl;
    Figlia* figlia = new Figlia();
    delete figlia;

    cout << endl << "Creo un puntatore di tipo Madre a Figlia" << endl;
    Madre* madre_ptr = new Figlia();
    delete madre_ptr;

    return 0;
}
