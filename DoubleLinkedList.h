#include <bits/stdc++.h>

using namespace std;

struct nodo{
    nodo * siguiente;
    nodo * anterior;
    nodo * ocurrencia_siguiente;
    nodo * ocurrencia_anterior; 
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
        void removeAtPair(pair<int,int> par, int reemplazo);
        void llenaMap(map<pair<int,int>,int> & mapa);
        void revisaPares(map<pair<int,int>,int> & mapa);
        pair<pair<int,int>,int> buscaMayor(map<pair<int,int>,int> &mapa);
        void imprime();
        int size();
        bool isEmpty();
};