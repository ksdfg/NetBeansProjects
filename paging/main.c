/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ksdfg
 *
 * Created on 29 April, 2019, 2:26 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int fifo(int ref[], int refLen, int noFrames){    //find number of page faults
    int fault = 0, meow = 0, rear = 0;    //meow is temp, fault stores number of page faults, rear for queue
    int frames[noFrames];      //queue to store page frames
    
    //initialize all frames initially as -1, since that is invalid page number
    for(int i=0; i<noFrames; i++)
        frames[i] = -1;
    
    for(int i=0; i<refLen; i++){    //traverse through reference string
        meow = 0;
        
        printf("\n%d", ref[i]); //current page number
        
        for(int j=0; j<3; j++)
            if(frames[j] == ref[i]){ //if page already in one of the frames
                meow = 1;
                break;
            }
        
        if(meow)
            continue;    //go to next page number
        
        frames[rear] = ref[i];  //push current page number into queue (call it to p.m.)
        rear = (rear + 1) % 3;  //update front value circularly
        
        printf("\t:\t");
        for(int i=0; i<noFrames; i++){ //print pages mapped to each frame
            if(frames[i] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[i]);
        }
        
        fault++;    //since there was a page fault ~.~
    }
    
    return fault;   //kaeritai -_-
}

int main(int argc, char** argv) {
    
    int frames; //total number of frames available
    printf("Enter number of frames available : ");
    scanf("%d", &frames);
    
    int refLen = 0; //length of reference string
    printf("Enter length of reference string : ");
    scanf("%d", &refLen);
    
    int ref[refLen];    //reference string
    printf("\nEnter reference string :\n");
    for(int i=0; i<refLen; i++)
        scanf("%d", &ref[i]);   //taking input of reference string
    
    printf("\n\nfaults = %d", fifo(ref, refLen, frames));   //call fifo, print number of page faults

    return (EXIT_SUCCESS);
}

