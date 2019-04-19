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
abstract class MummyThread implements Runnable {
    
    static Resource res;    //The shared resource, a queue in this case
    boolean shutdown;       //boolean to stop the process when it's work is done
    String name;            //name of the process

    public MummyThread(String name) {
        this.name = name;
        shutdown = false;
    }
    
    abstract void doJob();  //overridden in producer / consumer

    @Override
    public void run() {        
        do{
            if(res.semaphore){
                res.semaphore = false;
                this.doJob();
                res.semaphore = true;
            }
        } while(!shutdown);
    }
    
}
