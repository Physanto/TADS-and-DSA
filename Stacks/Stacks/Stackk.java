
public class Stackk<T>{ 

    // longitud del stack;
    private int index;

    // estructura contenedora
    private Object[] stack;

    // tamano predefinido
    private final int SIZE_DEFAULT = 5;

    // tamano del stack
    private int size = SIZE_DEFAULT;

    public Stackk(){
        stack = new Object[SIZE_DEFAULT];
        index = -1;
    }

    public <V> boolean push(V element){  

        if(index == size-1){  
            copyArray();
        }
        stack[++index] = element;
        return true;
    }

    public Object pop(){

        if(isEmpty()) return null;
        Object garbage = stack[index];
        stack[index--] = null;
        return garbage;
    }

    public int peek(){
       return index + 1; 
    }

    public boolean isEmpty(){ 
        return index == -1;
    }

    public void emptyAll(){ 

        int sizes = peek();
        for (int i = 0; i < sizes; i++){ 
            pop();
        }
    }

    public Object get(int index){
        try{
            return stack[index];
        }
        catch(IndexOutOfBoundsException ex){ 
            return ex;
        }
    }

    public void copyArray(){        

        Object[] arrayToCopy = new Object[stack.length + 5];

        for(int i = 0; i < stack.length; i++) { 
            arrayToCopy[i] = stack[i];
        } 
        stack = arrayToCopy;
        size = stack.length;
    }
}
