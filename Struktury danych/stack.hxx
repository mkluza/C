#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int *stos;
    int i;
public:
    Stack(int);

    void push(int);     // Wstawia element x na stos
    int pop();          // Usuwa element ze stosu i zwraca jego wartość
    int &top();         // Zwraca referencję do najmłodszego elementu
    int size();         // Zwraca liczbę elementów na stosie
    bool empty();       // Sprawdza czy stos jest pusty
};

Stack::Stack(int n) {
    stos = new int[n];
    i = 0;
}

bool Stack::empty() {
    if (i == 0) return true;
    else if (i > 0) return false;
}

int &Stack::top() {
    return stos[i];
}

void Stack::push(int x) {
    stos[i] = x;
    i++;
}

int Stack::pop() {
    int y = top();
    stos[y] = '/0';
    i--;
    return y;
}

int Stack::size() {
    return i;
}

