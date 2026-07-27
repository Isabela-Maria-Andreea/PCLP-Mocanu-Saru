#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Să se creeze o listă simplu înlănţuită care să conţină elemente ce descriu persoane prin nume şi vârstă. 
Să se caute în listă persoana numită George,  cu  vârsta  de  19  ani şi, dacă este găsită, să se verifice 
dacă  următoarea  persoană  din  listă  este  mai  tânără.  Atenţie  la  situaţia  în  care  persoana  căutată  
corespunde chiar ultimului element din listă!
*/

//nu am tratat cazul in care george nu exista in lista

typedef struct nod{


struct nod *next;
char nume[20];
int varsta;

}nod;


int main(){

nod *prim=NULL;
 nod *ultim=NULL;
 int n;
 printf("Cate persoane sunt?");
  scanf("%d",&n);

 for(int i=0;i<n;i++){
 char numele[20];
  int varsta2;
 printf("Persoana %d",i+1);
  printf("Nume:");
   scanf("%s",numele);
   printf("Varsta:");
    scanf("%d",&varsta2);

 nod *nou=(nod*) malloc(sizeof(nod));  //dupa maloc memoria e gunoi
  strcpy(nou->nume, numele);
  nou->varsta=varsta2;
 nou->next=NULL;
 if(prim== NULL) prim=nou;
 else{
  ultim->next=nou;
 }
  ultim=nou;

 }


 nod *curent=prim;
  while(curent!=NULL){

 if((strcmp(curent->nume,"George")==0) && curent->varsta==19){

 if(curent->next!=NULL){
 if(curent->next->varsta < curent->varsta) printf("DA");
 }
else printf("Capat de lista");
 break;

 }

 curent=curent->next;


  }
 










 }





