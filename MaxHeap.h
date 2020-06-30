#include <bits/stdc++.h>

using namespace std;

struct nodoHeap{
    int frecuencia;
    nodoHeap * padre;
    nodoHeap * hijoIzquierdo;
    nodoHeap * hijoDerecho;
    pair<int,int> par;
};

class MaxHeap{
    private:
        int mysize;
        int * arr;
    public:
        MaxHeap(int tam);
        ~MaxHeap();
        void insert();
        void removeMax();
        int size();
        bool isEmpty();
        pair<int,int> max();
        void modificaClave(nodoHeap * n, int clave_nueva);
};