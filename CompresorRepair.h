#include <bits/stdc++.h>
#include "DoubleLinkedList.h"
#include "DoubleListAdvanced.h"
#include "MaxHeap.h"

using namespace std;


class CompresorRepair{
    private:
        int sigma;
        DoubleLinkedList * d;
        DoubleListAdvanced * Ad;
        MaxHeap mh;
        map<pair<int,int>,int> mapa;
        map<pair<int,int>,pairOfMap> mapaAvanzado;

    public:
        CompresorRepair(DoubleLinkedList *lista);
        CompresorRepair(DoubleListAdvanced *lista);
        ~CompresorRepair();
        void versionDirecta();
        void versionAvanzada();
};