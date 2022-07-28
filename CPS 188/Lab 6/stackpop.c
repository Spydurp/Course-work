#include <stdio.h>
#define STACK_EMPTY '0'
#define STACK_SIZE 20

void
push(char stack[],    /* input/output - the stack */
     char item,       /* input - data being pushed onto the stack */
     int  *top,       /* input/output - pointer to top of stack */
     int  max_size)   /* input - maximum size of stack */
{
     if (*top < max_size-1) {
         ++(*top);
         stack[*top] = item;
     }
}

char
pop (char stack[],    /* input/output - the stack */
    int *top)        /* input/output - pointer to top of stack */
{
    char item;       /* value popped off the stack */

    if (*top >= 0) {
        item = stack[*top];
        --(*top);
    } else {
         item = STACK_EMPTY;
    }

    return (item);
}

int
main (void)
{
    char s [STACK_SIZE];
    int s_top = -1; // stack is empty
    int i;

    // add elements
    push(s, 'x', &s_top, sizeof(s));
    push(s, 'y', &s_top, sizeof(s));
    push(s, 'z', &s_top, sizeof(s));

    // print array
    for(i = 0; i < 3; i++){
        printf("%c", s[i]);
    }

    // remove top element
    s[2] = s[2] - pop(s, &s_top);
    
    // print array
    printf("\n");
    for(i = 0; i < 3; i++){
       printf("%c", s[i]);
    }

   /* complete the program here */

    return (0);
}
