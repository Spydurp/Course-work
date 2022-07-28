#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Remove non-alphabet characters and spaces
// convert capital letters to lower case
// return stripped function
void strip(char original[], char stripped[]){
    int i;
    int j = 0;
    int spaces = 0;

    for(i = 0; i < strlen(original); i++){
        if(original[i] == '\0'){
            break;
        }
        if(isalpha(original[i]) == 0){
            j = j-1;
            spaces = spaces + 1;
        }else if(isalpha(original[i])){
            if(isupper(original[i])){
                stripped[j] = tolower(original[i]);
            }else{
                stripped[j] = original[i];
            }
        }
        j = j+1;
        
        
        
    }
    
}

// reverse the order of the characters in the string using recursion
void reverse(char original[], char reversed[], int n){
    if (n != strlen(original)){
        reverse(original, reversed, n+1);
    }
    reversed[n] = original[strlen(original) - n];
}

// get the size of the stripped and reversed strings for easy initialization
int finalsize(char input[]){
    int i;
    int size = 1;
    for(i = 0; i < strlen(input); i++){
        if(isalpha(input[i])){
            size = size + 1;
        }
    }

    return size;
}

int main(void){

    // create string with decent size
    char input[50];
    
    // take input
    printf("Input a string: \n");
    fgets(input, 50, stdin);

    // repeat input
    printf("\nInput: %s", input);

    // find the size of the final string
    int size = finalsize(input);

    // create and initialize stripped and reversed strings
    char stripped[size];
    char reversed[size];

    // strip input, ensure end character is in place, get rid of unwanted addons
    strip(input, stripped);
    stripped[size - 1] = '\0';
    
    // Reverse stripped string
    reverse(stripped, reversed, 0);
    // end character is now at the front, remove it
    reversed[0] = ' ';
    memmove(reversed, reversed+1, strlen(reversed));
    // replace end character
    reversed[size-1] = '\0';   
    
    // compare stripped vs reversed strings
    // output result
    if(strcmp(reversed, stripped) == 0){
        printf("\nPalindrome");
    }else{
        printf("\nNot a palindrome");
    }



    return 0;
}