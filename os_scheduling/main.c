/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ksdfg
 *
 * Created on 17 April, 2019, 10:03 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

struct s{
	int name;	//name of the process
	int at;		//arrival time of the process
	int bt;		//burst time of the process
	int wt;		//wait time of the process
	int tat;	//turn around time of the process
} typedef proc;

void readProcs(proc p[], int size){	//initialise a process with details

	for(int i=0; i<size; i++){
		p[i].name = i;	//set name of process according to order in which entered
	
		printf("\nEnter arrival time of p%d : ", p[i].name);
		scanf("%d", &p[i].at);
	
		printf("Enter burst time of p%d : ", p[i].name);
		scanf("%d", &p[i].bt);
	
		//to be computed
		p[i].wt = p[i].tat = 0;
	}
	
}

void sortProcs(proc p[], int size){	//sort array of proc according to arrival time

	proc temp;	//temporary var for switching
	
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(p[i].at > p[j].at){	//switch if element after it is larger
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	
}

void dispProcs(proc p[], int size){	//display the array of processes in tabular form
	
	printf("\npName\tat\tbt\twt\ttat\n");	//headings
	
	for(int i=0; i<size; i++){
		printf("\np%d\t%d\t%d\t%d\t%d", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tat);	//print info of the process
	}
	
	printf("\n");
	
}

void fcfs(proc p[], int size){	//print gant chart and calculate waiting time and turn around time
	
	int currTime = p[0].at, t_wt = 0, t_tat = 0;
	
	printf("\n\tGant Chart for fcfs\n");
	printf("\n%d ", currTime);
	
	for(int i=0; i<size; i++){
		printf("<--p%d--> ", p[i].name);
		
		currTime += p[i].bt;
		
		p[i].tat = currTime - p[i].at;
		t_tat += p[i].tat;
		
		p[i].wt = p[i].tat - p[i].bt;
		t_wt += p[i].wt;
		
		printf("%d ", currTime);
		
		if(i<size-1 && currTime<p[i+1].at){
			currTime += p[i+1].at;
			printf("<--idle--> %d ", currTime);
		}
	}
	
	printf("\n");
	dispProcs(p, size);
	
	printf("\navg waiting time = %f\navg turnaround time = %f\n", ((float)t_wt/size), ((float)t_tat/size));
	
}

void sjfPre(proc p[], int size){
    
    int currTime = p[0].at, t_wt = 0, t_tat = 0;
    int i = 0, shutdown = 0, meow = -1;
    int burst[size];
    
    for(int j=0; j<size; j++)
        burst[j] = p[j].bt;
	
    printf("\n\tGant Chart for sjf pre-emptive\n");
    printf("\n%d ", currTime);

    while(!shutdown){
        if(meow != i)
            printf("%d <--p%d--> ", currTime, p[i].name);
        
        meow = i;

        currTime ++;
        burst[i]--;

        if(burst[i] == 0){
            p[i].tat = currTime - p[i].at;
            t_tat += p[i].tat;

            p[i].wt = p[i].tat - p[i].bt;
            t_wt += p[i].wt;
            
            for(int j=0; j<size; j++){
                if(burst[j] != 0){
                    i = j;
                    break;
                }
            }
        }

        shutdown = 1;
        for(int j=0; j<size; j++){
            if(p[j].at <= currTime && burst[j] != 0){
                i = (burst[i] > burst[j] ? j : i);
                shutdown = 0;
            }
        }
    }

    printf("%d\n", currTime);
    dispProcs(p, size);

    printf("\navg waiting time = %f\navg turnaround time = %f\n", ((float)t_wt/size), ((float)t_tat/size));
    
}

int main(int argc, char** argv) {

    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);

    proc p[n];

    readProcs(p, n);

    sortProcs(p, n);
    dispProcs(p, n);

    fcfs(p, n);
    sjfPre(p, n);
    
    return (EXIT_SUCCESS);
}

