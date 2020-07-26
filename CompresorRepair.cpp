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
            //d->imprime();
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
        Ad->imprime();
        mh.imprime();
        //for (map<pair<int,int>,pairOfMap>::iterator it=mapaAvanzado.begin(); it!=mapaAvanzado.end(); ++it)
            //cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor : ("<< it->second.nodoDelHeap->par.first<<","<<it->second.nodoDelHeap->par.second<<")"<<endl;

        int j = 1;
        while(bandera){
            if(mh.max() >= 2){
                /*
                    Removemos el par que tiene mayor frecuencia en el heap
                */
                pair<int,int> parAux = mh.removeMax();  
                //cout<<"par : ("<<parAux.first<<","<<parAux.second<<")"<<endl;
                /*
                    Obtenemos el puntero de la primera ocurrencia en la listaAvanzada
                */
                nodoAd * auxAd = mapaAvanzado.at(parAux).primera_ocurrencia;
                //if(j==2) cout<<"la ocurrencia siguiente de (1,1) :"<<auxAd->ocurrencia_siguiente->siguiente->n<<endl;
                
                //cout<<"primera ocurrencia :"<<auxAd->ocurrencia_siguiente->ocurrencia_siguiente->n<<endl;
                
                while(auxAd != NULL){
                    cout<<"("<<parAux.first<<","<<parAux.second<<")"<<endl;
                    //cout<<"auxAd"<<auxAd->n<<endl;
                    //if(auxAd != NULL)   cout<<"anterior: "<<auxAd->anterior->n<<endl;
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
                            //auxAd->anterior->ocurrencia_anterior = NULL;
                            //auxAd->anterior->ocurrencia_siguiente = NULL;
                            mh.modificaClave(it->second.nodoDelHeap->posicion,false);
                        }
                    }
                    
                    if((auxAd->siguiente->siguiente != NULL)&&(auxAd->siguiente->siguiente != nodoTail)){
                        pair<int,int> auxAdSig;
                        auxAdSig.first = auxAd->siguiente->n;
                        auxAdSig.second = auxAd->siguiente->siguiente->n;
                        it = mapaAvanzado.find(auxAdSig);
                        //if(j == 2)
                            //cout<<"par: "<<"("<<it->second.nodoDelHeap->par.first<<","<<it->second.nodoDelHeap->par.second<<")"<<endl;
                        if((it->second.primera_ocurrencia == auxAd->siguiente)||(it->second.ultima_ocurrencia == auxAd->siguiente)){
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            se la primera o la ultima ocurrencia de si mismo, se actualizan 
                            los punteros del mapa y de la lista avanzada
                            */
                            if(it->second.primera_ocurrencia == auxAd->siguiente){
                                if(it->second.primera_ocurrencia->ocurrencia_siguiente != NULL){
                                    if((auxAd->n != auxAd->siguiente->n)&&(auxAd->siguiente->n == auxAd->siguiente->siguiente->n)&&(auxAd->siguiente->siguiente->n == auxAd->siguiente->siguiente->siguiente->n)){
                                        auxAd->siguiente->siguiente->ocurrencia_siguiente = it->second.primera_ocurrencia->ocurrencia_siguiente;
                                        it->second.primera_ocurrencia->ocurrencia_siguiente->ocurrencia_anterior = auxAd->siguiente->siguiente;
                                        auxAd->siguiente->ocurrencia_siguiente = NULL;
                                        it->second.primera_ocurrencia = auxAd->siguiente->siguiente;
                                    }else{
                                        it->second.primera_ocurrencia->ocurrencia_siguiente->ocurrencia_anterior = NULL;
                                        it->second.primera_ocurrencia = it->second.primera_ocurrencia->ocurrencia_siguiente;
                                    }
                                }
                            }
                            if(it->second.ultima_ocurrencia == auxAd->siguiente){
                                if(it->second.ultima_ocurrencia->ocurrencia_anterior != NULL){
                                    if((auxAd->n != auxAd->siguiente->n)&&(auxAd->siguiente->n == auxAd->siguiente->siguiente->n)&&(auxAd->siguiente->siguiente->n == auxAd->siguiente->siguiente->siguiente->n)){
                                        auxAd->siguiente->siguiente->ocurrencia_anterior = it->second.ultima_ocurrencia->ocurrencia_anterior;
                                        it->second.ultima_ocurrencia->ocurrencia_anterior->ocurrencia_siguiente = auxAd->siguiente->siguiente;
                                        auxAd->siguiente->ocurrencia_anterior = NULL;
                                        it->second.ultima_ocurrencia = auxAd->siguiente->siguiente;
                                    }else{
                                        it->second.ultima_ocurrencia->ocurrencia_anterior->ocurrencia_siguiente = NULL;
                                        it->second.ultima_ocurrencia = it->second.ultima_ocurrencia->ocurrencia_anterior;
                                    }
                                }
                            }
                        }else{
                            /*
                            En caso de que el par inmediatamente anterior al par a cambiar,
                            no sea la primera o la ultima ocurrencia de si mismo, se  
                            actualizan solo los punteros de la lista avanzada
                            */
                            if((auxAd->n != auxAd->siguiente->n)&&(auxAd->siguiente->n == auxAd->siguiente->siguiente->n)&&(auxAd->siguiente->siguiente->n == auxAd->siguiente->siguiente->siguiente->n)){
                                auxAd->siguiente->siguiente->ocurrencia_anterior = auxAd->siguiente->ocurrencia_anterior;
                                auxAd->siguiente->siguiente->ocurrencia_siguiente = auxAd->siguiente->ocurrencia_siguiente;
                                auxAd->siguiente->ocurrencia_anterior->ocurrencia_siguiente = auxAd->siguiente->siguiente;
                                auxAd->siguiente->ocurrencia_siguiente->ocurrencia_anterior = auxAd->siguiente->siguiente;
                                auxAd->siguiente->ocurrencia_siguiente = NULL;
                                auxAd->siguiente->ocurrencia_anterior = NULL;
                            }else{
                                if(auxAd->siguiente->ocurrencia_anterior != NULL)
                                    auxAd->siguiente->ocurrencia_anterior->ocurrencia_siguiente = auxAd->siguiente->ocurrencia_siguiente;
                                if(auxAd->siguiente->ocurrencia_siguiente != NULL)
                                    auxAd->siguiente->ocurrencia_siguiente->ocurrencia_anterior = auxAd->siguiente->ocurrencia_anterior;
                            }
                        }
                        //auxAd->anterior->ocurrencia_anterior = NULL;
                        //auxAd->anterior->ocurrencia_siguiente = NULL;
                        if((auxAd->siguiente->n != auxAd->siguiente->siguiente->n)||(auxAd->siguiente->siguiente->n != auxAd->siguiente->siguiente->siguiente->n)){
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
                    auxAd->anterior->siguiente = nuevoAd;
                    auxAd->siguiente->siguiente->anterior = nuevoAd;
                    /*
                        Borramos el par que vamos a reemplazar por el nodo sigma + j
                    */
                    delete auxAd->siguiente;
                    nodoAd * auxDelete = auxAd;
                    //if(j==2) cout<<"AuxAd tiene : ("<<auxAd->n<<","<<auxAd->siguiente->n<<")"<<endl;
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
                                    it->second.ultima_ocurrencia->ocurrencia_siguiente = nuevoAd->anterior;
                                    nuevoAd->anterior->ocurrencia_anterior = it->second.ultima_ocurrencia;
                                    it->second.ultima_ocurrencia = nuevoAd->anterior; 
                                    mh.modificaClave(it->second.nodoDelHeap->posicion, true);
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

                    mh.imprime();
                    Ad->imprime();
                    //if((j==2)&& (auxAd!=NULL)) cout<<"el par siguiente de (1,1) :"<<auxAd->ocurrencia_siguiente->n<<endl;
                    //if((j==2)&& (auxAd!=NULL)) cout<<"el par siguiente de (1,1) :"<<auxAd->ocurrencia_siguiente->n<<endl;
                }
                ++j;
                /*
                if(j==3){
                    map<pair<int,int>,pairOfMap>::iterator it=mapaAvanzado.begin();
                    for(it ; it!= mapaAvanzado.end(); it++){
                        cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor : ("<< it->second.nodoDelHeap->par.first<<","<<it->second.nodoDelHeap->par.second<<") frecuencia : "<<it->second.nodoDelHeap->frecuencia<<endl;
                    }
                }*/
                //cout<<"tamo ready"<<endl;
                //mh.imprime();
                
                cout<<"sale "<<endl;
                
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


