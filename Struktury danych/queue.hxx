#include <cstdlib>
#include <iostream>
#include <string>

#define N 20

using namespace std;

class Queue {
private:
    int *kolejka;
    int head, tail, n;
public:
    Queue();

    void push(int x);     // Wstawia element x do kolejki (także enqueue)
    int pop();            // Usuwa element z kolejki (także dequeue) i zwraca jego wartość
    int &front();         // Zwraca referencję do najstarszego elementu (także peek)
    int size();           // Zwraca liczbę elementów w kolejce
    bool empty();         // Sprawdza czy kolejka jest pusta
};

Queue::Queue() {
    kolejka = new int[N + 1];
    head = 1;
    tail = 1;
    n = 0;
}

bool Queue::empty() {
    if (head == tail) return true;
    else return false;
}

int &Queue::front() {
    return kolejka[head];
}

void Queue::push(int x) {
    kolejka[tail] = x;
    tail = (tail % N) + 1;
    n++;
}

int Queue::pop() {
    int y = front();
    kolejka[y] = '/0';
    head = (head % N) + 1;
    if (n > 0) n--;
    return y;
}

int Queue::size() {
    return n;
}

