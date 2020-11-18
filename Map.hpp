//  Map.hpp
//  Part 1
//  Emilie Mines & Zach Eichler.


#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;


class Territory{
    int continent;
    int ownedBy;
    int numArmies;
    
    //for validation
    
    void DFS(int v, bool visited[]);
    
    
public:
    int destination;
    Territory *next;
    Territory(int d,int c, int o, int a);
    int getContient();
    int getOwnedBy();
    int getNumArmies();
    void printStuff();
    Territory getNext();
    
        
};


class Map{
    int V;
    list <int>  *adjList2;
    void DFS(int v, bool visited[]);
public:
    struct AdjList{
        Territory *head;
    };
    AdjList *arr;
    Map(int V); //
    
    //list<Territory> getList();
    
    void addEdge(int v, int w, int c, int o, int a);
    
    
    void printMap();
    
    //for validation
    
    void addEdge2(int v, int w);
    void validate(int v);

    
};

#endif /* Map_hpp */

