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
class MummyThread extends Thread {
    
    protected Resource res;    //The shared resource, a queue in this case
    protected boolean shutdown;       //boolean to stop the process when it's work is done
    String name;            //name of the process
    
    private Producer[] producer;
    private Consumer[] consumer;

    public MummyThread(String name) {
        this.name = name;
        shutdown = false;
    }

    public MummyThread(Resource res, String name, int producer, int consumer) {
        this.res = res;
        this.name = name;
        
        this.producer = new Producer[producer];
        for(int i=0; i<producer; i++){
            this.producer[i] = new Producer(name + " : p" + (i+1));
        }
        
        this.consumer = new Consumer[consumer];
        for(int i=0; i<consumer; i++){
            this.consumer[i] = new Consumer(name + " : c" + (i+1));
        }
    }
    
    public void mummyStart(){
        for (Producer producer1 : producer) {
            producer1.start();
        }
        
        for (Consumer consumer1 : consumer) {
            consumer1.start();
        }
    }
    
    protected void doJob(){}  //overridden in producer / consumer

    @Override
    public void run() {        
        do{
            if(res.semaphore.tryLock()){    //gets lock and returns true if free (basically wait)
                try{
                    this.doJob();
                }
                catch(Exception e){     //just in case
                    System.out.println(e.toString());
                }
                finally{
                    res.semaphore.unlock();     //frees resource (basically signal)
                }
            }
        } while(!shutdown);
        
        System.out.println(name + " stopped."); //notify that the thread has stopped.
    }
    
}
