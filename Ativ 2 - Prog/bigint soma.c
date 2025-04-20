#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct bigInt {
	char digit[101];
	int size;
} bigint;

void reverse(char s[]){
	int i = 0;
	int j = strlen(s)-1;
	while(i<j){
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}


bigint init_bigint(char s[]){
	bigint b;
	b.size = strlen(s);
	strcpy(b.digit, s);
	reverse(b.digit);
	return b;
}


int char2int(char c){
	return c-'0';
}

char int2char(int v){
	return '0'+v;
}

void imprime_bigint(bigint b){
	printf("bigint: ");
	for(int i = b.size-1; i >= 0; i--)
		printf("%c", b.digit[i]);
	printf("\n");
}

bigint soma(bigint a, bigint b){
	bigint c = init_bigint("");
	int i = 0;
	int tamanho, int_a, int_b, soma;
	char char_soma;
	int vai_um = 0;

	// Aqui verificaremos o tamanho do maior dos dois termos:
	if(a.size > b.size) tamanho = a.size;
	else tamanho = b.size;
	c.size = tamanho;

	// Aqui será o procedimento da soma:
	for(i=0;i<tamanho;i++){
		if(a.digit[i] =='\0' && b.digit[i] == '\0' && vai_um == 0){
			c.digit[i] = '\0';
			break;	
		}

		else{
			int_a = char2int(a.digit[i]);
			int_b = char2int(b.digit[i]);

			if(a.digit[i] == '\0') int_a = 0;
			if(b.digit[i] == '\0') int_b = 0;
			
			soma = int_a + int_b + vai_um;
			vai_um = 0;

			if(soma>9){
				soma = soma-10;
				vai_um = 1;
			}

			char_soma = int2char(soma);

			c.digit[i] = char_soma;

			}
		}
	
	imprime_bigint(c);
	return c;
	}

int main()
{
    printf("Problema 2\n");
	
	bigint a, b, c;
	
	a = init_bigint("123");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 1: %s\n", ( strcmp(c.digit, "644")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("123");
	b = init_bigint("123");   
	c = soma(a,b);
	printf("Teste 2: %s\n", ( strcmp(c.digit, "642")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 3: %s\n", ( strcmp(c.digit, "6483")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("48523");   
	c = soma(a,b);//52046
	printf("Teste 4: %s\n", ( strcmp(c.digit, "64025")==0 ) ?"OK\n":"FAIL\n");

    return 0;
}
