#include <iostream>
#include <vector>
#include <string>
#include "DoubleLinkedList.h"
#define sigma = 40;
using namespace std;

int main()
{
   DoubleLinkedList *d = new DoubleLinkedList();
   d->insertFirst(1);
   cout<<"first: "<<d->first()<<endl;
   d->insertFirst(2);
   cout<<"Last: "<<d->last()<<endl;
   d->insertFirst(3);
   cout<<"first: "<<d->first()<<endl;
   d->removeFirst();
   cout<<"first: "<<d->first()<<endl;
   cout<<"Last: "<<d->last()<<endl; 
   d->removeLast();
   cout<<"Last: "<<d->last()<<endl;
   cout<<"size: "<<d->size()<<endl;
}