#include<stdio.h>
#include <string.h>

/*
Se defineşte un tip structură informaţie cu câmpurile firma, produs, cantitate care reprezintă numele 
firmei, denumirea unui produs şi cantitatea din acel produs realizată de firma respectivă. Se declară un 
vector (tablou unidimensional) cu elemente de tip struct informaţie şi se populează cu date citite de la 
tastatură (maximum 5-6). Se va ţine cont de faptul că o firmă poate să apară în evidenţă de mai multe 
ori, cu produse diferite, dar şi că un acelaşi produs poate fi realizat de mai multe firme diferite. 
a) Găsiţi şi afişaţi numele firmei care realizează cea mai mare cantitate dintr-un anumit produs 
(precizat de la tastatură); 
b) Calculaţi şi afişaţi cantitatea totală dintr-un anumit produs (precizat de la tastatură) ce poate fi 
achiziţionată de la toate firmele care sunt înscrise în evidenţă. 
*/
  
  struct informatie{
  char firma[20];
  char produs[20];
   int cantitate;
  };
 




  int main(){
  int n;
  struct informatie v[7];
  printf("Exista urm nr de firme:");
   scanf("%d",&n);
  //Aici realizam citirea datelor din structura
    for(int i=0;i<n;i++){
  printf("Firma:");
   scanf("%s",v[i].firma);
  printf("\n");
  printf("Produsul:");
   scanf("%s",v[i].produs);
    printf("\n");
   printf("Cantitatea:");
    scanf("%d",&v[i].cantitate);
     }
     //Pentru cerinta a :
  char produs_cautat[20];
   printf("Produsul cautat este:");
   scanf("%s",produs_cautat);
  int maxi=-1;
   int index;
 for(int i=0;i<n;i++)
  if(strcmp(produs_cautat,v[i].produs)==0 && v[i].cantitate>maxi) {maxi=v[i].cantitate; index=i;
  }
 if(maxi!=-1) printf("Numele firmei este: %s",v[index].firma);
 else printf("Nu exista nicio firma cu acest produs");

 //Pentru cerinta b;
 char produs_dat[20];
  scanf("%s",produs_dat);
  int cantitate1=0;
 for(int i=0;i<n;i++)
 
 {
  if(strcmp(produs_dat,v[i].produs)==0) cantitate1=v[i].cantitate+cantitate1;

}
 printf("Cantitatea care poate fi cumparata este:%d",cantitate1);


    return 0;
  }



