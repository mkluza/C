#include <iostream>
#include "stack.hxx"
#include <chrono>

#define N 160000
using namespace std;

int change = 0;
int compare = 0;

int partition(int tab[], int l, int p) {
    int x = tab[p];                       //ustawiam element wobec ktorego bede sortowal

    int g = l - 1;                        //ustawiam granice czesciowego posortowania


    for (int i = l; i <= p - 1; i++)      //porownuje kolejne elementy tablicy z moim x
    {
        if (tab[i] <= x)                  //jesli element jest mniejszy od x
        {
            g++;                          //przesuwam granice
            swap(tab[g], tab[i]);         //zamieniam elementow porownywany z pierwszym elementem za granica
            change++;
        }
    }
    swap(tab[g + 1], tab[p]);             //zamieniam pierwszy element przed granica z elementem ostatnim (x)

    change++;
    compare++;
    return g + 1;                         //zwracam indeks pierwszego elementu przed granica
}

void quickSort(int tab[], int l, int p) {
    Stack stos(p - l + 1);                   //tworze stos

    stos.push(l);                            //ukladam lewa indeks tablicy na stos
    stos.push(p);                            //ukladam prawy indeks tablicy na stos


    while (!stos.empty())                       //dopoki stos nie jest pusty
    {
        p = stos.pop();                         //sciagam prawy indeks podtablicy ze stosu
        l = stos.pop();                         //sciagam lewy indeks podtablicy ze stosu

        int pivot = partition(tab, l, p);       //ustawiam granice podzialu podtablic

        if (pivot - 1 > l)                      //jesli granica-1 jest wieksza od lewego indeksu podtablicy
        {
            stos.push(l);                    //ukladam lewa indeks podtablicy na stos
            stos.push(pivot - 1);            //ukladam granice-1 (prawy indeks podtablicy) na stos
            compare++;
        }

        if (pivot + 1 < p)                      //jesli granica+1 jest mniejsza od prawego indeksu podtablicy
        {
            stos.push(pivot + 1);            //ukladam granice+1 (lewy indeks podtablicy) na stos
            stos.push(p);                    //ukladam prawy indeks podtablicy na stos
            compare++;
        }
    }
}

int main() {

    int x;
    int *tab = new int[N];
    int n = 0;

    while (cin >> x) {
        tab[n] = x;
        n++;
    }

    quickSort(tab, 0, n - 1);

    cout << "Porownania: " << compare << endl;
    cout << "Zamiany: " << change << endl;


    delete[] tab;

    return 0;
}
