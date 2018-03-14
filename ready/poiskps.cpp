#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


char *find(char *where, char *s)
{
int i=0, j=0, k, m=0, check=0;
char *rez;
rez=(char *)malloc(100);
while(check!=1 && where[j]!='\0')
 {
 if(s[i]==where[j])
     {
     k=j;
     while((s[i]==where[j] || s[i]=='\0') && where[j]!='\0')
      {
      rez[m]=where[j];
      i++;
      j++;
      m++;
      if(s[i]=='\0') check=1;
      }
     j=k;
     }
 i=0;
 j++;
 m=0;
 }
if(check!=1) return NULL;
  else
   {
   printf("where+%d\n", ++k);
//   puts("");
   return rez;
   }
}



int main()
{
char *where, *s, *rez;
int k;
 char *file1=(char *)"input.txt";
    FILE *f1=fopen("input.txt", "rt");
 char *file2=(char *)"output.txt";
    FILE *f2=fopen("output.txt", "wt");
if(f1==NULL)
{
perror("ERROR: f1");
exit(0);
}
if(f2==NULL)
{
perror("ERROR: f2");
exit(0);
}
where=(char *)malloc(100);
s=(char *)malloc(100);
    fscanf(f1, "%s", where);
    fscanf(f1, "%s", s);
rez=find(where, s);
fclose(f1);
free(where);
free(s);
if(rez!=NULL)
fprintf(f2, "%s", rez);
free(rez);
fclose(f2);
return 0;
}
