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
    //cout<<m.at(1).a<<m.at(2).a<<m.at(3).a<<endl;
    cout<<m.size()<<endl;
    cout<<m[2].a<<endl;
    /*
    for (map<int,nodo>::iterator it=m.begin(); it!=m.end(); ++it)
        cout << it->first << " => " << it->second.a << '\n';
    */
    return 0;
}