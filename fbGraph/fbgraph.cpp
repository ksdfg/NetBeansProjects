/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/
#include "fbGraph.h"
#include <iostream>
#include <string>

using namespace std;

Graph::Graph(int vertices) :   //constructor (parameterized)
vertices(vertices) {

    for(int i=0; i<vertices; i++){  //fill details of each vertex
        head[i] = new Node(i);

        cout<<"Enter name of user : ";
        cin>>head[i]->name;
    }
}

const int Graph::getIndex(string name){    //searching a vertex from list of all vertices
    for(int i=0; i<vertices; i++){
        if(head[i]->name == name){
            return i;
        }
    }

    return -1;    //returns NULL if vertex not found
}

void Graph::create(){  //fill in all the edges; make adjacency list
    Node* temp;
    char meow;
    string nyan;
    int index;

    for(int i=0; i<vertices; i++){  //ask for friends of all vertices
        temp = head[i];
        cout<<"\nDoes "<<head[i]->name<<" have any friends? y or n : ";
        cin>>meow;

        while(meow == 'y'){
            cout<<"Enter name of friend : ";
            cin>>nyan;

            index = getIndex(nyan);

            if(index == -1){   //search if friend actually exists -_-
                cout<<"Not your imaginary friends ~_~"<<endl;
            }
            else if(index == i){

            }
            else{
                temp->next = new Node(*head[index]);
            }

            temp = temp->next;  //make next friend if there

            cout<<"Does "<<head[i]->name<<" have any more friends ? y or n : ";
            cin>>meow;
        }//end while
    }//end for
}

void Graph::display(){ //display the graph (adjacency lists)
    Node* temp;

    cout<<endl;

    for(int i=0; i<vertices; i++){  //iterate through the head array
        temp = head[i];

        while(temp != NULL){    //iterate through the adjacency list
            cout<<temp->name<<"\t";
            temp = temp->next;
        }

        cout<<endl; //go to next line after printing an adjacency list
    }
}

void Graph::dfs(){ //handler
    int visited[vertices];  //array to store if a node has been visited

    for(int i=0; i<vertices; i++){  //no node is visited at first
        visited[i] = 0;
    }

    string meow;
    cout<<"\nEnter user name to start dft with : ";
    cin>>meow;

    dfs(getIndex(meow), visited);   //call to the recursive method
}

void Graph::dfs(int index, int visited[]){  //recursive call
    Node* temp = head[index];

    cout<<temp->name<<"\t"; //visit node
    visited[index] = 1;     //mark node as visited

    temp = temp->next;  //move on to adjacency lists
    while(temp != NULL){
        if(visited[temp->vertex] == 0){
            dfs(temp->vertex, visited);
        }
        temp = temp->next;
    }
}