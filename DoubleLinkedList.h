#include <bits/stdc++.h>

using namespace std;

struct nodo{
    nodo * siguiente;
    nodo * anterior;
    int n; 
};

class DoubleLinkedList{
    private:
        struct nodo * head;
        struct nodo * tail;
        int mysize;
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void insertFirst(int i);
        void insertLast(int i);
        void removeFirst();
        void removeLast();
        int first();
        int last();
        int size();
        bool isEmpty();
};