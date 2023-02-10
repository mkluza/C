#include <cstdlib>
#include <iostream>

#define NIL -1

using namespace std;
using position_t = int;     // int dla implementacji tablicowej i kursorowej

class CursorList {          // Klasa listy
private:
    struct node             // Zagnieżdżona klasa węzła
    {
        int x;              // Element przechowywany przez węzeł listy
        int next;           // Indeks kolejnego węzła
    };
    node *lista;            // Tablica węzłów
    int head;               // Indeks pierwszego węzła
    int _size;              // Ew. rozmiar listy
    int free;               // Ew. indeks pierwszego nieużytego elementu tablicy
    int s;                  //Rozmiar tablicy (maksymalny rozmiar _size)
public:
    CursorList(int n);

    ~CursorList();

    void push_front(int x);                     // Wstawia element na początek listy
    int pop_front();                            // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int x);                      // Wstawia element na koniec listy
    int pop_back();                             // Usuwa element z końca listy  i zwraca jego wartość
    position_t
    find(int x);                                // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub -1 gdy nie element istnieje
    position_t erase(position_t pos);           // Usuwa element z podanej pozycji
    position_t insert(position_t pos, int x);   // Wstawia element x przed pozycję pos i zwraca pozycję x
    int size();                                 // Zwraca liczbę elementów w liście
    bool empty();                               // Zwraca `true` gdy lista jest pusta
    void print();
};

CursorList::CursorList(int n) {
    lista = new node[n];                    //tworze tablice
    head = NIL;
    _size = 0;
    free = 0;
    s = n;

    for (int i = 0; i < s - 1; i++)         //ustawiam wszystkie elementy jako wolne
    {
        lista[i].x = '/0';
        lista[i].next = i + 1;
    }
    lista[s - 1].x = '/0';
    lista[s - 1].next = NIL;                //ustawiam ostatni element by wskazywal na NIL
}

CursorList::~CursorList() {
    delete[] lista;
}

void CursorList::push_front(int x) {
    if (free == NIL) cout << "NO EMPTY SPACE, FREE == NIL" << endl;

    else if (_size == 0) {
        int temp = lista[free].next;        //zapamietuje drugi wolny element
        lista[free].x = x;
        lista[free].next = NIL;
        head = free;                        //ustawiam pierwszy zajety element
        free = temp;                        //ustawiam nowy (pierwszy) wolny element
    } else {
        int temp = lista[free].next;        //zapamietuje drugi wolny element
        lista[free].x = x;
        lista[free].next = head;
        head = free;                        //ustawiam nowy (pierwszy) zajety element
        free = temp;                        //ustawiam nowy (pierwszy) wolny element
    }
    _size++;
}

int CursorList::pop_front() {
    int v = lista[head].x;
    int temp = lista[head].next;
    lista[head].x = '/0';
    lista[head].next = free;
    free = head;
    head = temp;

    _size--;
    return v;
}


void CursorList::push_back(int x) {
    if (free == NIL) cout << "NO EMPTY SPACE, FREE == NIL" << endl;

    else if (_size == 0) push_front(x);

    else {
        int i = head;

        while (lista[i].next != NIL) {
            i = lista[i].next;
        }

        int temp = lista[free].next;
        lista[i].next = free;
        lista[free].x = x;
        lista[free].next = NIL;
        free = temp;

        _size++;
    }
}

int CursorList::pop_back() {
    if (_size == 1) return pop_front();

    int v;
    int i = head;
    int j = head;
    bool a = true;
    bool b = true;

    while (a || b) {
        if (a && lista[i].next == NIL) {
            v = lista[i].x;
            lista[i].x = '/0';
            lista[i].next = free;
            free = i;
            a = false;
        } else if (a) i = lista[i].next;

        if (b && lista[j].next == free) {
            lista[j].next = NIL;
            b = false;
        } else if (b) j = lista[j].next;
    }

    _size--;
    return v;
}

position_t CursorList::find(int x) {
    int i = head;

    if (_size == 0) return -1;
    else {
        for (int j = 0; j <= _size; j++) {
            if (lista[i].x == x) return 1;
            else i = lista[i].next;
        }
        return -1;
    }
}

position_t CursorList::erase(position_t pos) {
    if (_size == 0) cout << "EMPTY" << endl;
    else if (pos < 0 || pos >= s) cout << "WRONG POSITION" << endl;
    else if (lista[pos].x = '/0') cout << "POSITION IS EMPTY" << endl;
    else if (pos == head) {
        int v = lista[pos].next;
        pop_front();
        return v;
    } else {
        int i = lista[head].next;
        for (int j = 0; j <= _size; j++) {
            if (lista[i].next == NIL && pos == i) {
                int v = lista[pos].next;
                pop_back();
                return v;
            } else if (pos == i) {
                int temp = lista[i].next;
                lista[i].x = '/0';
                lista[i].next = free;
                free = i;

                int k = head;
                bool a = true;
                while (a) {
                    if (lista[k].next == free) {
                        lista[k].next == temp;
                        a = false;
                    } else k = lista[k].next;
                }
                _size--;
                return temp;
            } else i = lista[i].next;
        }
    }
}

position_t CursorList::insert(position_t pos, int x) {
    if (free == NIL) cout << "NO EMPTY SPACE, FREE == NIL" << endl;
    else if (pos < 0 || pos > s) cout << "WRONG POSITION" << endl;
    else if (pos == head) {
        push_front(x);
        return NIL;
    } else {
        int i = head;
        while (1) {
            if (i == pos) {
                int temp = lista[free].next;
                lista[free].x = x;
                lista[free].next = lista[i].next;
                lista[i].next = free;
                free = temp;
                return lista[i].next;
            } else i = lista[i].next;
        }


    }
}

int CursorList::size() {
    return _size;
}

bool CursorList::empty() {
    return _size == 0;
}

void CursorList::print() {
    cout << "\t\t\t*****************************************" << endl;
    cout << "\t\t\thead: " << head << endl;
    cout << "\t\t\tfree: " << free << endl;
    cout << "\t\t\tsize: " << _size << endl;
    cout << "\t\t\t******************************************" << endl;
}
