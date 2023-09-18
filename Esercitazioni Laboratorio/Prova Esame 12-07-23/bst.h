#include <iostream>
#include "classes.h"

using namespace std;
#ifndef BST_H
#define BST_H

class Nodo {
    private:
        int key;
        Persona* p;
        Nodo* parent;
        Nodo* left;
        Nodo* right;
    
    public:
        Nodo(int key, Persona* p) : key(key), p(p), parent(nullptr), left(nullptr), right(nullptr) {}
        Nodo(Persona* p) : key((int)p->GetEta()), p(p), parent(nullptr), left(nullptr), right(nullptr) {}
        Nodo* GetParent() {return parent;}
        Nodo* GetLeft() {return left;}
        Nodo* GetRight() {return right;}
        void SetParent(Nodo* n) { parent=n;}
        void SetLeft(Nodo* n) {left=n;}
        void SetRight(Nodo* n) {right=n;}
        int Getkey() {return key;}
        Persona* GetPersona() {return p;}
};

class BST {
    private:
        Nodo* root;
        void PreOrder(Nodo* nodo);
        bool IsEmpty() {return root==nullptr;}
        void DistruggiBST(Nodo* n);
    public:
        BST() : root(nullptr) {}
        void Inserisci(Persona* p);
        Nodo* GetRoot() {return root;}
        void Stampa();
        ~BST();
};

void BST::Inserisci(Persona *p)
{
    Nodo *n = new Nodo(p);

    if(IsEmpty())
    {
        root = n;
        return;
    }

    Nodo *tmp = root;
    Nodo *pred;
    // Cerco la posizione in cui inserire il nodo
    while(tmp!=nullptr)
    {
        pred = tmp;
        if(n->Getkey() == tmp->Getkey())
            {
                cout << "Non è possibile inserire due chiavi uguali nel BST" << endl;
                exit(1);
            }
        tmp = n->Getkey() < tmp->Getkey() ? tmp->GetLeft() : tmp->GetRight();
    }

    if ( n->Getkey() < pred->Getkey())
        pred->SetLeft(n);
    else
        pred->SetRight(n);

    n->SetParent(pred);
}

void BST::PreOrder(Nodo* nodo)
{
    if (nodo==nullptr)
        return;

    nodo->GetPersona()->StampaPersona();
    PreOrder(nodo->GetLeft());
    PreOrder(nodo->GetRight());
}

void BST::Stampa()
{
    if (IsEmpty())
        cout << "Il BST è vuoto" << endl;
    else
        PreOrder(root);
}

void BST::DistruggiBST(Nodo* nodo)
{
    if(nodo == nullptr)
        return;
    
    DistruggiBST(nodo->GetLeft());
    DistruggiBST(nodo->GetRight());
    delete nodo;
}

BST::~BST()
{
    // Se l'albero è vuoto non devo fare nulla
    if(IsEmpty())
        return;
    
    // Altrimenti elimino tutti i nodi partendo dalla radice
    DistruggiBST(root);
}

#endif