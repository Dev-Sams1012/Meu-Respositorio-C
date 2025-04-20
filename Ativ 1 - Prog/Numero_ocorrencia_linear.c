int numero_ocorrencia_linear(int L[], int N, int k){
    int i = 0;
    int primeira_posicao, quantidade;

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

        return quantidade;
    }
    
}