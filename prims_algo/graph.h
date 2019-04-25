/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graph.h
 * Author: ksdfg
 *
 * Created on 25 April, 2019, 8:54 AM
 */

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    int nodes;  //total number of nodes
    int cost[20][20]; //matrix to store costs of edges
    
public:
    
    Graph(int nodes);   //parameterised constructor
    
    void create();      //to populate the graph with edges
    
    void display();     //to display the cost matrix
};

#endif /* GRAPH_H */

