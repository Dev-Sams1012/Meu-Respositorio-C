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

bigint incremento(bigint b){
	bigint c = b;
	
	for(int i = 0; i < c.size; i++){
		if( c.digit[i] < '9'){
			c.digit[i]++;
			return c;
		}else{
			c.digit[i] = '0';
		}
	}
	c.digit[c.size] = '1';
	c.size++;
	return c;
}


void imprime_bigint(bigint b){
	printf("bigint: ");
	for(int i = b.size-1; i >= 0; i--)
		printf("%c", b.digit[i]);
	printf("\n");
}

int maior(bigint a, bigint b){
	
	if(a.size > b.size ) return -1;
	
	if(a.size < b.size ) return 1;
	
	for(int i = a.size-1; i >= 0; i--){
		if(a.digit[i] > b.digit[i]) return -1;
		if(a.digit[i] < b.digit[i]) return 1;
	}
	
	return 0;
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
	
	c.digit[tamanho] = '\0';
	imprime_bigint(c);
	return c;
	}



int modulo(int n){
	if(n>=0) return n;
	else return -n;
}

bigint shift(bigint a, int n){
	bigint c = init_bigint("");
	int i, abs;
	abs = modulo(n);

	
	if(a.size < abs ){
		c.size = 1;
		c.digit[0] = '0';
		imprime_bigint(c);
		return c;
	}

	c.size = a.size + n;

	if(n>0){

		for(i=0;i<n;i++){
			c.digit[i] = '0';
		}

		for(i=n;i<c.size;i++){
			c.digit[i] = a.digit[i-n];
		}

		c.digit[i] = '\0';

	}

	else if(n<0){
		for(i=0;i<c.size;i++){
			c.digit[i] = a.digit[i+abs];
		}
	} 

	imprime_bigint(c);
	return c;
}

bigint soma_boquinha(bigint a, bigint b){

	bigint c = init_bigint("");
	int i = 0;
	int tamanho, tamanho_c, int_a, int_b, soma, aux;
	char char_soma;
	int estouro = 0;

	// Aqui verificaremos o tamanho do maior dos dois termos:
	if(a.size > b.size) tamanho = a.size;
	else tamanho = b.size;
    tamanho_c = tamanho;

	// Aqui será o procedimento da soma:
	for(i=0;i<tamanho+1;i++){
        if(a.digit[i] =='\0' && b.digit[i] == '\0'){
            if(estouro == 0){
                c.digit[i] = '\0';
			    break;
            }
            else{
            c.digit[i] = int2char(estouro);
            estouro = 0;
            tamanho_c++;
            }
        }

		else{
			int_a = char2int(a.digit[i]);
			int_b = char2int(b.digit[i]);

			if(a.digit[i] == '\0') int_a = 0;
			if(b.digit[i] == '\0') int_b = 0;

			soma = int_a + int_b + estouro;

			estouro = 0;

			if(soma>9){
                estouro = soma%10;
                soma = soma/10;
                if(soma > estouro){
                    aux = soma;
                    soma = estouro;
                    estouro = aux;
                }
				}

			char_soma = int2char(soma);

			c.digit[i] = char_soma;
        

			}
	    }

    c.digit[tamanho_c] = '\0';

    c.size = tamanho_c;

    imprime_bigint(c);
	return c;
}  


void problema1(){
	printf("Problema 1\n\n");
	
	bigint a, b;
	
	a = init_bigint("123");
	b = init_bigint("323");   
	printf("Teste 1: %s\n", (maior(a,b) == 1) ?"OK":"FAIL");
	
	a = init_bigint("123");
	b = init_bigint("123");   
	printf("Teste 2: %s\n", (maior(a,b) == 0) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("323");   
	printf("Teste 3: %s\n", (maior(a,b) == -1) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("45523");   
	printf("Teste 3: %s\n\n", (maior(a,b) == 1) ?"OK\n":"FAIL\n");
	
}


void problema2(){
	printf("Problema 2\n\n");
	
	bigint a, b, c;
	
	a = init_bigint("123");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 1: %s\n\n", ( strcmp(c.digit, "644")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("123");
	b = init_bigint("123");   
	c = soma(a,b);
	printf("Teste 2: %s\n\n", ( strcmp(c.digit, "642")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 3: %s\n\n", ( strcmp(c.digit, "6483")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("48523");   
	c = soma(a,b);//52046
	printf("Teste 4: %s\n\n", ( strcmp(c.digit, "64025")==0 ) ?"OK\n":"FAIL\n");
	
}


void problema3(){
	printf("Problema 3\n\n");
	
	bigint a;
	a = init_bigint("123");
	a = shift(a,3);   
	printf("Teste 1: %s\n\n", ( strcmp(a.digit, "000321")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("8567");
	a = shift(a,-2);   
	printf("Teste 2: %s\n\n", ( strcmp(a.digit, "58")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("8567");
	a = shift(a,-5);   
	printf("Teste 3: %s\n\n", ( strcmp(a.digit, "0")==0 ) ?"OK\n":"FAIL");
	

}

void problema4(){
	printf("Problema 4\n\n");
	bigint a, b, c, d;
	a = init_bigint("6");
	b = init_bigint("9");
	c = init_bigint("51");
	d = soma_boquinha(a,b); // 51
	printf("Teste 1: %s\n\n", ( strcmp(c.digit, d.digit )==0 ) ?"OK":"FAIL");

	a = init_bigint("734");
	b = init_bigint("812");
	c = init_bigint("5146");
	d = soma_boquinha(a,b); // 5146
	printf("Teste 2: %s\n\n", ( strcmp(c.digit, d.digit )==0 ) ?"OK":"FAIL");

	a = init_bigint("999");
	b = init_bigint("999");
	c = init_bigint("4221");
	d = soma_boquinha(a,b);
	printf("Teste 3: %s\n\n", ( strcmp(c.digit, d.digit) ==0 ) ?"OK":"FAIL");

	a = init_bigint("3523");
	b = init_bigint("48523");
	c = init_bigint("61046");
	d = soma_boquinha(a,b);
	printf("Teste 4: %s\n\n", ( strcmp(c.digit, d.digit)==0 ) ?"OK":"FAIL");
}

int main(){
	
	problema1();
	problema2();
	problema3();
	problema4();
}
