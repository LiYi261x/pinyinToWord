#include <stdio.h>
#include <string.h>
#include "t9.h"


char* run(char *str);
char vovel[6] = {'A','O','E','I','U','V'};
int q = 0;

char pinyin[500][6] = {0};
char word[500][2] = {0};
char initial[20] = {'Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','B','N','M'};
char viwel[33][5] = {"A","O","E","I","U","V","AI","EI","UI","AO","OU","IU","IE","VE","ER",
                     "AN","EN","IN","UN","VN","ANG","ENG","ING","ONG","IAN","IAO","IANG","UAN",
                     "UAI","UANG","UA","IA","UO"}; 
int numInitial[100] = { 0 };
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
	   /*   for (i = 0; i < q+2; i++)
		  {
		  printf("%d", numInitial[i]);

		  }*/


	   printf("对应的中文为：");
	   for (i = 0;; i++)
	   {
		   if (numInitial[i + 1] == 999)
			   break;
		   switch (numInitial[i + 1] - numInitial[i])
		   {
		   case 1:
			   for (j = 0; j < 7; j++)
			   {
				   if (strnicmp(&str[numInitial[i]], t9PY_index2[j].PY, 1) == 0)
				   {
					   printf("%s\n", t9PY_index2[j].PY_mb);
				   }
			   }
			   break;
		   case 2:
			   for (j = 7; j < 85; j++)
			   {
				   if (strnicmp(&str[numInitial[i]], t9PY_index2[j].PY, 2) == 0)
				   {
					   printf("%s", t9PY_index2[j].PY_mb);
				   }
			   }
			   break;
		   case 3:
			   for (j = 85; j < 252; j++)
			   {
				   if (strnicmp(&str[numInitial[i]], t9PY_index2[j].PY, 3) == 0)
				   {
					   printf("%s", t9PY_index2[j].PY_mb);
				   }

			   }
			   break;
		   case 4:
			   for (j = 252; j < 373; j++)
			   {
				   if (strnicmp(&str[numInitial[i]], t9PY_index2[j].PY, 4) == 0)
				   {
					   printf("%s", t9PY_index2[j].PY_mb);
				   }
			   }
			   break;
		   case 5:
			   for (j = 373; j < 397; j++)
			   {
				   if (strnicmp(&str[numInitial[i]], t9PY_index2[j].PY, 5) == 0)
				   {
					   printf("%s", t9PY_index2[j].PY_mb);
				   }
			   }
			   break;
		   default:
			   break;
		   }
	   }
	   printf("\n");
   }
   return 0;

}
char* run(char *s)
{
   int i,j;
   int p;

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
				 }
				/* else
				 {
					 numInitial[q] = i;
					 q++;
				 }*/

			 }

         }
      }

   }
   numInitial[q] = strlen(s);
   numInitial[q + 1] = 999;

   return str;
}


