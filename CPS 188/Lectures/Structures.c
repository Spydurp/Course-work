#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car{
    char make[20];
    char model[20];
    char color[20];
    int year;
};

int main(void){
    struct car c;
    c.year = 2021;
    strncpy(c.make, "Audi", 20);
    strncpy(c.model, "R8", 20);
    strncpy(c.color, "black", 20);
    printf("%s %s %s %d", c.make, c.model, c.color, c.year);

    return 0;
}