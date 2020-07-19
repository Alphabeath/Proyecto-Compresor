#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    nodoHeap cero;
    cero.frecuencia = 0;
    vec_nh.push_back(cero);
}
void MaxHeap::imprime(){
    for(int i = 0; i< vec_nh.size(); ++i){
        cout<<vec_nh.at(i).frecuencia<<" ";
    }
    cout<<endl;
}
int MaxHeap::upHeap(int pos){
    int i = pos;
    int padre = i/2;
    while(padre > 0){
        if(vec_nh[padre].frecuencia < vec_nh[i].frecuencia){
            nodoHeap aux = vec_nh[padre];
            vec_nh[padre] = vec_nh[i];
            vec_nh[i] = aux;
            i = padre; 
        }else{
            return i;
        }
        padre = i/2;
    }
    return i;
}

void MaxHeap::downHeap(int pos){

}

MaxHeap::~MaxHeap(){

}

void MaxHeap::insert(nodoHeap nh){
    vec_nh.push_back(nh);
    if(vec_nh.size() != 2){
        upHeap(vec_nh.size() - 1);
    }
}

pair<int,int> MaxHeap::removeMax(){
    pair<int,int> par_a_quitar = vec_nh[1].par;
    vec_nh.at(1).frecuencia = -1;

    return par_a_quitar;
}

int MaxHeap::size(){
    return vec_nh.size() - 1;
}

bool MaxHeap::isEmpty(){
    if(vec_nh.size() - 1 > 0)
        return false;
    else
        return true;
}

pair<int,int> MaxHeap::max(){
    return vec_nh.at(1).par;
}

void MaxHeap::modificaClave(nodoHeap * n, int clave_nueva ){

}

