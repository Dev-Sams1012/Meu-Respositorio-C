#include <stdio.h>

int pico_bitonica_binaria(int L[], int N){
    int pico, inicio, fim, meio;
    inicio = 0;
    fim = N-1;

    pico = L[0];
    while(inicio<fim){
        meio = (inicio+fim)/2;

        if(L[meio] > pico) pico = L[meio];

        else{
            if(L[meio] < L[meio-1]){
                pico = L[meio-1];
                fim = meio-1;
            }

            else if(L[meio] < L[meio+1]){
                pico = L[meio+1];
                inicio = meio+1;
            }

            else if(L[meio] == pico) break;
        }


        printf("\nparou no: %d", meio);
        printf("\no pico eh: %d", pico);
        
    }

	return pico;
}