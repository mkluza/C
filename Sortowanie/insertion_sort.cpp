#include <iostream>

using namespace std;

int main() {
    int x;
    int *tab = new int[10];
    int n = 0;
    bool sorted;

    cout << "Wprowadz liczby do posortowania:... ";
    while (cin >> x) {
        tab[n] = x;
        n++;
    }

    for (int i = 1; i < n; i++) {
        int temp = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > temp) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }

    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }

    delete[] tab;

    return 0;
}