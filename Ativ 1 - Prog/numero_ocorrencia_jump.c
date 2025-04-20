#include <math.h>
#include <stdio.h>

int numero_ocorrencia_jump(int L[], int N, int k){
    int i, pulo, quantidade;
    pulo = sqrt(N);
    quantidade = 0;

    i = 0;
    while(i < N && L[i] < k) i += pulo;

    if(i >= N){
        i = N-1; // Já que ultrapassou o tamanho do vetor, é justo colocar o "i" na ultima posição deste

        while(i >= 0 && L[i] >= k) {
            if(L[i] == k) quantidade++;
            i--;
        }
    }

    else if(L[i] == k){
        while(L[i] == k) i++; // "i" vai até a ultima posição ( +1, porém é descontado depois) de ocorrencia "k" no vetor
        i--;

        while(i >= 0 && L[i] == k){
            quantidade++;
            i--;
        }
    }

    else{ // o caso "normal", quando "i" para num numero maior que o "k" e não chegou na ultima posição do vetor
        while(i >= 0 && L[i] >= k){
            if(L[i] == k) quantidade++;
            i--;
        }
    }
    
    printf("\na quantidade eh: %d\n", quantidade);
    return quantidade;
}

    /*if(L[i] == k){
        ultima_posicao = i; // suposta ultima posicao  
        quantidade = 1;
        i--;

        while(i >= 0 && L[i] == k) i--;
        primeira_posicao = i+1;

        i = ultima_posicao;
        while(i < N && L[i] == k) i++;
        ultima_posicao = i-1;

        for(int j = primeira_posicao; j<ultima_posicao; j++) quantidade += 1;        
    }

    else if(L[i] > k && i < N){
        ultima_posicao = i; // considerar que as posicoes querem dizer "intervalo de possibilidade"
        primeira_posicao = i-pulo;

        for(int j = primeira_posicao; j<ultima_posicao; j++){
            if(L[j] == k) quantidade += 1;
        }
    }

    else if(i>N){
        ultima_posicao = N; // considerar que as posicoes querem dizer "intervalo de possibilidade"
        primeira_posicao = N - pulo;

        for(int j = primeira_posicao; j<ultima_posicao; j++){
            if(L[j] == k) quantidade += 1;
        }

    return quantidade;
    }

}
*/




























































