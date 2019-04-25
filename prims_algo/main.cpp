/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * Author: Kshitish Deshpande
 * Roll no: 203344
 * Panel: 5
 * Batch: E4
 * Serial no: 55
 *
 * Created on 25 April, 2019, 8:53 AM
 */

#include <cstdlib>
#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char** argv) {
    
    int nodes;
    cout<<"Enter number of nodes in graph : ";
    cin>>nodes;
    
    Graph g = Graph(nodes);
    g.create();
    g.display();

    return 0;
}

