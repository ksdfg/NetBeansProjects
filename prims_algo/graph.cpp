/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include<bits/stdc++.h>
#include "graph.h"

using namespace std;

Graph::Graph(int nodes) :   //parameterized constructor
nodes(nodes) {
    for(int i=0; i<nodes; i++)  //set cost of all edges as -1; edges don't exist
        for(int j=0; j<nodes; j++)
            cost[i][j] = INT_MAX;
}

void Graph::create(){    //to populate the graph with edges
    int edges;
    cout<<endl<<"enter number of edges : ";
    cin>>edges;
    
    int start, end;   //temp vars
    
    for(int i=0; i<edges; i++){ //take i/p of details of each edge
        cout<<endl<<"enter starting edge : ";
        cin>>start;
        cout<<"enter ending edge : ";
        cin>>end;
        cout<<"enter cost : ";
        cin>>cost[start][end];
        
        cost[end][start] = cost[start][end];    //cost is symmetric matrix
    }
}

void Graph::display(){    //to display the cost matrix
    cout<<endl;
    //iterate through the matrix and print all values
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(cost[i][j] == INT_MAX)   //don't want to print int_max, so inf
                cout<<"INF\t";
            else
                cout<<cost[i][j]<<"\t";
        }
        cout<<endl; //next row of matrix
    }
}