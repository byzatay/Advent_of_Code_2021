#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int incompleteLines[100];
int count=0;

int main() {
	FILE *input;
	input=fopen("input.txt","r");
	char line[200];
	int i,totalDiscardPoints=0;
	long long int totalIncompletePoints;
		
	while(!feof(input))
	{
		fscanf(input,"%s\n",&line);
		totalDiscardPoints+=isItCorrupted(line,i,&totalIncompletePoints);	
	}
	printf("Part I: %d\n",totalDiscardPoints);
	printf("Part II: %lld ",totalIncompletePoints);
	return 0;
}

void findIncompletePoints(char line[],int count)
{
	int i;
	unsigned long long int point=0;

	for(i=strlen(line)-1;i>=0;i--)
	{
		if(line[i]=='(')
		{
			point*=5;
			point+=1;
		}
		else if(line[i]=='[')
		{
			point*=5;
			point+=2;
		}
		else if(line[i]=='{')
		{
			point*=5;
			point+=3;
		}
		else if(line[i]=='<')
		{
			point*=5;
			point+=4;
		}
	}
	incompleteLines[count]=point;
}

void sortArray(int N)
{
	int i,j,min;
	for(i=0;i<N;i++)
	{
		min=i;
		for(j=i+1;j<N;j++)
		{
			if(incompleteLines[j]<incompleteLines[min])
				min=j;
		}
		long long int temp=incompleteLines[i];
		incompleteLines[i]=incompleteLines[min];
		incompleteLines[min]=temp;	
	}
}

int isItCorrupted(char line[],int N,int *totalIncompletePoints)
{
	// p: (), b: [], c: {}, m: <>
	int p,b,c,m,i,j;
		
	for(i=0;i<strlen(line);i++)
	{
		j=i-1;
		if(line[i]=='(')
			p++;
		else if(line[i]=='[')
			b++;
		else if(line[i]=='{')
			c++;
		else if(line[i]=='<')
			m++;
			
		if(line[i]==')')
		{
			if(p==0)
				break;
			while(line[j]=='-')
				j--;
			if(line[j]=='(')
			{
				line[j]='-';
				line[i]='-';
				p--;
			}
			else
				break;
		}
		else if(line[i]==']')
		{
			if(b==0)
				break;
			while(line[j]=='-')
				j--;
			if(line[j]=='[')
			{
				line[j]='-';
				line[i]='-';
				b--;
			}
			else
				break;
		}
		else if(line[i]=='}')
		{
			if(c==0)
				break;
			while(line[j]=='-')
				j--;
			if(line[j]=='{')
			{
				line[j]='-';
				line[i]='-';
				c--;
			}
			else
				break;
		}
		else if(line[i]=='>')
		{
			if(m==0)
				break;
			while(line[j]=='-')
				j--;
			if(line[j]=='<')
			{
				line[j]='-';
				line[i]='-';
				m--;
			}
			else
				break;
		}
	}
	
	if(i==strlen(line))
	{
		findIncompletePoints(line,count);
		count++;
		sortArray(count);
		*totalIncompletePoints=incompleteLines[(count/2)];
		return 0;
	}	
	else if(line[i]==')')
		return 3;
	else if(line[i]==']')
		return 57;
	else if(line[i]=='}')
		return 1197;
	else if(line[i]=='>')
		return 25137;
}
