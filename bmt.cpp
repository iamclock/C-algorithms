#include <stdio.h>
#include <stdlib.h>

int main()
{
char *s;
int **m, i=0, j, k, check=0, n=0;
char *file1;
FILE *f1=fopen("input.txt", "rt");
if(f1==NULL)
{perror(file1);
exit(0);
}
s=(char *)malloc(100);
  fscanf(f1, "%s", s);
  fscanf(f1, "%s", s);
while(s[i]!='\0')
 {
 n++;
 i++;
 }
m=(int **)malloc(n*sizeof(int *));
if(m==NULL)
{
 puts("Matrix memory allocation failed");
 exit(0);
}

//*********************************
//копирование и сортировка s в матрицу m
/*
if(s[i]!='\0') 
 {m[i]=(int *)s[i]; i++;
 }
for(j=1, i=1; s[i]!='\0'; ++j, ++i)
  {
  for(k=0; k!=j; k++)
   {
   if(m[k]==s[i])
    {
    check=1;
    }
   }
  if(check!=1)
   {
   m[j]=(int *)s[i];
   }
  }
*/
//************************************
/*
while(m[i]!='\0')
 {
 
 
 }

*/
i=0;
while(s[i]!='\0')
{
m[i]=(int *)s[i];
++i;
}
i=0;
while(m[i]!='\0')
{
printf("%d ", m[i]);
i++;
}
puts("");
fclose(f1);
free(m);
return 0;
}
