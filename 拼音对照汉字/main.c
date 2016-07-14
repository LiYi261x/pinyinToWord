#include <stdio.h>
#include <string.h>
#include "t9.h"

void print(char *str,int num, int numth);
void overallsoundprt(char *s, int length, int numth);
char* run(char *str);
char vovel[6] = {'A','O','E','I','U','V'};
int q = 0;

char pinyin[500][6] = {0};
char word[500][2] = {0};
char initial[20] = {'Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','B','N','M'};
char viwel[33][5] = {"A","O","E","I","U","V","AI","EI","UI","AO","OU","IU","IE","VE","ER",
                     "AN","EN","IN","UN","VN","ANG","ENG","ING","ONG","IAN","IAO","IANG","UAN",
                     "UAI","UANG","UA","IA","UO"}; 
char overallSound[10][5] = {"A","O","E","AI","AO","OU","ER","AN","EN","ANG"};
static int numInitial[100] = { 0 };
struct t9PY_index t9PY_index2[];
struct t9PY_index result[100];
int main()
{

   int i, j, p;
   char str[100];
   while (1)
   {
	   i = j = p = q = 0;
	   printf("输入大写的拼音： ");
	   gets(str);

	   //   printf("输入的拼音是 %s\n",str);
	   run(str);
	   /*printf("numInitial[0]  = %d", numInitial[0]);
	   printf("numInitial[1]  = %d", numInitial[1]);
	   printf("numInitial[2]  = %d", numInitial[2]);*/
	   /*   for (i = 0; i < q+2; i++)
		  {
		  printf("%d", numInitial[i]);

		  }*/


	   printf("对应的中文为：");
	   for (i = 0;; i++)
	   {
		   if (numInitial[i + 1] == 999)
			   break;
		   print(str, numInitial[i + 1] - numInitial[i], numInitial[i]);

	   }
	  // printf("\n");
   }
   return 0;

}
void print(char *str,int num,int numth)
{
	int j,flg=0;
	switch (num)
	{
	case 1:
printf("1\n");
		for (j = 0; j < 7; j++)
		{
			if (strnicmp(&str[numth], t9PY_index2[j].PY, 1) == 0)
			{
				printf("%s\n", t9PY_index2[j].PY_mb);
				flg = 1;
			}
		}
		if (flg) break;
		overallsoundprt(str, 1, numth);
		break;
	case 2:
printf("2\n");
		for (j = 7; j < 85; j++)
		{
			if (strnicmp(&str[numth], t9PY_index2[j].PY, 2) == 0)
			{
				printf("%s", t9PY_index2[j].PY_mb);
				flg = 1;
			}
		}
		if (flg) break;
		overallsoundprt(str, 2, numth);
		break;
	case 3:
printf("3\n");
		for (j = 85; j < 252; j++)
		{
			if (strnicmp(&str[numth], t9PY_index2[j].PY, 3) == 0)
			{
				printf("%s", t9PY_index2[j].PY_mb);
				flg = 1;
			}
		}
		if (flg) break;
		overallsoundprt(str, 3, numth);
		break;
	case 4:
printf("4\n");
		for (j = 252; j < 373; j++)
		{
			if (strnicmp(&str[numth], t9PY_index2[j].PY, 4) == 0)
			{
				printf("%s", t9PY_index2[j].PY_mb);
				flg = 1;
			}
		}
		if (flg) break;
		overallsoundprt(str, 4, numth);
		break;
	case 5:
printf("5\n");
		for (j = 373; j < 397; j++)
		{
			if (strnicmp(&str[numth], t9PY_index2[j].PY, 5) == 0)
			{
				printf("%s", t9PY_index2[j].PY_mb);
				flg = 1;
			}
		}
		if (flg) break;
		overallsoundprt(str, 5, numth);
		break;
	default:
		break;
	}
}
char* run(char *s)
{
   int i,j;
   int p,q;
   q = 1;
   numInitial[0] = 0;
   char str[100];
   for(i = 0; i<100; i++)
   {
      if(s[i] == '\0')
         break;
      
      for(j=0; j <6; j++)
      {
         if(s[i]==vovel[j])
         {
//			 printf("%c",s[i]);
			 for (p = 0; p < 20; p++)
			 {
				 if (s[i - 1] == initial[p])
				 {
					 numInitial[q] = i - 1;
					 

					 if (initial[p] == 'H');
					 {
						 if (s[i - 2] == 'C')
							 numInitial[q] = i - 2;
						 if (s[i - 2] == 'S')
							 numInitial[q] = i - 2;
						 if (s[i - 2] == 'Z')
							 numInitial[q] = i - 2;

					 }
					 q++;

					 break;
				 }
	
			 }
			
         }
      }

   }
   numInitial[q] = strlen(s);
   numInitial[q + 1] = 999;

   return str;
}

void overallsoundprt(char *s,int length,int numth)
{
	int i,flg,num,temp;
	flg = 1;
	for (i = 373; i < 397; i++)
	{
		if (strnicmp(&s[numth], t9PY_index2[i].PY, 5) == 0)
		{
			printf("%s", t9PY_index2[i].PY_mb);
			flg = 0;
			num = 5;
		}
	}
	if (flg)
	{
		for (i = 252; i < 373; i++)
		{
			if (strnicmp(&s[numth], t9PY_index2[i].PY, 4) == 0)
			{
				printf("%s", t9PY_index2[i].PY_mb);
				flg = 0;
				num = 4;
			}
		}
	}
	if (flg)
	{
		for (i = 85; i < 252; i++)
		{
			if (strnicmp(&s[numth], t9PY_index2[i].PY, 3) == 0)
			{
				printf("%s", t9PY_index2[i].PY_mb);
				flg = 0;
				num = 3;
			}

		}

	}
	if (flg)
	{
		for (i = 7; i < 85; i++)
		{
			if (strnicmp(&s[numth], t9PY_index2[i].PY, 2) == 0)
			{
				printf("%s", t9PY_index2[i].PY_mb);
				flg = 0;
				num = 2;
			}
		}
	}
	if (flg)
	{
		for (i = 0; i < 7; i++)
		{
			if (strnicmp(&s[numth], t9PY_index2[i].PY, 1) == 0)
			{
				printf("%s\n", t9PY_index2[i].PY_mb);
				flg = 0;
				num = 1;
			}

		}
	}
	for(i = length; i > num-1; i--)
	{
		
		if (s[numth + i] == 'A' || s[numth + i] == 'E' || s[numth + i] == 'O')
		{
			print(s, length - i, numth + i);
		}
	}
}

