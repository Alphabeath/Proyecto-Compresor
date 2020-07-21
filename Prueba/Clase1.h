#include <bits/stdc++.h>
#include "Clase2.h"


using namespace std;

struct nodoAd{
    nodoAd * siguiente;
    nodoAd * anterior;
    nodoAd * ocurrencia_siguiente;
    nodoAd * ocurrencia_anterior; 
    int n; 
};


class Clase1{
    private:
        Clase2 *clase_2;
    public:
        Clase1();
        ~Clase1();
        void metodo1();
};