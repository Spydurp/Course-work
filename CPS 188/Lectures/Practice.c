#include <stdio.h>

int main(void){

    int i = 0;
    FILE* in;
    double temp;

    in = fopen("numbers.txt", "r");

    fscanf(in, "%lf", &temp);
    while(!feof(in)){
        printf("\n%lf", temp);
        fscanf(in, "%lf", &temp);
    }

    fclose(in);

    return 0;
}