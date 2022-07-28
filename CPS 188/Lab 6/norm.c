#include <stdio.h>

int main(void){

    // Open file
    FILE *set;

    set = fopen("set.txt", "r");
    int count;
    double min;
    double max;

    // Loop until end of file
    while(fscanf(set, "%d", &count) != EOF){
        int i;
        double normx;
        // set numbers to really high/really low
        double low = 9999999;
        double high = -9999999;
        double read;

        // scan min and max
        fscanf(set, "%lf", &min);
        fscanf(set, "%lf", &max);

        // make array using count
        double arr[count];

        // put numbers into array, find lowest and highest number
        for(i = 0; i < count; i++){
            fscanf(set, "%lf ", &read);
            arr[i] = read;
            if(arr[i] < low){
                low = arr[i];
            
            }
            if(arr[i] > high){
                high = arr[i];
            
            }
        
        }

        //printf("\nhigh: %lf, low: %lf", high, low);
        //printf("\nmax: %lf, min: %lf", max, min);
        printf("\n");

        // normalize each number and output results
        printf("\nOriginal        Normalized");

        for(i = 0; i < count; i++){
            normx = min + (arr[i]-low) * (max - min) / (high - low);
            printf("\n%lf      %lf", arr[i], normx);
        }
        
    }

    // close file
    fclose(set);
    

    return 0;
}