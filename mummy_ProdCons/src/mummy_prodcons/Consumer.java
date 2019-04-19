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
        String s = res.queue.poll();
        
        if(s == null){
            System.out.println(name + " can't consume from an empty queue.");
        }
        else{
            System.out.println(s + " removed by " + name + " from queue.\t" + res.queue);
            if(s.equals("stop")){
                shutdown = true;
                System.out.println(name + " stopped.");
            }
        }
    }
    
}
