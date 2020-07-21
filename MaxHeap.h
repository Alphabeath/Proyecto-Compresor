#include <bits/stdc++.h>

using namespace std;

struct nodoHeap{
    int frecuencia;
    int posicion;
    pair<int,int> par;
};

class MaxHeap{
    private:   
        int mysize;
        vector<nodoHeap *> vec_nh;
        void upHeap(int pos);
        void heapSwap(int a,int b);
        void downHeap(int pos);
    public:
        MaxHeap();
        ~MaxHeap();
        void insert(nodoHeap * nh);
        pair<int,int> removeMax();
        int size();
        bool isEmpty();
        pair<int,int> max();
        void modificaClave(int pos, bool aumenta);
        void imprime();
};