#include <algorithm>
#include <iostream>

using namespace std;

class Heap {
private:
    void heapifyIter(int);    // Wersja iteracyjna
    void heapifyRec(int);     // Wersja rekurencyjna
    int *heap;
    int _size;
    int changes;
    int compares;
public:
    void build(int[], int);

    void push(int x);         // Wstawia element do kopca
    int pop();                // Usuwa element z kopca
    int &top();               // Zwraca referncję do ostatniego elementu
    int size();               // Zwraca liczbę elementów w kopcu
    bool empty();             // Sprawdza czy kopiec jest pusty
    bool check();             // Sprawdza czy właściwość kopca jest zachowana
    void sortRec(int[], int);

    void sortIter(int[], int);

    void print();
};

void Heap::build(int t[], int n) {
    changes = 0;
    compares = 0;
    heap = new int[n];
    _size = 0;

    for (int i = 0; i < n; i++) {
        push(t[i]);
        _size++;
    }

}

void Heap::push(int x) {
    heap[_size] = x;                                    //dodaje nowy wezel

    int s = _size;
    while (s >= 1) {                                    //dopoki sprawdzany wezel jest wiekszy lub rowny 2
        if (heap[s] > heap[(s - 1) / 2]) {              //jesli dodany wezel jest wiekszy od swojego rodzica
            swap(heap[s], heap[(s - 1) / 2]);
            s = (s - 1) / 2;                            //zmniejszam sprawdzany wezel dwukrotnie
        } else break;
    }
}

int Heap::pop() {
    int temp = heap[_size - 1];
    heap[_size] = '\0';
    _size--;
    return temp;
}

int &Heap::top() {
    return heap[_size - 1];
}

int Heap::size() {
    return _size - 1;
}

bool Heap::empty() {
    return _size == 0;
}

bool Heap::check() {
    for (int i = _size / 2; i >= 0; i--) {
        if (heap[i] < heap[2 * i + 1]) return false;            //czy lewe dziecko jest mniejsze od wezla
        if (heap[i] < heap[2 * i + 2]) return false;            //czy prawe dziecko jest mniejsze od wezla
        if (heap[i] > heap[(i - 1) / 2]) return false;          //czy wezel jest mniejszy od rodzica
    }
    return true;
}

void Heap::sortRec(int *tab, int roz) {
    build(tab, roz);                  //zbuduj kopiec

    int s = size();
    for (int i = s; i >= 0; i--)           //dla kazdego wezla kopca
    {
        swap(heap[0], top());              //zamien wartosc korzenia z wartoscia ostatniego elementu
        changes++;
        tab[i] = pop();                    //przepisz wartosc ostatniego elementu (wartosc korzenia) na koniec tablicy
        heapifyRec(
                0);                     //naprawa strukture kopca zaczynajac od korzenia (wartosc najmlodszego elementu)
    }
}

void Heap::sortIter(int *tab, int roz) {
    build(tab, roz);                 //zbuduj kopiec

    int s = size();
    for (int i = s; i >= 0; i--)          //dla kazdego wezla kopca
    {
        swap(heap[0], top());             //zamien wartosc korzenia z wartoscia ostatniego elementu
        changes++;
        tab[i] = pop();                   //przepisz wartosc ostatniego elementu (wartosc korzenia) na koniec tablicy
        heapifyIter(0);                //naprawa strukture kopca zaczynajac od korzenia (wartosc najmlodszego elementu)
    }
}

void Heap::heapifyIter(int x) {

    int s = size();                 //ustaw maxymalna ilosc powtorzen petli
    int i = x;                      //ustaw indeks rodzica do sprawdzenia
    int max_ch;

    do {
        max_ch = 2 * i + 1;                             //ustaw indeks wiekszego z dzieci (domyslnie lewe)

        if (max_ch < s &&                               //sprawdz czy prawe dziecko istnieje
            heap[max_ch + 1] > heap[max_ch])            //sprawdz czy prawe dziecko jest wieksze od lewego
            max_ch++;                                   //zamien indeks wiekszego dziecka na prawe dziecko

        if (max_ch <= s &&                              //sprawdz czy dziecko istnieje
            heap[i] < heap[max_ch])                     //sprawdz czy rodzic jest mniejszy od swojego rodzica
            swap(heap[i], heap[max_ch]);                //zamien rodzica z wiekszym dzieckiem
        changes++;
        i = max_ch;                                     //ustaw indeks rodzica do sprawdzenia, jako indeks wiekszego dziecka
        compares = compares + 2;
    } while (max_ch <
             s);                                        //dopoki nie sprawdzilismy najmniejszego z dzieci (ostatni element)
}

void Heap::heapifyRec(int x) {
    int max = x;                                //ustaw indeks najwiekszego elementu z rodziny (domyslnie rodzic)
    int left_ch = 2 * x + 1;                    //ustaw indeks lewego dziecka
    int right_ch = 2 * x + 2;                   //ustaw indeks prawego dziecka

    if (left_ch <= size() && heap[max] <
                             heap[left_ch])     //sprawdz czy lewe dziecko istnieje i czy jest wieksze od najwiekszego elementu
        max = left_ch;                          //ustaw indeks najwiekszego elementu na lewe dziecko

    if (right_ch <= size() && heap[max] <
                              heap[right_ch])   //sprawdz czy prawe dziecko istnieje i czy jest wieksze od najwiekszego elementu
        max = right_ch;                         //ustaw indeks najwiekszego elementu na lewe dziecko

    if (max != x) {                             //sprawdz czy indeks rodzica jest indeksem najwiekszego elementu
        swap(heap[x], heap[max]);               //zamien rodzica z najwiekszym elementem
        changes++;
        heapifyRec(max);                     //rekurencyjne wywolanie dla najwiekszego elementu
    }
    compares = compares + 3;
}

void Heap::print() {

    cout << endl;
    cout << "Porownania: " << compares << endl;
    cout << "Wymiany: " << changes << endl;

}