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
    int arr[4];
    int rear;
    int front;
} typedef Queue;

Queue makeQueue(){  //to initialize front and rear of a queue to 0
    Queue q;
    q.front = 0;
    q.rear = 0;
    return q;
}

void push(Queue q, int toPush){ //push item into queue
    q.rear = (q.rear + 1) % 4;
    q.arr[q.rear] = toPush;
}

int pop(Queue q){   //pop item from queue
    int ret = q.arr[q.front];
    q.front = (q.front + 1) % 4;
    return ret;
}

int fifo(int ref[]){    //find number of page faults
    int fault = 0;
    Queue q = makeQueue();
    
    return fault;
}

int main(int argc, char** argv) {
    
    int refLen = 0; //length of reference string
    printf("Enter length of reference string : ");
    scanf("%d", &refLen);
    
    int ref[refLen];    //reference string
    printf("\nEnter reference string :\n");
    for(int i=0; i<refLen; i++)
        scanf("%d", &ref[i]);   //taking input of reference string

    return (EXIT_SUCCESS);
}

