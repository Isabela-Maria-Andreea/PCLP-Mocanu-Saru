#include <stdio.h>

/*
Se defineşte un tip structură student cu câmpurile nume, nota1, nota2, nota3, care reprezintă numele 
studentului şi notele obţinute la 3 materii distincte (aceleaşi 3 materii şi în aceeaşi ordine pentru toţi 
studenţii). Se cere: 
a) Declaraţi un vector (tablou unidimensional) studenţi de tipul struct student în care stocaţi 
datele despre 5-6 studenţi, citite de la tastatură; 
b) Căutaţi un student după nume (precizat de la tastatură). Dacă îl găsiţi, afişaţi toate informaţiile 
care îl caracterizează; altfel, afişaţi un mesaj corespunzător; 
c) Aflaţi care este cel mai bun student la o anumită materie (precizată de la tastatură) şi afişaţi 
numele său. Dacă există mai mulţi astfel de studenţi, afisaţi numele tuturor în ordine alfabetică. 
d) Determinaţi premiantul/premianţii grupului de studenţi (cel/cei cu media generală maximă) şi 
afişaţi numele său. Dacă există mai mulţi astfel de studenţi, afisaţi numele tuturor. 
e) Sortaţi vectorul studenţi descrescător, în funcţie de valorea câmpului nota2.  
f) Determinaţi şi afişaţi numele studenţilor nepromovaţi la cel puțin o materie. 
*/

#define ADEVARAT 1 //Nu toate compilatoarele accespta sa folosesti bool asa ca am definit o variabila de tip int pentru a putea folosi valori booleene
#define FALS 0
 int gasit=FALS;  //ptr cei ce citesc asta puteti lucra fara define
typedef struct student{
 char nume;
 float nota1;
 float nota2;
 float nota3;
}student;




int main(){
   int n;
  student v[12];
     //Aici urmeaza sa fac citirile:
  printf("Nr de studenti este:");
  scanf("%d",&n);

  for(int i=0;i<n;i++){
      printf("Numele:");
   scanf("%s",v[i].nume);
   printf("Nota 1:");
    scanf("%f",&v[i].nota1);
     printf("Nota 2:");
    scanf("%f",&v[i].nota2);
 printf("Nota 3:");
    scanf("%f",&v[i].nota3);

  }
  //Ptr a cauta un student dupa nume voi aplica strcmp() pe fiecare student salvat
  char nume_cautat[20];
  scanf("%s",nume_cautat);
   for(int i=0;i<n;i++)
  if(strcmp(nume_cautat,v[i].nume)==0) { gasit=ADEVARAT;
  printf("Datele studentului sunt:\n");
   printf("Numele:%s",nume_cautat);
    printf("\nNota1:%f",v[i].nota1);
printf("\nNota2:%f",v[i].nota2);
printf("\nNota3:%f",v[i].nota3);
 break;
  }

 if(gasit==FALS) printf("Nu exista studentul cautat");








  return 0;


}