/*
Si consideri una classe AlberoBinario che rappresenta una struttura dati ad albero binario di ricerca di veicoli. La classe ha i seguenti attributi privati: 
-	radice: un puntatore al nodo radice dell'albero 
La classe ha i seguenti metodi pubblici: 
-	costruttore, distruttore 
-	inserisci: inserisce un nuovo veicolo nell’albero in base alla sua targa
-	elimina: elimina un nuovo veicolo nell’albero in base alla sua targa
-	cerca: cerca un veicolo nell'albero data la sua targa e restituisce un puntatore al veicolo se trovato, altrimenti restituisce nullptr 
-	stampa: stampa tutti i veicoli nell'albero in ordine alfabetico delle loro targe
-	verifica stampa: stampa tutti i veicoli eseguendo una visita Pre-Order dell’albero
*/

#include <iostream>
#include "classes.h"
using namespace std;

#ifndef BST_H
#define BST_H

class Nodo
{
    private:
        Veicolo* v;
        Nodo* left;
        Nodo* right;
        Nodo* parent;
    
    public:
        Nodo(Veicolo* v) : v(v), left(nullptr), right(nullptr), parent(nullptr) {}
        void SetLeft(Nodo* left) { this->left = left;}
        void SetRight(Nodo* right) { this->right = right;}
        void SetParent(Nodo* parent) { this->parent = parent;}
        Nodo* GetLeft() { return left;}
        Nodo* GetRight() { return right;}
        Nodo* GetParent() { return parent;}
        Veicolo* GetVeicolo() { return v;}
        void SetVeicolo(Veicolo* v) { this->v = v;}
};



class BST
{
    private:
        Nodo* root;
        bool IsEmpty() { return root == nullptr;}
        void PreOrder(Nodo* nodo);
        void InOrder(Nodo* nodo);
        Nodo* TrovaNodo(string targa);
        void CancellaNodo(Nodo* nodo);
        Nodo* Successore(Nodo* nodo);
        Nodo* Minimo(Nodo* nodo);
        void DistruggiBST(Nodo* nodo);
    public:
        BST() : root(nullptr) {}
        void Inserisci(Veicolo* v);
        void Stampa();
        void VerificaStampa();
        void StampaInOrdine();
        void Elimina(string targa);
        Veicolo* TrovaVeicolo(string targa);
        ~BST();
};

void BST::Inserisci(Veicolo* v)
{
    // Creiamo un nuovo nodo
    Nodo* nodo_nuovo = new Nodo(v);

    // Controlliamo se l'albero sia vuoto
    if(IsEmpty())
    {
        root = nodo_nuovo;
        return;
    }
    
    // Controlliamo dove mettere il nodo

    Nodo* tmp = root;
    Nodo* parent = nullptr;

    while(tmp!=nullptr)
    {
        parent = tmp;
        if(*nodo_nuovo->GetVeicolo() < *tmp->GetVeicolo())
            tmp = tmp->GetLeft();
        else
            tmp = tmp->GetRight();
    }

    // Controllo se il mio nodo sia maggiore o minore del padre
    if(*nodo_nuovo->GetVeicolo() < *parent->GetVeicolo())
        parent->SetLeft(nodo_nuovo);
    else
        parent->SetRight(nodo_nuovo);

    // Settiamo il parent del nuovo nodo
    nodo_nuovo->SetParent(parent);
}

void BST::PreOrder(Nodo* n)
{
    if(n == nullptr)
        return;

    n->GetVeicolo()->Stampa();
    PreOrder(n->GetLeft());
    PreOrder(n->GetRight());
}

void BST::InOrder(Nodo* n)
{
    if(n == nullptr)
        return;

    InOrder(n->GetLeft());
    n->GetVeicolo()->Stampa();
    InOrder(n->GetRight());
}

void BST::VerificaStampa()
{
    if(IsEmpty())
    {
        cout << "Albero vuoto" << endl;
        return;
    }
    PreOrder(root);
}

void BST::StampaInOrdine()
{
    if(IsEmpty())
    {
        cout << "Albero vuoto" << endl;
        return;
    }
    InOrder(root);
}

Nodo* BST::TrovaNodo(string targa)
{

    // Nodo temporaneo
    Nodo* tmp = root;

    while(tmp!=nullptr)
        if (targa.compare(tmp->GetVeicolo()->GetTarga()) == 0)
            return tmp;
        else if (targa.compare(tmp->GetVeicolo()->GetTarga()) < 0)
            tmp = tmp->GetLeft();
        else
            tmp = tmp->GetRight();
    

    return nullptr;
}

Veicolo* BST::TrovaVeicolo(string targa)
{

    // Trova il nodo (se esiste)
    Nodo* nodo = TrovaNodo(targa);

    // restituisce il veicolo
    if(nodo != nullptr)
        return nodo->GetVeicolo();
    else
        {
            cout << "Veicolo non trovato" << endl;
            return nullptr;
        }
}

Nodo* BST::Minimo(Nodo* n)
{
    //Scorriamo a sinistra finchè non troviamo il minimo
    while(n->GetLeft() != nullptr)
        n = n->GetLeft();
    
    return n;
}

Nodo* BST::Successore(Nodo* n)
{
    //Se esiste figlio destro allora il successore è il minimo del sottoalbero destro
    if(n->GetRight() != nullptr)
        return Minimo(n->GetRight());
    
    //Altrimenti dobbiamo salire e se esiste un nodo minore lo restituiamo
    Nodo* tmp = n->GetParent();
    while(tmp != nullptr)
        if (tmp->GetVeicolo() > n->GetVeicolo())
            return tmp;
    
    return nullptr;
}

void BST::CancellaNodo(Nodo* da_cancellare)
{
    // Controlliamo in che caso ci troviamo andando a vedere quanti figli ha il nodo da cancellare
    Nodo* figlio_sx = da_cancellare->GetLeft();
    Nodo* figlio_dx = da_cancellare->GetRight();
    
    // Caso 1 e 2: il nodo da cancellare non ha figli o ne ha solo uno
    if (figlio_sx == nullptr || figlio_dx == nullptr)
    {
        // Salviamo il figlio (se esiste) del nodo da cancellare
        Nodo* figlio = figlio_sx != nullptr ? figlio_sx : figlio_dx;
        // Salviamo il padre del nodo da cancellare
        Nodo* padre = da_cancellare->GetParent();

        // Se il nodo da cancellare non ha il padre, allora è la radice
        if (padre == nullptr)
            root = figlio;
        else
            // Dobbiamo capire se il nodo da cancellare è figlio sinistro o destro del padre
            if (da_cancellare == padre->GetLeft())
                padre->SetLeft(figlio);
            else
                padre->SetRight(figlio);

        // Il figlio del nodo (se esiste) da cancellare deve avere come nuovo padre il padre del nodo da cancellare
        if (figlio!=nullptr)
            figlio->SetParent(padre);
    }
    else
    {
        // Siamo nel caso 3: il nodo da cancellare ha due figli

        // Troviamo il successore del nodo da cancellare
        Nodo* successore = Successore(da_cancellare);
        // Cancello il successore
        CancellaNodo(successore);
        // Copio il veicolo del successore nel nodo da cancellare
        da_cancellare->SetVeicolo(successore->GetVeicolo());
    }
}

void BST::Elimina(string targa)
{
    //Cerco il nodo per vedere se esiste all'interno dell'albero
    Nodo* nodo_da_eliminare = TrovaNodo(targa);

    // Se non esiste stampo un messaggio di errore
    if(nodo_da_eliminare == nullptr)
    {
        cout << "Veicolo non trovato" << endl;
        return;
    }

    // Altrimenti elimino il nodo
    CancellaNodo(nodo_da_eliminare);
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
