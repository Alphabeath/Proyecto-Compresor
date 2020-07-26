#include <iostream>
#include <vector>
#include <string>
#include "CompresorRepair.h"
//#define sigma = 40;
using namespace std;

int main()
{
   DoubleLinkedList * Ad = new DoubleLinkedList();
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);

   /*
   Ad->insertLast(7);
   Ad->insertLast(9);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   */
   //cout<<"---- Lista ----"<<endl;
   //Ad->imprime();
   //cout<<"----------"<<endl;
   CompresorRepair *c = new CompresorRepair(Ad);
   //c->versionDirecta();
   Ad->imprime();
   c->versionDirecta();
   //c->imprime();
   //Ad->imprime();
   
   


   return 0;
}