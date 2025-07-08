package com.project.Arrays;

/**
 * Esto implementa un cifrado cesar no muy modular, pero a groso modo asi funciona un cifrado cesar
 * Ademas se puede modularizar mas, pero aqui solo se trata de saber como funciona y como se implementa en un modo basico.
 */
public class CaesarCipher {

    public static void main(String[] args){

        String txt = "manuel david";
        int rotation = 3;

        String txtCipher = caesarCipher(txt, rotation);

        System.out.println("Este es el mensaje cifrado: " + txtCipher);

        System.out.println("Este es el mensaje descifrado: " + caesarDecipher(txtCipher, rotation));

    }

    public static String caesarCipher(String txt, int rotation){
        
        char[] txtToArray = txt.toCharArray();

        for(int i = 0; i < txtToArray.length; i++){

            if(txtToArray[i] != ' '){ 
                txtToArray[i] += rotation;
            }
        }

        String txtToArrayCipher = new String(txtToArray);

        return txtToArrayCipher;
    }

    public static String caesarDecipher(String txtCipher, int rotation){

        char[] txtToArray = txtCipher.toCharArray();

        for(int i = 0; i < txtToArray.length; i++){

            if(txtToArray[i] != ' '){ 
                txtToArray[i] -= rotation;
            }           
        }

        String txtDecipher = new String(txtToArray);

        return txtDecipher;
    }
}
