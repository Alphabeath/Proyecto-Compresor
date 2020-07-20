#include <bits/stdc++.h>

using namespace std;

struct nodoHeap{
    int frecuencia;
    pair<int,int> par;
};

class MaxHeap{
    private:
        int mysize;
        map<pair<int,int>,pairOfMap> mapaPares;
        vector<nodoHeap> vec_nh;
        void upHeap(int pos);
        void heapSwap(int a,int b);
        void downHeap(int pos);
    public:
        MaxHeap();
        ~MaxHeap();
        void setMap(map<pair<int,int>,pairOfMap> mapa);
        void insert(nodoHeap nh);
        pair<int,int> removeMax();
        int size();
        bool isEmpty();
        pair<int,int> max();
        void modificaClave(int pos, bool aumenta);
        void imprime();
};