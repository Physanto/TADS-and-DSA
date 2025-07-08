package com.project.Queues;

public class Queue {

    private int sizeDefault = 5;
    private int size;
    private char[] arrayQueue;
    private int front;
    public int rear;
    public int cantItems;

    public Queue(){
        arrayQueue = new char[sizeDefault];
        front = 0;
        rear = -1;
        cantItems = -1;
    }
    public Queue(int size){
        this.size = size;
        arrayQueue = new char[size];
        front = 0;
        rear = -1;
        cantItems = -1;
    }

    public void push(char element){
        if(isFullyCircular()){
            if(rear == size-1){
                rear = -1;
            } 
            arrayQueue[++rear] = element;
            ++cantItems;
        } 
        else if(!isFully()){
            ++cantItems;
            arrayQueue[++rear] = element;
        }
    }
    
    public char pop(){
        if(!isEmpty()){
            --cantItems;
            return arrayQueue[front++]; 
        }
        return 'z';
    }

    public char rearPeek(){
        return arrayQueue[rear];
    }

    public char frontPeek(){
        return arrayQueue[front];
    }

    public boolean isFully(){
        return cantItems == size - 1;
    }

    public boolean isFullyCircular(){
        return (size - 1 == rear || rear < front-1) && front != 0 ;
    } 

    public boolean isEmpty(){
        return cantItems == 0;
    }

    public void printQueue(){
        for(char c : arrayQueue){
            System.out.println(c);
        }
    }
}
