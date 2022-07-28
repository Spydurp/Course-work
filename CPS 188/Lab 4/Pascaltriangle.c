#include <stdio.h>
#include <math.h>

int main (void){

    // declare variables
    int num1 = 1;
    int num2 = 0;
    int new = 0;
    int intCount;
    int i;
    // finding 9 rows
    int tri[9][9];
    
    // counting rows
    for(intCount = 0; intCount < 9; intCount ++){
        // counting columns
        for(i = 0; i < intCount + 1; i ++){
            // ones at the edges
            if(i == 0 || i == intCount){
                new = 1;
            }else{
                // get 2 numbers on top
                num1 = tri[intCount-1][i-1];
                num2 = tri[intCount-1][i];
                //add
                new = num1 + num2;
                
                
            }
            // put into array
            tri[intCount][i] = new;
            //print
            printf("%d ", new);
            
        }
        
        printf("\n");
        
    }

    return 0;
}