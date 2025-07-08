
public class Main{
    
    public static void main(String[] args){ 

        Stackk<Integer> stack = new Stackk<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);

        System.out.println("ELEMENTOS QUE APILO\n");
        System.out.println(stack.get(0));
        System.out.println(stack.get(1));
        System.out.println(stack.get(2));
        System.out.println(stack.get(3));
        System.out.println(stack.get(4));
        System.out.println(stack.get(5));
        System.out.println("este es el peek " + stack.peek());

        System.out.println("\nELEMENTOS QUE DESAPILO\n");
        stack.emptyAll();
        System.out.println(stack.get(0));
        System.out.println(stack.get(1));
    }

    public static void showStack(Stackk<Integer> stack){
        for(int i = 0; i < stack.peek(); i++){      
            System.out.println(stack.get(i));
        }
    }
}
