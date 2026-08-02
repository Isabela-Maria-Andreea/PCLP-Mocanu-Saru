#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct om{
    char nume[20];
    char localitate[20];
} om;

int main(){

    FILE *f = fopen("fisier.bin", "rb");
    if(f == NULL){
        printf("Nu e ce trb");
        return 1;
    }

    om p;
    char localitati[1000][20];
    int contor[1000];
    int nr_localitati = 0;

    while(fread(&p, sizeof(om), 1, f) == 1){

        int gasit = 0;
        int index_gasit = -1;
        for(int i=0; i<nr_localitati; i++){
            if(strcmp(localitati[i], p.localitate) == 0){
                gasit = 1;
                index_gasit = i;
                break;
            }
        }

        if(gasit == 1){
            contor[index_gasit]++;
        } else {
            strcpy(localitati[nr_localitati], p.localitate);
            contor[nr_localitati] = 1;
            nr_localitati++;
        }
    }

    fclose(f);

    for(int i=0; i<nr_localitati; i++){
        printf("%s: %d persoane\n", localitati[i], contor[i]);
    }

    return 0;
}