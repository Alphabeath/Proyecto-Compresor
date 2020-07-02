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
        int upHeap(int pos);
        void downHeap(int pos);
    public:
        MaxHeap();
        ~MaxHeap();
        void insert(nodoHeap nh);
        void removeMax();
        int size();
        bool isEmpty();
        pair<int,int> max();
        void modificaClave(nodoHeap * n, int clave_nueva);
        void imprime();
};