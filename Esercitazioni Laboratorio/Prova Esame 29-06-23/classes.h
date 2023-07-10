/*Si consideri una classe virtuale Frutto che rappresenta un frutto. La classe ha i seguenti attributi 
privati:
• nome, colore, stagione
La classe ha i seguenti metodi pubblici:
• costruttore
• get degli attributi
• stampa: un metodo per la stampa degli attributi
• sapore: un metodo virtuale puro che restituisce il sapore del frutto
*/

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
using namespace std;

class Frutto
{
    private:
        string nome;
        string stagione;
        string colore;
        string descrizione_sapore;

    public:
        Frutto(string nome, string colore, string stagione, string descrizione_sapore):
            nome(nome), colore(colore), stagione(stagione), descrizione_sapore(descrizione_sapore) {}
        string GetNome() { return nome; };
        string GetStagione() { return stagione; };
        string GetColore() { return colore; };
        string GetDescrizioneSapore() { return descrizione_sapore; };
        void Stampa();
        virtual string Sapore() = 0;
};

void Frutto::Stampa()
{
    cout << "Frutto: " << endl << "\tNome: " << GetNome() << " \tStagione: " 
    << GetStagione() << " \tColore: " << GetColore() << endl;
}

/*Si considerino due classi derivate da Frutto: Mela e Arancia. Ognuna di queste classi implementa il 
metodo sapore in modo appropriato per il tipo di frutto.*/

class Mela: public Frutto
{
    public:
        Mela(string nome, string colore, string stagione, string descrizione_sapore):
            Frutto(nome, colore, stagione, descrizione_sapore) {}
        string Sapore() { return "Sono una mela ed ho un " + GetDescrizioneSapore(); };
};

class Arancia : public Frutto
{
    public:
        Arancia(string nome, string colore, string stagione, string descrizione_sapore):
            Frutto(nome, colore, stagione, descrizione_sapore) {}
        string Sapore() { return "Sono un'arancia ed ho un " + GetDescrizioneSapore(); };
};



#endif