#include <iostream>
#include <vector>

using namespace std;
/*
### Esercitazione

**Titolo del problema**: "Gestione di un negozio di videogiochi online" 

**Descrizione del problema**: Un negozio di videogiochi online desidera sviluppare un sistema per gestire il carello. 

- Il negozio offre diversi tipi di videogiochi, tra cui giochi per console, giochi per PC e giochi per dispositivi mobili. Ogni tipo di videogioco ha attributi specifici, come il titolo, il genere, il prezzo e la piattaforma supportata.
- Il sistema deve essere in grado di gestire un carello di videogiochi e fornire funzionalità come l'aggiunta di nuovi giochi, la rimozione e la visualizzazione.

**Implementazione**: Per implementare il sistema, è necessario utilizzare le seguenti componenti: 

- Classe astratta "Videogioco": rappresenta un videogioco generico e definisce le funzioni per ottenere informazioni sul titolo, il genere, il prezzo e la piattaforma. Saranno create classi figlie per ogni tipo specifico di videogioco.
- Classi figlie: creare classi figlie derivate dalla classe "Videogioco" per rappresentare i diversi tipi di videogiochi come "GiochiConsole", "GiochiPC" e "GiochiMobile".
- Templates: utilizzare i templates per creare una classe generica "Carrello" che possa contenere oggetti di qualsiasi tipo di videogioco. Il template permetterà di gestire in modo flessibile il contenuto del carrello.
- Overloading degli operatori: sovraccaricare gli operatori per consentire il confronto tra due giochi per vedere se essi siano uguali o meno.
- Vettori: utilizzare vettori per gestire il carrello degli utenti. I vettori consentiranno di gestire in modo dinamico le dimensioni degli inventari e dei carrelli.

Il sistema dovrebbe essere in grado di gestire il carello e le informazioni dei giochi utilizzando classi astratte, classi figlie, templates, overloading degli operatori e vettori.

*/

class Videogioco
{
    protected:
        string titolo;
        string genere;
        float prezzo;
        string piattaforma;

    public:
        Videogioco(string titolo, string genere, 
                float prezzo, string piattaforma):
                titolo(titolo), genere(genere), 
                prezzo(prezzo), piattaforma(piattaforma) {};
        
        string GetTitolo() const { return titolo;}
        string GetGenere() const { return genere;}
        float GetPrezzo() const { return prezzo;}
        string GetPiattaforma() const { return piattaforma;}

        // friend bool operator==(Videogioco& g1, Videogioco& g2);
        bool operator==(const Videogioco* g2);
        virtual ~Videogioco() = 0;
};
Videogioco::~Videogioco() {};

bool Videogioco::operator==(const Videogioco* g2)
{
    cout << "== Sono in Videogioco" << endl;
    if (this->titolo == g2->GetTitolo() &&
        this->genere == g2->GetGenere() &&
        this->piattaforma == g2->GetPiattaforma())
        return true;
    
    return false;
};

class GiochiPc : public Videogioco{
    public:
        GiochiPc(string titolo, string genere, 
                float prezzo, string piattaforma):
                Videogioco(titolo, genere, prezzo, piattaforma) {}; 
};

class GiochiConsole : public Videogioco
{
    public:
        GiochiConsole(string titolo, string genere, 
                float prezzo, string piattaforma):
                Videogioco(titolo, genere, prezzo, piattaforma) {};
};

class GiochiMobile : public Videogioco
{
    public:
        GiochiMobile(string titolo, string genere, 
                float prezzo, string piattaforma):
                Videogioco(titolo, genere, prezzo, piattaforma) {};
};



template <typename T>
class Carrello
{
    private:
        vector<T*> giochi;
    
    public:
        Carrello() {};
        void AggiungiGioco(T* g);
        void RimuoviGioco(T* g);
        void StampaCarrello();
        ~Carrello();
};

template <typename T>
void Carrello<T>::AggiungiGioco(T* g)
{
    giochi.push_back(g);
}

template <typename T>
void Carrello<T>::StampaCarrello()
{
    for (T* g : giochi)
        cout << g->GetTitolo() << endl;
}

bool SonoUguali(Videogioco* g1, Videogioco* g2)
{
    if (g1->GetTitolo() == g2->GetTitolo() &&
        g1->GetGenere() == g2->GetGenere() &&
        g1->GetPiattaforma() == g2->GetPiattaforma())
        return true;
    
    return false;
}

template <typename T>
void Carrello<T>::RimuoviGioco(T* gioco)
{
    for (int i = 0; i < giochi.size(); i++)
        // if (SonoUguali(giochi[i], gioco))
        // if (giochi[i]->operator==(gioco))
        if (*giochi[i] == (const T*)gioco)
        {
            giochi.erase(giochi.begin() + i);
            break;
        }
}

template <typename T>
Carrello<T>::~Carrello()
{
    for (T* g : giochi)
        delete g;
}

int main()
{

    Carrello<Videogioco> c2;

    c2.AggiungiGioco(new GiochiPc("GTA V", "Azione", 59.99, "PC"));
    c2.AggiungiGioco(new GiochiMobile("Clash Royale", "Strategia", 0, "Mobile"));
    c2.AggiungiGioco(new GiochiPc("The Witcher 3", "Azione", 59.99, "PC"));

    cout << "Stampa carrello Videogiochi" << endl;
    c2.StampaCarrello();

    cout << endl<< endl;
    c2.RimuoviGioco(new GiochiPc("Clash Royale", "Strategia", 0, "Mobile"));

    cout << "Stampa carrello Videogiochi" << endl;
    c2.StampaCarrello();

    return 0;
}