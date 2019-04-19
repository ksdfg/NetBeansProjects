/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

import java.util.Queue;

/**
 *
 * @author ksdfg
 */
class Resource {    //class for shared resources, queue for now
    
    boolean semaphore;      //true if free
    Queue<String> queue;    //the shared resource

    public Resource(Queue<String> queue) {
        this.queue = queue;
        this.semaphore = true;
    }            
    
}
