#include <cstdlib>
#include <iostream>

using namespace std;

class LinkedList {      // Klasa listy
public:
    struct Node         // Zagnieżdżona klasa węzła
    {
        int x;          // Element przechowywany przez węzeł listy
        Node *prev;     // Wskaźnik do poprzedniego węzła
        Node *next;     // Wskaźnik do kolejnego węzła
    };
    Node *head;         // Wskaźnik do pierwszego węzła
    Node *tail;         // Wskaźnik do ostatniego węzła
    int _size;          // Ew rozmiar listy

    using position_t = Node *;                      // Typ pozycji w liście dla implementacji wskaźnikowej
    LinkedList();

    ~LinkedList();

    void push_front(int x);                         // Wstawia element na początek listy
    int pop_front();                                // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int x);                          // Wstawia element na koniec listy
    int pop_back();                                 // Usuwa element z końca listy  i zwraca jego wartość
    position_t
    find(int x);                                    // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub 'nullptr' gdy nie element istnieje
    position_t erase(position_t pos);               // Usuwa element z podanej pozycji
    position_t insert(position_t pos, int x);       // Wstawia element x przed pozycję pos i zwraca pozycję x
    int size();                                     // Zwraca liczbę elementów w liście
    bool empty();                                   // Zwraca `true` gdy lista jest pusta
    void deleteLinkedList();                        //Kasuje elemnty listy przy użyciu pop_back();
};


LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

LinkedList::~LinkedList() {
    deleteLinkedList();
}

void LinkedList::push_front(int x) {
    Node *node = new Node;
    node->x = x;
    node->prev = nullptr;
    if (_size == 0) {
        node->next = nullptr;
        tail = node;
    } else {
        node->next = head;
        head->prev = node;
    }
    head = node;
    _size++;

}

int LinkedList::pop_front() {
    Node *tymczasowy = head;
    int v = head->x;

    if (_size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    _size--;
    delete tymczasowy;
    return v;
}

void LinkedList::push_back(int x) {
    Node *node = new Node;
    node->x = x;
    node->next = nullptr;
    if (_size == 0) {
        node->prev = nullptr;
        head = node;
    } else {
        node->prev = tail;
        tail->next = node;
    }
    tail = node;
    _size++;
}

int LinkedList::pop_back() {
    Node *tymczasowy = tail;
    int v = tail->x;

    if (_size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {

        tail = tail->prev;
        tail->next = nullptr;
    }
    _size--;
    delete tymczasowy;
    return v;
}


LinkedList::position_t LinkedList::find(int x) {
    Node *tymczasowy = head;
    while (tymczasowy->x != x && tymczasowy->next != nullptr) {
        tymczasowy = tymczasowy->next;
    }
    if (tymczasowy->x == x) return tymczasowy;
    else return nullptr;
}

LinkedList::position_t LinkedList::erase(position_t pos) {
    Node *tymczasowy = pos->next;

    if (pos == head) {
        pop_front();
        return tymczasowy;
    } else if (pos == tail) {
        pop_back();
        return nullptr;
    } else {
        Node *tymczasowy1 = pos->prev;
        Node *tymczasowy2 = pos->next;
        tymczasowy1->next = tymczasowy2;
        tymczasowy2->prev = tymczasowy1;
        delete pos;
    }
    _size--;
    return tymczasowy;
}

LinkedList::position_t LinkedList::insert(position_t pos, int x) {
    Node *node = new Node;
    Node *tymczasowy = pos->prev;
    node->x = x;
    node->next = pos;
    node->prev = pos->prev;
    pos->next = node;
    pos->prev->next = node;
    _size++;
    delete tymczasowy;

    return node;
}

int LinkedList::size() {
    return _size;
}

bool LinkedList::empty() {
    return _size == 0;
}

void LinkedList::deleteLinkedList() {
    int size = _size;
    for (int i = 0; i < size; i++) pop_back();
}
