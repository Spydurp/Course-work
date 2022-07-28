#include <stdio.h>

int factorial(int n){
    if(n == 0){
        return(1);
    }
    else{
        n = n*factorial(n-1);
    }
}

int display (int n){
    int x;
    if (n == 0){
        x = 0;
    }else{
        x = display(n-1);
        printf("%d", n);
    }
    return(x);
}

void rec(int n){
    printf("Winding Level = %d\n", n);
    if(n < 500){
        rec(n+1);
        
    }
    printf("Unwinding Level = %d\n", n);
}

int main(void){
    int n;

    printf("Input N\n");
    scanf("%d", &n);

    n = factorial(n);
    printf("%d", n);

    rec(1);

    return 0;
}