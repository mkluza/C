#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Program sluzacy do wyszukiwania lidera zbioru
 */

void lider(int tab[], int n) {
    int lider = tab[0];                     //ustawiamy pierwszy element jako potencjalnego lidera
    int licznik = 1;                        //licznik wystapien potencjalnego lidera

    for (int i = 1; i < n; i++) {           //przechodzimy po kolei cala tablice
        if (licznik > 0) {
            if (tab[i] == lider)            //jesli element taki sam jak potencjalny lider to zwiekszamy licznik
                licznik++;
            else licznik--;                 //jesli nie to zmniejszamy
        } else                              //jesli licznik wyniesie 0 to zmieniamy potencjalnego lidera
        {
            lider = tab[i];
            licznik = 1;
        }
    }

    if (licznik == 0)
        cout << "Ciag nie posiada lidera." << endl;
    else {
        int wystapienia = 0;

        for (int i = 0; i < n; i++) {
            if (tab[i] == lider)
                wystapienia++;
        }

        if (wystapienia > n / 2)               //sprawdzamy czy potencjalny lider jest faktycznym liderem zbioru
            cout << "Liderem ciagu jest liczba " << lider << endl;
        else
            cout << "Ciag nie posiada lidera." << endl;
    }


}

int main() {
    int tab1[] = {2, 5, 2, 1, 2, 2, 5, 3, 2, 2};
    int tab2[] = {3, 4, 1, 6, 3, 4, 4, 4, 1, 9};
    int n = 10;

    cout << "Tablica a:" << endl;
    lider(tab1, n);

    cout << "Tablica b:" << endl;
    lider(tab2, n);

    return 0;
}