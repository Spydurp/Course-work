#include <stdio.h>

/*
Moon Function
find minimum and maximum travel time based on velocity
returns minimum travel time
sets maximum travel time directly
*/
double
moon(double v, double* maxT){
    double minT;
    *maxT = 405696 / v;
    minT = 363104 / v;
    return minT;
}

/*
Mars Function
find minimum and maximum travel time based on velocity
returns minimum travel time
sets maximum travel time directly
*/
double
mars(double v, double* maxT){
    double minT;
    *maxT = 401000000 / v;
    minT = 54600000 / v;
    return minT;
}

/*
Venus Function
find minimum and maximum travel time based on velocity
returns minimum travel time
sets maximum travel time directly
*/
double
venus(double v, double* maxT){
    double minT;
    *maxT = 261000000 / v;
    minT = 38000000 / v;
    return minT;
}

int
main(void){

    int choice;
    double speed;
    double minT;
    double maxT;

    // Loop until exit
    while(choice != 4){

        // Menu
        printf("\nSelect Destination");
        printf("\n1. Traveling to the Moon\n2. Traveling to Mars.\n3. Traveling to Venus\n4. Exit Program\n");
        scanf("%d", &choice);
        if(choice == 4){
            break;
        }
        printf("\nEnter velocity in km/h\n");
        scanf("%lf", &speed);

        // Call functions
        if(choice == 1){
            minT = moon(speed, &maxT);
            printf("It will take a minimum of %lf hours and a maximum of %lf hours to get to the Moon traveling at %.1lf km/h", minT, maxT, speed);
        }else if(choice == 2){
            minT = mars(speed, &maxT);
            printf("It will take a minimum of %lf hours and a maximum of %lf hours to get to Mars traveling at %.1lf km/h", minT, maxT, speed);
        }else if (choice == 3){
            minT = venus(speed, &maxT);
            printf("It will take a minimum of %lf hours and a maximum of %lf hours to get to Venus traveling at %.1lf km/h", minT, maxT, speed);
        }
    }

    return 0;
}