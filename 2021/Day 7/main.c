#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int number;
	int position[1000];
	int maxNum=0,i=0,j,t;
	long long  int fuel1,fuel2,totalFuel1,totalFuel2,temp;
	FILE *input;
	input=fopen("input.txt","r");
	
	while(!feof(input))
	{
		fscanf(input,"%d,",&number);
		if(number>maxNum)
			maxNum=number;
		totalFuel1+=number;
		totalFuel2+=number*(number+1)/2;
		position[i]=number;
		i++;
	}
	
	for(i=0;i<maxNum;i++)
	{
		for(j=0;j<1000;j++)
		{
			temp=abs(position[j]-i);
			fuel1+=temp;
			fuel2+=(temp)*(temp+1)/2;
		}
		if(fuel1<totalFuel1)
			totalFuel1=fuel1;
		if(fuel2<totalFuel2)	
			totalFuel2=fuel2;		
		fuel1=0;
		fuel2=0;
	}
	printf("Part I: %lld \n",totalFuel1);
	printf("Part II: %lld ",totalFuel2);
	return 0;
}
