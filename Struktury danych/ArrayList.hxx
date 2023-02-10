#include <cstdlib>
#include <iostream>

using namespace std;
using position_t = int;                             // int dla implementacji tablicowej i kursorowej

class ArrayList {
private:
    int *lista;
    int i;

public:
    ArrayList(int);

    void push_front(int x);                         // Wstawia element na początek listy
    int pop_front();                                // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int x);                          // Wstawia element na koniec listy
    int pop_back();                                 // Usuwa element z końca listy  i zwraca jego wartość
    position_t
    find(int x);                                    // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub -1 gdy nie element istnieje
    void erase(position_t pos);                     // Usuwa element z podanej pozycji
    position_t insert(position_t pos, int x);       // Wstawia element x przed pozycję pos i zwraca pozycję x
    int size();                                     // Zwraca liczbę elementów w liście
    bool empty();                                   // Zwraca `true` gdy lista jest pusta

};

ArrayList::ArrayList(int n) {
    lista = new int[n];
    i = 0;
}

void ArrayList::push_front(int x) {
    {
        for (int j = i; j >= 0; j--) {
            lista[j] = lista[j - 1];
        }
        lista[0] = x;
    }
    i++;
}

int ArrayList::pop_front() {
    int x = lista[0];
    for (int j = 0; j < i; j++) {
        lista[j] = lista[j + 1];
    }
    lista[i] = NULL;
    i--;
    return x;
}

void ArrayList::push_back(int x) {
    lista[i] = x;
    i++;
}

int ArrayList::pop_back() {
    int x = lista[i - 1];
    lista[i - 1] = NULL;
    i--;
    return x;
}

position_t ArrayList::find(int x) {
    for (int j = 0; j < i; j++) {
        if (lista[j] == x) return lista[j];
    }
    return -1;
}

void ArrayList::erase(position_t pos) {
    if (pos == 0) pop_front();
    else if (pos == i) pop_back();
    else if (pos > i)
        cout << "Podana pozycja musi byc mniejsza badz rowna wielkosci listy" << endl;
    else {
        for (int j = pos + 1; j < i; j++) {
            lista[j - 1] = lista[j];
        }
        i--;
    }
}

position_t ArrayList::insert(position_t pos, int x) {
    if (pos == 1) {
        push_front(x);
        return 0;
    } else if (pos == i + 1) {
        push_back(x);
        return i;
    } else if (pos > i) {
        cout << "Podana pozycja musi byc mniejsza badz rowna wielkosci listy" << endl;
        return -1;
    } else {
        for (int j = i; j >= pos; j--) {
            lista[j] = lista[j - 1];
        }
        lista[pos - 1] = x;
        i++;
        return pos - 1;
    }
}

int ArrayList::size() {
    return i;
}

bool ArrayList::empty() {
    return size() == 0;
}
