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
abstract class MummyThread extends Thread {
    
    public static Resource[] resList;    //The shared resource, a queue in this case
    protected boolean shutdown;      //boolean to stop the process when it's work is done
    String name;                     //name of the process
    int resId;                    //index of the resource to get from resList       

    public MummyThread(String name, int resId) {
        this.name = name;
        this.resId = resId;
        this.shutdown = false;
    }
    
    abstract void doJob();  //overridden in producer / consumer

    @Override
    public void run() {        
        do{
            if(resList[resId].semaphore.tryLock()){    //gets lock and returns true if free (basically wait)
                try{
                    this.doJob();
                }
                catch(Exception e){     //just in case
                    System.out.println(e.toString());
                }
                finally{
                    resList[resId].semaphore.unlock();     //frees resource (basically signal)
                }
            }
        } while(!shutdown);
        
        System.out.println(name + " stopped."); //notify that the thread has stopped.
    }
    
}
