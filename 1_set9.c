#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int valoare;
    struct nod *next;
} nod;

int main()
{

    nod *prim = NULL; // lista e goala la inceput
    nod *ultim = NULL;  // vom pointa ultimul nod adaugat

    int n;
    printf("Cate elemente are lista?");
    scanf("%d", &n);

    // constuirea listei

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Elementul %d:", i + 1);
        scanf("%d", &val);
//aici vom aloca memoria ptr nodul nou
         nod *nou=(nod*)malloc(sizeof(nod));
          nou->valoare=val;
          nou->next=NULL;

 if(prim==NULL) prim=nou; //daca lista era goala 
 else{
     ultim->next=nou; //legatura la ultim
 }
 ultim=nou; //acum "nou" e noul ultim element ceea ce are ft mult sens

    }

  //afisarea listei

  printf("Asa arata lista initiala");
  nod *curent=prim;  //asta e un fel indicator ptr parcurgere
  while(curent!=NULL){  
  printf("%d",curent->valoare);
   curent=curent->next;
  }
  printf("\n");


//eliminare elemente pare

 curent=prim;
  nod *anterior=NULL;

 while(curent!=NULL){

 if(curent->valoare%2==0){
  nod *sters=curent;

 if(anterior==NULL){
    //e primul element din lista
    prim=curent->next;
 }
else{ //ptr elem din mijl sau sfarsit
 anterior->next=curent->next;

}


  curent=curent->next; //avansez la urm 
 free(sters); //facem eliberarea memoriei

 }
else
 {
  anterior=curent;
  curent=curent->next;

 }

 }


return 0;

}