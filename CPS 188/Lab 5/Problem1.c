#include <stdio.h>

/*
Sequence function
Sorts values from least to greatest
returns 0
sets values directly
*/
int 
sequence(int array[3], int* low, int* mid, int* high){
    int i;
    int cur;
    int next;
    int swap;

    // Sort the array
    while(swap != 0){
        swap = 0;
        for(i = 0; i < 3; i++){
            cur = array[i];
            if(i == 2){
                break;
            }
            next = array[i+1];
            if(cur > next){
                array[i] = next;
                array[i+1] = cur;
                swap = 1;
            }
        
        }
    }

    // Set values
    *low = array[0];
    *mid = array[1];
    *high = array[2];
    
    return 0;
    
}

int
main(void){

    // Variables
    int in[3];
    int high;
    int mid;
    int low;

    // Get numbers
    for(int i = 0; i < 3; i++){
        printf("Input Integer: ");
        scanf("%d", &in[i]);
    }

    // Call function
    sequence(in, &low, &mid, &high);

    // Print
    printf("%d, %d, %d", low, mid, high);

    return 0;
}