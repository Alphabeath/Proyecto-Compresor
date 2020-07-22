#include "CompresorRepair.h"

CompresorRepair::CompresorRepair(DoubleLinkedList * lista){
    sigma = 27;
    d = lista;
}

CompresorRepair::CompresorRepair(DoubleListAdvanced * lista){
    sigma = 27;
    Ad = lista;
}

CompresorRepair::~CompresorRepair(){
    delete Ad;
    delete d;
}

void CompresorRepair::versionDirecta(){
    bool bandera = true;
    int j = 1;
    while(bandera){
        if(d->size() > 3){
            d->llenaMap(mapa);
            d->revisaPares(mapa);
            pair<pair<int,int>,int> par = d->buscaMayor(mapa);
            if(par.second > 1){
                pair<int,int> aux = par.first;
                d->removeAtPair(aux,sigma + j);
                ++j;
            }else{
                bandera = false;
            }
            d->imprime();
            mapa.clear();
        }else{
            bandera = false;
        }
    }    
    //for (map<pair<int,int>,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
        //cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor :"<< it ->second<<endl;
}

void CompresorRepair::versionAvanzada(){
    if(Ad->size() > 2){
        bool bandera = true;;
        pair<int,int> auxI;
        pairOfMap auxP;
        nodoHeap * auxH;
        nodoAd * uno = Ad->getHead()->siguiente;
        nodoAd * dos = Ad->getHead()->siguiente->siguiente;
        for(int i = 0; i<Ad->size()-1; ++i){
            auxI.first = uno->n;
            auxI.second = dos->n;
            map<pair<int,int>,pairOfMap>::iterator it;
	        it = mapaAvanzado.find(auxI);
	        if(it == mapaAvanzado.end()){
                auxP.primera_ocurrencia = uno;
                auxP.ultima_ocurrencia = uno;
                auxH = new nodoHeap();
                auxH->frecuencia = 1;
                auxH->par = auxI;
                auxP.nodoDelHeap = auxH;
                mapaAvanzado.insert(pair<pair<int,int>,pairOfMap>(auxI,auxP));
                mh.insert(auxH);
            }else{
                it->second.ultima_ocurrencia->ocurrencia_siguiente = uno;
                uno->ocurrencia_anterior = it->second.ultima_ocurrencia;
                it->second.ultima_ocurrencia = uno;
                mh.modificaClave(it->second.nodoDelHeap->posicion,true);
            }
            uno = dos;
            dos = dos->siguiente;
        }
        int j = 1;
        while(bandera){
            if(mh.max() >= 2){
                pair<int,int> parAux = mh.removeMax();
                nodoAd * auxAd = mapaAvanzado.at(parAux).primera_ocurrencia;
                nodoAd * nuevoAd = new nodoAd();
                nuevoAd->anterior = auxAd->anterior;
                nuevoAd->siguiente = auxAd->siguiente->siguiente;
                nuevoAd->n = sigma + j;
                auxAd->anterior->siguiente = nuevoAd;
                auxAd->siguiente->siguiente->anterior = nuevoAd;
                delete auxAd->siguiente;
                delete auxAd;
                map<pair<int,int>,pairOfMap>::iterator it;
                if(nuevoAd->anterior!=NULL){
                    pair<int,int> parAnt;
                    parAnt.first = nuevoAd->anterior->n;
                    parAnt.second = nuevoAd->n;
                    it = mapaAvanzado.find(parAnt);
	                if(it == mapaAvanzado.end()){
                        nodoHeap * auxHeap = new nodoHeap();
                        auxHeap->par = parAnt;
                        auxHeap->frecuencia = 1;
                        
                        mh.insert(auxHeap);
                    }else{
                        mh.modificaClave(it->second.nodoDelHeap->posicion, true);
                        
                    }   
                }
                if(nuevoAd->siguiente != NULL){
                    pair<int,int> parSig;
                    parSig.first = nuevoAd->n;
                    parSig.second = nuevoAd->siguiente->n;
                    it = mapaAvanzado.find(parSig);
	                if(it == mapaAvanzado.end()){
                        auxP.primera_ocurrencia = nuevoAd;
                        auxP.ultima_ocurrencia = nuevoAd;
                        nodoHeap * auxHeap = new nodoHeap();
                        auxHeap->par = parSig;
                        auxHeap->frecuencia = 1;
                        auxP.nodoDelHeap = auxHeap;
                        mapaAvanzado.insert(pair<pair<int,int>,pairOfMap>(parSig,auxP));
                        mh.insert(auxHeap);
                    }else{


                        it->second.ultima_ocurrencia->ocurrencia_siguiente = nuevoAd;
                        
                        
                        
                        uno->ocurrencia_anterior = it->second.ultima_ocurrencia;
                        it->second.ultima_ocurrencia = uno;
                        mh.modificaClave(it->second.nodoDelHeap->posicion, true);
                    }
                }
                ++j;
            }else{
                bandera = false;
            }
        }
    }
    
}

void CompresorRepair::imprime(){
    //mh.imprime();
    /*
    cout<<"-- mapa --"<<endl;
    map<pair<int,int>,pairOfMap>::iterator it;
    it= mapaAvanzado.begin();
    while(it!= mapaAvanzado.end()){
        cout<<"("<< it->first.first <<","<< it->first.second<<") primera ocurrencia :" << it->second.primera_ocurrencia->i<<"  ultima ocurrencia :"<<it->second.ultima_ocurrencia->i<<endl;
        it++;
    }
    */

}
    
   /*
    nodoHeap * uno = new nodoHeap();
    uno->frecuencia = 5;
    uno->par.first = 1;
    uno->par.second = 2;
    nodoHeap * dos= new nodoHeap();
    dos->frecuencia = 3;
    dos->par.first = 4;
    dos->par.second = 5;
    nodoHeap * tres = new nodoHeap();
    tres->frecuencia = 2;
    tres->par.first = 3;
    tres->par.second = 4;
    nodoHeap * cuatro = new nodoHeap();
    cuatro->frecuencia = 1;
    cuatro->par.first = 2;
    cuatro->par.second = 3;
    nodoHeap * cinco = new nodoHeap();
    cinco->frecuencia = 1;
    cinco->par.first = 1;
    cinco->par.second = 2;
    mh.insert(uno);
    mh.insert(dos);
    mh.insert(tres);
    mh.insert(cuatro);
    mh.insert(cinco);
    mh.imprime();
    mh.modificaClave(1,false);
    mh.imprime();
    mh.modificaClave(1,false);
    mh.imprime();
    mh.modificaClave(3,false);
    mh.imprime();
    mh.modificaClave(3,false);
    mh.imprime();
    cout<<endl;
    mh.modificaClave(6,true);
    mh.imprime();
    mh.modificaClave(6,true);
    mh.imprime();
    mh.modificaClave(6,true);
    mh.imprime();
    mh.modificaClave(5,true);
    mh.imprime();
    */


