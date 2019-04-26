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

