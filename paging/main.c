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
struct queue{   //struct for queue
    int arr[3];
    int rear;
    int front;
} typedef Queue;

Queue makeQueue(){  //to initialize front and rear of a queue to 0
    Queue q;
    for(int i=0; i<3; i++)  //initially set all to -1 (invalid)
        q.arr[i] = -1;
    q.front = 0;
    q.rear = 0;
    return q;
}

void push(Queue *q, int toPush){ //push item into queue
    q->arr[q->rear] = toPush;
    q->rear = (q->rear + 1) % 3;    //update front value circularly
}

int fifo(int ref[], int refLen){    //find number of page faults
    int fault = 0, meow = 0;    //meow is temp, fault stores number of page faults
    Queue q = makeQueue();      //queue to store page frames
    
    for(int i=0; i<refLen; i++){    //traverse through reference string
        meow = 0;
        
        printf("\n%d", ref[i]); //current page number
        
        for(int j=0; j<3; j++)
            if(q.arr[j] == ref[i]){ //if page already in one of the frames
                meow = 1;
                break;
            }
        
        if(meow)
            continue;    //go to next page number
        
        push(&q, ref[i]);   //push current page number into queue (call it to p.m.)
        
        printf("\t:\t");
        for(int i=0; i<3; i++){ //print pages mapped to each frame
            if(q.arr[i] == -1)
                printf("-\t");
            else
                printf("%d\t", q.arr[i]);
        }
        
        fault++;
    }
    
    return fault;   //kaeritai -_-
}

int main(int argc, char** argv) {
    
    int refLen = 0; //length of reference string
    printf("Enter length of reference string : ");
    scanf("%d", &refLen);
    
    int ref[refLen];    //reference string
    printf("\nEnter reference string :\n");
    for(int i=0; i<refLen; i++)
        scanf("%d", &ref[i]);   //taking input of reference string
    
    printf("\n\nfaults = %d", fifo(ref, refLen));   //call fifo, print number of page faults

    return (EXIT_SUCCESS);
}

