#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    nodoHeap * cero = new nodoHeap();
    cero->frecuencia = 0;
	cero->posicion = 0;
    vec_nh.push_back(cero);
}

MaxHeap::~MaxHeap(){
	for(int i = 0; i<vec_nh.size(); ++i)
		delete vec_nh[i];
}

void MaxHeap::imprime(){
    for(int i = 0; i< vec_nh.size(); ++i){
        cout<<vec_nh.at(i)->frecuencia<<" ";
    }
	cout<<"pos->>     ";
	for(int i = 0; i< vec_nh.size(); ++i){
        cout<<vec_nh.at(i)->posicion<<" ";
    }
	cout<<"pares->>     ";
	for(int i = 0; i< vec_nh.size(); ++i){
        cout<<"("<<vec_nh.at(i)->par.first<<","<<vec_nh.at(i)->par.second<<")"<<" ";
    }
    cout<<endl;
}

void MaxHeap::heapSwap(int a,int b){
	nodoHeap * aux = vec_nh[a];
	aux->posicion = b;
	vec_nh[b]->posicion = a;
	vec_nh[a] = vec_nh[b];
	vec_nh[b] = aux;

}

void MaxHeap::upHeap(int pos){
    int i = pos;
    int padre = i/2;
    while(padre > 0){
        if(vec_nh[padre]->frecuencia < vec_nh[i]->frecuencia){
            heapSwap(padre,i);
            i = padre; 
        }else{
            return;
        }
        padre = i/2;
    }
}

void MaxHeap::downHeap(int pos){
    int padre = pos;
	int hijo_l = pos*2;
	int hijo_r = (pos*2) + 1;
	int hijo_aux;
	bool bandera = true;
	while(bandera){
		hijo_aux = -1;
		if(hijo_r < vec_nh.size()){
			if(vec_nh.at(hijo_r)->frecuencia > vec_nh.at(hijo_l)->frecuencia){
				hijo_aux = hijo_r;
			}else{
				if(hijo_l < vec_nh.size()){
					hijo_aux = hijo_l;
				}
			}
		}else{
			if(hijo_l < vec_nh.size()){
				hijo_aux = hijo_l;
			}
		}
		if(hijo_aux != -1){
			if(vec_nh.at(padre)->frecuencia < vec_nh.at(hijo_aux)->frecuencia){
				heapSwap(padre,hijo_aux);
				padre = hijo_aux;
				hijo_l = padre*2;
				hijo_r = padre*2 + 1;
				bandera = true;
			}else{
				bandera = false;
			}
		}else{
			bandera = false;
		}
	}
}

void MaxHeap::insert(nodoHeap * nh){
    vec_nh.push_back(nh);
	nh->posicion = vec_nh.size() - 1;
    if(vec_nh.size() > 2){
        upHeap(vec_nh.size() - 1);
    }
}

pair<int,int> MaxHeap::removeMax(){
    pair<int,int> par_a_quitar = vec_nh.at(1)->par;
    if(vec_nh.size() > 3){
		heapSwap(1,vec_nh.size() - 1);
		vec_nh.at(vec_nh.size()-1)->frecuencia = -1;
		downHeap(1);
	}else{
		if(vec_nh.size() == 3){
			heapSwap(1,2);
			vec_nh.at(2)->frecuencia = -1;
		}else{
			if(vec_nh.size() == 2){
				vec_nh.at(1)->frecuencia = -1;
				vec_nh.at(1)->posicion = 1;
			}
		}
	}
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

int MaxHeap::max(){
    return vec_nh.at(1)->frecuencia;
}

void MaxHeap::modificaClave(int pos, bool aumenta){
    if(aumenta){
		++vec_nh[pos]->frecuencia; 
       	upHeap(pos);
	}else{
		--vec_nh[pos]->frecuencia;
		downHeap(pos);
	}
}

