#include<stdio.h>
#include<string.h>

/*Scrieţi un program care  să  numere  cuvintele  şi propoziţiile unui text.  Textul este încheiat  de  caracterul “sfârşit de 
fişier”. -adica EOF  Cuvintele  sunt  separate  prin  virgulă  şi  spaţiu  iar  propoziţiile  se  termină  cu  unul  dintre  caracterele  punct, 
semnul  exclamării  sau  semnul  întrebării.  Un  cuvânt  poate  începe  printr-o  literă  sau  printr-o  cifră  iar  în  interiorul 
cuvintelor se acceptă doar: literele, cifrele şi caracterul cratimă (-)*/







int main(){

FILE *f=fopen("text.txt","r");
if(f==NULL){ printf("Eroare la deschiderea fisierului");
  return 1;
}
 int cuvinte=0,propozitii=0;
 int caracter;
  while((caracter=fgetc(f))!=EOF){
    
 if(caracter==',' || caracter == ' '){
 cuvinte++;
  }
  if(caracter=='.' || caracter=='!' || caracter=='?'){
  propozitii++;
  }
  } 




}