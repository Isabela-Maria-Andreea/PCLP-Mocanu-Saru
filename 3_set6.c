#include <stdio.h>

#define MAX 100


  void functie(int v[],int n,int *poz,int *neg,int *nul){

 *poz=*neg=*nul=0;

  for(int i=0;i<n;i++)
  if(v[i]>0) (*poz)++;
   else if(v[i]<0) (*neg)++;
   else (*nul)++;


  }





int main(){
int v[MAX];
int n;

printf("Introdu nr de elem ale vectorului:");
scanf("%d",&n);

printf("Introdu elementele vectorului:");
  for(int i=0;i<n;i++)
  scanf("%d",&v[i]);

 int poz,neg,nul;
 functie(v,n,&poz,&neg,&nul);

 printf("Pozitive:%d\n",poz);
  printf("Negative:%d\n",neg);
  printf("Nule:%d\n",nul);


  return 0;
}