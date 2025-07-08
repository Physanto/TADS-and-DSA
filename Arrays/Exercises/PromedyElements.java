package com.project.Arrays.Exercises;

import java.util.Random;

public class PromedyElements {
    
    public static void main(String[] args){ 
        
        Random random = new Random();

        int[] numbers = new int[10];

    }

    /**
     * Ingresa los elementos al array
     * 
     * @param numbers array de numeros 
     * @param random instancia de la clase random
     */
    public static void inputElements(int[] numbers, Random random){
        
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(0,10);
        }
    }

}
