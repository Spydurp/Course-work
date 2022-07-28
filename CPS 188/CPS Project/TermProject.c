#include <stdio.h>
#include <math.h>

double lowest(double arr[]){
    
}

int get_min_range (double list[], int first, int last)
{
/* smallest element's position */
    int k;
    // counter
    int i;
    // initialize smallest to very high
    int smallest = 999999;

    //find smallest position
    for (i = first; i <= last; i++){
        if(smallest > list[i]){
            smallest = list[i];
            k = i;
        }
    }
    return k;

   /* complete the function here */


}

// sorts the data in array list
void
select_sort(double list[], int n)    
{
     int fill,           /* index of first element in unsorted subarray    */
         temp,           /* temporary storage                              */
         index_of_min;   /* subscript of next smallest element             */

     for (fill = 0; fill < n-1; ++fill) {
          /* Find position of smallest element in unsorted subarray */
          index_of_min = get_min_range (list, fill, n-1);

          /* Exchange elements at fill and index_of_min */
          if (fill != index_of_min) {
                temp = list[index_of_min];
                list[index_of_min] = list[fill];
                list[fill] = temp;
          }
     }
}

int main(void){

    FILE* in;
    in = fopen("surftemp.txt", "r");
    double data[366][8];
    int i;
    int j;
    double sup = 0;
    double mich = 0;
    double huron = 0;
    double erie = 0;
    double ont = 0;
    double stclr = 0;
    double totavg;

    for(i = 0; i < 366; i++){
        fscanf(in, "%lf %lf    %lf    %lf    %lf    %lf    %lf    %lf", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &data[i][4], &data[i][5], &data[i][6], &data[i][7]);
    }
    for(i = 0; i < 366; i++){
        sup = sup + data[i][2];
        mich = mich + data [i][3];
        huron = huron + data [i][4];
        erie = erie + data [i][5];
        ont = ont + data [i][6];
        stclr = stclr + data [i][7];
    }

    sup = sup/366;
    mich = mich/366;
    huron = huron/366;
    erie = erie/366;
    ont = ont/366;
    stclr = stclr/366;
    totavg = (sup + mich + huron + erie + ont + stclr)/6;

    double avg[] = {sup, mich, huron, erie, ont, stclr};

    int min = get_min_range(avg, 0, 5);

    if(min == 0){
        printf("\nLowest average temperature: Lake Superior - %lf C", avg[min]);
    }else if(min == 1){
        printf("\nLowest average temperature: Lake Michigan - %lf C", avg[min]);
    }else if(min == 2){
        printf("\nLowest average temperature: Lake Huron - %lf C", avg[min]);
    }else if(min == 3){
        printf("\nLowest average temperature: Lake Erie - %lf C", avg[min]);
    }else if(min == 4){
        printf("\nLowest average temperature: Lake Ontario - %lf C", avg[min]);
    }else if(min == 5){
        printf("\nLowest average temperature: Lake St. Claire - %lf C", avg[min]);
    }

    /*
    printf("average temps:");
    printf("\nSup: %lf", sup);
    printf("\nMich: %lf", mich);
    printf("\nHuron: %lf", huron);
    printf("\nErie: %lf", erie);
    printf("\nOnt: %lf", ont);
    printf("\nStclr: %lf", stclr);
    printf("\nTotal Average: %lf", totavg);
    */

    return 0;
}