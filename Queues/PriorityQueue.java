package com.project.Queues;

public class PriorityQueue {

    private int size = 10;
    private int[] queArray;
    private int front;
    private int rear;
    private int cantItems;

    public PriorityQueue(){  
        queArray = new int[size];
        front = -1;
        rear = -1;
        cantItems = 0;
    }

    public PriorityQueue(int size){
        this.size = size;
        queArray = new int[size];
        front = -1;
        rear = -1;
        cantItems = 0;
    }

    public void push(int element){
        
        if(cantItems == 0){
            queArray[cantItems++] = element;
            ++front;
            return;
        }

        for (int i = 0; i <= cantItems; i++) {

            if(element < queArray[i] || queArray[i] == 0){
                
                //corre los elementos hacia atras para dejar el espacio en (i) 
                for (int j = cantItems; j >= i; j--) {
                   queArray[j+1] = queArray[j];
                }
                //agrega el elemento hasta donde llega i
                queArray[i] = element;
                cantItems++;
            } 
        }
    }

    // public boolean isEmpty(){
    //
    // }

    public boolean isFully(){
        return cantItems == size;
    }

    public void print(){
        for (int c : queArray) {
           System.out.println(c); 
        }
    }
}


