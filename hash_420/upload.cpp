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
 * Created on 26 April, 2019, 11:05 AM
 */

#include <cstdlib>
#include <iostream>
#include "hash_classes.h"

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

void Hashing::lWoP(){
    Student meow;   //to take i/p of student
    int index = 0, nyan;  //index to store hash index of record to , nyan is temp
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
        cin>>nyan; //using index to store i/p
        shutdown = nyan == 0;
    } while(!shutdown);
}

void Hashing::lWP(){
    Student meow, woof;   //to take i/p of student, woof is temp
    int index = 0, nyan;  //index to store hash index of record to , nyan is temp
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
        
        if(hashtable[index].rollNo != -1){
            if(hashtable[index].rollNo % MAX != index){ //in this case, need to replace
                woof = hashtable[index];
                hashtable[index] = meow;
                meow = woof;
            }
            
            while(hashtable[index].rollNo != -1){  //calculating correct hash index
            index = ++index % MAX;
            shutdown = true;
            if(index == nyan)
                break;
            }
        }
        
        if(index == nyan && shutdown){
            cout<<endl<<"can't enter, no space"<<endl;
        }
        else{
            hashtable[index] = meow;
        }
        
        cout<<endl<<"do you want to enter another student? 1 or 0 : ";
        cin>>nyan; //using index to store i/p
        shutdown = nyan == 0;
    } while(!shutdown);
}

int main(int argc, char** argv) {

    Hashing h;
    int meow;
    
    do{
        cout<<"what to do, to do, todotodotodotodotodooo..."<<endl;
        cout<<"1. linear probing without replacement"<<endl;
        cout<<"2. linear probing with replacement"<<endl;
        cout<<"choice ? ";
        cin>>meow;
        
        switch(meow){
            case 1:
                h.lWoP();
                break;
                
            case 2:
                h.lWP();
                break;
                
            default:
                cout<<endl<<"did you get so confused by the pink panther theme";
                cout<<" song in the menu that you forgot what options there were?";
        }
        
        cout<<endl<<"want to perform another operation? 1 or 0 : ";
        cin>>meow;
    } while(meow);
    
    return 0;
}