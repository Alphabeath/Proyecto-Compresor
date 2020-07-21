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
        struct nodoAd * getHead();
        void insertFirst(int i);
        void insertLast(int i);
        void removeAtPair(pair<int,int> par, int reemplazo);
        void imprime();
        int size();
        bool isEmpty();
};