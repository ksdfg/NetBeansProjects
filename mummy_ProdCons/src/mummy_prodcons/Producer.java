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
    static Random r = new Random();     //to randomly pick one
    
    public Producer(String name) {
        super(name);
    }

    @Override
    void doJob() {
        String s = data[r.nextInt(5)];      //pick an element randomly
        
        try{
            MummyThread.res.queue.offer(s); //add string to queue if queue not full
            System.out.println(s + " entered by " + name + " into queue.\t" + MummyThread.res.queue);
        }
        catch(java.util.ConcurrentModificationException e1){    //in case of fail
            System.out.println("HOUSTON, WE'VE GOT A PROBLEM\t" + name + " failed");
        }
        
        if(s.equals("stop")){   //stop the thread
            shutdown = true;
        }
    }
    
}
