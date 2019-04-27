/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ksdfg
 *
 * Created on 27 April, 2019, 1:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define max 20

/*
 * 
 */

//take entry of values into a matrix
void enter(int r, int c, int matrix[r][c]){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("Process %d, Resource Type %d : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
}

//display a matrix
void dispMatrix(int r, int c, int matrix[r][c]){
    printf("  \tr0\tr1\tr2\n"); //print headings
    for(int i=0; i<r; i++){
        printf("p%d\t", i);
        for(int j=0; j<c; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");   //move on to next process
    }
}

int main(int argc, char** argv) {
    //get number of resource types and processes
    int res, proc;
    printf("Enter number of resource types : ");
    scanf("%d", &res);
    printf("Enter number of processes : ");
    scanf("%d", &proc);
    
    int available[res];     //available instances of each resource types
    int mxm[proc][res];     //max number of resources required by each process
    int alloc[proc][res];   //number of resources allocated to each process
    int need[proc][res];    //number of resources needed by each process
    
    //take input of available array
    printf("\n");
    for(int i=0; i<res; i++){
        printf("Available instances of resource type %d = ", i);
        scanf("%d", &available[i]);
    }

    //take input of mxm matrix
    printf("\nTaking input of MAX matrix\n");
    enter(proc,res,mxm);

    //take input of alloc matrix
    printf("\nTaking input of ALLOC matrix\n");
    enter(proc,res,alloc);
    
    //calculate need matrix
    for(int i=0; i<proc; i++)
        for(int j=0; j<res; j++)
            need[i][j] = mxm[i][j] - alloc[i][j];
    
    //display max matrix
    printf("\nMAX matrix =\n");
    dispMatrix(proc, res, mxm);
    
    //display alloc matrix
    printf("\nALLOC matrix =\n");
    dispMatrix(proc, res, alloc);
    
    //display need matrix
    printf("\nNEED matrix =\n");
    dispMatrix(proc, res, need);
    
    return (EXIT_SUCCESS);
}

