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
class Consumer extends MummyThread{

    public Consumer(String name) {
        super(name);
    }

    @Override
    void doJob() {
        String s = MummyThread.res.queue.poll();    //remove front element from queue
        
        if(s != null){  //poll() returns null if queue empty
            try{
                System.out.println(s + " removed by " + name + " from queue.\t" + MummyThread.res.queue);
            }
            catch(java.util.ConcurrentModificationException e){    //in case of fail
                System.out.println("HOUSTON, WE'VE GOT A PROBLEM\t" + name + " failed");
            }
            
            if(s.equals("stop")){   //stop the thread
                shutdown = true;
            }
        }
    }
    
}
