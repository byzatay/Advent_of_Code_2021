#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 1000
#define COLUMN 1000

int main() {
	int **line,temp,x1,x2,y1,y2,i,j;
	char coordinate1[10],coordinate2[10];
	
	line = (int **)malloc(LINE*sizeof(int*));
    for(i=0;i<LINE;i++)
    	line[i]=(int*)malloc(COLUMN*sizeof(int));
        
	FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			line[i][j]=0;
		}
	}

	while(!feof(input))
	{
		fscanf(input,"%s -> %s",&coordinate1,&coordinate2);
		
		char *num=strtok(coordinate1,",");
		temp=atoi(num);
		x1=temp;
		num = strtok(NULL, ",");
		temp=atoi(num);
		y1=temp;
	
		num=strtok(coordinate2,",");
		temp=atoi(num);
		x2=temp;
		num = strtok(NULL, ",");
		temp=atoi(num);
		y2=temp;
	
		if(x1==x2)
		{
			if(y1>y2)
			{
				for(i=y2;i<=y1;i++)
					line[i][x1]+=1;
			}
			else
			{
				for(i=y1;i<=y2;i++)
					line[i][x1]+=1;
			}	
		}
		else if(y1==y2)
		{
			if(x1>x2)
			{
				for(i=x2;i<=x1;i++)
					line[y1][i]+=1;
			}
			else
			{
				for(i=x1;i<=x2;i++)
					line[y1][i]+=1;
			}
		}
		// For Part II
		/*else
		{
			if(x1>x2)
			{
				if(y1>y2)
				{
					for(i=x1,j=y1;i>=x1,j>=y2;i--,j--)
						line[j][i]+=1;
				}
				else
				{
					for(i=x1,j=y1;i>=x2,j<=y2;i--,j++)
						line[j][i]+=1;
				}
			}
			else
			{
				if(y1>y2)
				{
					for(i=x1,j=y1;i<=x2,j>=y2;i++,j--)
						line[j][i]+=1;
				}
				else
				{
					for(i=x1,j=y1;i<=x2,j<=y2;i++,j++)
					{
						line[j][i]+=1;
					}
				}
			}
		}*/
	}
	int count=0;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			if(line[i][j]>1)
				count++;		
		}
	}
	printf("Part I: %d ",count);
	//printf("Part II: %d ",count);
	return 0;
}

