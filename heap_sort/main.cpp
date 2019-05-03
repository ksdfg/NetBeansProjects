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
 * Created on 2 May, 2019, 8:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

#define MAX 20

class Student{
    string name;
    int marks;
    char grades;
    
    friend class Heap;
    
public:
    Student(string name, int marks, char grades) :
    name(name), marks(marks), grades(grades) {
    }

    Student() :
    name(" "), marks(-1), grades(' ') {
    }
    
    void display(){
        cout<<endl<<"name : "<<name;
        cout<<endl<<"marks : "<<marks;
        cout<<endl<<"grades : "<<grades<<endl;
    }
};

class Heap{
    Student heapArr[MAX];
    int size;   //current size of heap
    bool type;  //true = max heap, false = min heap
    
    void insertHeap(int index); //called inside create to insert a single node
    
public:
    Heap(bool type) :
    size(0), type(type) {
    }
    
    Heap(){}    //default constructor (for temp var)

    void createHeap();  //insert nodes into heap 
    
    void extractMinMax();   //get min and max element
};

void Heap::createHeap(){
    bool shutdown = false;  //how many keys to take
    Student meow;   //temp student var
    int nyan;   //temp var
    
    while(!shutdown){
        //take i/p of student
        cout<<"Enter Student name : ";
        cin>>meow.name;
        cout<<"Enter Student marks : ";
        cin>>meow.marks;
        cout<<"Enter Student grade : ";
        cin>>meow.grades;
        
        heapArr[++size] = meow; //enter student in to heap
        insertHeap(size);       //sort heap accordingly
        
        cout<<"Do you want to enter another Student ? 1 or 0 : ";
        cin>>nyan;
        cout<<endl; //for neatness '_'
        shutdown = nyan == 0;
    }
}

void Heap::insertHeap(int index){
    Student nyan;   //temp var
    
    while(index/2 > 0){
        if(type && heapArr[index/2].marks < heapArr[index].marks){ //swap if not in order for max heap
            nyan = heapArr[index/2];
            heapArr[index/2] = heapArr[index];
            heapArr[index] = nyan;
        }
        else if(!type && heapArr[index/2].marks > heapArr[index].marks){ //swap if not in order for max heap
            nyan = heapArr[index/2];
            heapArr[index/2] = heapArr[index];
            heapArr[index] = nyan;
        }
        
        index /= 2;    //previous node : check it's children
    }
}

void Heap::extractMinMax(){
    if(type)    //if max heap
        cout<<endl<<"MAX = ";
    else
        cout<<endl<<"MIN = ";
    
    heapArr[1].display();
    
    cout<<endl;
}

int main(int argc, char** argv) {
    
    bool shutdown = false;
    Heap h;
    int meow;
    
    do{
        cout<<"what to do, to do, todotodotodotodotodoooo..."<<endl;
        cout<<"1.Max Heap"<<endl<<"2.Min Heap"<<endl<<"choice = ";
        cin>>meow;
        
        if(meow == 1)
            h = Heap(true);
        else if(meow == 2)
            h = Heap(false);
        else
            cout<<endl<<"did you get confused by the pink panther theme?"<<endl;
        
        h.createHeap();
        h.extractMinMax();
        
        cout<<endl<<"once more? 1 or 0 : ";
        cin>>meow;
        cout<<endl;
        shutdown = meow == 0;
    } while(!shutdown);

    return 0;
}

