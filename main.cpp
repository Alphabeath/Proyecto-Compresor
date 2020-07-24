#include <iostream>
#include <vector>
#include <string>
#include "CompresorRepair.h"
//#define sigma = 40;
using namespace std;

int main()
{
   DoubleListAdvanced * Ad = new DoubleListAdvanced();
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(1);

   //cout<<"---- Lista ----"<<endl;
   //Ad->imprime();
   //cout<<"----------"<<endl;
   CompresorRepair *c = new CompresorRepair(Ad);
   //c->versionDirecta();
   c->versionAvanzada();
   //c->imprime();
   //Ad->imprime();
   


   return 0;
}