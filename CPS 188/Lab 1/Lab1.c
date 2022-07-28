#include <stdio.h>
#include <math.h>

int main(void){

    /* Problem 1 */

    int Lowest;
    int current;
    int size;
    int intCount;
    int swap = 1;
    int old;

    printf("input array size: ");
    scanf("%d", &size);

    int array [size];

    for(intCount = 0; intCount < size; intCount ++){
        printf("Input 2 digit number: ");
        scanf("%d", &array[intCount]);
    }

     for(intCount = 0; intCount < size; intCount ++){
        printf("%d, ", array[intCount]);
        
    }

    while(swap > 0){
        swap = 0;
        for(intCount = 0; intCount < size - 1; intCount++){
            Lowest = array[intCount];
            current = array[intCount + 1];
            if(Lowest > current){
                array[intCount] = current;
                array[intCount + 1] = Lowest;
                swap ++;
            }
        }
        printf("\nloop");
    }
        
        printf("\n");

     for(intCount = 0; intCount < size; intCount ++){
        printf("%d, ", array[intCount]);
        
    }

    /* Problem 2 */

    printf("\nMy first program \n");

    /* Problem 3 */

    float a;
    float b;
    float c;

    printf("Input side A: ");
    scanf("%f", &a);

    printf("Input side B: ");
    scanf("%f", &b);

    c = sqrt(pow(a, 2)+pow(b, 2));
    c = roundf(c*100)/100;

    printf("The hypotenuse C is: %.2f", c);


    return 0;
}