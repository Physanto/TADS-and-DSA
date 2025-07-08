package com.project.Arrays;

public class ScoreBoard {
    private int numEntries = 0;
    private GameEntry[] board;
    private int capacity; 
    
    public ScoreBoard(int capacity) {
        this.capacity = capacity;
        board = new GameEntry[capacity];
    }
    
    public void add(GameEntry score){

        int newScore = score.getScore();

        if(numEntries == 0 || (numEntries < capacity && newScore < board[numEntries-1].getScore())){
            board[numEntries] = score;
            numEntries++;
            return;
        }

        if(numEntries >= capacity){
            System.out.println("arreglo lleno");
            return;
        }


        int extract = extractInitalPosition(newScore);

        // if(extract != -1){
               // agrego el elemento y desplazo una posicion a la derecha cada uno
        //     for (int i = extract; i <= numEntries; i++) {
        //         Object temp = board[i];
        //         board[i] = score;
        //         score = (GameEntry)temp;
        //     }         
        //     numEntries++;
        // }
        
        if(extract != -1){
            // desplazo los elementos uno a uno empezando desde el ultimo hasta donde se va agregar el nuevo
            for (int i = numEntries-1; i >= extract; i--) {
                board[i+1] = board[i];
            }         
            board[extract] = score;
            numEntries++;
        }
    }    
    /**
     * extrae el indice donde debe de ser agregado el elemento
     *
     * @param int newScore es el valor del elemento que se va agregar
     * @return el indice del array donde se va almacenar el elemento
     */
    public int extractInitalPosition(int newScore){

        for (int i = 0; i < capacity; i++) {

            if(newScore > board[i].getScore()){
                return i;
            }
        }
        return -1;
    }

    /**
     * elimina el elemento indicado y dezplaza los objetos una posicion a la izquierda
     *
     * @param int index : indice del elemento a eliminar
     */ 
    public void remove(int index) throws IndexOutOfBoundsException {
        
        if(index > capacity || index < 0){
            throw new IndexOutOfBoundsException("indice no valido " + index);
        }

        if(numEntries == 0){
            System.out.println("No se pueden eliminar mas elementos porque el array esta vacio");
        }

        for (int i = index; i < numEntries; i++) {
            board[i] = board[i+1];
        }         
        numEntries--;
    }

    public void todo(){

        for (GameEntry gameEntry : board) {
            System.out.println(gameEntry);
        }
    }
}

