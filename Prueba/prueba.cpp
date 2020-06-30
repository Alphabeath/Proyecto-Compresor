#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
struct nodo{
    int n;
    string a;
    char c;
};


int main (){
    int sigma = 27;
    map <pair<int, int>, int> map_p;
    vector<int> vec_p;
    vec_p.push_back(1);
    vec_p.push_back(4);
    vec_p.push_back(2);
    vec_p.push_back(5);
    vec_p.push_back(3);
    vec_p.push_back(4);
    vec_p.push_back(2);
    vec_p.push_back(5);
    vec_p.push_back(6);
    vec_p.push_back(7);
    for(int i = 0;i < vec_p.size() - 1;i++){
        map_p[{vec_p.at(i),vec_p.at(i + 1)}];
    }
    for(int i = 0;i < vec_p.size() - 1;i++){
        ++map_p[{vec_p.at(i),vec_p.at(i + 1)}];
    }

    for (map<pair<int,int>,int>::iterator it=map_p.begin(); it!=map_p.end(); ++it)
        cout <<"Primera parte :" << it->first.first <<" Segunda parte: "<< it->first.second << " Su valor :"<< it ->second<<endl;

    
    /*
    map<int,nodo> m;
    nodo a,b,c;
    a.n = 1;
    a.a = "hola"; 
    a.c = 'x';
    b.n = 2;
    b.a = "adios";
    b.c = 'y';
    c.n = 3;
    c.a = "fuck";
    c.c = 'w';
    m.insert(pair<int,nodo>(1,a));
    m.insert(pair<int,nodo>(2,b));
    m.insert(pair<int,nodo>(3,c));
    */
    //cout<<m.at(1).a<<m.at(2).a<<m.at(3).a<<endl;
    //cout<<m.size()<<endl;
    //cout<<m[2].a<<endl;
    /*
    for (map<int,nodo>::iterator it=m.begin(); it!=m.end(); ++it)
        cout << it->first << " => " << it->second.a << '\n';
    */
    return 0;
}