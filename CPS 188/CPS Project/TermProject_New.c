#include <stdio.h>
#include <string.h>
#define maxday 366

void datefinder(int x, char date[]);
void lakenamer(int x, char name[]);
int partition(double array[], int bot, int top);
void quicksort(double array[], int bot, int top);
/**put header of sorting function here*/

typedef enum
{sup, mic, hur, eri, ont, stc}
lakes;

int main(void)
{   FILE* in=fopen("surftemp_2020.txt", "r");
	FILE* in2=fopen("surftemp_2019.txt", "r");
    double data[maxday][7], data2[maxday][8], lakeavg[6], lakeavg2[6], totavg, totavg2, lowest, highest, plchldr;
    int i, j, k, numdates, numdates2;
    char lakename[3][10], date[20][5], date2[20][5];

    for(i=0; i<maxday; ++i)
    {	fscanf(in, "%lf%lf%lf%lf%lf%lf%lf%lf", &plchldr, &data[i][1], &data[i][sup], &data[i][mic], &data[i][hur], &data[i][eri], &data[i][ont], &data[i][stc]);
    }
	for(i=0; i<maxday-1; ++i)
	{	fscanf(in2, "%lf%lf%lf%lf%lf%lf%lf%lf", &plchldr, &data2[i][1], &data2[i][sup], &data2[i][mic], &data2[i][hur], &data2[i][eri], &data2[i][ont], &data2[i][stc]);
	}
    fclose(in);
    fclose(in2);
    
    /*Question 1*/
    /*computes and prints the avg for each lake,
     * then computes the total avg and prints*/
    printf("|Question 1|\n");
    totavg=0;
    for(j=sup; j<=stc; ++j)
    {	lakeavg[j]=0;
		for(i=0; i<maxday; ++i)
		{	lakeavg[j]=lakeavg[j]+data[i][j];
		}
		lakeavg[j]=lakeavg[j]/maxday;
		totavg=totavg+lakeavg[j];
		lakenamer(j, lakename[1]);
		printf("Average Temperature of Lake %s is %.2lfC.\n", lakename[1], lakeavg[j]);
    }
    totavg=totavg/6;
    printf("Average Temperature of All Lakes is %.2lfC.\n", totavg);
    
    
    /*Question 2*/
    /*computes which lakes have the lowest/highest avg, and which are above/below the avg*/
    printf("\n|Question 2|\n");
    lowest=totavg;
	highest=totavg;
	for(j=sup; j<=stc; ++j)
    {	if(lakeavg[j]<lowest)
		{	lowest=lakeavg[j];
			lakenamer(j, lakename[0]);
		}
		if(lakeavg[j]>highest)
		{	highest=lakeavg[j];
			lakenamer(j, lakename[1]);
		}
	}
	printf("The coldest lake on average is Lake %s.\n", lakename[0]);
    printf("The warmest lake on average is Lake %s.\n", lakename[1]);
    for(j=sup; j<=stc; ++j)
    {	if(lakeavg[j]<totavg)
		{	lakenamer(j, lakename[2]);
			printf("Lake %s is below the average temperature.\n", lakename[2]);
		}
		if(lakeavg[j]>totavg)
		{	lakenamer(j, lakename[2]);
			printf("Lake %s is above the average temperature.\n", lakename[2]);
		}
    }

	double q2sorted[6];
	for(j = 0; j < 6; j++){
		q2sorted[j] = lakeavg[j];
	}

	int intCount;
	double super = q2sorted[0];
	double michigan = q2sorted[1];
	double hur = q2sorted[2];
	double eri = q2sorted[3];
	double ontario = q2sorted[4];
	double stcr = q2sorted[5];
	double names[6];
	
	quicksort(q2sorted, 0, 5);
	printf("From warmest to coldest on average all year: \n");
	for(intCount = 0; intCount < 6; intCount++){
		if(q2sorted[intCount] == super){
			printf("Superior, ");
			names[intCount] = 0;
		}else if(q2sorted[intCount] == michigan){
			printf("Michigan, ");
			names[intCount] = 1;
		}else if(q2sorted[intCount] == hur){
			printf("Huron, ");
			names[intCount] = 2;
		}else if(q2sorted[intCount] == eri){
			printf("Erie, ");
			names[intCount] = 3;
		}else if(q2sorted[intCount] == ontario){
			printf("Ontario, ");
			names[intCount] = 4;
		}else if(q2sorted[intCount] == stcr){
			printf("St. Clair, ");
			names[intCount] = 5;
		}
	}
	printf("\n");
   
    
    /*Question 3*/
    /*for every lake, finds the extreme temp and records all the dates for those temps,
     * resets if a new extreme temp is found. Then prints the extreme temps and every recorded date*/
	printf("\n|Question 3|\n");
    for(j=sup; j<=stc; ++j)
    {	lowest=lakeavg[j];
		highest=lakeavg[j];
		for(i=0; i<maxday; ++i)
		{	if(data[i][j]==lowest)
			{	++numdates;
				datefinder(i, date[numdates]);
			}
			if(data[i][j]<lowest)
			{	numdates=0;
				lowest=data[i][j];
				datefinder(i, date[numdates]);
			}
			if(data[i][j]==highest)
			{	++numdates2;
				datefinder(i, date2[numdates2]);
			}
			if(data[i][j]>highest)
			{	numdates2=0;
				highest=data[i][j];
				datefinder(i, date2[numdates2]);
			}
		}
		lakenamer(j, lakename[0]);
		printf("The lowest temperature for Lake %s was %.2lfC on ", lakename[0], lowest);
		for(k=0; k<=numdates; ++k)
		{	printf("%s, ", date[k]);
		}
		printf("\b\b.\n");
		printf("The highest temperature for Lake %s was %.2lfC on ", lakename[0], highest);
		for(k=0; k<=numdates2; ++k)
		{	printf("%s, ", date2[k]);
		}
		printf("\b\b.\n");
	}
	
	
	/*Question 4*/
	/* similar to question 3 but finds exteme temp for all lakes (every data point), 
	* and stores the lake name everytime a new one is found, along with dates and temp*/
	printf("\n|Question 4|\n");
	lowest=totavg;
	highest=totavg;
	for(j=sup; j<=stc; ++j)
    {	for(i=0; i<maxday; ++i)
		{	if(data[i][j]==lowest)
			{	++numdates;
				datefinder(i, date[numdates]);
			}
			if(data[i][j]<lowest)
			{	numdates=0;
				lowest=data[i][j];
				datefinder(i, date[numdates]);
				lakenamer(j, lakename[0]);
			}
			if(data[i][j]==highest)
			{	++numdates2;
				datefinder(i, date2[numdates2]);
			}
			if(data[i][j]>highest)
			{	numdates2=0;
				highest=data[i][j];
				datefinder(i, date2[numdates2]);
				lakenamer(j, lakename[1]);
			}
		}
	}
	printf("The overall lowest temperature was %.2lfC in Lake %s on ", lowest, lakename[0]);
	for(k=0; k<=numdates; ++k)
	{	printf("%s, ", date[k]);
	}
	printf("\b\b.\n");
	printf("The overall highest temperature was %.2lfC in Lake %s on ", highest, lakename[1]);
	for(k=0; k<=numdates2; ++k)
	{	printf("%s, ", date2[k]);
	}
	printf("\b\b.\n");
	
	
	/*Question 5*/
	/* calculates the lake averages again but within the given timeframe
	 * then sorts the array containing the averages and prints them*/
	printf("\n|Question 5|\n");
    for(j=sup; j<=stc; ++j)
    {	lakeavg[j]=0;
		for(i=171; i<265; ++i)
		{	lakeavg[j]=lakeavg[j]+data[i][j];
		}
		lakeavg[j]=lakeavg[j]/94;
    }
    /**use sorting algorithm here to sort from coldest to warmest
     * and then print them in that order*/
	intCount;
	super = lakeavg[0];
	michigan = lakeavg[1];
	hur = lakeavg[2];
	eri = lakeavg[3];
	ontario = lakeavg[4];
	stcr = lakeavg[5];
	double names5[6];
	
	quicksort(lakeavg, 0, 5);
	printf("From warmest to coldest in the summer: \n");
	for(intCount = 0; intCount < 6; intCount++){
		if(lakeavg[intCount] == super){
			printf("Superior, ");
			names5[intCount] = 0;
		}else if(lakeavg[intCount] == michigan){
			printf("Michigan, ");
			names5[intCount] = 1;
		}else if(lakeavg[intCount] == hur){
			printf("Huron, ");
			names5[intCount] = 2;
		}else if(lakeavg[intCount] == eri){
			printf("Erie, ");
			names5[intCount] = 3;
		}else if(lakeavg[intCount] == ontario){
			printf("Ontario, ");
			names5[intCount] = 4;
		}else if(lakeavg[intCount] == stcr){
			printf("St. Clair, ");
			names5[intCount] = 5;
		}
	}
	printf("\n");

	if(names5[0] == names[0] && names5[1] == names[1] && names5[2] == names[2] && names5[3] == names[3] && names5[4] == names[4] && names5[5] == names[5]){
		printf("The order matches what was calculated in Question 2.\n");
	}else{
		printf("The order does not match with what was calculated in Question 2.\n");
	}
	

	/*Question 6*/
	printf("\n|Question 6|\n");
    for(j=sup; j<=stc; ++j){	
		lakeavg[j] = 0;
		for(i=0; i<367; ++i){	
			if(i==78){	
				i=354;
			}
			lakeavg[j] = lakeavg[j] + data[i][j];
		}
		lakeavg[j]=lakeavg[j]/91;
    }
    /**use sorting algorithm here to sort from coldest to warmest
     * and then print them in that order*/
	super = lakeavg[0];
	michigan = lakeavg[1];
	hur = lakeavg[2];
	eri = lakeavg[3];
	ontario = lakeavg[4];
	stcr = lakeavg[5];
	
	quicksort(lakeavg, 0, 5);
	printf("From warmest to coldest in the winter: \n");
	for(intCount = 0; intCount < 6; intCount++){
		if(lakeavg[intCount] == super){
			printf("Superior, ");
			names5[intCount] = 0;
		}else if(lakeavg[intCount] == michigan){
			printf("Michigan, ");
			names5[intCount] = 1;
		}else if(lakeavg[intCount] == hur){
			printf("Huron, ");
			names5[intCount] = 2;
		}else if(lakeavg[intCount] == eri){
			printf("Erie, ");
			names5[intCount] = 3;
		}else if(lakeavg[intCount] == ontario){
			printf("Ontario, ");
			names5[intCount] = 4;
		}else if(lakeavg[intCount] == stcr){
			printf("St. Clair, ");
			names5[intCount] = 5;
		}
	}
	printf("\n");

	if(names5[0] == names[0] && names5[1] == names[1] && names5[2] == names[2] && names5[3] == names[3] && names5[4] == names[4] && names5[5] == names[5]){
		printf("The order matches what was calculated in Question 2.\n");
	}else{
		printf("The order does not match with what was calculated in Question 2.\n");
	}

    
    /*Question 7*/	
    /*checks if a day satisfies the condition and adds it to a sum if it does,
     * then prints how many days satisy the condition*/
    printf("\n|Question 7|\n");
    for(j=sup; j<=stc; ++j)
    {	k=0;
		for(i=0; i<maxday; ++i)
		{	if(data[i][j]>20)
			{ k=k+1;
			}
		}
		lakenamer(j, lakename[0]);
		printf("The number of days Lake %s can be swam in is %d.\n", lakename[0], k);
	}
	
	
	/*Question 8*/
	/* exact same as question 7 except with a different condition*/
	printf("\n|Question 8|\n");
    for(j=sup; j<=stc; ++j)
    {	k=0;
		for(i=0; i<maxday; ++i)
		{	if(data[i][j]<0)
			{ k=k+1;
			}
		}
		lakenamer(j, lakename[0]);
		printf("The number of days Lake %s is frozen is %d.\n", lakename[0], k);
	}
	
	
	/*Question 9*/
	printf("\n|Question 9|\n");
	totavg=0;
	totavg2=0;
    for(j=sup; j<=stc; ++j)
    {	lakeavg[j]=0;
		for(i=0; i<maxday; ++i)
		{	lakeavg[j]=lakeavg[j]+data[i][j];
		}
		lakeavg[j]=lakeavg[j]/maxday;
		totavg=totavg+lakeavg[j];
	}
	totavg=totavg/6;
	for(j=sup; j<=stc; ++j)
    {	lakeavg2[j]=0;
		for(i=0; i<maxday-1; ++i)
		{	lakeavg2[j]=lakeavg2[j]+data2[i][j];
		}
		lakeavg2[j]=lakeavg2[j]/(maxday-1);
		totavg2=totavg2+lakeavg2[j];
	}
    totavg2=totavg2/6;
    printf("Lake Name\t2020\t2019\tChange in Temp.\n");
    for(j=sup; j<=stc; ++j)
    {	lakenamer(j, lakename[0]);
		printf("%-8s\t%.2lf\t%.2lf\t%.2lf\n", lakename[0], lakeavg[j], lakeavg2[j], lakeavg[j]-lakeavg2[j]); 
	}
	printf("Total Average\t%.2lf\t%.2lf\t%.2lf\n", totavg, totavg2, totavg-totavg2);
    return (0);
}


/** put sorting function here*/



void datefinder(int x, char date[])
{	int day, month;
	char month_init[12][3]={"JA","FE","MR","AP","MY","JN","JL","AU","SE","OC","NV","DE"};
	++x;
	if(x<=31)
	{	month=1;
		day=x;
	}
	if(x>31 && x<=60)
	{	month=2;
		day=x-31;
	}
	if(x>60 && x<=91)
	{	month=3;
		day=x-60;
	}
	if(x>91 && x<=121)
	{	month=4;
		day=x-91;
	}
	if(x>121 && x<=152)
	{	month=5;
		day=x-121;
	}
	if(x>152 && x<=182)
	{	month=6;
		day=x-152;
	}
	if(x>182 && x<=213)
	{	month=7;
		day=x-182;
	}
	if(x>213 && x<=244)
	{	month=8;
		day=x-213;
	}
	if(x>244 && x<=274)
	{	month=9;
		day=x-244;
	}
	if(x>274 && x<=305)
	{	month=10;
		day=x-274;
	}
	if(x>305 && x<=335)
	{	month=11;
		day=x-305;
	}
	if(x>335)
	{	month=12;
		day=x-335;
	}
	sprintf(date, "%s%02d", month_init[month-1], day);
}

void lakenamer(int x, char name[])
{	if(x==sup)
	{	strcpy(name, "Superior");
	}
	if(x==mic)
	{	strcpy(name, "Michigan");
	}
	if(x==hur)
	{	strcpy(name, "Huron");
	}
	if(x==eri)
	{	strcpy(name, "Erie");
	}
	if(x==ont)
	{	strcpy(name, "Ontario");
	}	
	if(x==stc)
	{	strcpy(name, "St. Clair");
	}
}

int partition(double array[], int bot, int top){
	double pivot = array[top];
	int i = bot - 1;
	int j;
	double temp;

	for(j = bot; j < top; j++){
		if(array[j] > pivot){
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i+1];
	array[i+1] = array[top];
	array[top] = temp;

	return(i+1);
}

void quicksort(double array[], int bot, int top){
	int pi;
	if(bot < top){
		pi = partition(array, bot, top);
		quicksort(array, bot, pi-1);
		quicksort(array, pi+1, top);
	}
}