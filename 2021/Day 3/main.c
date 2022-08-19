#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void deleteOnes(int,int);
void deleteZeros(int,int);
int findO2();
int findCo2();

int main() {
	FILE *input;
	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("Dosya acilamadi.\n");
		exit(1);
	}
	char number[15];
	int digit,zero=0,one=0,i=0,j=0;
	fscanf(input,"%s",&number);
	digit=strlen(number);
	
	char gammaRate[digit+1],epsilonRate[digit+1];
	int gamma=0,epsilon=0;
	REPEAT1:
	fseek(input,0,SEEK_SET);
	while(!feof(input))
	{
		fscanf(input,"%s",&number);
		if(number[i]=='0')
			zero++;
		else 
			one++;
	}
	if(zero>one)
	{
		gammaRate[i]='0';
		epsilonRate[i]='1';
		zero=0;
		one=0;
		i++;
	}
	else
	{
		gammaRate[i]='1';
		epsilonRate[i]='0';
		zero=0;
		one=0;
		i++;
	}
	if(i<digit)
		goto REPEAT1;
	
	gammaRate[i]='\0';
	epsilonRate[i]='\0';
	
	for(i=digit-1;i>=0;i--)
	{
		if(gammaRate[i]=='1')
			gamma+=pow(2,j);
		j++;	
	}
	j=0;
	for(i=digit-1;i>=0;i--)
	{
		if(epsilonRate[i]=='1')
			epsilon+=pow(2,j);
		j++;	
	}
	fclose(input);
	printf("Part I: %d \n",gamma*epsilon);
	
	printf("Part II: %d ",findO2()*findCo2());	
	return 0;
}

int findCo2()
{
	FILE *input;
	FILE *co2File;
	int i=0,co2=0,zero=0,one=0,digit,j;
	char number[15];

	input=fopen("input.txt","r");
	fscanf(input,"%s",&number);
	digit=strlen(number);
		
	co2File=fopen("co2File.txt","w");
	fseek(input,0,SEEK_SET);
	
	while(!feof(input))
	{
		fscanf(input,"%s",&number);
		fprintf(co2File,"%s\n",number);
	}
	fclose(co2File);
	fclose(input);
	
	REPEAT3:
	co2File=fopen("co2File.txt","r");
	fscanf(co2File,"%s",&number);
	while(!feof(co2File))
	{
		if(number[i]=='0')
			zero++;
		else 
			one++;
		fscanf(co2File,"%s",&number);		
	}
	fclose(co2File);
	if(zero>one)
	{
		deleteZeros(i,1);
		zero=0;
		one=0;
		i++;
	}
	else if(one>zero)
	{
		deleteOnes(i,1);
		zero=0;
		one=0;
		i++;
	}
	else
	{
		deleteOnes(i,1);
		zero=0;
		one=0;
		i++;
	}
	
	if(numberOfLines(1)>2  )
		goto REPEAT3;
		
	co2File=fopen("co2File.txt","r");
	fscanf(co2File,"%s",&number);
		
	if(number[i]=='1')
		fscanf(co2File,"%s",&number);
	fclose(co2File);
	
	j=0;	
	for(i=digit-1;i>=0;i--)
	{	
		if(number[i]=='1')
			co2+=pow(2,j);
		j++;	
	}
	return co2;	
}

int findO2()
{
	FILE *input;
	FILE *o2File;
	int i=0,o2=0,zero=0,one=0,digit,j;
	char number[15];
	
	input=fopen("input.txt","r");
	fscanf(input,"%s",&number);
	digit=strlen(number);
	
	o2File=fopen("o2File.txt","w");
	fseek(input,0,SEEK_SET);
	
	while(!feof(input))
	{
		fscanf(input,"%s",&number);
		fprintf(o2File,"%s\n",number);
	}
	fclose(o2File);
	fclose(input);
	
	REPEAT2:
	o2File=fopen("o2File.txt","r");
	fscanf(o2File,"%s",&number);
	while(!feof(o2File))
	{
		if(number[i]=='0')
			zero++;
		else 
			one++;
		fscanf(o2File,"%s",&number);		
	}
	fclose(o2File);
	
	if(zero>one)
	{
		deleteOnes(i,0);
		zero=0;
		one=0;
		i++;
	}
	else
	{
		deleteZeros(i,0);
		zero=0;
		one=0;
		i++;
	}

	if(numberOfLines(0)>2 )
		goto REPEAT2;
		
	o2File=fopen("o2File.txt","r");
	fscanf(o2File,"%s",&number);
	if(number[i]=='0')
		fscanf(o2File,"%s",&number);
	fclose(o2File);
	
	j=0;
	for(i=digit-1;i>=0;i--)
	{	
		if(number[i]=='1')
			o2+=pow(2,j);			
		j++;	
	}
	return o2;
}

void deleteOnes(int i, int code)
{
	FILE *input;
	FILE *temp;
	if(code==0)
	{	
		input=fopen("o2File.txt","r");
		temp=fopen("temp.txt","w");
		char number[15];
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		if(temp==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		fscanf(input,"%s",&number);
		while(!feof(input))
		{
			if(number[i]!='1')
				fprintf(temp,"%s\n",number);
			fscanf(input,"%s",&number);
		}
		fclose(input);
		fclose(temp);
		remove("o2File.txt");
		rename("temp.txt","o2File.txt");
	}
	else if(code==1)
	{
		input=fopen("co2File.txt","r");
		temp=fopen("temp.txt","w");
		char number[15];
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		if(temp==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		fscanf(input,"%s",&number);
		while(!feof(input))
		{
			if(number[i]!='1')
				fprintf(temp,"%s\n",number);
			fscanf(input,"%s",&number);	
		}
		fclose(input);
		fclose(temp);
		remove("co2File.txt");
		rename("temp.txt","co2File.txt");
	}	
}

void deleteZeros(int i, int code)
{
	FILE *input;
	FILE *temp;
	if(code==0)
	{
		input=fopen("o2File.txt","r");
		temp=fopen("temp.txt","w");
		char number[15];
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		if(temp==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		fscanf(input,"%s",&number);
		while(!feof(input))
		{
			if(number[i]!='0')
				fprintf(temp,"%s\n",number);
			fscanf(input,"%s",&number);
		}
		fclose(input);
		fclose(temp);
		remove("o2File.txt");
		rename("temp.txt","o2File.txt");	
	}
	else if(code==1)
	{
		input=fopen("co2File.txt","r");
		temp=fopen("temp.txt","w");
		char number[15];
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		if(temp==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		fscanf(input,"%s",&number);
		while(!feof(input))
		{
			if(number[i]!='0')
				fprintf(temp,"%s\n",number);
			fscanf(input,"%s",&number);	
		}
		fclose(input);
		fclose(temp);
		remove("co2File.txt");
		rename("temp.txt","co2File.txt");
	}	
}

int numberOfLines(int code)
{
	int line=0;
	char number[15];
	FILE *input;
	if(code==0)
	{
		input=fopen("o2File.txt","r");
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}	
		while(!feof(input))
		{
			fscanf(input,"%s ",&number);
			line++;
		}
		fclose(input);
	}
	else if(code==1)
	{
		input=fopen("co2File.txt","r");
		if(input==NULL)
		{
			printf("Dosya acilamadi.\n");
			exit(1);
		}
		while(!feof(input))
		{
			fscanf(input,"%s ",&number);
			line++;
		}
		fclose(input);
	}
	return line;
}
