/*
Si consideri una classe astratta Veicolo. La classe ha i seguenti attributi privati: 
-	Targa, nome modello, anno di fabbricazione, marca.
La classe ha i seguenti metodi pubblici: 
-	costruttore, get degli attributi
-	un metodo virtuale puro per la stampa
 
Si considerino due classi derivate da Veicolo: Auto e Moto. Ognuna di queste classi implementa il metodo stampa in modo appropriato per il tipo di veicolo. 
La classe Auto ha i seguenti attributi privati: 
-	numero_porte
La classe Moto ha i seguenti attributi privati: 
-	tipo_moto (sportiva, chopper, enduro, ecc)
*/

#include <iostream>
#include <string>
#include "classes.h"
#include "bst.h"

using namespace std;


int main()
{
    Auto panda("1", "Panda FIRE", "Fiat", 1986, 769, 3);
    Auto ferrari("3", "Ferrari Testarossa", "Ferrari", 1984, 4943, 3);
    Moto r3("4", "YZF-R3", "Yamaha", 2014, 249, "Sportiva");
    Auto peugeot("5", "Peugeot 208", "Peugeot", 2019, 1199, 5);
    Moto xlv("6", "Honda Africa Twin 650", "Honda", 1983, 749, "Enduro");

    BST albero;

    albero.Inserisci(&ferrari);
    albero.Inserisci(&panda);
    albero.Inserisci(&peugeot);
    albero.Inserisci(&r3);
    albero.Inserisci(&xlv);
    

    cout << "Verifica la stampa (Pre-Order)" << endl;

    albero.VerificaStampa();

    cout << endl << endl;

    cout << "Stampa in ordine" << endl;
    albero.StampaInOrdine();


    cout << endl << endl;

    cout << "Cerco il veicolo con targa 3" << endl;
    Veicolo* v = albero.TrovaVeicolo("3");
    if (v != nullptr)
        v->Stampa();
    else
        cout << "Veicolo non trovato" << endl;

    cout << endl << endl;
    cout << "Elimino veicolo con targa 3" << endl;
    albero.Elimina("3");

    cout << "Elimino veicolo con targa 5" << endl;
    albero.Elimina("5");

    cout << "Verifica la stampa (Pre-Order)" << endl;
    albero.VerificaStampa();
}