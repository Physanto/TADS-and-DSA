package com.project.Queues;

public class Main {

    public static void main(String[] args){
        //
        // Queue queue = new Queue(6);
        //
        // queue.push('m');
        // queue.push('a');
        // queue.push('n');
        // queue.push('u');
        // queue.push('e');
        // queue.push('l');
        // System.out.println("elemento eliminado " + queue.pop());
        // System.out.println("elemento eliminado " + queue.pop());
        // queue.push('f');
        // queue.push('k');
        // queue.push('h');
        // queue.printQueue();
        // System.out.println("cantidad terminos " + queue.cantItems);

        PriorityQueue priorityQueue = new PriorityQueue(5);

        priorityQueue.push(10);
        priorityQueue.push(20);
        priorityQueue.push(30);

        priorityQueue.print();
    }
}
