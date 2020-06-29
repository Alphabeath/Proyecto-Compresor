#include "CompresorRepair.h"

CompresorRepair::CompresorRepair(DoubleLinkedList * lista){
    d = lista;
}

CompresorRepair::~CompresorRepair(){
    delete d;
}

void CompresorRepair::versionDirecta(){
    
    cout<<"size de mapa : "<<mapa.size()<<endl;
    d->llenaMap(mapa);
    for (map<pair<int,int>,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
        cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor :"<< it ->second<<endl;
    cout<<"size de mapa : "<<mapa.size()<<endl;
    
}

void CompresorRepair::versionAvanzada(){
    
}

