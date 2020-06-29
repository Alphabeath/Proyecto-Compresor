#include "CompresorRepair.h"

CompresorRepair::CompresorRepair(DoubleLinkedList * lista){
    d = lista;
}

CompresorRepair::~CompresorRepair(){
    delete d;
}

void CompresorRepair::versionDirecta(){
    d->llenaMap(mapa);
    d->revisaPares(mapa);
    /*
    Considerar frecuencia mayores estricto que 1 iguales (se soluciona desempatando de izquierda a derecha)
    Considerar frecuencia mayores estricto unica (trivial)
    Considerar caso todas iguales mayores o menores (no hace nada)
    */
    for (map<pair<int,int>,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
        cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor :"<< it ->second<<endl;
}

void CompresorRepair::versionAvanzada(){
    
}

