#include <stdio.h>

double sumdiag(double arr[10][10]){
    int i;
    double sum = 0;
    for(i = 0; i < 10; i++){
        sum = sum + arr[i][i];
    }
    return sum;
}

double sumall(double arr[10][10]){
    int i;
    int j;
    double sumtot = 0;
    double sumrow = 0;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            sumrow = sumrow + arr[i][j];
        }
        sumtot = sumtot + sumrow;
        sumrow = 0;
    }

    return sumtot;
}

double avright(double arr[10][10]){
    double avg = 0;
    int i;

    for(i = 0; i < 10; i++){
        avg = avg + arr[i][9];
    }
    avg = avg/10;
    return avg;
}

double corners(double arr[10][10]){
    double sum = arr[0][0] + arr[0][9] + arr[9][0] + arr[9][9];
    return sum;
}

double largeanti(double arr[10][10]){
    int i;
    int j = 9;
    double largest = -99999;
    for(i = 0; i < 10; i++){
        if(arr[i][j] >= largest){
            largest = arr[i][j];
        }
        j--;
    }
    return largest;
}