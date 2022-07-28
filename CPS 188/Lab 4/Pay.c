#include <stdio.h>
#include <math.h>

int main(void){

    // declare variables
    FILE *data;
    int i = 0;
    double dump;
    int intCount;
    double shifts;

    //open file
    data = fopen("test.txt", "r");

    // scan file to get number of rows
    while (fscanf(data, "%lf", &dump) == 1){
        
        fscanf(data, "%lf", &shifts);
        fscanf(data, "%lf", &dump);

        for(int k = 0; k < shifts; k++){
            fscanf(data, "%lf", &dump);
        }
        i++;
    }
    fclose(data);
    
    // use number of rows to initialize array
    double info[3][i];

    // reopen file
    FILE *read;

    read = fopen("test.txt", "r");

    printf("Employee Number   Hours   Salary");

    for(intCount = 0; intCount < i; intCount ++){
        // declare variables
        double shifts;
        double time = 0;
        double in;
        double pay;
        double grosspay;

        // read data from file
        fscanf(read, "%lf", &info[0][intCount]);
        fscanf(read, "%lf", &shifts);
        fscanf(read, "%lf", &pay);
        
        // get shift hours
        for(int j = 0; j < shifts; j++){
            fscanf(data, "%lf", &in);
            time = time + in;
        }
        // record total hours
        info[1][intCount] = time;

        // calculate total salary
        if(time > 15 && time <= 25){
            grosspay = (time*pay) * 1.05;
        }else if(time > 25){
            grosspay = (time*pay) * 1.10;
        }else{
            grosspay = time*pay;
        }

        // round to 2 decimal places
        grosspay = round(grosspay*10)/10;
        // record pay
        info[2][intCount] = grosspay;
        // output
        printf("\n   %.0lf            %.0lf    $%.2lf", info[0][intCount], info[1][intCount], info[2][intCount]);
    }
    fclose(read);

    return 0;
}