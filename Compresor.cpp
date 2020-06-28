#include "Compresor.h"

Compresor::Compresor(){
    d = new DoubleLinkedList();
}

Compresor::~Compresor(){
    delete d;
}