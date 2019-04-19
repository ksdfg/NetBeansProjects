/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

import java.util.Queue;
import java.util.Random;

/**
 *
 * @author ksdfg
 */
class Producer extends MummyThread{
    
    String[] data = {"1", "2", "3", "4", "stop"};   //all possible data that can be produced
    static Random r;
    
    public Producer(String name) {
        super(name);
        Producer.r = new Random();
    }

    @Override
    void doJob() {
        String s = data[r.nextInt(5)];
        
        try{
            res.queue.add(s);
            System.out.println(s + " entered by " + name + " into queue.\t" + res.queue);
        }
        catch(IllegalStateException e){
            System.out.println(name + " cannot enter string into queue, it's full.");
        }
        
        if(s.equals("stop")){
            shutdown = true;
            System.out.println(name + " stopped.");
        }
    }
    
}
