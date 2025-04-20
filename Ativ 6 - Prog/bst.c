#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node_tree{
	int val;
	struct node_tree * esq;
	struct node_tree * dir;
} node_tree;


node_tree * criar_no(int valor){
	node_tree * no = malloc( sizeof(node_tree) );
	no->val = valor;
	no->esq = NULL;
	no->dir = NULL;
	return no;
}

/*
     13
   /    \
  5     20
 / \   /  \
2   6 15  31
*/


node_tree * arvore1(){
	node_tree * n1 = criar_no(13);
	node_tree * n2 = criar_no(5);
	node_tree * n3 = criar_no(2);
	node_tree * n4 = criar_no(6);
	node_tree * n5 = criar_no(20);
	node_tree * n6 = criar_no(15);
	node_tree * n7 = criar_no(31);
	n1->esq = n2;
	n1->dir = n5;
	n2->esq = n3;
	n2->dir = n4;
	n5->esq = n6;
	n5->dir = n7;
	return n1;
}


/*
       10
      /  \
     5    15
    / \
   2   12 
*/
node_tree * arvore2(){
	node_tree * n1 = criar_no(10);
	node_tree * n2 = criar_no(5);
	node_tree * n3 = criar_no(2);
	node_tree * n4 = criar_no(12);
	node_tree * n5 = criar_no(15);
	n1->esq = n2;
	n1->dir = n5;
	n2->esq = n3;
	n2->dir = n4;
	return n1;
}


int busca(node_tree * p, int k){
	if(p==NULL)	return 0;
	else{
		node_tree * q = p;
		while( q != NULL){
			if(k == q->val){
				return 1;
			}else if(k < q->val){
				q = q->esq;
			}else{
				q = q->dir;
			}
		}
		return 0;
	}
}

void problema_busca(){
	printf("Problema 1: Busca BST\n");
	node_tree * n1 = arvore1();
	
	printf("Teste 1 : ");
	if( busca(n1, 5) == 1) printf("OK\n");
	else printf("FAIL\n");
	
	printf("Teste 2 : ");
	if( busca(n1, 7) == 0) printf("OK\n");
	else printf("FAIL\n");
	
	printf("Teste 3 : ");
	if( busca(n1, 15) == 1) printf("OK\n");
	else printf("FAIL\n");
	
	printf("Teste 4 : ");
	if( busca(n1, 5) == 1) printf("OK\n");
	else printf("FAIL\n");
	
}

node_tree * insere(node_tree * p, int k){
	
	if(p == NULL){
		return	criar_no(k);
	}else{
		node_tree * q1 = p; //no atual
		node_tree * q2 = NULL; // pai do no atual
		
		//1 Etapa: Descida na arvore
		
		while( q1 != NULL){
			q2 = q1;
			if( k < q1->val ){
				q1 = q1->esq; 
			}else{
				q1 = q1->dir;
			}}

		if( k < q2->val ){
			q2->esq = criar_no(k);
		}else{
			q2->dir = criar_no(k);
		}
	}
	
	return p;
}

#define STACKSIZE 100

typedef struct {
	node_tree * no;
	int min, max;
} stack_node;

	
int checaBST(node_tree * p){
	
	stack_node pilha[STACKSIZE];
	int topo;

	
	
	topo = -1;
	pilha[++topo] = (stack_node){p, INT_MIN, INT_MAX};
	
	while( topo >= 0){
		stack_node atual = pilha[topo--];
		
		printf("(valor, min, max) = (%d, %d, %d)\n", atual.no->val, atual.min, atual.max);
		
		if( atual.no->val <= atual.min || atual.no->val >= atual.max )
			return 0;
		
		if( atual.no->dir != NULL ) 
			pilha[++topo] = (stack_node){atual.no->dir, atual.no->val, atual.max};
		
		
		if( atual.no->esq != NULL ){ 
			pilha[++topo] = (stack_node){ atual.no->esq, atual.min, atual.no->val};
		}
	}
	
	return 1;

}

void problema_checaBST(){
	printf("Problema 2: Checar BST\n");
	int res;
	node_tree * n1 = arvore1();
	res = checaBST(n1);
	printf("Teste 1 : ");
	if( res == 1 ) printf("OK\n");
	else printf("FAIL\n");
	node_tree * n2 = arvore2();
	res = checaBST(n2);
	printf("Teste 2 : ");
	if( res == 0 ) printf("OK\n");
	else printf("FAIL\n");
}

void problema_insereBST(){
	printf("Problema 3: Insere BST\n");
	int res;
	
	node_tree * n1 = arvore1();
	n1 = insere(n1, 7);
	
	res = checaBST(n1) && busca(n1, 7);
	printf("Teste 1: ");
	if( res == 1) printf("OK\n");
	else printf("FAIL\n");
	
	n1 = insere(n1, 23);
	res = checaBST(n1) && busca(n1, 7);
	printf("Teste 2: ");
	if( res == 1) printf("OK\n");
	else printf("FAIL\n");
}


int pega_menor(node_tree * p){
	node_tree *atual = p;

	while(atual->esq != NULL){
		atual = atual->esq;
	}

	return atual->val;
}

node_tree * remove_menor(node_tree * p){
	node_tree *menor = p;
	node_tree *pai_menor = NULL;

	while(menor->esq != NULL){
		pai_menor = menor;
		menor = menor->esq;
	}

	if(pai_menor == NULL) return menor->dir;

	if(menor->dir == NULL){
		pai_menor->esq = NULL;
	}else{
		pai_menor->esq = menor->dir;
	}

	return p;
}

void percurso_inorder(node_tree * p){	
	node_tree * atual = p;
	node_tree * pilha[STACKSIZE];
	int topo = -1;
	while( topo >= 0 || atual != NULL){
		while(atual != NULL){
			pilha[++topo] = atual;
			atual = atual->esq;
		}
		atual = pilha[topo--];
		printf("%d\n", atual->val);		
		atual = atual->dir;
	}

}


int sucessor(node_tree * p, int k){
	node_tree * atual = p;
	node_tree * sucessor = NULL;
	while(atual != NULL){
		if(k < atual->val){
			sucessor = atual;
			atual = atual->esq;
		}else{
			atual = atual->dir;
		}
	}
	return sucessor->val;
}


int range(node_tree * p, int N, int M){
	
	if(p == NULL) return 0;

	int cont = 0;


	if(p->val >= N && p->val <= M) cont = 1;
	cont += range(p->esq,N,M);

	cont += range(p->dir,N,M);
	return cont;
}



void problema1(){
	printf("Problema 1: pega menor\n");
	node_tree * n1 = arvore1();
	int res;
	
	res = pega_menor(n1);
	printf("Teste 1: ");
	if( res == 2) printf("OK\n");
	else printf("FAIL\n");
	
	n1 = insere(n1, 7);
	res = pega_menor(n1);
	printf("Teste 2: ");
	if( res == 2) printf("OK\n");
	else printf("FAIL\n");
	
	n1 = insere(n1, 1);
	res = pega_menor(n1);
	printf("Teste 2: ");
	if( res == 1) printf("OK\n");
	else printf("FAIL\n");
	
	

}

void problema2(){
	printf("Problema 2: Remove Menor\n");
	
	node_tree * n1 = arvore1();
	int res;
	
	int v[] = {2,5,6,13,15,20,31};
	int n = sizeof(v)/sizeof(int);
	
	for(int i = 1; i < n; i++){
		n1 = remove_menor(n1);
		res = pega_menor(n1);
		printf("Teste %d:", i);
		if(res == v[i]) printf("OK\n");
		else printf("FAIL\n");
	}
}

void problema3(){
	printf("Problema 3: Sucessor\n");
	
	node_tree * n1 = arvore1();
	int res;
	
	int v[] = {2,5,6,13,15,20,31};
	int n = sizeof(v)/sizeof(int);
	
	for(int i = 0; i < n-1; i++){
		res = sucessor(n1, v[i]);
		printf("Teste %d:", i+1);
		if(res == v[i+1]) printf("OK\n");
		else printf("FAIL\n");
	}
}

typedef struct{
int x, y;
} pair;

void problema4(){
	printf("Problema 4: Range\n");
	
	node_tree * n1 = arvore1();
	int res;
	
	pair pares[] = { {6,20},{2,10} ,{6,18},{5,25} ,{1,18}};
	int sol[] = { 4 , 3 , 3, 5,5};
	int n = sizeof(pares)/sizeof(pair);
	
	
	for(int i = 0; i < n; i++){
		res = range(n1, pares[i].x, pares[i].y);
		
		printf("Teste %d:", i+1);
		if(res == sol[i]) printf("OK\n");
		else printf("FAIL\n");
	}
}



int main(){
	//problema_busca();
	//problema_insereBST();
	//problema_checaBST();
	
	problema1();
	problema2();
	problema3();
	problema4();
	
}
	
