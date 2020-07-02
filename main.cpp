#include <iostream>
#include <vector>
#include <string>
#include "CompresorRepair.h"
//#define sigma = 40;
using namespace std;

int main()
{
   DoubleLinkedList *d = new DoubleLinkedList();
   d->insertLast(1);
   d->insertLast(2);
   d->insertLast(9);
   d->insertLast(1);
   d->insertLast(2);
   d->insertLast(9);
   d->insertLast(8);

   //d->imprime();
   
   CompresorRepair *c = new CompresorRepair(d);
   //c->versionDirecta();
   c->versionAvanzada();

   return 0;
}