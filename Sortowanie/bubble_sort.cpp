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

    do {
        sorted = true;

        for (int j = n - 1; j > 0; j--) {
            if (tab[j - 1] > tab[j]) {
                sorted = false;
                swap(tab[j - 1], tab[j]);
            }
        }
    } while (sorted == false);

    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }

    delete[] tab;

    return 0;
}