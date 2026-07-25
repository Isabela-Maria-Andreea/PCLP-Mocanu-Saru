/*Se defineşte un tip structură persoana cu câmpurile nume, prenume şi CNP (toate şiruri de caractere). 
Se cere: 
a) Construiţi un vector (tablou unidimensional) cu elemente de tip struct persoana, citind 
informaţiile necesare de la tastatură; 
b) Ordonaţi persoanele descrise în vector descrescător, după data naşterii. 
c) Ordonaţi persoanele descrise în vector în funcţie de nume și prenume, ca într-un catalog. */

#include <stdio.h>
#include <string.h> 
// EX  6 06 05 25
//formatul cnp ului e S AA LL ZZ ******
typedef struct persoana{
 char nume[20];
 char prenume[20];
 char CNP[14];
}persoana;

int main(){ 
    //ptr a totul basic citirile generale 
 persoana v[6];
 int n;
  printf("Se citesc urm nr de persoane:");
  scanf("%d",&n);
 for(int i=0;i<n;i++){
  printf("Nume:");
   scanf("%s",v[i].nume);
  printf("Prenume:");
   scanf("%s",v[i].prenume);
    printf("CNP:");
    scanf("%s",v[i].CNP);
 }

  //la b nu e prea complicat ,dar e o chestiune de atentie 
  //in CNP avem caractere,nu cifre numerice deci ptr numeric facem o operatie de genul CNP[2]-'0'
  //trb sa comparam an/luna/zi
  //intervine si chestiunea de 1960 si 2006 asta e exemplu de secole diferite,dar presupunem ca nu e cazul aici
  //si ca fun funct CNP[0] pe langa sex semnifica si secolul

  // IMPORTANT: nu facem swap direct in bucla j , pentru ca
  // an/luna/zi de la pozitia i raman "vechi" dupa un swap si strica urmatoarele comparatii.
  // Solutie: selection sort -> retinem doar indexul celui mai bun candidat gasit,
  // si facem un singur swap, la finalul buclei interioare j.
  for(int i=0;i<n-1;i++){
      int index_ales = i; // presupunem ca v[i] e cel mai "tanar" pana acum
      int an=(v[index_ales].CNP[1]-'0')*10+(v[index_ales].CNP[2]-'0');
      int luna=(v[index_ales].CNP[3]-'0')*10+(v[index_ales].CNP[4]-'0');
      int zi=(v[index_ales].CNP[5]-'0')*10+(v[index_ales].CNP[6]-'0');

      for(int j=i+1;j<n;j++){       
          int an2=(v[j].CNP[1]-'0')*10+(v[j].CNP[2]-'0');
          int luna2=(v[j].CNP[3]-'0')*10+(v[j].CNP[4]-'0');
          int zi2=(v[j].CNP[5]-'0')*10+(v[j].CNP[6]-'0');

          // descrescator = cel mai recent nascut (an mai mare, apoi luna, apoi zi) primul
          if(an2>an || (an2==an && luna2>luna) || (an2==an && luna2==luna && zi2>zi)){
              index_ales = j;
              an = an2; luna = luna2; zi = zi2; // actualizam "cel mai bun" gasit pana acum
          }
      }

      if(index_ales != i){
          persoana aux = v[i];    
          v[i] = v[index_ales];  
          v[index_ales] = aux; 
      }
  }

  printf("\nPersoane ordonate descrescator dupa data nasterii:\n");
  for(int i=0;i<n;i++){
      printf("%s %s - CNP: %s\n", v[i].nume, v[i].prenume, v[i].CNP);
  }

  //la c e mai simplu, doar ca trebuie sa avem grija la strcmp() si la ordinea alfabetica
  for(int i=0;i<n-1;i++){
      int index_ales = i;

      for(int j=i+1;j<n;j++){
          int cmp_nume = strcmp(v[j].nume, v[index_ales].nume);
          // daca numele sunt identice, decidem dupa prenume (ca la catalog: nume, apoi prenume)
          if(cmp_nume < 0 || (cmp_nume == 0 && strcmp(v[j].prenume, v[index_ales].prenume) < 0)){
              index_ales = j;
          }
      }

      if(index_ales != i){
          persoana aux = v[i];
          v[i] = v[index_ales];
          v[index_ales] = aux;
      }
  }

  printf("\nPersoane ordonate alfabetic (nume, prenume):\n");
  for(int i=0;i<n;i++){
      printf("%s %s - CNP: %s\n", v[i].nume, v[i].prenume, v[i].CNP);
  }

  return 0;
}