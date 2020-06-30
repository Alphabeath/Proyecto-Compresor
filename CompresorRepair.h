#include <bits/stdc++.h>
#include "DoubleLinkedList.h"

using namespace std;

class CompresorRepair{
    private:
        int sigma;
        DoubleLinkedList * d;
        map<pair<int,int>,int> mapa;
    public:
        CompresorRepair(DoubleLinkedList *lista);
        ~CompresorRepair();
        void versionDirecta();
        void versionAvanzada();
};