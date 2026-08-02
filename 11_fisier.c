/*Se consideră un fişier în care sunt  înscrise următoarele informaţii referitoare la o grupă de studenţi: nume student, 
prenume  student,  media  obţinută  de  student  în  sesiunea  de  examene  curentă.  Să  se  scrie  funcţii  care  să  realizeze 
următoarele operaţii: 
- să afişeze media şi numele studentului cu media cea mai mare; 
- să  determine  media  studentului  de  la  mijlocul  fişierului  şi  să  semnaleze  situaţia  în  care  fişierul  conţine  un 
număr par de articole (caz în care nu va mai determina media, ci va genera o valoare care să permită înţelegerea 
acestei situaţii); 
- să ordoneze crescător articolele fişierului după valoarea mediilor şi să afişeze media şi numele studentului aflat 
pe ultima poziţie din fişier în urma acestei operaţii. */

#include<stdio.h>
#include<string.h>


typedef struct student{
 char nume[20];
  char prenume[20];
 float media;
}student;


void gaseste_max(FILE *f,char *nume_max,char *prenume_max,float *media_m){

 student s;
  *media_m=-1;
 while(fread(&s,sizeof(student),1,f)==1){

if(s.media>(*media_m)){
 *media_m=s.media;
  strcpy(nume_max, s.nume);
strcpy(prenume_max, s.prenume);

 }
 }

}








int main(){

 FILE *f=fopen("studenti.bin","wb");

 if(f==NULL) {
    printf("Eroare la deschiderea fisierului");
 }
  int n;
  scanf("%d",&n);
  
 for(int i=0;i<n;i++){
     student s;
    scanf("%s", s.nume);       
    scanf("%s", s.prenume);
    scanf("%f", &s.media);

 fwrite(&s,sizeof(student),1,f);

 }

 fclose(f);

 f=fopen("studenti.bin","rb");
 char nume_max[20];
  char prenume_max[20];
 float media_m; 
  gaseste_max(f,nume_max,prenume_max,&media_m);

 printf("Studentul cu media maxima: %s %s ,media %f",nume_max,prenume_max,media_m);

fclose(f);

 f=fopen("studenti/bin","rb");
 
 fseek(f,0,SEEK_END);  //ne  numta la finalul fisierului
  long dimensiune_octeti=ftell(f); //ftell ne spune exact la ce poz ne sit dupa
  int n=dimensiune_octeti/sizeof(student); //dimensiunea in octeti impartita la dimensiunea unui student ne da nr de studenti
  if(n%2==0){ printf("Fisierul contine un numar par de articole, nu se poate determina media studentului de la mijloc");}
  else{ printf("Media studentului de la mijloc este: %f",s.media);}




    return 0;
}