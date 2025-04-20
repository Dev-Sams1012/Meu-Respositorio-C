#include <stdio.h>


int impares_ordem_crescente(int L[], int N){
    int ultimo_impar,proximo_impar;

    int i = 0;
    while(i<N && (L[i]%2 == 0)) i++;

    if(i==N) return -1;

    ultimo_impar = L[i];

    i++;
    proximo_impar = 0;
    while(i < N){

        if(L[i]%2 != 0) proximo_impar = L[i]; 

        if(proximo_impar != 0 && proximo_impar > ultimo_impar) ultimo_impar = proximo_impar;

        else if(proximo_impar != 0 && proximo_impar < ultimo_impar) return -1;

        i++;
    }

	return 0;
}
