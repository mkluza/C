#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

//Procedura bezstratnej dekompresji Lempel-Ziv-Welch'a 
//czyta dane ze standardowego wejscia i wypisuje wynik na standardowe wyjscie
void decompress() {

    int dictionary_size = 256;                   //rozmiar naszego podstawowego slownika
    map<int, string> dictionary;                 //slownik (tablica asocjacyjna<kod,znak>)
    for (int i = 0; i < dictionary_size; i++)    //wypelnia podstawowy slownik
    {
        dictionary[i] = string(1, i);
    }


    vector<int> vec;                    //wektor przchowujacy kod do zdekompresowania
    int a;
    while (cin >> a)                    //zczytaj kod dopoki jest co zczytywac
    {
        vec.push_back(a);               //dodaj kod na koniec wektora
    }

    auto begin = vec.begin();           //poczatek wektora (pierwszy element)
    auto end = vec.end();               //koniec wektora (za ostatnim elementem)

    string pk = dictionary[*begin];     //ustaw pk jako znak dla pierwszego kodu
    cout << pk;                         //wypisz pierwszy znak na standardowe wyjscie

    string pc;                          //poczatkowy znak
    for (begin = begin + 1; begin != end; begin++) {
        int k = *begin;                     //kolejny kod z wektora

        if (dictionary.count(k))            //jesli kod istnieje w slowniku
        {
            pc = dictionary[k];             //ustaw poczatkowy znak jako znak dla kodu
        } else if (k == dictionary_size)    //jesli zczytany kod jest rowny wielkosci slownika
        {
            pc = pk +
                 pk[0];                     //ustaw poczatkowy znak jako poprzedni znak(ciag) + pierwszy element poprzedniego znaku(ciagu)
        } else {
            throw "ERROR - wrong input data\n";
        }

        cout << pc;                                        //wypisz poczatkowy znak

        dictionary[dictionary_size++] = pk + pc[0];        //dodaj nowy kod do slownika

        pk = pc;                                           //ustaw pierwszy znak jako poczatkowy znak
    }
    cout << endl;
}

//Funkcja main jedynie wywoluje procedure
int main() {
    decompress();
    return 0;
}
