#include <stdio.h>

int maior_menor_media(int L[], int N){
    float media;
    int maior_menor, somador;

    somador = 0;
    int i;
    for(i=0;i<N;i++) somador+=L[i];

    media=(float)somador/N;
    printf("a media eh = %f", media);

    i = 0;
    while(i < N && L[i] >= media) i++;
    maior_menor = L[i];
    printf("o maior menor por enquanto eh: %d",maior_menor);

    for(int j = i+1;j<N;j++){
        if(L[j] < media && L[j] >= maior_menor ) maior_menor = L[j];

    }

    return maior_menor;
}

int main()
{
    printf("Problema 1\n");
        int teste1[] = {5,1,3,10,8,13,6,12,4,16};
        int n = 10;
        if (maior_menor_media(teste1,n) == 6)
            printf("Teste 1: OK\n");
        else
            printf("Teste 1: FAIL\n");
    return 0;
}
