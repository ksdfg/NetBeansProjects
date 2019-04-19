/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * Author: Kshitish
 * Panel : 5 (E4)
 * Roll no. : 203344
 * Serial Number : 55
 *
 * Created on April 11, 2019, 8:52 AM
 */

#include <cstdlib>
#include <iostream>
#include "fbGraph.h"

using namespace std;

int main(int argc, char** argv) {
    
    int users;
    cout<<"Enter number of users in the graph : ";
    cin>>users;
    
    Graph* fb = new Graph(users);
    fb->create();
    fb->display();
    fb->dfs_r();
    cout<<endl;
    fb->dfs_nr();
    cout<<endl;
    fb->bfs_nr();

    return 0;
}

