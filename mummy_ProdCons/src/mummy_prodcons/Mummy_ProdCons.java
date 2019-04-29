/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mummy_prodcons;

import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author ksdfg
 */
public class Mummy_ProdCons {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Enter number of resources / queues : ");
        int n = (new Scanner(System.in)).nextInt();
        MummyThread.resList = new Resource[n];
        
        for(int i=0; i<n; i++)
            MummyThread.resList[i] = new Resource(new LinkedList<>());
        
        for(int i=0; i<n; i++)
            (new Mummy("mummy-"+i, i, 2, 2)).start();
    }
    
}
