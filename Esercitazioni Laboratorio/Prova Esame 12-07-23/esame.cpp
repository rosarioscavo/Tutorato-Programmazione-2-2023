#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "classes.h"
#include "bst.h"

using namespace std;

void VisitaAlbero(Nodo *nodo, int *sommaEtaStudenti, int *sommaEtaLavoratori, int *sommaEtaPensionati, int *numeroStudenti, int *numeroLavoratori, int *numeroPensionati) {
    if (nodo) {
        
        Persona *p = nodo->GetPersona();
        const string categoria = p->GetCategoria();

        if (categoria == "Studente") {
            *sommaEtaStudenti += p->GetEta();
            (*numeroStudenti)++;
        } else if (categoria == "Lavoratore") {
            *sommaEtaLavoratori += p->GetEta();
            (*numeroLavoratori)++;
        } else if (categoria == "Pensionato") {
            *sommaEtaPensionati += p->GetEta();
            (*numeroPensionati)++;
        }

        VisitaAlbero(nodo->GetLeft(), sommaEtaStudenti, sommaEtaLavoratori, sommaEtaPensionati, numeroStudenti, numeroLavoratori, numeroPensionati);
        VisitaAlbero(nodo->GetRight(), sommaEtaStudenti, sommaEtaLavoratori, sommaEtaPensionati, numeroStudenti, numeroLavoratori, numeroPensionati);
    }
}

void CalcoloMedieEta(BST* albero)
{
    int sommaEtaStudenti = 0;
    int sommaEtaLavoratori = 0;
    int sommaEtaPensionati = 0;
    int numeroStudenti = 0;
    int numeroLavoratori = 0;
    int numeroPensionati = 0;

    VisitaAlbero(albero->GetRoot(), &sommaEtaStudenti, &sommaEtaLavoratori, &sommaEtaPensionati, &numeroStudenti, &numeroLavoratori, &numeroPensionati);

    double mediaStudenti = numeroStudenti > 0 ? sommaEtaStudenti / numeroStudenti : 0;
    double mediaLavoratori = numeroLavoratori > 0 ? sommaEtaLavoratori / numeroLavoratori : 0;
    double mediaPensionati = numeroPensionati > 0 ? sommaEtaPensionati / numeroPensionati : 0;

    cout<< "Età media studenti: " << mediaStudenti << endl;
    cout<< "Età media lavoratori: " << mediaLavoratori << endl;
    cout<< "Età media pensionati: " << mediaPensionati << endl;
};

int GenRandNum(int min, int max)
{
    return min + (rand() % (max-min + 1));
}

int main()
{
    srand(time(0));
    BST bst;

    Studente *studente;
    for (int i = 0; i < 2; i++) {
        bst.Inserisci(new Studente("NomeS" + to_string(i), "CognomeS" + to_string(i), GenRandNum(5,30)));
        bst.Inserisci(new Lavoratore("NomeL" + to_string(i), "CognomeL" + to_string(i), GenRandNum(20,70)));
        bst.Inserisci(new Pensionato("NomeP" + to_string(i), "CognomeP" + to_string(i), GenRandNum(65,95)));
    }

    bst.Stampa();
    CalcoloMedieEta(&bst);

    return 0;
}