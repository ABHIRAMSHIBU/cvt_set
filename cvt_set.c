/*This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>*/
//  cvt_set  Copyright (C) 2017  Abhiram Shibu
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char license[]="svt_set.c  Copyright (C) 2017 Abhiram Shibu\nThis program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\nThis is free software, and you are welcome to redistribute it under certain conditions;\n";
char *read_command(char command[])
{
	FILE *fp;
	char *buff,buff1[2];
	buff=malloc(sizeof(char)*1000);
	fp=malloc(sizeof(fp));
	fp=popen(command,"r");
	buff1[1]='\0';
	//*buff='\0';
	while(1)
		
		{
			buff1[0]=fgetc(fp);
			if(!feof(fp))
				strcat(buff,buff1);
			else
				break;
		}	
	return buff;

}
int *find(char string1[],char what,int size) //Finds what in string 1
{
	int i,j=0;
	int *z=malloc(sizeof(int)*size); //A list with indexes
	for(i=0;i<size;i++)     //Zero garbage
		z[i]=0;
	for(i=0;i<strlen(string1);i++) //Finding all occurences
	{
		if(string1[i]==what)
		{
			z[j]=i;
			j++;
		}
	}	
	return z;
}

int main(int argc, char *argv[])
{
	char *buff,buff1[100];
	FILE *fp;
	int i,*list;
	printf("%s",license);
	fp=malloc(sizeof(FILE));//allocating memory
	fp=popen("ls","r");
	if(argc<2) //Check for arguments
	{
		printf("You havnt given any arguments!");
	}
	else  //Main program starts
	{
		if(!strcmp(argv[1],"--help") || !strcmp(argv[1],"-h"))
		{
			printf("  HELP MENU\n  cvt_set res.fps\n     Example: cvt_set 1920x1080.60\n  END\n");
		}
		else
		{
			strcpy(buff1,argv[1]);
			list=find(buff1,'x',strlen(buff1));
			for(int i=0;i<strlen(buff1);i++)
			{
				printf("%d",list[i]);
			}
			buff=read_command("cvt");
			//puts(buff);
		}
	}
}
	
