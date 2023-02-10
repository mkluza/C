#include <iostream>

using namespace std;

int main() {
    int x;
    int *tab = new int[10];
    int n = 0;

    cout << "Wprowadz liczby do posortowania:... ";
    while (cin >> x) {
        tab[n] = x;
        n++;
    }

    int min;
    int poz;

    for (int i = 0; i < n; i++) {
        min = tab[i];
        poz = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < min) {
                min = tab[j];
                poz = j;
            }
        }
        tab[poz] = tab[i];
        tab[i] = min;
    }


    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }

    delete[] tab;

    return 0;
}