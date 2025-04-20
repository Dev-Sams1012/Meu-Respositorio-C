#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"


int conta_menores(Node * head, int k){

	if(head == NULL) return 0;
	else{
		if(head->val < k) return 1 + (conta_menores(head->prox,k));
		else return 0 + (conta_menores(head->prox,k));
	}
}

Node * remove_menores(Node * head, int k){
	if(head == NULL) return NULL;
	else{
		if(head->val < k){
			Node *temp = remove_menores(head->prox, k);
			free(head);
			return temp;
		}
		else{
			head->prox = remove_menores(head->prox, k);
			return head;
		}
	}

	return NULL;
}

int conta_inversao(Node * head){
	if(head->prox == NULL) return 0;
	else{
		if(head->val > head->prox->val) return 1 + conta_inversao(head->prox);
		else return 0 + conta_inversao(head->prox);
	}

}

Node * troca_pares_consecutivos(Node * head){
	if( head == NULL || head->prox == NULL) return head;
	else{

		int temp = head->val;
		head->val = head->prox->val;
		head->prox->val = temp;

		troca_pares_consecutivos(head->prox->prox);
	}
	return head;
}

Node * duplicar_nodes(Node * head){
	if(head == NULL) return head;
	else{
		Node* new = (Node*) malloc(sizeof(Node));

		new->val = head->val;
		new->prox = head->prox;
		head->prox = new;
		
		duplicar_nodes(new->prox);

	}

	return head;
}

Node * merge(Node * cabeca1, Node * cabeca2){
	if(cabeca1 == NULL && cabeca2 == NULL) return NULL;
	else if(cabeca1 != NULL && cabeca2 == NULL) return cabeca1;
	else if(cabeca1 == NULL && cabeca2 != NULL) return cabeca2;

	Node* cabeca_merge = NULL;
	if(cabeca1->val <= cabeca2->val){
		cabeca_merge = cabeca1;
		cabeca1 = cabeca1->prox;
	}else{
		cabeca_merge = cabeca2;
		cabeca2 = cabeca2->prox;
	}

	Node* atual = cabeca_merge;
	while(cabeca1 != NULL && cabeca2 != NULL){
		if(cabeca1->val <= cabeca2->val){
			atual->prox = cabeca1;
			cabeca1 = cabeca1->prox;
		}else{
			atual->prox = cabeca2;
			cabeca2 = cabeca2->prox;
		}
		atual = atual->prox;
	}

	if(cabeca1 == NULL) atual->prox = cabeca2;
	else if(cabeca2 == NULL) atual->prox = cabeca1;

	return cabeca_merge;
}

void problema1(){
	printf("Problema 1\n");
	int v1[] = {2,4,7,8,3,2,1};
	int n = sizeof(v1)/sizeof(int);
	Node * head = criar_lista_vetor(v1, n);
	int res;
	
	res = conta_menores(head, 3);
	if(res == 3) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
	
	res = conta_menores(head, 5);
	if(res == 5) printf("Teste 2: OK\n");
	else printf("Teste 2: FAIL\n");
}

void problema2(){
	printf("Problema 2\n");
	int v1[] = {2,4,7,8,3,2,1};
	int n1 = sizeof(v1)/sizeof(int);
	Node * head1 = criar_lista_vetor(v1, n1);
	mostra_lista("head1 ", head1);
	head1 = remove_menores(head1, 3);
	mostra_lista("head1 apos remocao ", head1);
	
	int v2[] = {4,7,8,3};
	int n2 = sizeof(v2)/sizeof(int);
	Node * head2 = criar_lista_vetor(v2, n2);
	mostra_lista("head2 ", head2);
	
	if(iguais(head1, head2) ) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
	
	
}

void problema3(){
	printf("Problema 3\n");
	int v1[] = {2,4,7,8,3,2,1};
	int n = sizeof(v1)/sizeof(int);
	Node * head1 = criar_lista_vetor(v1, n);
	mostra_lista("head1 ", head1);
	int res = conta_inversao(head1);
	if(res == 3) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
	
}

void problema4(){
	printf("Problema 4\n");
	int v1[] = {2,4,7,8,3,2,1,4};
	int n1 = sizeof(v1)/sizeof(int);
	Node * head1 = criar_lista_vetor(v1, n1);
	mostra_lista("head1 ", head1);
	head1 = troca_pares_consecutivos(head1);
	mostra_lista("head1 apos troca ", head1);
	
	int v2[] = {4,2,8,7,2,3,4,1};
	int n2 = sizeof(v1)/sizeof(int);
	Node * head2 = criar_lista_vetor(v2, n2);
	
	if(iguais(head1, head2) ) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
	
	
}

void problema5(){
	printf("Problema 5\n");
	int v1[] = {1,5,7,9,10};
	int n1 = sizeof(v1)/sizeof(int);
	Node * head1 = criar_lista_vetor(v1, n1);
	mostra_lista("head1 ", head1);
	
	int v2[] = {1,1,5,5,7,7,9,9,10,10};
	int n2 = sizeof(v2)/sizeof(int);
	Node * head2 = criar_lista_vetor(v2, n2);
	mostra_lista("head2 ", head2);
	
	Node * head3 = duplicar_nodes(head1);
	
	if(iguais(head2, head3) ) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
}

void problema6(){
	printf("Problema 6\n");
	int v1[] = {1,5,7,9,10};
	int n1 = sizeof(v1)/sizeof(int);
	Node * head1 = criar_lista_vetor(v1, n1);
	mostra_lista("head1 ", head1);
	
	int v2[] = {2,3,8,11,13};
	int n2 = sizeof(v2)/sizeof(int);
	Node * head2 = criar_lista_vetor(v2, n2);
	mostra_lista("head2 ", head2);
	
	
	int v3[] = {1,2,3,5,7,8,9,10,11,13};
	int n3 = sizeof(v3)/sizeof(int);
	Node * head3 = criar_lista_vetor(v3, n3);
	
	Node * head4 = merge(head1, head2);
	mostra_lista("head4 ", head4);
	
	if(iguais(head3, head4) ) printf("Teste 1: OK\n");
	else printf("Teste 1: FAIL\n");
	
	
}

void teste_ordena(){
	Node * head = criar_lista_aleatoria(10);
	mostra_lista("head = ", head);
	head = ordena_lista(head);
	mostra_lista("head = ", head);
}

int main(){
	//inicializa a semente de numeros aleatorios
	srand(time(NULL));
	
	problema1();
	problema2();
	problema3();
	problema4();
	problema5();
	problema6();
	teste_ordena();
}	
