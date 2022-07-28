#include <stdio.h>
#include <math.h>

int main(void){

    double i;
    double n;
    int choice;
    double g;
    double adji;

    double fpin;
    double pfin;

    double afin;
    double fain;

    double apin;
    double pain;

    double aGin;
    double pagin;

    printf("Enter interest rate(decimal form): ");
    scanf("%lf", &i);
    printf("Enter number of periods: ");
    scanf("%lf", &n);

    fpin = pow(1+i,n);
    pfin = 1/fpin;

    afin = i/(pow(1+i,n)-1);
    fain = 1/afin;

    apin = (i*pow(1+i,n))/(pow(1+i,n)-1);
    pain = 1/apin;

    aGin = (1/i) - (n/(pow(1+i,n)-1));

    printf("1: F/PiN\n2: P/FiN\n3: A/FiN\n4: F/AiN\n5: A/PiN\n6: P/AiN\n7: A/GiN\n8: P/AgiN \n");
    scanf("%d", &choice);

    if(choice == 1){
        printf("\nF/PiN: %lf", fpin);
    }else if(choice == 2){
        printf("\nP/FiN: %lf", pfin);
    }else if(choice == 3){
        printf("\nA/FiN: %lf", afin);
    }else if(choice == 4){
        printf("\nF/AiN: %lf", fain);
    }else if(choice == 5){
        printf("\nA/PiN: %lf", apin);
    }else if(choice == 6){
        printf("\nP/AiN: %lf", pain);
    }else if(choice == 7){
        printf("\nA/GiN: %lf", aGin);
    }else if(choice == 8){
        printf("\nEnter g: ");
        scanf("%lf", g);
        adji = (1+i)/(1+g) - 1;
        pagin = (pow((1+adji),n) - 1) / (adji*pow((1+adji),n)) * (1/(1+g));
        printf("\nP/AgiN: %lf", pagin);
    }

    return 0;
}