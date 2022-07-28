#include <stdio.h>
#include <math.h>

// Returns nearest whole number payback periods (rounded up)
int main(void){
    double i;
    double n = 0;
    double icost;
    double payper;
    double paid = 0;
    double pfin;
    int count;

    printf("Input interest rate(decimal form): ");
    scanf("%lf", &i);
    printf("Input inital cost: ");
    scanf("%lf", &icost);
    printf("Input return per period: ");
    scanf("%lf", &payper);

    while(paid < icost){
        n++;
        pfin = 1/pow((1+i),n);
        paid = paid + payper*pfin;
    }
    paid = 0;
    n = 0;
    //while(icost >= 0){
       // n++;
    //}

    printf("\nDiscounted Payback Period is: %lf", n);

    

    return 0;
}

