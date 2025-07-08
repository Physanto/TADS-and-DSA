package com.project.Arrays.ExercisesW3Resource;

public class Exercise8 {

    public static void main(String[] args){
        int size = 6;

        ResourcesForExercises resourcesForExercises = new ResourcesForExercises(size);
        int[] arrayNew = new int[size];

        resourcesForExercises.fillArrayElementsRandom();
        int[] arrayOriginal = resourcesForExercises.getElements();

        System.out.println("Impresion del array original\n");
        resourcesForExercises.printArray();

        System.out.println("Impresion de la matriz nueva llena\n");
        copyArray(arrayOriginal, arrayNew);
        resourcesForExercises.printArray();

    }

    public static void copyArray(int[] arrayOriginal, int[] arrayNew){
        for(int i = 0; i < arrayOriginal.length; i++) {
            arrayNew[i] = arrayOriginal[i];
        } 
    }

}
