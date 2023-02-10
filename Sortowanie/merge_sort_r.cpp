#include <iostream>
#include <chrono>

#define N 160000
using namespace std;

int change = 0;
int compare = 0;

void merge(int tab[], int l, int s, int p) {
    int n1 = s - l + 1;                 //ustawiam nowy zakres lewej tablicy
    int n2 = p - s;                     //ustawiam nowy zakres prawej tablicy

    int L[n1], P[n2];                   //tworze pomocnicze tablice

    for (int i = 0; i < n1; i++)        //uzupelniam lewa tablice
    {
        L[i] = tab[l + i];
    }
    for (int i = 0; i < n2; i++)        //uzupelniam prawa tablice
    {
        P[i] = tab[s + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)            //uzupelniam wlasciwa tablice mniejsza wartoscia z dwoch tablic pomocniczych
    {
        if (L[i] <= P[j]) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = P[j];
            j++;
        }
        k++;
        compare = compare + 3;
        change++;
    }

    while (i < n1)                  //uzupelniam wlasciwa tablice tym co zostało w lewej tablicy
    {
        tab[k] = L[i];
        i++;
        k++;
        change++;
    }
    while (j < n2)                  //uzupelniam wlasciwa tablice tym co zostało w prawej tablicy
    {
        tab[k] = P[j];
        j++;
        k++;
        change++;
    }
}

void mergeSort(int tab[], int l, int p) {
    if (l < p) {                               //sprawdzam czy podany zakres zawiera wiecej niz jeden element
        int s = (l + p - 1) / 2;               //ustawiam srodek zakresu

        mergeSort(tab, l, s);               //rekurencyjnie dla lewej czesci zakresu
        mergeSort(tab, s + 1, p);           //rekurencyjnie dla prawej czesci zakresu

        merge(tab, l, s, p);                  //lacze oba zakresy
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

    mergeSort(tab, 0, n - 1);

    cout << "Porownania: " << compare << endl;
    cout << "Zamiany: " << change << endl;

    delete[] tab;

    return 0;
}
