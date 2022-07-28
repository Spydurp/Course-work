#include <stdio.h>
#include <math.h>

float spsound(float tempC){
    float a = 0;
    float speed = 0;
    float tempF = 0;

    tempF = (tempC*9/5) + 32;
    a = 1086*sqrt((5*tempF + 297)/247);
    speed = a*1.097;

    return speed;
}

int
main(void){

    float Speedms = 0;
    float tempC = 0;

    printf("Input Temperature in Celcius: ");
    scanf("%f", &tempC);

    
    Speedms = spsound(tempC);

    printf("The speed of sound is: %f km/h", Speedms);

    return 0;
}