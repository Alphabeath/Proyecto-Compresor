#include <bits/stdc++.h>

using namespace std;

struct nodoAd{
    nodoAd * siguiente;
    nodoAd * anterior;
    nodoAd * ocurrencia_siguiente;
    nodoAd * ocurrencia_anterior; 
    int n; 
};

class DoubleListAdvanced{
    private:
        struct nodoAd * head;
        struct nodoAd * tail;
        int mysize;
    public:
        DoubleListAdvanced();
        ~DoubleListAdvanced();
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