#include <iostream>
#include <vector>
#include <string>
#include "CompresorRepair.h"
using namespace std;
double ciclo(int max){
   srand(time(NULL));
   DoubleLinkedList * d = new DoubleLinkedList();
	for(int i = 0; i<max ; ++i){
	   d->insertLast((rand()%80)+1);
	}
   CompresorRepair * c = new CompresorRepair(d);
   clock_t start = clock();
   c->versionDirecta();
	clock_t end = clock();
  	return end - start;
}

int main(){
   int mil = 1000;
   int rep = 15;
  	double time;
   double t;
   for(int k = 0; k < 20; k++){
      time = 0;
      cout<<mil<<" --> ";
	   for(int i = 0; i < rep; i++){
         t = ciclo(mil);
		   time += (double)t / CLOCKS_PER_SEC;
      }
	   printf("%.8f\n",time/(double)rep);
      mil = 1000 + mil;
   }
   /*
   DoubleLinkedList * d = new DoubleLinkedList();
   	CompresorRepair *c = new CompresorRepair(d);
   	cout<<"inserte la cantidad de elementos random"<<endl;
   	int cantidad;
   	cin>>cantidad;
	for(int i = 0; i<cantidad ; ++i){
		d->insertLast((rand()%27)+1);
	}

  	double time = 0;
	int rep = 100;
	for(int i = 0; i < rep; i++){
		clock_t start = clock();
		c->versionDirecta();
		clock_t end = clock();
		time += (double)(end - start) / CLOCKS_PER_SEC;
	}
	printf("Tiempo: %.8f\n\n",time/(double)rep);
   */
   return 0;
}