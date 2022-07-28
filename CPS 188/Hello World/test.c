#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int toronto (int x)
{
    int w; 
    if (x == 0) w = 1; else w = toronto (x-1); 

	return (w);
}


int main(void){
    int xf3r6;
    int c = 0;
    int d = 2;
    char word[15] = "hello";
    int a = 10;
    int *p = 0;

    char *string = "hello world";

    printf("%d", p);

    printf ("\n%lf", 2 / 4 / 2);
    printf("/0");
    printf("\n%40s", word);
    printf("\n%4d", 5-c/d);
    printf("/0");
    printf("\n%d\n", atoi("12f1g"));


    a = 99;
	printf ("%d", toronto (a));

    printf("\n");



    register int t;
    printf("%d", t);
    

    return 0;
} 