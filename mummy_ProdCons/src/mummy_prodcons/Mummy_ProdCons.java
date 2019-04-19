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
        
        MummyThread.setResource(queue);
        
        Thread p1 = new Thread(new Producer("p1"));
        Thread c1 = new Thread(new Consumer("c1"));
        
        p1.start();
        c1.start();
    }
    
}
