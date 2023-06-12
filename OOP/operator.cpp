#include <iostream>
#include <string.h>

using namespace std;

class Colore
{
    private:
        string name;
    
    public:
        Colore(string name) : name(name) {}
        string getName();
        void setName(string name);
        friend string operator+(Colore& colore1, Colore& colore2); //provare a rimuovere
        friend ostream& operator<< (ostream& output, Colore& colore);
};

string Colore::getName()
{
    return name;
}

void Colore::setName(string name)
{
    this->name = name;
}

string operator+(Colore& colore1, Colore& colore2)
{
    if(colore1.getName()=="rosso" && colore2.getName()=="giallo")
        return "arancione";
    else if (colore1.getName()=="giallo" && colore2.getName()=="rosso")
        return "arancione";
    else if(colore1.getName()=="blu" && colore2.getName()=="giallo")
        return "verde";
    else if(colore1.getName()=="giallo" && colore2.getName()=="blu")
        return "verde";
    else if(colore1.getName()=="rosso" && colore2.getName()=="blu")
        return "viola";
    else if(colore1.getName()=="blu" && colore2.getName()=="rosso")
        return "viola";

    return "errore";
}

ostream& operator<< (ostream& output, Colore& colore)
{
    output << colore.name <<endl;
    return output;
}

int main()
{
    Colore colore_1("giallo");
    Colore colore_2("rosso");
    Colore colore_3("blu");
    
    string nuovo_colore_1 = colore_1 + colore_2;
    string nuovo_colore_2 = colore_2 + colore_3;

    cout << colore_1.getName() << " + " << colore_2.getName() << " = " << nuovo_colore_1 << endl;
    cout << colore_2.getName() << " + " << colore_3.getName() << " = " << nuovo_colore_2 << endl;

    cout << colore_1;
    return 0;
}