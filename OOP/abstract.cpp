#include <iostream>
using namespace std;

// Classe astratta
class Veicolo {
public:
    virtual void Accelerare() = 0;
    virtual void Frenare() = 0;
};

// Classe figlia 1
class Auto : public Veicolo {
public:
    void Accelerare() {
        cout << "L'auto accelera." << endl;
    }

    void Frenare() {
        cout << "L'auto frena." << endl;
    }
};

// Classe figlia 2
class Moto : public Veicolo {
public:
    void Accelerare() {
        cout << "La moto accelera." << endl;
    }

    void Frenare() {
        cout << "La moto frena." << endl;
    }
};

int main() {
    // Veicolo veicolo_1; NON POSSIAMO ISTANZIARE UNA CLASSE ASTRATTA
    Auto auto1;
    Moto moto1;

    auto1.Accelerare();  // Output: L'auto accelera.
    auto1.Frenare();     // Output: L'auto frena.

    moto1.Accelerare();  // Output: La moto accelera.
    moto1.Frenare();     // Output: La moto frena.


    Veicolo *veicolo = new Auto();

    int option;

    cout << "1 auto, 2 moto: " << endl, cin >> option;

    if (option == 1) veicolo = new Auto();
    else veicolo = new Moto();

    veicolo->Accelerare();  // Output: Non lo possiamo sapere a tempo di compilazione.

    return 0;
}