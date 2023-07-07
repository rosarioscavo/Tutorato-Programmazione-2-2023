#include <iostream>
#include "classes.h"
#include "queue.h"

using namespace std;

int main()
{
    // Creazione degli studenti
    Studente studente1(1001, "Mario", "Rossi", 25.5);

    BorsaDiStudio borsa1(880);
    StudenteBorsista studenteBorsista1(1002, "Anna", "Verdi", 28.0, &borsa1);

    Studente studente2(1003, "Luca", "Bianchi", 26.0);
    Studente studente3(1004, "Sara", "Neri", 27.5);

    BorsaDiStudio borsa2(500);
    StudenteBorsista studenteBorsista2(1005, "Marco", "Gialli", 24.0, &borsa2);

    BorsaDiStudio borsa3(600);
    StudenteBorsista studenteBorsista3(1006, "Laura", "Marroni", 29.0, &borsa3);


    Queue coda;

    // Inserimento degli studenti nella coda
    coda.InserisciStudente(&studente1);
    coda.InserisciStudente(&studenteBorsista1);
    coda.InserisciStudente(&studente2);
    coda.InserisciStudente(&studente3);
    coda.InserisciStudente(&studenteBorsista2);
    coda.InserisciStudente(&studenteBorsista3);

    // Stampa coda
    coda.Stampa();

    cout << endl << endl;

    cout << "Elimino i primi due elementi e li inserisco nuovamente" << endl;
    coda.Dequeue();
    coda.Dequeue();
    coda.InserisciStudente(&studente1);
    coda.InserisciStudente(&studenteBorsista1);
    
    // Stampo la coda
    coda.Stampa();
    cout << endl << endl;

    //Pulisci Coda
    cout << "Pulisco la coda (elimino gli studenti con media minore di 25):"<<endl;
    coda.PulisciCoda();

    // Stampo la coda
    cout << endl << "Contenuto coda:" << endl;
    coda.Stampa();
    // Stampo l'importo totale delle borse di studio
    cout << "Importo totale delle borse di studio: " << coda.GetImportoBorsisti() << endl;

    return 0;
}