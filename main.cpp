#include <iostream>
#include <vector>
#include <string>
#include "CompresorRepair.h"
//#define sigma = 40;
using namespace std;

void ciclo(int max, int i){
   srand(time(NULL));
   DoubleListAdvanced * Ad = new DoubleListAdvanced();
   DoubleListAdvanced * aucs = new DoubleListAdvanced();
	for(int i = 0; i<max ; ++i){
	   int r = (rand()%2)+1;
	   Ad->insertLast(r);
	   aucs->insertLast(r);
	}
   CompresorRepair * c = new CompresorRepair(Ad);
	Ad->imprimeResumido();
  	c->versionAvanzada();
  	aucs->imprimeResumido();
   Ad->imprimeResumido();
   cout<<" ----- separador ----- ("<<i<<")"<<endl;
}

int main(){
   
   int random;
	cout<<"Random?"<<endl<<"Si (1)"<<endl<<"No (2)"<<endl;
	cin>>random;
	int max, op;
	cout<<"inserte la cantidad de numeros a insertar"<<endl;
   cin>>max;
    cout<<"Version Avanzada (1)"<<endl<<"Version Directa (2)"<<endl;
    cin>>op;
    cout<<endl;
    CompresorRepair * c;
    DoubleLinkedList * d = new DoubleLinkedList();
    DoubleListAdvanced * Ad = new DoubleListAdvanced();
    if(op == 1)
    	c = new CompresorRepair(Ad);
    
    if(op == 2)
    	c = new CompresorRepair(d);
    
	if(random == 1){
		srand(time(NULL));
		if(op == 1){
			DoubleListAdvanced * aucs = new DoubleListAdvanced();
			for(int i = 0; i<max ; ++i){
				int r = (rand()%5)+1;
				Ad->insertLast(r);
				aucs->insertLast(r);
			}
			Ad->imprimeResumido();
  			c->versionAvanzada();
  			aucs->imprimeResumido();
  			Ad->imprimeResumido();
		}
		if(op == 2){
			for(int i = 0; i<max ; ++i){
				d->insertLast((rand()%26)+1);
			}
			d->imprime();
  			c->versionDirecta();
		}
	}
	if(random == 2){
    	int auxi;
    	if(op == 1){
    		for(int i = 0; i< max ; ++i){
   				cin>>auxi;
   				Ad->insertLast(auxi);
  			}
  			Ad->imprime();
  			c->versionAvanzada();
    	}
    	if(op == 2){
   			for(int i = 0; i< max ; ++i){
   				cin>>auxi;
   				d->insertLast(auxi);
  			}
  			d->imprime();
  			c->versionDirecta();
		}
	}

   /*
	int max, op, pruebas;
   op=0;
	cout<<"inserte la cantidad de numeros a insertar"<<endl;
   cin>>max;
   cout<<"ingrese cantidad de pruebas"<<endl;
   cin>>pruebas;
   int i = 0;
   while(op < pruebas){
      ciclo(max,i);
      ++op;
      ++i;
   }
   */
   /*
   DoubleListAdvanced * Ad = new DoubleListAdvanced();
   Ad->insertLast(1);
   Ad->insertLast(3);
   Ad->insertLast(4);
   Ad->insertLast(1);
   Ad->insertLast(5);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(4);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(4);
   Ad->insertLast(5);
   Ad->insertLast(3);
   Ad->insertLast(4);
   Ad->insertLast(1);
   Ad->insertLast(3);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(3);
   Ad->insertLast(4);
   Ad->insertLast(3);
   Ad->insertLast(4);
   Ad->insertLast(4);
   Ad->insertLast(4);
   Ad->insertLast(1);
   Ad->insertLast(4);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(1);
   Ad->insertLast(1);
   Ad->insertLast(2);
   Ad->insertLast(3);
   Ad->insertLast(2);
   Ad->insertLast(2);
   Ad->insertLast(5);
   Ad->insertLast(3);
   Ad->insertLast(2);
   Ad->insertLast(5);
   Ad->insertLast(5);
   CompresorRepair *c = new CompresorRepair(Ad);
   Ad->imprime();
   c->versionAvanzada();
   */
   return 0;
}