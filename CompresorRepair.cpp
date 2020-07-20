#include "CompresorRepair.h"

CompresorRepair::CompresorRepair(DoubleLinkedList * lista){
    sigma = 27;
    d = lista;
}

CompresorRepair::CompresorRepair(DoubleListAdvanced * lista){
    sigma = 27;
    Ad = lista;

}

CompresorRepair::~CompresorRepair(){
    delete Ad;
    delete d;
}

void CompresorRepair::versionDirecta(){
    bool bandera = true;
    int j = 0;
    while(bandera){
        if(d->size() > 3){
            d->llenaMap(mapa);
            d->revisaPares(mapa);
            pair<pair<int,int>,int> par = d->buscaMayor(mapa);
            if(par.second > 1){
                pair<int,int> aux = par.first;
                d->removeAtPair(aux,sigma + j);
                ++j;
            }else{
                bandera = false;
            }
            d->imprime();
            mapa.clear();
        }else{
            bandera = false;
        }
    }    
    //for (map<pair<int,int>,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
        //cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor :"<< it ->second<<endl;
}

void CompresorRepair::versionAvanzada(){
    nodoHeap uno;
    uno.frecuencia = 2;
    nodoHeap dos;
    dos.frecuencia = 3;
    nodoHeap tres;
    tres.frecuencia = 1;
    nodoHeap cuatro;
    cuatro.frecuencia = 1;
    nodoHeap cinco;
    cinco.frecuencia = 4;
    nodoHeap seis;
    seis.frecuencia = 1;
    nodoHeap siete;
    siete.frecuencia = 1;
    mh.insert(uno);
    mh.insert(dos);
    mh.insert(tres);
    mh.insert(cuatro);
    mh.insert(cinco);
    mh.insert(seis);
    mh.insert(siete);
    mh.imprime();
    pair<int,int> prueba = mh.removeMax();
    cout<<prueba.first<<" "<< prueba.second<<endl;
    mh.imprime();

}

