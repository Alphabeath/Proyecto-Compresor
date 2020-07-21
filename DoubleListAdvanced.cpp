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

struct nodoAd * DoubleListAdvanced::getHead(){
    return head;
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


void DoubleListAdvanced::imprime(){
    nodoAd * aux = head;
    for(int i = 0; i< mysize; ++i){
        cout<<aux->siguiente->n<<" ";
        aux = aux->siguiente;
    }
    cout<<endl;
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
