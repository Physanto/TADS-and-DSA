package com.project.Arrays;

import java.util.Random;

public class InsertionSort {
    static int[] numbers = new int[1000];
    static int numEntries = 0;

    public static void main(String[] args){ 
        
        Random random = new Random();
        
        long starTime = System.nanoTime();
        for (int i = 0; i < 1000; i++) {
            sortInsertion(random.nextInt(0,1000));
        }
        long finalTime = System.nanoTime(); 
        long totalTime = finalTime - starTime;

        System.out.println("\nesto es lo que tarda " + totalTime);


        int[] data = {4,6,2,7,5,8,10,3,9};
        insertionSort(data);
        for(int i : data){
            System.out.println(i);
        }
    }

    public static void sortInsertion(int element){

        if(numEntries == 0 || element > numbers[numEntries-1]){
            numbers[numEntries] = element;
            numEntries++;
            return;
        }

        for(int i = 0; i < numEntries; i++){

            if(element < numbers[i]){

                for(int j = i; j <= numEntries; j++){
                    int temp = numbers[j];
                    numbers[j] = element;
                    element = temp;
                }
                numEntries++;
                break;
            }
            
        }
        
    }

    /**
     * esta es la forma estandar de hacer el algoritmo de ordenar por insercion
     */
    public static void insertionSort(int[] data){
        int length = data.length;

        for(int i = 1; i < length; i++){
            int element = data[i];
            int j = i;

            while(j > 0 && data[j-1] > element){
                data[j] = data[j-1];
                j--;
            }
            data[j] = element;
        }
    }
}
