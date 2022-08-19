#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}
	int depth,newDepth,increased=0;
	
	fscanf(input,"%d",&depth);
	while(!feof(input))
	{
		fscanf(input,"%d",&newDepth);
		
		if(newDepth>depth)
			increased++;
		depth=newDepth;
	}
	printf("Part I: %d \n",increased);
	
	fseek(input,0,SEEK_SET);
	int totalDepth=0,newTotalDepth=0,count=0,len=1,temp;
	increased=0;
	
	while(count<3)
	{
		fscanf(input,"%d",&depth);
		totalDepth+=depth;
		count++;
	}
	while(!feof(input))
	{
		count=0;
		fseek(input,0,SEEK_SET);
		temp=len;
		for(temp;temp>0;temp--)
			fscanf(input,"%d",&depth);
		while(count<3)
		{
			fscanf(input,"%d",&depth);
			newTotalDepth+=depth;
			count++;
		}
		len++;
		if(newTotalDepth>totalDepth)
			increased++;
		totalDepth=newTotalDepth;
		newTotalDepth=0;
	}
	printf("Part II: %d ",increased);
	fclose(input);
	return 0;
}
