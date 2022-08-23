#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foldPaper(char **,char *,int ,int *,int *);

int main() {
	int number1,number2,maxNum1=0,maxNum2=0,i,j,count=0;
	char str[20];
	FILE *input;
	input=fopen("input.txt","r");
	
	while(!feof(input))
	{
		fscanf(input,"%s ",&str);
		if(strstr(str,"fold")!=NULL)
			break;
		char *temp=strtok(str,",");
		number1=atoi(temp);
		temp=strtok(NULL,",");
		number2=atoi(temp);
		
		if(number1>maxNum1)
			maxNum1=number1;
		if(number2>maxNum2)
			maxNum2=number2;
	}
	maxNum1++;
	maxNum2++;

	char **paper;
	paper = (char **)malloc(maxNum2*sizeof(char *));
    for(i=0;i<maxNum2;i++)
    	paper[i]=(char*)malloc(maxNum1*sizeof(char));
    	
    for(i=0;i<maxNum2;i++)
    {
    	for(j=0;j<maxNum1;j++)
    		paper[i][j]='.';
	}
	fseek(input,0,SEEK_SET);
	
	while(!feof(input))
	{
		fscanf(input,"%s ",&str);
		if(strstr(str,"fold")!=NULL)
			break;
		char *temp=strtok(str,",");
		number1=atoi(temp);
		temp=strtok(NULL,",");
		number2=atoi(temp);
		paper[number2][number1]='#';
	}
	
	fscanf(input,"%s ",&str);
	fscanf(input,"%s ",&str);
	
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='=')
			break;
	}
	
	int t=i+1,fold;
	char num[5];
	for(j=0;j<strlen(str)-t;j++)
	{
		num[j]=str[i+1];
		i++;
	}
	fold=atoi(num);
	foldPaper(paper,str,fold,&maxNum1,&maxNum2);
	
	for(i=0;i<maxNum2;i++)
    {
    	for(j=0;j<maxNum1;j++)
    	{
    	if(paper[i][j]=='#')
    		count++;
		}
	}
	printf("Part I: %d \n\n",count);
	
	while(!feof(input))
	{
		fscanf(input,"%s ",&str);
		fscanf(input,"%s ",&str);
		fscanf(input,"%s ",&str);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='=')
				break;
		}
		t=i;
		for(j=0;j<strlen(str)-t;j++)
		{
			num[j]=str[i+1];
			i++;
		}
		fold=atoi(num);
		foldPaper(paper,str,fold,&maxNum1,&maxNum2);
	}
	printf("Part II: \n\n");
	for(i=0;i<maxNum2;i++)
	{
		for(j=0;j<maxNum1;j++)
		{
			printf("%c ",paper[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void foldPaper(char **paper,char *str,int fold,int *N1,int *N2)
{
	int count=1, i,j;
	if(strstr(str,"x")!=NULL)
	{
		for(i=0;i<*N2;i++)
		{
			
			for(j=fold+1;j<*N1;j++)
			{	
				count++;
				if(paper[i][j]=='#')
					paper[i][fold+1-count]='#';			
			}
			count=1;
		}
		*N1=fold;
	}
	else if(strstr(str,"y")!=NULL)
	{
		for(i=fold+1;i<*N2;i++)
		{
			count++;
			for(j=0;j<*N1;j++)
			{	
				if(paper[i][j]=='#')
					paper[fold+1-count][j]='#';	
			}
		}
		*N2=fold;
	}
}
