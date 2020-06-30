#include <bits/stdc++.h>
#include "DoubleLinkedList.h"
#include "MaxHeap.h"

using namespace std;

struct pairOfMap{
    nodo * primera_ocurrencia;
    nodo * ultima_ocurrencia;
    nodoHeap *  nodo_heap_actual;
};

class CompresorRepair{
    private:
        int sigma;
        DoubleLinkedList * d;
        map<pair<int,int>,int> mapa;
        map<pair<int,int>,pairOfMap> mapaAvanzado;

    public:
        CompresorRepair(DoubleLinkedList *lista);
        ~CompresorRepair();
        void versionDirecta();
        void versionAvanzada();
};