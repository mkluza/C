#include "queue.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int main() {
    int x;
    int *tab = new int[100];
    int n = 0;

    cout << "Wprowadz liczby do posortowania:... ";
    while (cin >> x) {
        tab[n] = x;                 //zapisujemy
        n++;
    }

    cout << "tablica przed sortowaniem" << endl;
    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;

    Queue que[10];                               //tworze tablice 10 kolejek
    int *max = max_element(tab, tab + n);        //szukam najwiekszego elementu
    int p = *max;
    int counter = 0;                             //licznik cyfr w najwiekszym elemencie

    while (p >= 1.0)                             //sprawdzam ilosc cyfr w najwiekszym elemencie
    {
        p = p / 10;
        counter++;
    }


    for (int j = 0; j < counter; j++)            //powtarzam tyle razy ile cyfr ma najwiekszy element
    {
        for (int i = 0; i < n; i++)              //powtarzam tyle razy ile liczb mam posortowac
        {
            int temp = tab[i] / pow(10, j);      //sprawdzam kolejna (liczac od konca) cyfre w liczbie
            que[temp % 10].push(tab[i]);         //dodaje do odpowiedniej kolejki
        }
        int y = 0;
        for (int x = 0; x < 10; x++)             //powtarzam tyle razy ile jest kolejek
        {
            while (!que[x].empty())              //sprawdzam czy kolejka nie jest pusta
            {
                int k = que[x].pop();            //usuwam z kolejki
                tab[y] = k;                      //dodaje do tablicy

                y++;                             //zwiekszam indeks posortowanej tablicy
            }
        }
    }


    cout << "tablica posortowana" << endl;
    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;

    delete[] tab;

    return 0;
}

