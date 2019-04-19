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
class Consumer extends MummyThread{

    public Consumer(String name) {
        super(name);
    }

    @Override
    void doJob() {
        String s = MummyThread.res.queue.poll();
        
        if(s == null){
            System.out.println(name + " can't consume from an empty queue.");
        }
        else{
            try{
                System.out.println(s + " removed by " + name + " from queue.\t" + MummyThread.res.queue);
            }
            catch(java.util.ConcurrentModificationException e){
                System.out.println("HOUSTON, WE'VE GOT A PROBLEM\t" + name + " failed");
            }
            if(s.equals("stop")){
                shutdown = true;
                System.out.println(name + " stopped.");
            }
        }
    }
    
}
