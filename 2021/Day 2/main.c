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
	char command[10];
	int number,position=0,depth=0;
	while(!feof(input))
	{
		fscanf(input,"%s %d",&command,&number);
		int forward=strcmp(command,"forward");
		int down=strcmp(command,"down");
		int up=strcmp(command,"up");
		
		if(forward==0)
			position+=number;
		else if(down==0)
			depth+=number;
		else if(up==0)
			depth-=number;
	}
	printf("Part I: %d\n",depth*position);
	
	fseek(input,0,SEEK_SET);
	depth=0,position=0;
	int aim=0;
	while(!feof(input))
	{
		fscanf(input,"%s %d",&command,&number);
		int forward=strcmp(command,"forward");
		int down=strcmp(command,"down");
		int up=strcmp(command,"up");
		if(forward==0)
		{
			position+=number;
			if(aim!=0)
				depth+=aim*number;
		}
		else if(down==0)
			aim+=number;
		else if(up==0)
			aim-=number;
	}
	printf("Part II: %d ",depth*position);
	fclose(input);
	return 0;
}
