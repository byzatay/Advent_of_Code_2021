#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateScore(int [],int [][5],int);
int search(int [],int [][5]);

int main() {
	char numbers[500];
	int i=0,j=0,count=0,temp,drawns[100],bingo[5][5],positionWin=101,positionLost=0,cardWin,cardLost;
	FILE *input;
	input=fopen("input.txt","r");
	fscanf(input,"%s\n",&numbers);
	
	char *num=strtok(numbers,",");
	while(num!=NULL)
	{
		temp=atoi(num);
		drawns[i]=temp;
		i++;
		num = strtok(NULL, ",");
	}

	while(!feof(input))
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				fscanf(input,"%d\n",&temp);
				bingo[i][j]=temp;
			}
		}
		temp=search(drawns,bingo);
		count++;
		
		if(temp<positionWin)
		{
			positionWin=temp;
			cardWin=count;	
		}
		if(temp>positionLost)
		{
			positionLost=temp;
			cardLost=count;	
		}	
	}
	count=cardWin;
	fseek(input,0,SEEK_SET);
	fscanf(input,"%s\n",&numbers);
	
	while(count>0)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				fscanf(input,"%d\n",&temp);
				bingo[i][j]=temp;
			}
		}
		count--;
	}
	printf("Part I: %d \n",calculateScore(drawns,bingo,positionWin));
	
	count=cardLost;
	fseek(input,0,SEEK_SET);
	fscanf(input,"%s\n",&numbers);
	
	while(count>0)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				fscanf(input,"%d\n",&temp);
				bingo[i][j]=temp;
			}
		}
		count--;
	}
	printf("Part II: %d ",calculateScore(drawns,bingo,positionLost));
	fclose(input);
	return 0;
}

int calculateScore(int drawns[],int bingo[5][5],int position)
{
	int score=0,i,j,t;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{	
			for(t=0;t<position;t++)
			{	
				if(bingo[i][j]==drawns[t])
					break;
			}
			if(t==position)
				score+=bingo[i][j];
		}
	}
	score*=drawns[position-1];
	return score;
}

int search(int drawns[],int array[5][5])
{
	int positionNum=0,positionCol=101,positionRow=0,temp,count=0,i=0,j=0,t=0,column[5],row[5],count1=0,count2=0,score=0;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{	
			for(t=0;t<100;t++)
			{	
				if(array[i][j]==drawns[t])
				{	
					temp=t+1;
					if(temp>positionNum)
						positionNum=temp;
					break;
				}				
			}
		}
		if(positionNum<positionCol)
			positionCol=positionNum;
		positionNum=0;
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{	
			for(t=0;t<100;t++)
			{	
				if(array[j][i]==drawns[t])
				{
					temp=t+1;
					if(temp>positionNum)
						positionNum=temp;
					break;
				}					
			}
		}
		if(positionNum<positionCol)
			positionCol=positionNum;
		positionNum=0;
	}
	return positionCol;	
}
