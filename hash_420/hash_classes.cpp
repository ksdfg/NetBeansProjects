/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "hash_classes.h"

using namespace std;

void Hashing::lWoP(){
    Student meow;   //to take i/p of student
    int index = 0, nyan;  //to store hash index of record to insert
    bool shutdown = false;  //control outer loop : how many entries
    
    do{
        nyan = 0;   //reset value
        
        //take input of student
        cout<<endl<<"enter name of student : ";
        cin>>meow.name;
        cout<<"enter roll no. of student : ";
        cin>>meow.rollNo;
        cout<<"enter grade of student : ";
        cin>>meow.grade;
        
        nyan = index = meow.rollNo % MAX;  //calculate initial hash index
        
        while(hashtable[index].rollNo != -1){  //calculating correct hash index
            index = ++index % MAX;
            shutdown = true;
            if(index == nyan)
                break;
        }
        
        if(index == nyan && shutdown){
            cout<<endl<<"can't enter, no space"<<endl;
        }
        else{
            hashtable[index] = meow;
        }
        
        cout<<endl<<"do you want to enter another student? 1 or 0 : ";
        cin>>index; //using index to store i/p
        shutdown = index == 0;
    } while(!shutdown);
}