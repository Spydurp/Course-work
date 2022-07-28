#include <stdio.h>

int main(void){

    int x = 2000000;
    FILE *out;

    out = fopen("result.txt", "w");

    fprintf(out, "%d", x);

    fclose (out);

    FILE *in;
    in = fopen("result.txt", "r");
    int y;

    fscanf(in, "%d", &y);
    fclose (in);
    
    printf("%d", y);

    return 0;

}