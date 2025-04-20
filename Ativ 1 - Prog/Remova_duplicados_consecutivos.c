// a a a b b b c c d d

// a b c d \0 \0 \0 \0 \0 \0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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


int main(){
	printf("Problema 3\n");
	char s[] = "ssaabbddeeeeeeeeeee";
	
	remova_duplicados_consecutivos(s);
	
	if ( strcmp(s, "sabde") == 0)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");

    return 0;
}

