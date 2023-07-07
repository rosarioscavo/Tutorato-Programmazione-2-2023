#include <iostream>
#include <string>

#ifndef CLASSES_H
#define CLASSES_H

using namespace std;

// Si consideri una classe Studente che rappresenta uno studente universitario. La classe  
// ha i seguenti attributi privati: 
// •	matricola, nome, cognome, media La classe ha i seguenti metodi pubblici: 
// •	costruttore, get degli attributi, stampa 

class Studente
{
    private:
        int matricola;
        string nome;
        string cognome;
        double media;

    public:
        Studente(int matricola, string nome, string cognome, double media) : matricola(matricola), nome(nome), 
        cognome(cognome), media(media) {}

        int GetMatricola() { return matricola;}
        string GetNome() { return nome;}
        string GetCognome() { return cognome;}
        double GetMedia() { return media;}
        virtual void Stampa();
};

void Studente::Stampa() {
    cout << matricola << ": " << nome << " " << cognome << " - " << media;
}

// Si consideri una classe BorsaDiStudio che rappresenta una borsa di studio assegnata a uno 
// studente. La classe ha i seguenti attributi privati:
// • importo, durata

class BorsaDiStudio
{
    private:
        double importo;
        int durata; //in mesi

    public:
        BorsaDiStudio(double importo, int durata=20) : importo(importo), durata(durata) {};
        double GetImporto() { return importo;}
        double GetDurata() { return durata;}
};

// Si consideri una classe StudenteBorsista che deriva dalla classe Studente e ha un attributo privato 
// aggiuntivo:
// - borsa: un puntatore a BorsaDiStudio che indica la borsa di studio assegnata allo studente
// La classe ha i seguenti metodi pubblici:
// - get_importo_borsa: restituisce l'importo della borsa di studio assegnata allo studente
// - stampa: stampa a video le informazioni dello studente nel formato "matricola: nome 
// cognome - media [borsa di importo euro]", se è titolare di borsa, altrimenti stampa le 
// informazioni dello studente senza la borsa

class StudenteBorsista : public Studente
{
    private:
        BorsaDiStudio* borsa;
    
    public:
        StudenteBorsista(int matricola, string nome, string cognome, double media, BorsaDiStudio* borsa) : 
        Studente(matricola, nome, cognome, media), borsa(borsa) {}

        double GetImportoBorsa() { return borsa->GetImporto();}
        void Stampa();
};

void StudenteBorsista::Stampa() {
    Studente::Stampa();
    // if (borsa != nullptr) {
    //     cout << " [borsa di " << borsa->GetImporto() << " euro]";
    // }
    cout << " [borsa di " << borsa->GetImporto() << " euro]";
}


#endif