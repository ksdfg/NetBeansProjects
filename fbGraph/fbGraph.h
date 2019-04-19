/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fbGraph.h
 * Author: ksdfg
 *
 * Created on 17 April, 2019, 12:17 PM
 */
#ifndef FBGRAPH_H
#define FBGRAPH_H

#include <string>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    
    int vertex; //vertex number of node
    string name;    //fb user name
    Node* next; //linked list for his friends
    
    friend class Graph;
    
public:
    Node(int vertex) :  //parameterized constructor
    vertex(vertex) {
        next = NULL;
    }

    Node(const Node& other) :   //copy constructor
    vertex(other.vertex), name(other.name), next(NULL) {
    }

};

class Graph{
    
    Node* head[INT_MAX];    //list of all the vertices and their adjacency lists
    int vertices;   //total number of vertices in the graph
    
private:
    
    const int getIndex(string name);    //get the vertex number of a node with given name
    
    void dfs(int index, int visited[]); //depth first something (hey that actually works out, supposed to be traversal tho)
    
public:
    
    Graph(int vertices);    //constructor (parameterized)
    
    ~Graph();               //destructor

    void create();          //populate the graph with nodes and edges
    
    void display();         //adjacency lists
    
    void dfs_r();           //handler method for dfs
    
    void dfs_nr();          //non recursive depth first something (hey that actually works out, supposed to be traversal tho)
};

#endif /* FBGRAPH_H */

