package com.project.Arrays.ExercisesW3Resource;

import java.util.Random;

public class ResourcesForExercises{
    private int[] elements;
    private int size;

    public ResourcesForExercises(int size){
        this.size = size;
        elements = new int[this.size];
    }

    public void fillArrayElementsRandom(){

        Random random = new Random(); 

        for (int i = 0; i < elements.length; i++) {
            elements[i] = random.nextInt(1,10);
        }
    }

    public void printArray(){
        for(int element : elements){
            System.out.println(element);
        }
    }

    public int[] getElements(){ return elements; }
}
