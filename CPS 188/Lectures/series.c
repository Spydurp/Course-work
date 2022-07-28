#include <stdio.h>
#include <math.h>

int main(void){

    double sum = 0;
    double i;

    for(i=1; i< 9999999; i++){
        sum = sum + 1/(pow(2,i));
        
    }
    printf("%lf, ", sum);

    return 0;
}