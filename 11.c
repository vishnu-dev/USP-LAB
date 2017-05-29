#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void gen(char c[],char s1[],char s2[],int elseflag);

int main()
{
	int elseflag=0,i=0;
	char token[100][10],*p,stmt[50];

	printf("if (a<b) then (s,a)\n");
        printf("if (a<b) then (s,a) else (s,b)\n");
        
	printf("Enter a string:\n");
	scanf("%[^\n]", stmt);
	p=strtok(stmt," ");
	while(p!=NULL)
	{
		strcpy(token[i++],p);
		if(strcmp(p,"else")==0)
			elseflag=1;
		p=strtok(NULL," ");
	}
	if(strcmp(token[2],"then")!=0)
	{
		printf("Invalid expression!");
		return 0;
	}
	else if(elseflag && strcmp(token[4],"else")!=0)
	{
		printf("Invalid expression!");
		return 0;
	}
	gen(token[1],token[3],token[5],elseflag);
}

void gen(char c[],char s1[],char s2[],int elseflag)
{
	printf("\n if %s then goto %d",c,100);
	printf("\n goto %d",200);
	printf("\n %d:%s",100,s1);
	if(!elseflag)
		printf("\n %d:",200);
	else
	{	
		printf("\n goto %d",300);
		printf("\n %d:%s",200,s2);
		printf("\n %d:",300);
	}
}
