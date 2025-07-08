package com.project.Arrays.Exercises;

import java.util.Random;

/**
 * Operaciones basicas que se pueden hacer con Arrays
 */ 

public class OperationsArrays {

    private int[] elements;
    private int size;


    public OperationsArrays(int size){
        this.size = size;
        elements = new int[size];

    }

    @Override
    public String toString(){

        String string = "[";
                                    //esto se podria mejorara con la clase StringBuilder que es mas eficiente cuando se quiere mutar cadenas
        for(int i : elements){
            string += String.valueOf(i);
            string += ", ";
        }
        string += "]";
        return string;
    }


    /**
     * Llena el array con elementos aletorios
     */
    public int[] fillArrayElementsRandom(){

        Random random = new Random(); 

        for (int i = 0; i < elements.length; i++) {
            elements[i] = random.nextInt(0,10);
        }
        return elements;
    }
    
    /**
     * Suma todos los elementos del array
     */
    public int sumElements(){
        
        int sumElements = 0;

        for (int i = 0; i < elements.length; i++) {
            sumElements += elements[i];
        }
        return sumElements; 
    }
    
    public float promedyValues(){
        
        int sumElements = sumElements();

        if(sumElements == 0){
            return 0;
        } 
        return sumElements / size;
    }

    public void maxAndMinValue(){
        
        int max = elements[0];
        int min = elements[0];

        for(int i = 0; i < elements.length; i++){

            if(max < elements[i]){
                max = elements[i];
            }
            else if(min > elements[i]){
                min = elements[i];
            }
        }
        System.out.println("el menor es: " + min + " y el mayor es: " + max);
    }

    public int searchElement(int element){
        
        for (int i = 0; i < elements.length; i++) {

            if(element == elements[i]){
                return i;
            }
        }
        return -1;
    }

    public void reverseArray(){
    
        int temp;

        for (int i = 0, j = elements.length-1; i < elements.length / 2; i++, j--) { 

            temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        } 
    }

    public void deleteDuplicates(){

        for (int i = 0; i < elements.length; i++) {
            for (int j = i+1; j < elements.length; j++) {

                if(elements[i] == elements[j]){
                    moveElements(j);
                }
            } 
        }
    }

    public void moveElements(int index){
        
        for (int i = index; i < elements.length - 1; i++) {
            elements[i] = elements[i+1];
        }
        elements[elements.length-1] = 0;
    }

    public void movePositionElementsArray(){

        int prev = elements[0];
        for (int i = 1; i < elements.length; i++) {
            int temp = elements[i];
            elements[i] = prev;
            prev = temp;
        }
    }

    public void movePositionElementsArray(int position){
        
        int lenght = elements.length - 1;

        position %= lenght;
        int k = 0;
        for(int i = 0; i < elements.length - position; i++){

            int prev = elements[i]; 
            int j = i;

            while(j <= lenght){

                j = j + position;
                int temp = elements[j];
                elements[j] = prev;
                prev = temp;
                
                if((j+position) >= lenght) break;

            }
            while(j <= lenght){

                j = j + position;
                int temp = elements[j];
                elements[j] = prev;
                prev = temp;
                k = j;
                
                if((k+position) >= lenght){
                    j = (j + position) - elements.length;
                } 
            } 

        }
    }
    
    /**
     * Ordena un array en orden creciente
     */
    public void sortArray(){
        
        for (int i = 0; i < elements.length; i++) {

            for (int j = 0; j < i; j++) {

                if(elements[j] > elements[i]){
                    int aux = elements[i];
                    elements[i] = elements[j];
                    elements[j] = aux;
                }
            }
        }
    }

    public void secondNumberMax(){ 

        int max = elements[0];
        int secondMax = 0;
        int thirdMax = 0;
        for(int i = 1; i < elements.length; i++){

            if(max < elements[i]){
                thirdMax = secondMax;
                secondMax = max;
                max = elements[i]; 
            } 
            else if(secondMax < elements[i] && elements[i] != max){ 
                secondMax = elements[i];
            }
            else if(thirdMax < elements[i] && elements[i] != secondMax){
                thirdMax = elements[i];
            }
        }
        System.out.println("el elemento mas grande es " + max + " y el segundo mas grande es " + secondMax + " tercero " + thirdMax);
    }
    /**
     * Imprime el array
     */
    public void printArray(){

        for (int i : elements) {
            System.out.println(i);
        }
    }

    public static void main(String[] args){
        
        OperationsArrays operationsArrays = new OperationsArrays(6);
        
        operationsArrays.fillArrayElementsRandom();
        operationsArrays.printArray();
        //operationsArrays.sortArray();
        System.out.println("\n\n");

        operationsArrays.printArray();

        operationsArrays.secondNumberMax();


        // System.out.println("Elementos ingresados al arreglo de forma aleatoria");
        // operationsArrays.printArray();
        //
        // System.out.println("\nSuma de elementos: " + operationsArrays.sumElements());
    }
}
