#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

//Procedura bezstratnej kompresji Lempel-Ziv-Welch'a 
//czyta dane ze standardowego wejscia i wypisuje wynik na standardowe wyjscie
void compress() {

    int dictionary_size = 256;                      //rozmiar naszego podstawowego slownika
    map<string, int> dictionary;                    //slownik (tablica asocjacyjna<znak,kod>)
    for (int i = 0; i < dictionary_size; i++)       //wypelnia podstawowy slownik
    {
        dictionary[string(1, i)] = i;
    }

    string text;                        //string przchowujacy tekst do skompresowania
    while (1) {
        char ch = getchar();            //zczytaj jeden znak ze standardowego wejscia
        if (ch == -1) break;            //jesli nie ma czego zczytac to wyjdz z petli
        else text = text + ch;          //powieksz tekst o zczytany znak
    }
    text.pop_back();                    //usun znak nowej linii

    string c;                           //poczatkowy znak
    for (string::const_iterator it = text.begin(); it != text.end(); it++) {
        char s = *it;                   //kolejny znak z tekstu
        string cs = c + s;              //dodaj znak do poprzedniego znaku (ciagu znakow)
        if (dictionary.count(cs))
            c = cs;                     //jesli ciag znakow istnieje w slowniku to poczatkowy znak(ciag) = aktualny ciag
        else                            //jesli znak(ciag) nie znajduje sie w slowniku
        {
            cout << dictionary[c] << " ";           //wypisz kod dla poczatkowego znaku(ciagu)

            dictionary[cs] = dictionary_size++;     //dodaj nowy ciag do slownika
            c = string(1, s);                       //poczatkowy znak = ostatni znak nowego ciagu
        }
    }
    cout << dictionary[c] << endl;                  //wypisz kod dla ostatniego znaku(ciagu)

}

//Funkcja main jedynie wywoluje procedure
int main() {
    compress();
    return 0;
}
