#include "DoubleListAdvanced.h"

DoubleListAdvanced::DoubleListAdvanced(){
    mysize = 0;
	head = NULL;
    tail = NULL;
}

DoubleListAdvanced::~DoubleListAdvanced(){
    nodoAd *aux1 = head->siguiente;
    nodoAd *aux2 = NULL;
    if(mysize == 1){	
    	delete aux1;
	}else{
		for(int i = 0; i < mysize; ++i){
			aux2 = aux1->siguiente;
			delete aux1;
			aux1 = aux2;
	    }
	}
    delete tail;
	delete head;
}

void DoubleListAdvanced::insertFirst(int i){
    nodoAd *a = new nodoAd();
	a->n = i;
	if(head == NULL){
		head = new nodoAd();
        tail = new nodoAd();
		head->siguiente = a;
        tail->anterior = a;
        a->siguiente = tail;
        a->anterior = head;
	}else{
		a->siguiente = head->siguiente;
        a->siguiente->anterior = a;
        a->anterior = head;
		head->siguiente = a;
	}
	++mysize;
}

void DoubleListAdvanced::insertLast(int i){
    nodoAd *a = new nodoAd();
	a->n = i;
	if(head == NULL){
		head = new nodoAd();
        tail = new nodoAd();
		head->siguiente = a;
        tail->anterior = a;
        a->siguiente = tail;
        a->anterior = head;
	}else{
		a->siguiente = tail;
        a->anterior = tail->anterior;
        a->anterior->siguiente = a;
		tail->anterior = a;
	}
	++mysize;
}

/*
    Recibe el par a reemplazar, y el entero sigma+1 que sera nuevo nodoAd
    De esta manera borra todas las apariciones del par en la Double Linked List dejando el nuevo nodoAd
    que contiene el entero antes mencionado en su lugar
*/
void DoubleListAdvanced::removeAtPair(pair<int,int> par, int reemplazo){
    //El tamanio debe ser minimo 4, es decir existen al menos 2 pares a reemplazar
    if(mysize > 3){
        nodoAd * aux1 = head->siguiente;
        nodoAd * aux2 = head->siguiente->siguiente;
        nodoAd * nodoAd_r = NULL;
        for(int i = 0; i< mysize - 1;++i){
            if((aux1->n == par.first)&&(aux2->n == par.second)){
                nodoAd_r = new nodoAd();          
                nodoAd_r->n = reemplazo;
                nodoAd_r->anterior = aux1->anterior;
                nodoAd_r->siguiente = aux2->siguiente; 
                aux1->anterior->siguiente = nodoAd_r;
                aux2->siguiente->anterior = nodoAd_r;
                delete aux1;
                delete aux2;
                --mysize;
                aux1 = nodoAd_r->siguiente;
                aux2 = nodoAd_r->siguiente->siguiente;
            }else{
                aux1 = aux2;
                aux2 = aux2->siguiente;
            }
        } 
    }
}

void DoubleListAdvanced::imprime(){
    nodoAd * aux = head;
    for(int i = 0; i< mysize; ++i){
        cout<<aux->siguiente->n<<" ";
        aux = aux->siguiente;
    }
    cout<<endl;
}

pair<pair<int,int>,int> DoubleListAdvanced::buscaMayor(map<pair<int,int>,int> & mapa){
    if(mapa.size() > 1){
        map<pair<int,int>,int>::iterator it=mapa.begin();
        pair<pair<int,int>,int> par;
        par.first = it->first;
        par.second = it->second;
        for (it ; it!=mapa.end(); ++it){
            if(it->second > par.second){
                par.first = it->first;
                par.second = it->second;
            }
        }
        return par;
    }else{
        //nunca caera a este else pero esta seria una forma de hacerlo mas general
        map<pair<int,int>,int>::iterator it=mapa.begin();
        if(mapa.size() == 1){
            pair<pair<int,int>,int> par;
            par.first = it->first;
            par.second = it->second;
            return par;
        }
        pair<pair<int,int>,int> vacio;
        vacio.first.first = 0;
        vacio.first.second = 0;
        vacio.second = 0;
        cout<<"No hay pares para comparar"<<endl;
        return vacio;
    }
}

void DoubleListAdvanced::llenaMap(map<pair<int,int>,int> & mapa){
    if(mysize > 3){
        nodoAd * aux1 = head->siguiente;
        nodoAd * aux2 = aux1->siguiente;
        for(int i = 0; i < mysize - 1; i++){
            mapa[{aux1->n,aux2->n}]; //mapa inicializa el valor de la clave en 0
            aux1 = aux2;
            aux2 = aux2->siguiente;
        }
    }else{
        cout<<"No hay suficientes nodoAds (minimo 2 pares)"<<endl;
    }
}
/*
Metodo que aumenta la frecuencia de las apariciones de un par en la lista,
con estos previamente guardados en un mapa
*/
void DoubleListAdvanced::revisaPares(map<pair<int,int>,int> & mapa){
    if(mysize > 3){
        nodoAd * aux1 = head->siguiente;
        nodoAd * aux2 = aux1->siguiente;
        for(int i = 0;i < mysize - 1;i++){
            ++mapa[{aux1->n,aux2->n}];
            aux1 = aux2;
            aux2 = aux2->siguiente;
        }
    }else{
        cout<<"No hay suficientes nodoAds (minimo 2 pares)"<<endl;
    }
}

int DoubleListAdvanced::size(){
    return mysize;
}
bool DoubleListAdvanced::isEmpty(){
    if(mysize > 0)
        return false;
    else
        return true;
}
