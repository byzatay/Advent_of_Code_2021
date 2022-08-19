#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *input;
	input=fopen("input.txt","r");
	char segments[10][8],output[10];
	int returnPoint,i,j,code[4],count=0;
	long int total=0;
	
	while(!feof(input))
	{
		returnPoint=ftell(input);
		for(i=0;i<10;i++)
		{
			fscanf(input,"%s ",&output);
			if(strlen(output)==2)
				strcpy(segments[1],output);
			else if(strlen(output)==3)
				strcpy(segments[7],output);
			else if(strlen(output)==4)
				strcpy(segments[4],output);
			else if(strlen(output)==7)
				strcpy(segments[8],output);
		}
		
		fscanf(input,"%s",output);
		fseek(input,returnPoint,SEEK_SET);
		
		for(i=0;i<10;i++)
		{
			fscanf(input,"%s",output);
			if(strlen(output)==5 && compareSignals(output,segments[1])==2)
				strcpy(segments[3],output);
			else if(strlen(output)==5 && compareSignals(output,segments[4])==2)
				strcpy(segments[2],output);
			else if(strlen(output)==5 && compareSignals(output,segments[4])==3)
				strcpy(segments[5],output);
			else if(strlen(output)==6 && compareSignals(output,segments[1])==1)
				strcpy(segments[6],output);
			else if(strlen(output)==6 && compareSignals(output,segments[4])==3)
				strcpy(segments[0],output);
			else if(strlen(output)==6 && compareSignals(output,segments[4])==4)	
				strcpy(segments[9],output);	
		}
		fscanf(input,"%s",output);
		for(i=0;i<4;i++)
		{
			fscanf(input,"%s",output);
			if(strlen(output)==2 || strlen(output)==3 || strlen(output)==4 || strlen(output)==7)
				count++;
			for(j=0;j<10;j++)
			{
				if(strlen(output)==strlen(segments[j]))
				{
					if(compareSignals(output,segments[j])==strlen(output))
					{
						code[i]=j;
						break;
					}
				}
			}	
		}
		total+=(code[0]*1000)+(code[1]*100)+(code[2]*10)+(code[3]);	
	}
	printf("Part I: %d \n",count);
	printf("Part II: %d ",total);
	return 0;
}

int compareSignals(char output[],char segment[])
{
	int i,j,count=0;
	for(i=0;i<strlen(output);i++)
	{
		for(j=0;j<strlen(segment);j++)
		{
			if(output[i]==segment[j])
				count++;
		}
	}
	return count;
}
