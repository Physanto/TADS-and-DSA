package com.project.Arrays.Exercises;

import java.util.Random;

/**
 * Clase para la suma de elementos de un array
 *
 * @author P
 */

public class SumElements {
     
    public static void main(String[] args){

        Random random = new Random();

        int[] numbers = new int[10];
        
        inputElements(numbers, random);

        System.out.println("Elementos ingresados al arreglo de forma aleatoria");
        printArray(numbers);

        System.out.println("\nSuma de elementos: " + sumElements(numbers));
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
    
    /**
     * Suma todos los elementos del array
     *
     * @param numbers array de numeros
     */
    public static int sumElements(int[] numbers){
        
        int sumElements = 0;

        for (int i = 0; i < numbers.length; i++) {
            sumElements += numbers[i];
        }
        return sumElements; 
    }
    
    /**
     * Imprime el array que se pase por parametro
     * @param numbers array de numeros
     */
    public static void printArray(int[] numbers){

        for (int i : numbers) {
            System.out.println(i);
        }
    }

    
}
