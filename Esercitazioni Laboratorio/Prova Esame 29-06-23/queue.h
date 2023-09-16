/*
Si consideri una classe template Coda<T> che rappresenta una struttura dati a coda di elementi di 
tipo T. 
La classe ha i seguenti attributi privati:
• testa: un puntatore al nodo in testa alla coda
• coda: un puntatore al nodo in coda alla coda
• dimensione: il numero di nodi nella coda 
La classe ha i seguenti metodi pubblici:
• costruttore, distruttore
• enqueue: inserisce un nuovo elemento in coda alla coda
• dequeue: rimuove e restituisce l’elemento in testa alla coda, se la coda non è vuota
• front: restituisce l’elemento in testa alla coda senza rimuoverlo, se la coda non è vuota
• stampa: stampa tutti gli elementi nella coda dal primo all’ultimo inserito
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo
{
    private:
        T* ele;
        Nodo<T>* next;

    public:
        Nodo(T* ele, Nodo<T>* next) : ele(ele), next(next) {};
        Nodo(T* ele) : ele(ele), next(nullptr) {};

        T* GetEle() { return ele; };
        Nodo<T>* GetNext() { return next; };
        void SetEle(T* ele) { this->ele = ele; };
        void SetNext(Nodo<T>* next) { this->next = next; };
};

template <typename T>
class Coda
{
    private:
        Nodo<T>* testa;
        Nodo<T>* coda;
        int dimensione;
        bool IsEmpty() { return testa == nullptr; };
    public:
        Coda() : testa(nullptr), coda(nullptr), dimensione(0) {};
        ~Coda();
        void Enqueue(T* ele);
        T* Dequeue();
        T* Front();
        void Stampa();
        int GetDimensione() { return dimensione; };
};

template <typename T>
void Coda<T>::Enqueue(T* ele)
{
    // creaiamo un nuovo nodo
    Nodo<T>* nodo_nuovo = new Nodo<T>(ele);

    // Se è vuota allora sia la testa che la coda puntano al nuovo nodo
    if(IsEmpty())
    {
        testa = coda = nodo_nuovo;
    }
    else
    {
        coda->SetNext(nodo_nuovo);
        coda = nodo_nuovo;
    }

    // aggiorniamo la dimensione
    dimensione++;
}

template <typename T>
T* Coda<T>::Dequeue()
{
    // Controllo se la coda è vuota
    if (IsEmpty())
        return nullptr;
    
    // Copiamo il nodo in testa e il suo valore
    Nodo<T>* testa_copy = testa;
    T* ele = testa_copy->GetEle();

    // Controllo se la coda ha un solo elemento
    if (testa==coda)
    {
        testa = coda = nullptr;
    }
    else
        testa = testa->GetNext();

    // Eliminiamo il nodo in testa
    delete testa_copy;

    // Aggiorniamo la dimensione
    dimensione--;

    // Ritorniamo il valore
    return ele;
}

template <typename T>
void Coda<T>::Stampa()
{ 
    Nodo<T>* temp = testa;
    T* ele;

    while(temp!=nullptr)
    {
        ele = temp->GetEle();
        ele->Stampa();
        cout << "\t" << ele->Sapore() << endl;

        temp = temp->GetNext();
    }
}

template <typename T>
Coda<T>::~Coda()
{
    Nodo<T>* temp = testa;
    Nodo<T>* temp_next;

    while(temp!=nullptr)
    {
        temp_next = temp->GetNext();
        delete temp;
        temp = temp_next;
    }
}

#endif