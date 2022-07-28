#include <stdio.h>
#include "mylibrary.h"

int main(void){
    FILE* numbers;
    numbers = fopen("num.txt", "r");

    double arr[10][10];
    int i;
    int j;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            fscanf(numbers, "%lf", &arr[i][j]);
        }
    }
    double sumdia = sumdiag(arr);
    double suma = sumall(arr);
    double avr = avright(arr);
    double corner = corners(arr);
    double large = largeanti(arr);

    FILE *output = fopen("data.bin", "wb");

    fwrite(&sumdia, sizeof(int), 1, output);
    fwrite(&suma, sizeof(int), 1, output);
    fwrite(&avr, sizeof(int), 1, output);
    fwrite(&corner, sizeof(int), 1, output);
    fwrite(&large, sizeof(int), 1, output);

    fclose(output);

    FILE *read = fopen("data.bin", "rb");
    
    fread(&sumdia, sizeof(int), 1, read);
    fread(&suma, sizeof(int), 1, read);
    fread(&avr, sizeof(int), 1, read);
    fread(&corner, sizeof(int), 1, read);
    fread(&large, sizeof(int), 1, read);

    printf("\nThe sum of the main diagonal is: %.1lf", sumdia);
    printf("\nThe sum of all numbers is: %.1lf", suma);
    printf("\nThe average of the right column is: %.1lf", avr);
    printf("\nThe sum of the four corners is: %.1lf", corner);
    printf("\nThe largest number in the antidiagonal is: %.1lf", large);

    return 0;
}