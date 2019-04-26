/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash_classes.h
 * Author: ksdfg
 *
 * Created on 26 April, 2019, 11:07 AM
 */

#ifndef HASH_CLASSES_H
#define HASH_CLASSES_H

#include <cstdlib>
#include <string>

using namespace std;

#define MAX 10

class Student{
    int rollNo;
    string name;
    char grade;
    
    friend class Hashing;
    
public:
    
    Student() : //will be required when initially making the hashtable
    rollNo(-1), name(" "), grade(' ') {
    }
    
};

class Hashing{
    Student hashtable[MAX];
    
public:
    void display(){ //display entire hashtable
        cout<<endl<<"index\tr no.\tname\tgrade"<<endl<<endl;
        for(int i=0; i<MAX; i++){
            cout<<i<<"\t"<<hashtable[i].rollNo<<"\t"<<hashtable[i].name<<"\t"<<hashtable[i].grade<<endl;
        }
    }
    
    void lWoP();   //linear probing without replacement
    
    void lWP();    //linear probing with replacement
};

#endif /* HASH_CLASSES_H */

