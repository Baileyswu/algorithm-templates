#include <string.h>

#include <stdio.h> 
#define M 1100100
char b[M],a[M<<1]; int p[M<<1]; int Min(int a,int b) { 
    return a<b?a:b; } 
int main() {     
int i,n,id,MaxL,MaxId,o=1;
     while(scanf("%s",b)!=EOF)     {
         MaxL=MaxId=0;if(strcmp(b,"END")==0)break;
         for(i=1;b[i]!='\0';i++)         {
             a[(i<<1)]=b[i];
             a[(i<<1)+1]='#';
         }

         a[0]='?';a[1]='#';
         n=(i<<1)+2;a[n]=0;
         MaxId=MaxL=0;
         for(i=1;i<n;i++)         {
             if(MaxId>i)             {
                 p[i]=Min(p[2*id-i],MaxId-i);
             }             else             {
                 p[i]=1;             }             while(a[i+p[i]]==a[i-p[i]])             {                 p[i]++;             }             if(p[i]+i>MaxId)             {                 MaxId=p[i]+i;                 id=i;             }             if(p[i]>MaxL)             {                 MaxL=p[i];             }         }         printf("Case %d: %d\n",o++,MaxL-1);     }     return 0; }  

