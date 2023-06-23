/*
Si consideri una classe astratta Veicolo. La classe ha i seguenti attributi privati: 
-	Targa, nome modello, anno di fabbricazione, marca, cilindrata.
La classe ha i seguenti metodi pubblici: 
-	costruttore, get degli attributi
-	un metodo virtuale puro per la Stampa
 
Si considerino due classi derivate da Veicolo: Auto e Moto. Ognuna di queste classi implementa il metodo Stampa in modo appropriato per il tipo di veicolo. 
La classe Auto ha i seguenti attributi privati: 
-	numero_porte
La classe Moto ha i seguenti attributi privati: 
-	tipo_moto (sportiva, chopper, enduro, ecc)
*/

#include <iostream>
#include <string>

using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

class Veicolo
{
    private:
        string targa;
        string nome_modello;
        int anno_fabbricazione;
        int cilindrata;
        string marca;

    public:
        Veicolo(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata);
        string GetTarga() { return targa;}
        string GetNomeModello() { return nome_modello;}
        int GetAnnoFabbricazione() { return anno_fabbricazione;}
        int GetCilindrata() { return cilindrata;}
        string GetMarca() { return marca;}
        virtual void Stampa() = 0;
        friend bool operator<(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) < 0;}
        friend bool operator>(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) > 0;}
        friend bool operator==(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) == 0;}
};

Veicolo::Veicolo(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata)
{
    this->targa = targa;
    this->nome_modello = nome_modello;
    this->anno_fabbricazione = anno_fabbricazione;
    this->cilindrata = cilindrata;
    this->marca = marca;
}

class Auto : public Veicolo
{
    private:
        int numero_porte;

    public:
        Auto(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata ,int numero_porte);
        int GetNumeroPorte() { return numero_porte;}
        void Stampa();
};

Auto::Auto(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata , int numero_porte) : 
Veicolo(targa, nome_modello, marca, anno_fabbricazione, cilindrata)
{
    this->numero_porte = numero_porte;
}

void Auto::Stampa()
{
        cout << "Auto:  " << endl
             << "\tTarga: " << GetTarga() << "\tNome modello: " << GetNomeModello() << endl
             << "\tMarca: " << GetMarca() << "\tAnno fabbricazione: " << GetAnnoFabbricazione() << endl
             << "\tCilindrata: " << GetCilindrata() << "\tNumero porte: " << numero_porte << endl;
}

class Moto : public Veicolo
{
    private:
        string tipo_moto;

    public:
        Moto(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata, string tipo_moto);
        string GetTipoMoto() { return tipo_moto;}
        void Stampa();
};

Moto::Moto(string targa, string nome_modello, string marca, int anno_fabbricazione, int cilindrata, string tipo_moto) :
Veicolo(targa, nome_modello, marca, anno_fabbricazione, cilindrata) , tipo_moto(tipo_moto) {};

void Moto::Stampa()
{
        cout << "Moto:  " << endl
             << "\tTarga: " << GetTarga() << "\tNome modello: " << GetNomeModello() << endl
             << "\tMarca: " << GetMarca() << "\tAnno fabbricazione: " << GetAnnoFabbricazione() << endl
             << "\tCilindrata: " << GetCilindrata() << "\tTipo moto: " << tipo_moto << endl;
}


#endif