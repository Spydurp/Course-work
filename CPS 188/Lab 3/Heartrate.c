#include <stdio.h>
#include <math.h>

int main(void){

    char gender;
    int age;
    double maxRate;
    double trainRate;
    int restRate;
    char fitLevel;
    double inten;
    int rounded;

    printf("Input Gender: (M)ale (F)emale \n");
    scanf("%c", &gender);

    printf("Input Age: ");
    scanf("%d", &age);

    printf("Input resting heart rate: ");
    scanf("%d", &restRate);

    printf("Input Fitness Level: \n(L)ow   (M)edium   (H)igh \n");
    scanf(" %c", &fitLevel);


    if(gender == 'M'){
        maxRate = 203.7/(1+exp(0.033*(age-104.3)));
    }else if(gender == 'F'){
        maxRate = 190.2/(1+exp(0.0453*(age-107.5)));
    }

    if(fitLevel == 'L'){
        inten = 0.55;
    }else if(fitLevel == 'M'){
        inten = 0.65;
    }else if(fitLevel == 'H'){
        inten = 0.8;
    }

    trainRate = (maxRate - restRate) * inten + restRate;
    rounded = round(trainRate);

    printf("Your training heart rate is: %d", rounded);

    return 0;
}