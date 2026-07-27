#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Să se construiască o listă simplu înlănţuită de cuvinte, cu câmp de informaţii de tip char cuv[15] pentru 
cuvântul conţinut de fiecare element. Informaţiile pentru popularea listei vor fi citite de la tastatură. Afişaţi 
conţinutul listei pe ecran (cuvânt şi adresa următorului element din listă). Parcurgeţi apoi, din nou, lista şi 
generaţi o frază prin concatenarea cuvintelor şi adăugarea caracterului spaţiu între  acestea.  La  final, 
afisaţi pe ecran fraza astfel construită. 

*/

 typedef struct nod{

 char cuv[15];
 struct nod *next;
 }nod;



int main(){

printf("Se citesc cuvinte de la tastatura:");
int n;
scanf("%d",&n);

 nod *prim=NULL;
 nod *ultim=NULL;

  for(int i=0;i<n;i++){

 char cuvinte[15];
  printf("Cuvantul %d",i+1);
  scanf("%s",cuvinte);


  nod *nou=(nod*)malloc(sizeof(nod));
 strcpy(nou->cuv,cuvinte);
 nou->next=NULL;
if(prim==NULL) prim=nou;
else{
    ultim->next=nou;
    
}
ultim=nou;

  }

 nod *curent=prim;
 printf("Cuvintele:\n");
 for(int i=0;i<n;i++){
  
  printf("%s - adresa urmatorului:%p\n",curent->cuv,(void*)curent->next );

 curent=curent->next;

 }

char fraza[100]="";
 curent=prim;
  while(curent!=NULL){
  strcat(fraza,curent->cuv);
  strcat(fraza," ");
  curent=curent->next;
  }

 printf("Fraza este:%s",fraza);




    
}