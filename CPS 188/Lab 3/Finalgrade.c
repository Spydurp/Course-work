#include <stdio.h>
#include <math.h>

int main(void){
    double quiz[10];
    double midterm;
    double final;
    int intCount;
    double Lowest = 10;
    double curr;
    double quizTot = 0;
    double quizAvg;
    double new[10];
    double grade;

    printf("Input quiz marks: \n");
    for(intCount = 0; intCount < 10; intCount ++){
        scanf("%lf", &quiz[intCount]);
    }
    printf("Input midterm mark: ");
    scanf("%lf", &midterm);
    printf("Input final exam mark: ");
    scanf("%lf", &final);

    for(intCount = 0; intCount < 10; intCount ++){
        curr = quiz[intCount];
        if(curr < Lowest){
            Lowest = curr;
        }
    }
    
    for(intCount = 0; intCount < 10; intCount ++){
        if(quiz[intCount] != Lowest){
            new[intCount] = quiz[intCount];
        }else if(quiz[intCount] == Lowest){
            new[intCount] = 0;
        }
    }
    Lowest = 10;
    for(intCount = 0; intCount < 10; intCount ++){
        curr = new[intCount];
        if(curr < Lowest && curr != 0){
            Lowest = curr;
        }
        quizTot = quizTot + curr;
    }
    quizTot = quizTot - Lowest;
    quizAvg = ((quizTot / 8)/10) * 100;

    if(midterm >= final){
        grade = 0.35*midterm + 0.40*final + 0.25*quizAvg;
    }else if(final > midterm){
        grade = 0.25*midterm + 0.50*final + 0.25*quizAvg;
    }
    

    printf("The final grade is: %.3lf", grade);

    return 0;
}