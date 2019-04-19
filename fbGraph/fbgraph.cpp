/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/
#include "fbGraph.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

Graph::Graph(int vertices) :   //constructor (parameterized)
vertices(vertices) {

    for(int i=0; i<vertices; i++){  //fill details of each vertex
        head[i] = new Node(i);

        cout<<"Enter name of user : ";
        cin>>head[i]->name;
    }
}

Graph::~Graph(){
    Node *meow, *nyan;
    
    for(int i=0; i<vertices; i++){
        meow = head[i]->next;
        delete head[i];
        
        while(meow != NULL){
            nyan = meow;
            meow = meow->next;
            delete nyan;
        }
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

bool Graph::friendOf(int toCheck, const Node* meow){   //figure out if two users are already friends
    meow = meow->next;  //no need to check the given node, that's covered in different case
    
    while(meow != NULL){    //iterate through adjacency list
        if(*meow == *head[toCheck]){
            return true;
        }
        meow = meow->next;
    }
    
    return false;
}

void Graph::create(){  //fill in all the edges; make adjacency list
    Node* temp;
    char meow;
    string nyan;
    int index;

    for(int i=0; i<vertices; i++){  //ask for friends of all vertices
        cout<<"\nDoes "<<head[i]->name<<" have any friends? y or n : ";
        cin>>meow;

        while(meow == 'y'){
            cout<<"Enter name of friend : ";
            cin>>nyan;

            index = getIndex(nyan);

            if(index == -1){   //search if friend actually exists -_-
                cout<<"Not your imaginary friends ~_~"<<endl;
            }
            else if(index == i){    //if he entered himself as his own friend
                cout<<"That's you buddy... this is just sad T-T"<<endl;
            }
            else if(friendOf(index, head[i])){  //if they're already friends
                cout<<"You're already friends ~_~"<<endl;
            }
            else{
                //make new guy a friend of current guy
                temp = new Node(*head[index]);
                temp->next = head[i]->next;
                head[i]->next = temp;
                
                //make current guy a friend of new guy
                temp = new Node(*head[i]);
                temp->next = head[index]->next;
                head[index]->next = temp;
            }

            cout<<"Does "<<head[i]->name<<" have any more friends ? y or n : ";
            cin>>meow;
        }//end while
    }//end for
}

void Graph::display(){ //display the graph (adjacency lists)
    Node* temp;

    for(int i=0; i<vertices; i++){  //iterate through the head array
        cout<<endl<<head[i]->name;
        temp = head[i]->next;

        while(temp != NULL){    //iterate through the adjacency list
            cout<<"\t-->\t"<<temp->name;
            temp = temp->next;
        }
    }
    
    cout<<endl;
}

void Graph::dfs_r(){ //handler
    int visited[vertices];  //array to store if a node has been visited

    for(int i=0; i<vertices; i++){  //no node is visited at first
        visited[i] = 0;
    }

    string meow;
    cout<<endl<<"Recursive\nEnter user name to start dft with : ";
    cin>>meow;

    dfs(getIndex(meow), visited);   //call to the recursive method
}

void Graph::dfs(int index, int visited[]){  //recursive call for dft
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

void Graph::dfs_nr(){   //non recursive method for dft
    int visited[vertices];  //array to store if a node has been visited
    queue<int> q;
    Node *temp;

    for(int i=0; i<vertices; i++){  //no node is visited at first
        visited[i] = 0;
    }

    string meow;
    cout<<endl<<"Non Recursive\nEnter user name to start dft with : ";
    cin>>meow;
    
    q.push(getIndex(meow)); //push first node to queue
    
    while(!q.empty()){
        temp = head[q.front()];
        q.pop();
        
        if(visited[temp->vertex] == 0){
            visited[temp->vertex] = 1;  //mark node as visited
            cout<<temp->name<<"\t";     //visit node
        }
        
        temp = temp->next;
        while(temp != NULL){    //push adjacent nodes to queue
            if(visited[temp->vertex] == 0){
                q.push(temp->vertex);
            }
            temp = temp->next;  //to iterate through adjacency list
        }
    }
}
    
void Graph::bfs_nr(){          //non recursive depth first something (hey that actually works out, supposed to be traversal tho)
    int visited[vertices];  //array to store if a node has been visited
    stack<int> q;
    Node *temp;

    for(int i=0; i<vertices; i++){  //no node is visited at first
        visited[i] = 0;
    }

    string meow;
    cout<<endl<<"Non Recursive\nEnter user name to start dft with : ";
    cin>>meow;
    
    q.push(getIndex(meow)); //push first node to queue
    
    while(!q.empty()){
        temp = head[q.top()];
        q.pop();
        
        if(visited[temp->vertex] == 0){
            visited[temp->vertex] = 1;  //mark node as visited
            cout<<temp->name<<"\t";     //visit node
        }
        
        temp = temp->next;
        while(temp != NULL){    //push adjacent nodes to queue
            if(visited[temp->vertex] == 0){
                q.push(temp->vertex);
            }
            temp = temp->next;  //to iterate through adjacency list
        }
    }
}