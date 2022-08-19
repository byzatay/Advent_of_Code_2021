#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char number;
    unsigned long long int days[9],temp,totalFish=0;
    int i,j;
    for(i=0;i<9;i++)
        days[i]=0;

    FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}
    while(!feof(input))
	{
		fscanf(input,"%c,",&number);
        temp=number-'0';
        if(temp==0)
            days[0]++;
        else if(temp==1)
            days[1]++;
        else if(temp==2)
            days[2]++;
        else if(temp==3)
            days[3]++;
        else if(temp==4)
            days[4]++;
        else if(temp==5)
            days[5]++;
        else if(temp==6)
            days[6]++;
	}

	for(i=0;i<80;i++)
    {
        temp=days[0];
        for(j=0;j<8;j++)
            days[j]=days[j+1];

        days[6] +=  temp;
    	days[8] = temp;
    }
	for(i=0;i<9;i++)
        totalFish+=days[i];
    printf("Part I: %lld ",totalFish);

    // For Part II
	/*for(i=0;i<256;i++)
    {
        temp=days[0];
        for(j=0;j<8;j++)
            days[j]=days[j+1];

        days[6] +=  temp;
    	days[8] = temp;
    }
	for(i=0;i<9;i++)
        totalFish+=days[i];
    printf("Part II: %lld ",totalFish);*/
	return 0;
}
