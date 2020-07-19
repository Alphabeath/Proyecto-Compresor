#include <bits/stdc++.h>

using namespace std;

struct nodoHeap{
    int frecuencia;
    pair<int,int> par;
};

class MaxHeap{
    private:
        int mysize;
        vector<nodoHeap> vec_nh;
        int upHeap();
        void heapSwap(int a,int b);
        void downHeap();
    public:
        MaxHeap();
        ~MaxHeap();
        void insert(nodoHeap nh);
        pair<int,int> removeMax();
        int size();
        bool isEmpty();
        pair<int,int> max();
        void modificaClave(nodoHeap * n, int clave_nueva);
        void imprime();
};