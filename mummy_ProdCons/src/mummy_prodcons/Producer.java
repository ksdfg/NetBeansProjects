/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

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
            MummyThread.res.queue.add(s);
            System.out.println(s + " entered by " + name + " into queue.\t" + MummyThread.res.queue);
        }
        catch(IllegalStateException e){
            System.out.println(name + " cannot enter string into queue, it's full.");
        }
        catch(java.util.ConcurrentModificationException e1){
            System.out.println("HOUSTON, WE'VE GOT A PROBLEM\t" + name + " failed");
        }
        
        if(s.equals("stop")){
            shutdown = true;
            System.out.println(name + " stopped.");
        }
    }
    
}
