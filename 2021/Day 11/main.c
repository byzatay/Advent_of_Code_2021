#include <stdio.h>
#include <stdlib.h>

void newDay();
void checkFlashes();
int control();

int energy[10][10];
int count=0;

int main() {
	
	char num;
	int temp,i,j,d,day=100;

	FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			fscanf(input,"%c ",&num);
			temp=num-'0';
			energy[i][j]=temp;
		}
	}
	
	for(d=0;d<100;d++)
		newDay();
	printf("Part I: %d \n",count);	
	
	while(1)
	{
		newDay();
		day++;
		if(control()==1)
			break;
	}
	printf("Part II: %d ",day);
	return 0;
}

int control()
{
	int i,j,temp=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(energy[i][j]==0)
				temp++;
		}
	}
	if(temp==100)
		return 1;
	else 
		return 0;
}

void checkFlashes(int i,int j)
{
	energy[i][j]=-1;
	
	if(energy[i-1][j-1]!=-1 && i!=0 && j!=0)
		energy[i-1][j-1]++;
	if(energy[i-1][j-1]>9 && i!=0 && j!=0)
	{
		count++;
		checkFlashes(i-1,j-1);
	}
	
	if( energy[i-1][j]!=-1 && i!=0)	
		energy[i-1][j]++;
	if(energy[i-1][j]>9 && i!=0)
	{
		count++;
		checkFlashes(i-1,j);
	}
	
	if( energy[i-1][j+1]!=-1 && i!=0 && j!=9)	
		energy[i-1][j+1]++;
	if(energy[i-1][j+1]>9 && i!=0 && j!=9)
	{
		count++;
		checkFlashes(i-1,j+1);
	}
	
	if( energy[i][j-1]!=-1 && j!=0)	
		energy[i][j-1]++;
	if(energy[i][j-1]>9 && j!=0)
	{
		count++;
		checkFlashes(i,j-1);
	}
	
	if( energy[i][j+1]!=-1 && j!=9)		
		energy[i][j+1]++;
	if(energy[i][j+1]>9 && j!=9)
	{
		count++;
		checkFlashes(i,j+1);
	}
	
	if(energy[i+1][j-1]!=-1  && j!=0 && i!=9)		
		energy[i+1][j-1]++;
	if(energy[i+1][j-1]>9 && j!=0 && i!=9)
	{
		count++;
		checkFlashes(i+1,j-1);
	}
	
	if(energy[i+1][j]!=-1  && i!=9)		
		energy[i+1][j]++;
	if(energy[i+1][j]>9 && i!=9)
	{
		count++;
		checkFlashes(i+1,j);
	}
	
	if(energy[i+1][j+1]!=-1 && i!=9 && j!=9)		
		energy[i+1][j+1]++;
	if(energy[i+1][j+1]>9 && i!=9 && j!=9)
	{
		count++;
		checkFlashes(i+1,j+1);
	}
}

void newDay()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			energy[i][j]+=1;
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(energy[i][j]>9)
			{
				count++;
				checkFlashes(i,j);
			}
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(energy[i][j]==-1)
				energy[i][j]=0;
		}
	}
}
