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

    public Consumer(String name, int resId) {
        super(name, resId);
    }

    @Override
    protected void doJob() {
        String s = resList[resId].queue.poll();    //remove front element from queue
        
        if(s != null){  //poll() returns null if queue empty
            try{
                System.out.println(s + " removed by " + name + " from queue " + resId + ".\t" + resList[resId].queue);
            }
            catch(java.util.ConcurrentModificationException e){    //in case of fail
                System.out.println("HOUSTON, WE'VE GOT A PROBLEM\t" + name + " failed");
            }
            
            shutdown = s.equals("stop");   //stop the thread if true
        }
    }
    
}
