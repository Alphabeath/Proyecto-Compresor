#include "CompresorRepair.h"

CompresorRepair::CompresorRepair(DoubleLinkedList * lista){
    sigma = 27;
    d = lista;
}

CompresorRepair::CompresorRepair(DoubleListAdvanced * lista){
    sigma = 100;
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
            mapa.clear();
        }else{
            bandera = false;
        }
    }     
}

void CompresorRepair::versionAvanzada(){
    if(Ad->size() > 2){
        bool bandera = true;
        pair<int,int> auxI;
        pairOfMap auxP;
        nodoHeap * auxH;
        nodoAd * nodoHead = Ad->getHead();
        nodoAd * nodoTail = Ad->getTail();
        nodoAd * uno = nodoHead->siguiente;
        nodoAd * dos = nodoHead->siguiente->siguiente;
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
                if(uno != it->second.ultima_ocurrencia->siguiente){
                    it->second.ultima_ocurrencia->ocurrencia_siguiente = uno;
                    uno->ocurrencia_anterior = it->second.ultima_ocurrencia;
                    it->second.ultima_ocurrencia = uno;
                    mh.modificaClave(it->second.nodoDelHeap->posicion,true);
                }
            }
            uno = dos;
            dos = dos->siguiente;
        }
        int j = 1;
        while(bandera){
            if(mh.max() >= 2){
                /*
                    Removemos el par que tiene mayor frecuencia en el heap
                */
                pair<int,int> parAux = mh.removeMax();  
                /*
                    Obtenemos el puntero de la primera ocurrencia en la listaAvanzada
                */
                nodoAd * auxAd = mapaAvanzado.at(parAux).primera_ocurrencia;
                
                while(auxAd != NULL){
                    /*
                        Verificamos la existencia de pares contiguos al nodo a reemplazar (nodo sigma + j)
                    */
                    map<pair<int,int>,pairOfMap>::iterator it;
                    if((auxAd->anterior != NULL)&&(auxAd->anterior != nodoHead)){
                        pair<int,int> auxAdAnt;
                        auxAdAnt.first = auxAd->anterior->n;
                        auxAdAnt.second = auxAd->n;
                        it = mapaAvanzado.find(auxAdAnt);
                        if((it->second.primera_ocurrencia->siguiente == auxAd)||(it->second.ultima_ocurrencia->siguiente == auxAd)){
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            se la primera o la ultima ocurrencia de si mismo, se actualizan 
                            los punteros del mapa y de la lista avanzada
                            */
                            if(it->second.primera_ocurrencia->siguiente == auxAd){
                                if(it->second.primera_ocurrencia->ocurrencia_siguiente != NULL){
                                    it->second.primera_ocurrencia->ocurrencia_siguiente->ocurrencia_anterior = NULL;
                                    it->second.primera_ocurrencia = it->second.primera_ocurrencia->ocurrencia_siguiente;
                                }
                            }
                            if(it->second.ultima_ocurrencia->siguiente == auxAd){
                                if(it->second.ultima_ocurrencia->ocurrencia_anterior != NULL){
                                    it->second.ultima_ocurrencia->ocurrencia_anterior->ocurrencia_siguiente = NULL;
                                    it->second.ultima_ocurrencia = it->second.ultima_ocurrencia->ocurrencia_anterior;
                                }
                            }
                        }else{
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            no sea la primera o la ultima ocurrencia de si mismo, se  
                            actualizan solo los punteros de la lista avanzada
                            */
                            
                            if(auxAd->anterior->ocurrencia_anterior != NULL)
                                auxAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = auxAd->anterior->ocurrencia_siguiente;
                            if(auxAd->anterior->ocurrencia_siguiente != NULL)
                                auxAd->anterior->ocurrencia_siguiente->ocurrencia_anterior = auxAd->anterior->ocurrencia_anterior;
                        }
                        if((auxAd->anterior->n != auxAd->anterior->anterior->n)||(auxAd->n != auxAd->anterior->n)){
                            mh.modificaClave(it->second.nodoDelHeap->posicion,false);
                        }else{
                            if(auxAd->anterior->ocurrencia_anterior != NULL){
                                if(auxAd->anterior->ocurrencia_siguiente != NULL){
                                    if(auxAd->anterior->ocurrencia_anterior->siguiente->siguiente == auxAd->anterior){
                                        auxAd->anterior->ocurrencia_anterior = NULL;
                                        mh.modificaClave(it->second.nodoDelHeap->posicion,false);
                                    }
                                }
                            }
                        }
                    }
                    if((auxAd->siguiente->siguiente != NULL)&&(auxAd->siguiente->siguiente != nodoTail)){
                        pair<int,int> auxAdSig;
                        auxAdSig.first = auxAd->siguiente->n;
                        auxAdSig.second = auxAd->siguiente->siguiente->n;
                        it = mapaAvanzado.find(auxAdSig);
                        if((it->second.primera_ocurrencia == auxAd->siguiente)||(it->second.ultima_ocurrencia == auxAd->siguiente)){
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            se la primera o la ultima ocurrencia de si mismo, se actualizan 
                            los punteros del mapa y de la lista avanzada
                            */
                            if(it->second.primera_ocurrencia == auxAd->siguiente){
                                if(it->second.primera_ocurrencia->ocurrencia_siguiente != NULL){
                                        it->second.primera_ocurrencia->ocurrencia_siguiente->ocurrencia_anterior = NULL;
                                        it->second.primera_ocurrencia = it->second.primera_ocurrencia->ocurrencia_siguiente;
                                }
                            }
                            if(it->second.ultima_ocurrencia == auxAd->siguiente){
                                if(it->second.ultima_ocurrencia->ocurrencia_anterior != NULL){
                                        it->second.ultima_ocurrencia->ocurrencia_anterior->ocurrencia_siguiente = NULL;
                                        it->second.ultima_ocurrencia = it->second.ultima_ocurrencia->ocurrencia_anterior;
                                }
                            }
                        }else{
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            no sea la primera o la ultima ocurrencia de si mismo, se  
                            actualizan solo los punteros de la lista avanzada
                            */
                            if((auxAd->n != auxAd->siguiente->n)||(auxAd->siguiente->n != auxAd->siguiente->siguiente->n)){
                                if(auxAd->siguiente->ocurrencia_anterior != NULL)
                                    auxAd->siguiente->ocurrencia_anterior->ocurrencia_siguiente = auxAd->siguiente->ocurrencia_siguiente;
                                if(auxAd->siguiente->ocurrencia_siguiente != NULL)
                                    auxAd->siguiente->ocurrencia_siguiente->ocurrencia_anterior = auxAd->siguiente->ocurrencia_anterior;
                            }
                        }
                        bool caso_final_triple = false;
                        if(auxAd->siguiente->siguiente != nodoTail){
                            if(auxAd->siguiente->siguiente->siguiente != NULL){
                                if((auxAd->siguiente->n == auxAd->siguiente->siguiente->n)&&(auxAd->siguiente->siguiente->n == auxAd->siguiente->siguiente->siguiente->n)&&(auxAd->siguiente->siguiente->siguiente->siguiente == nodoTail)){
                                    if(auxAd->siguiente->ocurrencia_anterior != NULL){
                                        auxAd->siguiente->ocurrencia_anterior->ocurrencia_siguiente = auxAd->siguiente->siguiente; 
                                        caso_final_triple == true;
                                    }
                                }
                            }
                        }
                        if((caso_final_triple == false)&&(auxAd->n != auxAd->siguiente->n)||(auxAd->siguiente->n != auxAd->siguiente->siguiente->n)){
                            mh.modificaClave(it->second.nodoDelHeap->posicion,false); 
                        }
                    }
                    /*
                        Inicializamos el nuevo puntero sigma +j de la lista avanzada
                    */
                    nodoAd * nuevoAd = new nodoAd();
                    nuevoAd->anterior = auxAd->anterior;
                    nuevoAd->siguiente = auxAd->siguiente->siguiente;
                    
                    nuevoAd->n = sigma + j;
                    /*
                        Actualizamos los nodos que estan justo antes y despues del par
                    */
                    if(auxAd->ocurrencia_siguiente!=NULL){
                        auxAd->ocurrencia_siguiente->ocurrencia_anterior = NULL;
                    }
                    auxAd->anterior->siguiente = nuevoAd;
                    auxAd->siguiente->siguiente->anterior = nuevoAd;
                    /*
                        Borramos el par que vamos a reemplazar por el nodo sigma + j
                    */
                    delete auxAd->siguiente;
                    nodoAd * auxDelete = auxAd;
                    auxAd = auxAd->ocurrencia_siguiente;
                    delete auxDelete;
                    /*
                        Si existe un nodo anterior al par a reemplazar creamos un nuevo par
                        o aumentamos la frecuencia en caso que vuelva a coincidir
                    */
                    if((nuevoAd->anterior!=NULL)&&(nuevoAd->anterior != nodoHead)){
                        pair<int,int> parAnt;
                        parAnt.first = nuevoAd->anterior->n;
                        parAnt.second = nuevoAd->n;
                        it = mapaAvanzado.find(parAnt);
	                    if(it == mapaAvanzado.end()){
                            /*
                                Se inicializa la estructura pairOfMap correspondiente al valor en el mapa
                            */
                            
                            if((nuevoAd->anterior->ocurrencia_anterior != NULL)&&(nuevoAd->anterior->ocurrencia_siguiente != NULL)){
                                if((nuevoAd->anterior->ocurrencia_anterior->siguiente->n != nuevoAd->n)&&(nuevoAd->anterior->ocurrencia_siguiente->siguiente->n != nuevoAd->n)){
                                    nuevoAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = nuevoAd->anterior->ocurrencia_siguiente;
                                    nuevoAd->anterior->ocurrencia_siguiente->ocurrencia_anterior = nuevoAd->anterior->ocurrencia_anterior;
                                    nuevoAd->anterior->ocurrencia_anterior = NULL;
                                    nuevoAd->anterior->ocurrencia_siguiente = NULL;
                                }
                            }else{
                                if(nuevoAd->anterior->ocurrencia_anterior != NULL){
                                    if(nuevoAd->anterior->ocurrencia_anterior->siguiente->n != nuevoAd->n){  
                                        nuevoAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = nuevoAd->anterior->ocurrencia_siguiente;
                                        nuevoAd->anterior->ocurrencia_anterior = NULL;
                                    }
                                }
                                if(nuevoAd->anterior->ocurrencia_siguiente != NULL){
                                    if(nuevoAd->anterior->ocurrencia_siguiente->siguiente->n != nuevoAd->n){
                                        nuevoAd->anterior->ocurrencia_siguiente->ocurrencia_anterior = nuevoAd->anterior->ocurrencia_anterior;
                                        nuevoAd->anterior->ocurrencia_siguiente = NULL;
                                    }
                                }
                            }       
                            auxP.primera_ocurrencia = nuevoAd->anterior;
                            auxP.ultima_ocurrencia = nuevoAd->anterior;
                            /*
                                Se crea un nuevo puntero para el heap de dicho par 
                            */
                            nodoHeap * auxHeap = new nodoHeap();
                            auxHeap->par = parAnt;
                            auxHeap->frecuencia = 1;
                            /*
                                Agregamos este puntero del heap a la estructura
                            */
                            auxP.nodoDelHeap = auxHeap;
                            /*
                                Finalmente se añade el par al mapa y al heap
                            */
                            mapaAvanzado.insert(pair<pair<int,int>,pairOfMap>(parAnt,auxP));
                            mh.insert(auxHeap);
                        }else{
                            if(nuevoAd->anterior != it->second.ultima_ocurrencia){
                                if(nuevoAd->anterior != it->second.ultima_ocurrencia->siguiente){

                                    if(nuevoAd->anterior->ocurrencia_anterior != NULL){
                                        if(nuevoAd->anterior->ocurrencia_anterior->siguiente->n != nuevoAd->n){
                                            nuevoAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = nuevoAd->anterior->ocurrencia_siguiente;
                                            nuevoAd->anterior->ocurrencia_anterior = NULL;
                                        }
                                    }
                                    if(nuevoAd->anterior->ocurrencia_siguiente != NULL){
                                        if(nuevoAd->anterior->ocurrencia_siguiente->siguiente->n != nuevoAd->n){
                                            nuevoAd->anterior->ocurrencia_siguiente->ocurrencia_anterior = nuevoAd->anterior->ocurrencia_anterior;  
                                            nuevoAd->anterior->ocurrencia_siguiente = NULL;
                                        }
                                    }
                                    it->second.ultima_ocurrencia->ocurrencia_siguiente = nuevoAd->anterior;
                                    nuevoAd->anterior->ocurrencia_anterior = it->second.ultima_ocurrencia;
                                    it->second.ultima_ocurrencia = nuevoAd->anterior; 
                                    mh.modificaClave(it->second.nodoDelHeap->posicion, true);
                                }else{
                                    pair<int,int> borrar;
                                    if(nuevoAd->anterior->ocurrencia_anterior != NULL){
                                        nuevoAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = NULL;
                                        if(nuevoAd->anterior->ocurrencia_siguiente!= NULL){
                                            nuevoAd->anterior->ocurrencia_anterior->ocurrencia_siguiente = nuevoAd->anterior->ocurrencia_siguiente;
                                        }
                                    }
                                    if(nuevoAd->anterior->ocurrencia_anterior != NULL){
                                        borrar.first = nuevoAd->anterior->n;
                                        borrar.second = nuevoAd->anterior->ocurrencia_anterior->siguiente->n;
                                        it = mapaAvanzado.find(borrar);
                                        mh.modificaClave(it->second.nodoDelHeap->posicion, false);
                                    }else{
                                        if(nuevoAd->anterior->ocurrencia_siguiente!= NULL){
                                            borrar.first = nuevoAd->anterior->n;
                                            borrar.second = nuevoAd->anterior->ocurrencia_siguiente->siguiente->n;
                                            it = mapaAvanzado.find(borrar);
                                            mh.modificaClave(it->second.nodoDelHeap->posicion, false);
                                        }
                                    }
                                }
                            }
                        }   
                    }
                    /*
                        Si existe un nodo siguiente al par a reemplazar creamos un nuevo par
                        o aumentamos la frecuencia en caso que vuelva a coincidir
                    */
                    if((nuevoAd->siguiente != NULL)&&(nuevoAd->siguiente != nodoTail)){
                        /*
                            Inicializamos el par (nodo sigma + j, nodo siguiente a este)
                        */
                        pair<int,int> parSig;
                        parSig.first = nuevoAd->n;
                        parSig.second = nuevoAd->siguiente->n;
                        /*
                            Preguntamos si este para se encontraba ya en el mapa avanzado,
                            si no se encontraba se agrega a este y al heap,
                            en caso contrario solo se aumenta su frecuencia en el heap
                        */
                        it = mapaAvanzado.find(parSig);
                        if(it == mapaAvanzado.end()){
                        /*
                            Se inicializa la estructura pairOfMap correspondiente al valor en el mapa
                        */
                        auxP.primera_ocurrencia = nuevoAd;
                        auxP.ultima_ocurrencia = nuevoAd;
                        /*
                            Se crea un nuevo puntero para el heap de dicho par 
                        */
                        nodoHeap * auxHeap = new nodoHeap();
                        auxHeap->par = parSig;
                        auxHeap->frecuencia = 1;
                        /*
                            Agregamos este puntero del heap a la estructura
                        */
                        auxP.nodoDelHeap = auxHeap;
                        /*
                            Finalmente se añade el par al mapa y al heap
                        */
                        mapaAvanzado.insert(pair<pair<int,int>,pairOfMap>(parSig,auxP));
                        mh.insert(auxHeap);
                    }else{
                        if(it->second.nodoDelHeap->frecuencia > 0){
                            it->second.ultima_ocurrencia->ocurrencia_siguiente = nuevoAd;
                            nuevoAd->ocurrencia_anterior = it->second.ultima_ocurrencia;
                            it->second.ultima_ocurrencia = nuevoAd;
                            mh.modificaClave(it->second.nodoDelHeap->posicion, true);
                        }    
                    }
                }
            }
            ++j;
            }else{
                bandera = false;
            }
        }
    }
}

