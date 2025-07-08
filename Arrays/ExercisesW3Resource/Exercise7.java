package Arrays.ExercisesW3Resource;

import Arrays.ExercisesW3Resource.*;
/**
 * Exercise 7: Write a program to remove a specific element from an array
 *
 * @see <a href"https://www.w3resource.com/java-exercises/array/index.php">W3resources</a>
 * 
 */
public class Exercise7 {
    
    public static void main(String[] args){

        ResourcesForExercises resourcesForExercises = new ResourcesForExercises(6);

        resourcesForExercises.fillArrayElementsRandom();
        int[] elements = resourcesForExercises.getElements();

        System.out.println("Impresion del array original\n");
        resourcesForExercises.printArray();


        removeElement(elements,elements[2]);

        System.out.println("Elemento eliminado\n");
        resourcesForExercises.printArray();

    }
    
    /**
     * remove an element specific
     *
     * @param elements is array from elements
     * @param element is element specific to remove
     */
    public static void removeElement(int[] elements, int element){

        int i = 0;

        for (i = 0; i < elements.length; i++) {
            if(element == elements[i]){
                break;
            }
        }
        moveElements(i, elements);
    }
    
    /**
     * move the elements one left position
     *
     * @param index where have start to move the elements
     * @param elements is array from elements
     */
    public static void moveElements(int index, int[] elements){
        
        for (int i = index+1; i < elements.length; i++) { 
           elements[i-1] = elements[i];
        }
        elements[elements.length-1] = 0;
    }
}
