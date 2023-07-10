#include <iostream>
#include <string>
#include "classes.h"
#include "queue.h"

using namespace std;

// template <typename T>
// bool IsSameType(T* ele, string tipo)
// {
//     string tipo_ele = typeid(ele).name();

//     bool val = tipo_ele.find(tipo) != string::npos;

//     cout << "Tipo ele: " << tipo_ele << " Valore ritornato: " << val << endl;
//     return tipo_ele.find(tipo) != string::npos;
// }

template <typename T>
bool IsSameType(T* ele, string tipo)
{
    T* frutto;
    if (tipo == "Mela")
        frutto = dynamic_cast<Mela*>(ele);
    else if (tipo == "Arancia")
        frutto = dynamic_cast<Arancia*>(ele);
    else
    {
        cout << "Tipo non valido" << endl;
        exit(1);
    }
    
    return frutto != nullptr;
}

template <typename T>
int RimuoviElementiTipoIt(Coda<T>* coda, string tipo)
{
    int num_ele_inizio = coda->GetDimensione();
    int dim_counter = num_ele_inizio;

    if (dim_counter == 0)
        return 0;

    T* ele;
    string tipo_ele;
    while(dim_counter > 0)
    {
        ele = coda->Dequeue();
        // Se il tipo non coincide con quello che voglio eliminare (ovvero, non trovo una substring),
        // lo reinserisco in coda
        if (IsSameType(ele, tipo) == false)
            coda->Enqueue(ele);

        dim_counter--;
    }

    int num_ele_fine = coda->GetDimensione();

    return num_ele_inizio - num_ele_fine;
}

template <typename T>
int RimuoviElementiTipoRic(Coda<T>* coda, int counter, string tipo)
{
    if (counter==0)
        return 0;

    T* ele = coda->Dequeue();

    if (IsSameType(ele, tipo) == false)
    {
        coda->Enqueue(ele);
        return 0 + RimuoviElementiTipoRic(coda, counter -1, tipo);
    }

    return 1 + RimuoviElementiTipoRic(coda, counter -1, tipo);
}


template <typename T>
void RimuoviElementiTipo(Coda<T>* coda, string tipo)
{
    // int ele_rimossi = RimuoviElementiTipoIt(coda, tipo);
    int ele_rimossi = RimuoviElementiTipoRic(coda, coda->GetDimensione(), tipo);
    cout << "Sono stati rimossi " << ele_rimossi << " frutti dalla coda." << endl;
    cout << "Frutti rimanenti nella coda:" << endl;
    coda->Stampa();
}

int main()
{
    Mela frutto1("Granny Smith", "Verde", "Autunno", "sapore Aspro");
    Arancia frutto2("Tarocco", "Arancione", "Inverno", "sapore Dolce");
    Mela frutto3("Golden Delicious", "Giallo", "Autunno", "sapore Dolce");
    Arancia frutto4("Navel", "Arancione", "Inverno", "sapore Dolce-Acido");
    Mela frutto5("Fuji", "Rosso", "Autunno", "sapore Dolce");
    Arancia frutto6("Valencia", "Arancione", "Estate", "sapore Acido");

    // Creo una coda di frutti
    Coda<Frutto> coda;

    // Inseriamo i frutti nella coda
    coda.Enqueue(&frutto1);
    coda.Enqueue(&frutto2);
    coda.Enqueue(&frutto3);
    coda.Enqueue(&frutto4);
    coda.Enqueue(&frutto5);
    coda.Enqueue(&frutto6);

    // Stampo la coda
    cout << endl << "Stampa coda: " << endl;
    coda.Stampa();

    // Chiediamo all'utente di inserire il tipo di frutti da rimuovere
    cout << endl << "Inserisci il tipo di frutti da rimuovere: ";
    string tipo;
    cin >> tipo;

    cout << endl;
    // Rimuoviamo i frutti di quel tipo
    RimuoviElementiTipo(&coda, tipo);

    return 0;
}
