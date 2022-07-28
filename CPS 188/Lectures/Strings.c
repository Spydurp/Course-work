#include <stdio.h>

int main(void){

    char airline[] = "Air Canada";
    char cars[10][15] = {"Toyota"};

    printf("%s", cars);

    printf("Enter car name: ");
    fgets(cars[1], 15, stdin);
    
    printf("\neneter airline: ");
    scanf("%s", airline);

    printf("\n%s", airline);



    return 0;
}