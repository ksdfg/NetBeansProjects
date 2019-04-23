/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author ksdfg
 */
public class Mummy_ProdCons {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Queue<String> queue = new LinkedList<>();
        
        MummyThread.res = new Resource(queue);
        
        Producer[] p = new Producer[5];
        Consumer[] c = new Consumer[5];
        
        for(int i=0; i<5; i++){
            p[i] = new Producer("p" + (i+1));
            p[i].start();
            
            c[i] = new Consumer("c" + (i+1));
            c[i].start();
        }
    }
    
}
