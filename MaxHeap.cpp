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
int MaxHeap::upHeap(int size){
    int i = vec_nh.size();
    while(i > 1){
        int padre = (i - 1)/2;
        if(padre == 0) return i - 1;
        if(vec_nh[padre].frecuencia < vec_nh[i - 1].frecuencia){
            nodoHeap aux = vec_nh[padre];
            vec_nh[padre] = vec_nh[i - 1];
            vec_nh[i - 1] = aux;
            i = padre; 
        }else{
            return i - 1;
        }
    }
    return -1;
}

void MaxHeap::downHeap(int pos){

}

MaxHeap::~MaxHeap(){

}

void MaxHeap::insert(nodoHeap nh){
    vec_nh.push_back(nh);
    if(vec_nh.size() != 1){
        upHeap(vec_nh.size());
    }
}

void MaxHeap::removeMax(){

}

int MaxHeap::size(){
    return mysize;
}

bool MaxHeap::isEmpty(){
    if(mysize > 0)
        return false;
    else
        return true;
}

pair<int,int> MaxHeap::max(){
    return vec_nh.back().par;
}

void MaxHeap::modificaClave(nodoHeap * n, int clave_nueva ){

}

