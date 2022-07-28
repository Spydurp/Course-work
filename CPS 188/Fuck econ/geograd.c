#include <stdio.h>
#include <math.h>

int main(void){

    int exit = 0;
    double interest;
    double g;
    double N;
    double adji;
    double PAIN;

    while (exit != 1){
        printf("Enter interest per period (decimal form): ");
        scanf("%lf", &interest);

        printf("Enter g (decimal form): ");
        scanf("%lf", &g);

        printf("Enter N: ");
        scanf("%lf", &N);

        adji = (1+interest)/(1+g) - 1;
        PAIN = (pow((1+adji),N) - 1) / (adji*pow((1+adji),N)) * (1/(1+g));

        printf("Geometric gradient factor: %lf", PAIN);

        printf("\nEnter 1 to exit, 0 to continue: ");
        scanf("%d", &exit);
        
    }

    return 0;
}