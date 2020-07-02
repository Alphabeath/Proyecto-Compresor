#include <bits/stdc++.h>
#include "DoubleLinkedList.h"
#include "MaxHeap.h"

using namespace std;

struct pairOfMap{
    nodo * primera_ocurrencia;
    nodo * ultima_ocurrencia;
    int nodoHeap;
};

class CompresorRepair{
    private:
        int sigma;
        DoubleLinkedList * d;
        MaxHeap mh;
        map<pair<int,int>,int> mapa;
        map<pair<int,int>,pairOfMap> mapaAvanzado;

    public:
        CompresorRepair(DoubleLinkedList *lista);
        ~CompresorRepair();
        void versionDirecta();
        void versionAvanzada();
};