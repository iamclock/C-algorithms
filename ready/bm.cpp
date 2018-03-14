#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int identify(int i, char s[])
{   int j=0;
    while(j!=i) {
        if(s[j]==s[i]) return 0;
        j++;
    }
    return 1;
}
*/

int BMs(char where[], char s[])
{   int i, j, n, m, k, l=-1, shift[257];
    n=(strlen(where));
    m=(strlen(s));
    if(m>n) return -2;
    //формирование массива shift для последующего смещения
    //при поиске
    for(i=0; i<256; i++) shift[i]=m;
    for(i=0; i<m-1; i++) {
// if(identify(i, s))
        shift[(unsigned)s[i]]=m-i-1;
    }
    for(i=m-1; ((i<n)&&(l==-1)); i+=shift[(unsigned)where[i]]) {
        for(j=m-1, k=i; (j>=0)&&(s[j]==where[k]); j--, k--);
        if(j<0) l=i-m+1;
    }
    printf("%d\n", l);
    return l;
}


int main()
{
char *where, *s;
int rez, i;
char *file1=(char *)"input.txt";
FILE *f1=fopen("input.txt", "rt");
char *file2=(char *)"output.txt";
FILE *f2=fopen("output.txt", "wt");
if(f1==NULL){
 perror(file1);
 exit(0);
 }
if(f2==NULL){
 perror(file2);
 exit(0);
 }
where=(char *)malloc(100);
s=(char *)malloc(100);
fscanf(f1, "%s", where);
fscanf(f1, "%s", s);
rez=BMs(where, s);
if(rez>=0){
 for(i=rez; where[i]!='\0'; i++){
  fprintf(f2, "%c", where[i]);
  printf("%c", where[i]);
  }
 }
 puts("");
 printf("where+%d\n", rez+1);
fclose(f1);
free(where);
free(s);
    fclose(f2);
    return 0;
}