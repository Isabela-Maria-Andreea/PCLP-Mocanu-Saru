#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
13. Articolele unui fişier conţin următoarele informaţii referitoare la lucrătorii din cadrul unei secţii: 
- număr marcă; 
- nume lucrător; 
- cod operaţie efectuată; 
- număr de execuţii ale operaţiei; 
- valoare manoperă pentru execuţia unei operaţii.  Dacă articolele sunt ordonate crescător după valoarea  „număr marcă”, să se creeze un fişier cu articole care conţin 
următoarele informaţii: număr marcă, nume lucrător, retribuţia.*/

 typedef struct informatii{
 int numar_marca;
 char nume[20];
  char cod;
  int nr_executii;
  float valoare;
 }informatii;


 typedef struct nou{
 int numar_marca;
  char name[20];
    float retributie;
 }nou;


int main(){

 FILE *f=fopen("fisier.bin","rb");
 if(f==NULL){ printf("Fisierul nu s a putut deschide cu succes");
  return 1 ;
 }

  else{

 FILE *g=fopen("fisier2.bin","wb");
  if(g==NULL){ printf("Fisierul nu s a creat cu succes"); return 1; }
  
 informatii s;
 while(fread(&s,sizeof(informatii),1,f)==1){
 float retributie=s.nr_executii*s.valoare;
  nou p;
 p.numar_marca=s.numar_marca;
  strcpy(p.name,s.nume);
  p.retributie=retributie;
  fwrite(&p,sizeof(nou),1,g);
  }

 fclose(g);
 fclose(f);


 }
 

return 0;

    
  }





