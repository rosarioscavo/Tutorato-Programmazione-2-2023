#include <iostream>

using namespace std;

class Animale
{
    private:
        int eta;
    
    public:
        Animale(int eta) : eta(eta) {}
        int GetEta();
        virtual void FaiVerso();
        void FaiVersoLungo();
};

void Animale::FaiVerso()
{
    cout << "Verso" << endl;
}

void Animale::FaiVersoLungo()
{
    cout << "Verso lungo" << endl;
}

class Gatto : public Animale
{
    public:
        Gatto(int eta) : Animale(eta) {}
        void FaiVerso();
        void FaiVersoLungo();
};

void Gatto::FaiVerso()
{
    cout << "Miao" << endl;
}

void Gatto::FaiVersoLungo()
{
    cout << "Miao lungo" << endl;
}


int Animale::GetEta()
{
    return eta;
}

class Persiano : public Gatto
{
    public:
        Persiano(int eta) : Gatto(eta) {}
        void FaiVerso();
        void FaiVersoLungo();
};

void Persiano::FaiVerso()
{
    cout << "Miao persiano" << endl;
}

void Persiano::FaiVersoLungo()
{
    cout << "Miao lungo persiano" << endl;
}

int main()
{   
    cout << "Animale:" << endl;
    Animale a(5);
    Persiano p(3);
    a.FaiVerso();
    a.FaiVersoLungo();

    cout << endl << endl << "Gatto:" << endl;
    Gatto g(3);
    g.FaiVerso();
    g.FaiVersoLungo();

    cout << endl << endl << "Animale ptr Gatto:" << endl;
    Animale *animale_ptr;
    animale_ptr = new Gatto(1);
    animale_ptr->FaiVerso();
    animale_ptr->FaiVersoLungo();

    cout << endl << endl << "Animale ptr Persiano:" << endl;
    Animale *animale_ptr_pers;
    animale_ptr_pers = new Persiano(1);
    animale_ptr_pers->FaiVerso();
    animale_ptr_pers->FaiVersoLungo();


    cout << endl << endl << "Gatto ptr Persiano:" << endl;
    Gatto *gatto_ptr;
    gatto_ptr = new Persiano(1);
    gatto_ptr->FaiVerso();
    gatto_ptr->FaiVersoLungo();

    return 0;
}