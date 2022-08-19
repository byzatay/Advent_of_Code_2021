#include <stdio.h>
#include <stdlib.h>
#define LINE 100
#define COLUMN 100

int size=0,size1=0,size2=0,size3=0;
int tempPoints[LINE][COLUMN];

void findBigThree()
{
	if(size+1>size1)
	{
		size3=size2;
	    size2=size1;
		size1=size+1;
	}
	else if(size+1>size2)
	{
		size3=size2;
		size2=size+1;
	}
	else if(size+1>size3)
        size3=size+1;
}

void findSizeOfBasin(int points[][COLUMN],int l,int c)
{
    // right
    if(points[l][c]<points[l][c+1] && points[l][c+1]!=9 && tempPoints[l][c+1]!=-1 && c!=COLUMN-1)
    {
        tempPoints[l][c+1]=-1;
        size++;
        findSizeOfBasin(points,l,c+1);
    }
    // left
    if(points[l][c]<points[l][c-1] && points[l][c-1]!=9 && tempPoints[l][c-1]!=-1 && c!=0)
    {
        tempPoints[l][c-1]=-1;
        size++;
        findSizeOfBasin(points,l,c-1);
    }
    // up
    if(points[l][c]<points[l-1][c] && points[l-1][c]!=9 && tempPoints[l-1][c]!=-1 && l!=0)
    {
        tempPoints[l-1][c]=-1;
        size++;
        findSizeOfBasin(points,l-1,c);
    }
    // down
    if(points[l][c]<points[l+1][c] && points[l+1][c]!=9 && tempPoints[l+1][c]!=-1 && l!=LINE-1)
    {
        tempPoints[l+1][c]=-1;
        size++;
        findSizeOfBasin(points,l+1,c);
    }
}

void checkLowPoints(int points[][COLUMN],int tempPoints[][COLUMN],int *totalRisk)
{
    int i,j,tempsize;
    for(i=0;i<LINE;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			if(i==0 && j==0)
			{
			    if(points[i][j]<points[i+1][j] && points[i][j]<points[i][j+1])
                {
                    *totalRisk+=points[i][j]+1;
                    
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i==0 && j!=0 && j!=COLUMN-1)
			{

				if(points[i][j]<points[i+1][j] && points[i][j]<points[i][j+1] && points[i][j]<points[i][j-1])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i==0 && j==COLUMN-1)
			{
				if(points[i][j]<points[i+1][j] && points[i][j]<points[i][j-1])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i!=0 && i!=LINE-1 && j==0)
			{
				if(points[i][j]<points[i+1][j] && points[i][j]<points[i][j+1] && points[i][j]<points[i-1][j])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i!=0 && i!=LINE-1 && j==COLUMN-1)
			{
				if(points[i][j]<points[i+1][j] && points[i][j]<points[i-1][j] && points[i][j]<points[i][j-1])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i==LINE-1 && j==0)
			{
				if(points[i][j]<points[i][j+1] && points[i][j]<points[i-1][j])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i==LINE-1 && j!=0 && j!=COLUMN-1)
			{
				if(points[i][j]<points[i-1][j] && points[i][j]<points[i][j-1] && points[i][j]<points[i][j+1])
				{
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else if(i==LINE-1 && j==COLUMN-1)
			{
				if(points[i][j]<points[i][j-1] && points[i][j]<points[i-1][j])
				{
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
			else
			{
				if(points[i][j]<points[i+1][j] && points[i][j]<points[i-1][j] && points[i][j]<points[i][j-1] && points[i][j]<points[i][j+1])
                {
                    *totalRisk+=points[i][j]+1;
                    findSizeOfBasin(points,i,j);
                    findBigThree();
                    size=0;
                }
			}
        }
	}
}

int main(void)
{
    int points[LINE][COLUMN],i,j,temp,totalRisk=0,tempPoints[LINE][COLUMN];
	char num;

	FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}

	while(!feof(input))
	{
		for(i=0;i<LINE;i++)
		{
			for(j=0;j<COLUMN;j++)
			{
				fscanf(input,"%c\n",&num);
				temp=num-'0';
				points[i][j]=temp;
				tempPoints[i][j]=temp;
			}
		}
	}
	checkLowPoints(tempPoints,tempPoints,&totalRisk);
	printf("Part I: %d \n",totalRisk);
	printf("Part II: %d ",size1*size2*size3);	
}
