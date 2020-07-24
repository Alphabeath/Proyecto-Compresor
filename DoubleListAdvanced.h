#include <bits/stdc++.h>

using namespace std;

struct nodoAd{
    nodoAd * siguiente;
    nodoAd * anterior;
    nodoAd * ocurrencia_siguiente;
    nodoAd * ocurrencia_anterior; 
    int n; 
    int i;
};

class DoubleListAdvanced{
    private:
        struct nodoAd * head;
        struct nodoAd * tail;
        int mysize, j;
    public:
        DoubleListAdvanced();
        ~DoubleListAdvanced();
        struct nodoAd * getHead();
        struct nodoAd * getTail();
        void insertFirst(int i);
        void insertLast(int i);
        void imprime();
        int size();
        bool isEmpty();
};