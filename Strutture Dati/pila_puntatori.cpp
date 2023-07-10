#include <iostream>

using namespace std;

template <class T>
class Pila
{
    private:
        Pila<T>* next;
        T* ele;
        bool Vuota() { return next == nullptr; };
    public:
        Pila(): next(nullptr), ele(nullptr) { };
        Pila(T& e): next(nullptr), ele(&e) { };
        void Push(T& e);
        T* Pop();
        void Stampa();
        void Distruzione();
};

template <class T>
void Pila<T>::Push(T& e)
{
    // Creare una nuova pila
    Pila<T>* nuova = new Pila<T>(e);

    // La nuova pila deve avere come next la pila che è in cima (this->next)
    nuova->next = this->next;

    // La cima deve avere come next il nuovo nodo
    this->next = nuova;
}

template <class T>
T* Pila<T>::Pop()
{
    // Se la pila è vuota ritorna nullptr
    if(Vuota())
        return nullptr;
    
    // Il nodo che vogliamo eliminare è il nodo che viene dopo la cima (this->next)
    Pila<T>* da_eliminare = this->next;

    // Salviamo il valore dell'elemento che vogliamo eliminare
    T* ele = da_eliminare->ele;

    // La cima deve avere come next il nodo che viene dopo quello che stiamo per eliminare
    this->next = da_eliminare->next;

    // Eliminiamo il nodo
    delete da_eliminare;

    return ele;
}

template <class T>
void Pila<T>::Stampa()
{
    Pila<T>* p = this->next;
    while(p != nullptr)
    {
        cout << *(p->ele) << endl;
        p = p->next;
    }
}

template <class T>
void Pila<T>::Distruzione()
{
    while(!Vuota())
        Pop();
}

template <class T>
void StampaValore(T* e)
{
    if (e == nullptr)
        cout << "nullptr" << endl;
    else
        cout << *e << endl;
}

class A
{
    private:
        int val;
    public:
        A() : val(0) { };
        A(int v) : val(v) { };
        int GetVal() const { return val; };
        friend ostream& operator<<(ostream& os, const A& a) { return os << a.val; };
};

int main()
{
    Pila<int> p;

    cout << " Push 1" << endl;
    int val_1 = 1;
    p.Push(val_1);

    cout << " Push 2" << endl;
    int val_2 = 2;
    p.Push(val_2);

    cout << " Push 5" << endl;
    int val_5 = 5;
    p.Push(val_5);

    cout << "Stampo la pila" << endl;
    p.Stampa();

    cout << " Pop" << endl;
    StampaValore(p.Pop());

    cout << "Stampo la pila" << endl;
    p.Stampa();

    cout << " Pop" << endl;
    StampaValore(p.Pop());

    cout << "Stampo la pila" << endl;
    p.Stampa();

    cout << " Push 10" << endl;
    int val_10 = 10;
    p.Push(val_10);

    cout << "Stampo la pila" << endl;
    p.Stampa();

    // Distruggo la pila
    p.Distruzione();

    return 0;
}