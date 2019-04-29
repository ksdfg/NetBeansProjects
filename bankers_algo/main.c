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

int safetySequence(int proc, int res, int alloc[proc][res], int need[proc][res], int available[res]){
    int isSafe = 0, cnt = 0;    //isSafe whether deadlock happens or not, cnt is counter for iterations
    int meow = -1, nyan;   //temp var
    
    int work[res];  //copy of available since we don't want changes in arg
    for(int i=0; i<res; i++)
        work[i] = available[i];
    
    int finish[proc];   //keeps tracked of finished processes
    for(int i=0; i<proc; i++)
        finish[i] = 0;
    
    printf("\nthe safety sequence is : \n");
    
    while(++cnt < (res*proc*proc)){
        if(++meow == proc)
            meow = 0;
        
        if(finish[meow] == 1)
            continue;
        
        for(int i=0; i<res; i++){
            if(need[meow][i] > work[i]){
                nyan = 1;
                break;
            }
            else{
                nyan = 0;
            }
        }
        
        if(nyan)
            continue;
        
        for(int i=0; i<res; i++)
            work[i] += alloc[meow][i];
        
        finish[meow] = 1;
        
        printf("\np%d\nwork = { ", meow);
        for(int i=0; i<res; i++)
            printf("%d ", work[i]);
        printf("}\nfinish = { ");
        for(int i=0; i<proc; i++)
            printf("%d ", finish[i]);
        printf("}\n");
        
        nyan = 1;
        for(int i=0; i<proc; i++)
            if(finish[i] == 0){
                nyan = 0;
                break;
            }
        if(nyan){
            isSafe = 1;                
            break;
        }
    }
    
    return isSafe;
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
    
    if(safetySequence(proc, res, alloc, need, available))  //call safety sequence method
        printf("\nThis sequence is safe\n");
    else
        printf("\nThis sequence is not safe");
    
    return (EXIT_SUCCESS);
}

