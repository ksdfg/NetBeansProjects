/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

/**
 *
 * @author ksdfg
 */
public class Mummy {
    
    String name;
    private final Producer[] p;
    private final Consumer[] c;
    
    public Mummy(String name, int resId, int prod, int con){
        this.name = name;
                
        p = new Producer[prod];
        for(int i=0; i<prod; i++)
            p[i] = new Producer(name+".p"+i, resId);
        
        c = new Consumer[con];
        for(int i=0; i<con; i++)
            c[i] = new Consumer(name+".c"+i, resId);
    }
    
    public void start(){
        for (Producer p1 : p)
            p1.start();
        
        for(Consumer c1 : c)
            c1.start();
    }
    
}
