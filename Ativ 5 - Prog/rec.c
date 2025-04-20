#include "pilha.h"

int f(int n){
	if(n == 1) return 1;
	else {
		return 2*f(n-1) + 3;
	}
}

int f_pilha(int n){
	Pilha chamada;
	Pilha operandos;
	Pilha operadores;
	inicializar_pilha(&chamada);
	inicializar_pilha(&operandos);
	inicializar_pilha(&operadores);
	push(&chamada, n);

	while( !is_empty(&chamada) ){
		int n = pop(&chamada);
		if(n == 1){
			push(&operandos, 1);
		}else{
			push(&operandos, 3);
			push(&operandos, 2);
			push(&operadores, '+');
			push(&operadores, '*');
			push(&chamada, n-1);
		}

		mostra_pilha(&operandos);
		mostra_pilha_char(&operadores); 
	}

	while( !is_empty(&operadores) ){
		int op = pop(&operadores);
		int op2 = pop(&operandos);
		int op1 = pop(&operandos);
		
		if(op == '+'){
			push(&operandos, op1+op2);
		}else{
			push(&operandos, op1*op2);
		}
	}

	return pop(&operandos);


}

int g(int n){
	if(n == 1) return 1;
	else {
		return g(n-1) + (n%101);
	}
}



int main(){
	printf("%d\n", f(4) );

	printf("%d\n", f_pilha(4) );

}


