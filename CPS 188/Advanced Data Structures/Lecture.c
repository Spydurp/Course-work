#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fruits{
    char name[15];
    char colour[10];
    struct fruits *next;
}fruit;

int main(void){

    int array1[100];
    int* array2;
    int i;
    int* array3; //array 10 x 5

    array2 = (int *)calloc(100, sizeof(int));
    array2[5] = 99;

    array3 = (int *)calloc(10*5, sizeof(int));
    array3[3*5+4] = 77; // row number x number of columns + column number. Same as array3[3][4]

    for(i = 0; i< 100; i++){
        printf("%d ", array2[i]);
    }
    printf("\n\n");
    for(i = 0; i< 10; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", array3[i*5+j]);
        }
        printf("\n");
    }
    free(array2);
    free(array3);

// Linked Lists
    struct fruits f1;
    struct fruits f2;
    struct fruits *head, *p;
    struct fruits f3;
    strncpy(f1.name, "banana", 15);
    strncpy(f1.colour, "yellow", 10);
    f1.next = &f2;
    strncpy(f2.name, "strawberry", 15);
    strncpy(f2.colour, "red", 10);
    f2.next = NULL;
    head = &f3;
    strncpy(f3.name, "blueberry", 15);
    strncpy(f3.colour, "blue", 10);
    f3.next = &f1;

    for(p = head; p!=NULL; p=p->next){
        printf("%s %s /0\n", p->colour, p->name);
    }


    return 0;
}