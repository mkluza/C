#include <iostream>
#include <algorithm>

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

    int *max = max_element(tab, tab + n);
    int size = *max + 1;
    int histogram[size];
    int sorted[n];

    for (int i = 0; i < size; i++) {
        histogram[i] = 0;
    }
    cout << "wyzerowany" << endl;

    for (int j = 0; j < n; j++) {
        cout << tab[j] << " ";
    }
    cout << "..." << endl;

    for (int i = 0; i < n; i++) {
        histogram[tab[i]]++;
    }

    for (int j = 0; j < size; j++) {
        cout << histogram[j] << " ";
    }

    cout << "..." << endl;

    for (int i = 1;
         i < size; i++)                  //zmiana licznika tak ze zawiera teraz dokladna pozycje danej liczby w outpucie
    {
        histogram[i] = histogram[i] + histogram[i - 1];
    }

    for (int j = 0; j < size; j++) {
        cout << histogram[j] << " ";
    }

    cout << "sortuje..." << endl;

    for (int i = n - 1; i >= 0; i--) {
        sorted[histogram[tab[i]] - 1] = tab[i];
        histogram[tab[i]]--;
    }

    for (int j = 0; j < n; j++) {
        cout << sorted[j] << " ";
    }

    delete[] tab;

    return 0;
}