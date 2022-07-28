#include <stdio.h>
#include <math.h>

int main(void){

    double height;
    double weight;
    double BMI;
    double rounded;

    for(int i = 0; i < 3; i++){
        printf("\nInput height in meters: ");
        scanf("%lf", &height);

        printf("Input weight in kg: ");
        scanf("%lf", &weight);

        BMI = weight/(pow(height,2));
        rounded = round(BMI*10)/10;

        if(BMI < 18.5){
            printf("Your BMI value is %.1lf, which classifies you as Underweight", rounded);
        }else if(BMI >= 18.5 && BMI <=24.9){
            printf("Your BMI value is %.1lf, which classifies you as Normal", rounded);
        }else if(BMI >= 25 && BMI <= 29.9){
            printf("Your BMI value is %.1lf, which classifies you as Overwieght", rounded);
        }else if(BMI >= 30){
            printf("Your BMI value is %.1lf, which classifies you as Obese", rounded);
        }
    }

    return 0;
}