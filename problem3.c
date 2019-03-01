#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void mygrep(FILE *fp, char *find);

void myreplace(FILE *fp,char *find, char * replace);

int  main(int argc,char *argv[])
{
	int behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

        printf("%s\n", argv[0]);
   
	if(argv[0]=GREP)
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = GREP;
	}
	
	else if(argv[0]=REPLACE)
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = REPLACE;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}

	fp=fopen(filename,"rt");

	if(behaviour == GREP)
	{
		mygrep(fp,find);	

	}
	else if ( behaviour == REPLACE )
	{
		myreplace(fp,find,replace);		
	}
	
	fclose(fp);	
	return 0;
}

void mygrep(FILE *fp,char *find)
{	
	char fline[500];
	char *newline;
	int i,count=0,occ=0;
	
	f=fopen(c[1],"r");
	
	while(fgets(fline,100,fp)!=NULL)
	{
		count++;
		
		if(newline=strchr(fline,'\n'))
		*newline='\0';
		
		if(strstr(fline,find[2])!=NULL)
		{
		printf("%s %d %s \n",find[1],count,fline);
		occ++;
		}
	}
	printf("\n Occurence= %d",occ);
}

void myreplace(FILE *fp,char *find, char * replace)
{	
	int i , j, m;
 	char s[500],char r[500],char f[500];
 	if(fgets(s,500,find)&&fgets(r,500,replace)&&fgets(f,500,fp))
 	{
 		s[strcspn(s,"\n")]='\0';
 		f[strcspn(f,"\n")]='\0';
 		r[strcspn(r,"\n")]='\0';
 		i=j=m=0;
 		
 		while(s[i]!='\0')
 		{
 			if(s[m++]==f[j++])
 			{
 				if(f[j]=='\0')
 				{
 					fputs(r,stdout);
 					i=m;
 					j=0;
				 }
			 }
			 else
			 {
			 	putchars(s[i++]);
			 	j=0;
			 	m=i;
			 }
 			
		 }
 		
	 }
}


