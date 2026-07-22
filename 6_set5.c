#include <stdio.h>

int estePalindrom(int n){
    int x = n;
    int nr = 0;
    while(x != 0){
        nr = nr*10 + x%10;
        x /= 10;
    }
    return nr;
}

int functie(int n, int *nr){
    *nr = 0;
    int gasit = 0;          
    while(n != 0){
        if(n%10 % 2 == 0){
            *nr = *nr*10 + n%10;
            gasit = 1;
        }
        n /= 10;
    }

    if(gasit == 0) return 0;      //nicio cifră pară găsită

    *nr = estePalindrom(*nr);     // inversăm ordinea cifrelor (le puneam "invers" la acumulare)
    return 1;                     // e bun
}

int main(){
    int n, rezultat;

    printf("Introduceti numarul: ");
    scanf("%d", &n);

    int succes = functie(n, &rezultat);

    if(succes == 1)
        printf("numarul obtinut din %d este %d\n", n, rezultat);
    else
        printf("Numarul %d nu are nicio cifra para, nu se poate construi un numar nou.\n", n);

    return 0;
}