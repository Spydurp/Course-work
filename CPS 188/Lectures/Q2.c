#include <stdio.h>

int main(void){
    int input;
    printf("Input an integer between 1 and 4\n");
    scanf("%d", &input);

    switch(input){
        case 1:
            printf("Stuff");
            break;
        case 2:
            printf("Stuff");
            break;
        case 3:
            printf("Stuff");
            break;
        case 4:
            printf("Stuff");
            break;
        default:
            printf("Invalid");
    }

    return 0;
}