#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList(){
    mysize = 0;
	head = NULL;
    tail = NULL;
}
DoubleLinkedList::~DoubleLinkedList(){
    nodo *aux1 = head->siguiente;
    nodo *aux2 = NULL;
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
void DoubleLinkedList::insertFirst(int i){
    nodo *a = new nodo();
	a->n = i;
	if(head == NULL){
		head = new nodo();
        tail = new nodo();
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
void DoubleLinkedList::insertLast(int i){
    nodo *a = new nodo();
	a->n = i;
	if(head == NULL){
		head = new nodo();
        tail = new nodo();
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
void DoubleLinkedList::removeFirst(){
    if(mysize > 0){
		nodo * aux = head->siguiente;
		head->siguiente = aux->siguiente;
        aux->siguiente->anterior = head;
        delete aux;
		--mysize;
	}
}
void DoubleLinkedList::removeLast(){
    if(mysize > 0){
		nodo * aux = tail->anterior;
		tail->anterior = aux->anterior;
        aux->anterior->siguiente = tail;
        delete aux;
		--mysize;
	}
}
int DoubleLinkedList::first(){
    if(mysize > 0){
        return head->siguiente->n;
    }else{
        return -1;
    }
}
int DoubleLinkedList::last(){
    if(mysize > 0){
        return tail->anterior->n;
    }else{
        return -1;
    }
        
}
int DoubleLinkedList::size(){
    return mysize;
}
bool DoubleLinkedList::isEmpty(){
    if(mysize > 0)
        return false;
    else
        return true;
};
