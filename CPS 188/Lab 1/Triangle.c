#include <stdio.h>
#include <math.h>

int
main(void){
     
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