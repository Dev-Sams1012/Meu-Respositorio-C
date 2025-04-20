#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int maior_menor_media(int L[], int N){
    float media;
    int maior_menor, somador;

    somador = 0;
    int i;
    for(i=0;i<N;i++) somador+=L[i];

    media=(float)somador/N;

    i = 0;
    while(i < N && L[i] >= media) i++;
    maior_menor = L[i];

    for(int j = i+1;j<N;j++){
        if(L[j] < media && L[j] >= maior_menor ) maior_menor = L[j];

    }

    return maior_menor;
}

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

void remova_duplicados_consecutivos(char L[]){
    int i = 1;
    int j = 0;

    while(L[i] != '\0'){
        while(L[i] == L[j]){
            L[i] = '\0';
            ++i;
        }

        j++;
        L[j] = L[i];
        L[i] = '\0';
        i++;
    }

}

int numero_ocorrencia_linear(int L[], int N, int k){
    int i = 0;
    int primeira_posicao, quantidade;

    quantidade = 0;
    while(i<N && L[i] < k){
        i++;
    }

    if(i == N || L[i] > k) return 0;

    else if(L[i] == k){
        quantidade = 1;
        primeira_posicao = i;
        i++;

        while (i<N && L[primeira_posicao] == L[i]){
        quantidade ++;
        i++;
        }

    }
    
    return quantidade;
}

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
    
    return quantidade;
}

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
        
    }

	return pico;
}

void problema1(){
	printf("Problema 1\n");
	int teste1[] = {5,1,3 ,10 ,8,13,6,12,4,16};
	int n = sizeof(teste1)/sizeof(int);
	if (maior_menor_media(teste1,n) == 6)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

void problema2(){
	printf("Problema 2\n");
	int teste1[] = {2,1,8,4,5,6,16,7,9,12};
	int n = sizeof(teste1)/sizeof(int);
	if (impares_ordem_crescente(teste1,n) == 0)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

void problema3(){
	printf("Problema 3\n");
	char s[] = "aaabbbccdd";
	
	remova_duplicados_consecutivos(s);
	
	if ( strcmp(s, "abcd") == 0)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

int generate_sequence(int v[], int n, int m, int k){
	int cont = 0 ;
	
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		v[i] = rand() % m;
		if(v[i] == k) cont++;   
	}
	return cont;
}

int compara(const void *a, const void *b)
{
  return * (int *)a - * (int *)b;
}

void imprime_lista(int v[], int n){
	printf("[");
	printf("%d", v[0]);
	for(int i = 1; i < n; i++)
		printf(" , %d", v[i]);
	printf("]\n");
}

void problema4a(){
	printf("Problema 4a\n");
	int teste1[] = {1,2,2,2,3,3,4,5,6,7};
	int n = sizeof(teste1)/sizeof(int);
	if (numero_ocorrencia_linear(teste1,n,2) == 3)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	if (numero_ocorrencia_linear(teste1,n,3) == 2)
		printf("Teste 2: OK\n");
	else
		printf("Teste 2: FAIL\n");

	
	for(int i = 0; i < 5; i++){
		int n = rand() % 30 + 8 ;
		int v[n];
		int r = rand() % (n/2);
		int cont = generate_sequence(v, n, n/2, r);
		qsort(v, n, sizeof(int), compara);
		printf("v[] = "); 
		imprime_lista(v, n);
		printf("k = %d\n", r);
		printf("cont = %d\n", cont);
		if (numero_ocorrencia_linear(v,n,r) == cont)
			printf("Teste %d: OK\n", i + 3);
		else
			printf("Teste %d: FAIL\n", i + 3);

	}
	printf("\n\n");
}

void problema4b(){
	printf("Problema 4b\n");
	int teste1[] = {1,2,2,2,3,3,4,5,6,7};
	int n = sizeof(teste1)/sizeof(int);
	if (numero_ocorrencia_jump(teste1,n,2) == 3)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	if (numero_ocorrencia_jump(teste1,n,3) == 2)
		printf("Teste 2: OK\n");
	else
		printf("Teste 2: FAIL\n");

    for(int i = 0; i < 5; i++){
		int n = rand() % 30 + 8 ;
		int v[n];
		int r = rand() % (n/2);
		int cont = generate_sequence(v, n, n/2, r);
		qsort(v, n, sizeof(int), compara);
		printf("v[] = "); 
		imprime_lista(v, n);
		printf("k = %d\n", r);
		printf("cont = %d\n", cont);
		if (numero_ocorrencia_jump(v,n,r) == cont)
			printf("Teste %d: OK\n", i + 3);
		else
			printf("Teste %d: FAIL\n", i + 3);
    }
}

void problema5(){
	printf("Problema 5\n");
	int teste1[] = {0,1,4,9,16,10,12,5,3};
	int n = sizeof(teste1)/sizeof(int);
	if (pico_bitonica_binaria(teste1,n) == 16)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	
	
}

int main(){
	problema1();
	problema2();
	problema3();
	problema4a();
	problema4b();
	problema5();
	
	
}
