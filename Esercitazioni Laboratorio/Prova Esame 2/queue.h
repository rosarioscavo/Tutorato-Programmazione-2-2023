#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

const int MAX_SIZE = 6;

class Queue
{
    private:
        Studente* coda[MAX_SIZE];
        int front;
        int rear;

        bool IsEmpty() { return (front==-1 && rear==-1);}
        bool IsFull() { return (rear+1)% MAX_SIZE == front;}
        bool HasToBeDeleted(Studente* studente) {return (studente->GetMedia()<25);}
        void DeleteStudente(Studente* studente);
    public:
        Queue() : front(-1), rear(-1) {};

        void InserisciStudente(Studente* studente);
        double GetImportoBorsisti();
        Studente* Dequeue();
        void Stampa();
        void PulisciCoda();
};

void Queue::InserisciStudente(Studente* studente)
{
    
    if (IsFull())
    {
        cout << "La coda è piena" << endl;
        return;
    }

    if(IsEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear+1) % MAX_SIZE;

    coda[rear] = studente;
}

Studente* Queue::Dequeue()
{
    if (IsEmpty()) {
        cout << "Coda vuota" << endl;
        return nullptr;
    }

    Studente* studente = coda[front];
    coda[front] = nullptr;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    return studente;
}

void Queue::Stampa()
{
    if (IsEmpty()) {
        cout << "Coda vuota" << endl;
        return;
    }

    int num_elementi = (rear - front + MAX_SIZE) % MAX_SIZE + 1;

    int idx = front;
    while (num_elementi > 0) {
        coda[idx]->Stampa();
        cout << endl;

        idx = (idx+1)%MAX_SIZE;
        num_elementi--;
    }
}

double Queue::GetImportoBorsisti()
{
    if (IsEmpty()) {
        cout << "Coda vuota" << endl;
        return 0;
    }

    double importo = 0;
    
    int num_elementi = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    int idx = front;
    while (num_elementi>0) {
        // Facciamo un downcast, questo significa che se convertiamo Studente a StudenteBorsista
        // Otteniamo un nullptr
        StudenteBorsista* studente = dynamic_cast<StudenteBorsista*>(coda[idx]);
        if (studente != nullptr)
            importo += studente->GetImportoBorsa();
        idx = (idx + 1) % MAX_SIZE;

        num_elementi--;
    }

    return importo;
}

// Solo per la stampa del messaggio di avviso
void Queue::DeleteStudente(Studente* studente)
{
    cout << "Cancellazione=> ";
    studente->Stampa();
    cout << endl;
}

// L'idea è quella che se estraggo e inserisco tutti gli elementi,
// l'ordine rimane invariato e la complessità è O(n)
void Queue::PulisciCoda()
{
    if (IsEmpty()) {
        cout << "Coda vuota" << endl;
        return;
    }

    int num_elementi = (rear - front + MAX_SIZE) % MAX_SIZE + 1;

    while (num_elementi > 0) {
        Studente* studente = Dequeue();
        if (!HasToBeDeleted(studente))
            InserisciStudente(studente);
        else
            DeleteStudente(studente);

        num_elementi--;
    }
}


#endif