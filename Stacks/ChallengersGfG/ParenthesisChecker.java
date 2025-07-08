package com.project.Stacks.ChallengersGfG;

public class ParenthesisChecker {

    static char[] arrayChars = new char[50];
    static int top = -1;

    public ParenthesisChecker(){ 

    }

    public static boolean isParenthesisBalanced(String s) {
                
        char[] charSequence = s.toCharArray();
        byte cont = 0;
        byte verify = 0;

        for(int i = 0; i < charSequence.length; i++){

            char character = charSequence[i];

            switch(character){

                case '{':
                case '[':
                case '(':
                    push(character);
                    break;

                case '}':
                case ']':
                case ')':

                    char characterX = pop();
                    if(character == '}' && characterX == '{' ||
                        character == ']' && characterX == '[' ||
                        character == ')' && characterX == '(' ){
                        verify++;
                        System.out.println("comparando lo que me llega " + character + " y saco de la pila: " + characterX);
                    }
                    break;

                default:
                    break;
            }

        }
        if(cont == verify){
            return true;
        }
        return false;
    }

    public static void push(char c){
        arrayChars[++top] = c;
    }

    public static char pop(){
        return arrayChars[top--];
    }
}
