package com.project.Stacks.ChallengersGfG;

import java.util.Arrays;

public class Main {

    static char[] arrayChars = new char[50];
    static int top = -1;

    public static void main(String[] args){
    // Casos donde debe devolver true (balanceado):

   isParenthesisBalanced("()"); // true

   isParenthesisBalanced("{[()]}"); // true

   isParenthesisBalanced("({[()]})"); // true

   isParenthesisBalanced(""); // true

   isParenthesisBalanced("{()}"); // true



    // Casos donde debe devolver false (no balanceado):
   isParenthesisBalanced(")"); // false

   isParenthesisBalanced("("); // false

   isParenthesisBalanced("{[}"); // false

   isParenthesisBalanced("{[(])}"); // false

   isParenthesisBalanced("({[}])}"); // false

   isParenthesisBalanced("{[("); // false
                                    //
    isParenthesisBalanced("{[()]})"); // false


    //Casos adicionales

   //isParenthesisBalanced("a{b[c]d}e"); // true
   //
   //isParenthesisBalanced("({[})"); // false
   //
   //isParenthesisBalanced("{[(()])}"); // false
   // isParenthesisBalanced("](())");
    isParenthesisBalanced("{[()()]}");
        
    }
    static boolean isParenthesisBalanced(String s) {
        Arrays.fill(arrayChars, '\0'); 
        char[] charSequence = s.toCharArray();
        byte verify = 0;
        byte cont = 0;
        byte contT = 0;

        for(char character : charSequence){

            if(character == '{' || character == '[' || character == '('){
                push(character);
                cont++;
            }
            else if(character == '}' || character == ']' || character == ')'){ 
                contT++;
                if(!isEmpty()){ 
                    char characterX = pop();
                    if(characterX == '{' && character == '}'){
                        verify++;
                    }
                    else if(characterX == '[' && character == ']'){
                        verify++;
                    }
                    else if(characterX == '(' && character == ')'){
                        verify++;
                    }
                }  
            }
        }
        //System.out.println("esto es " + verify);
        if(verify >=1 && cont == verify && contT == verify){
            System.out.println("true");
            return true;
        }
        System.out.println("false");
        return false;
    }

    public static void push(char c){
        arrayChars[++top] = c;
    }

    public static char pop(){
        return arrayChars[top--];
    }

    public static boolean isEmpty(){
        return top == -1;
    } 
}
