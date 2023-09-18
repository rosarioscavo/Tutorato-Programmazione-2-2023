#include <iostream>
#include <string>

using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

class Persona {
    private:
        string nome;
        string cognome;
        string categoria;
        int eta;

    public:
        Persona(string nome, string cognome, int eta)
            : nome(nome), cognome(cognome), eta(eta) {}
        
        int GetEta() {return eta;}
        void StampaPersona();
        virtual string GetCategoria() {return "Persona";}
};

void Persona::StampaPersona(){
    cout << nome << " " << cognome << "(" << eta << ")" << endl;
}

class Studente : public Persona {
    public:
        Studente(string nome, string cognome, int eta) : Persona(nome, cognome, eta) {};
        string GetCategoria() {return "Studente";}

};

class Lavoratore : public Persona {
    public:
        Lavoratore(string nome, string cognome, int eta) : Persona(nome, cognome, eta) {};
        string GetCategoria() {return "Lavoratore";}
};

class Pensionato : public Persona {
    public:
        Pensionato(string nome, string cognome, int eta) : Persona(nome, cognome, eta) {};
        string GetCategoria() {return "Pensionato";}
};

#endif