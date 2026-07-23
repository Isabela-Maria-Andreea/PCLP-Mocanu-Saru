#include <stdio.h>
/*
Scrieţi o funcție C pentru extragerea elementelor comune din 2 vectori (neordonați), primiţi ca parametri,
într-un al treilea vector. Se va ţine cont de faptul că cei 2 vectori analizaţi pot avea număr diferit de
elemente şi pot, la limită, să nu aibă nici un element comun. Afişaţi din main() vectorul rezultat, dacă a
putut fi creat.
*/

  void functie(int v1[],int n,int v2[],int m,int v3[],int *nr){
  *nr=0;
  for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
    if(v1[i]==v2[j]){
   int gasit=0;
   for(int k=0;k<*nr;k++)
    if(v3[k]==v1[i]){
     gasit=1;
     break;
    }
   if(gasit==0){
     v3[*nr]=v1[i];
      (*nr)++;
      break;
    }
    }
}   






int main(){
 
 int v1[100],v2[100],v3[100];
 int n,m,nr;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
   scanf("%d",&v1[i]);
  scanf("%d",&m);
  for(int i=0;i<m;i++)
   scanf("%d",&v2[i]);

  functie(v1,n,v2,m,v3,&nr);
  for(int i=0;i<nr;i++)
   printf("%d ",v3[i]);

return 0;
}

