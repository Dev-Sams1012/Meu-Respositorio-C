# Projeto de Programação em C – Semestre 2024.2

Este repositório reúne todos os meus arquivos em **C** da disciplina de Programação (2º semestre de 2024). Eles estão organizados por módulos/pastas, seguindo o conteúdo lecionado ao longo do semestre.

---

## 📁 Atividades da Disciplina de Programação (2024.2)

Aqui estão os links para as pastas contendo os arquivos em C, organizados por atividade:

## [📘 Lógica e Sintaxe básica em C](./Ativ%201%20-%20Prog/)

Esta atividade contém a implementação de diversos algoritmos em C com foco em lógica de programação, manipulação de vetores e strings, e busca eficiente. A seguir, um resumo dos problemas resolvidos:

- **Problema 1:** Determina o maior número menor que a média dos elementos de um vetor.
- **Problema 2:** Verifica se os números ímpares de um vetor aparecem em ordem crescente.
- **Problema 3:** Remove caracteres duplicados consecutivos de uma string.
- **Problema 4a:** Conta o número de ocorrências de um valor `k` em um vetor ordenado usando busca linear otimizada.
- **Problema 4b:** Realiza a mesma contagem usando uma abordagem mais eficiente baseada em Jump Search.
- **Problema 5:** Encontra o pico (maior valor) em uma sequência bitônica usando busca binária.


## [📘 Implementação de BigInt em C](./Ativ%202%20-%20Prog/)

Esta atividade contém a implementação de diversas operações com **Big Integers (BigInt)** em C, manipulando grandes números inteiros armazenados como strings. O foco principal é a implementação de funções básicas de operações aritméticas e manipulação de números grandes.

### Problemas Resolvidos

- **Problema 1:** Implementa a comparação de dois números grandes, retornando se o primeiro número é maior, menor ou igual ao segundo.
- **Problema 2:** Realiza a soma de dois números grandes, incluindo o tratamento de transbordos de dígitos.
- **Problema 3:** Implementa a operação de deslocamento (shift) dos dígitos de um número grande para a esquerda ou direita.
- **Problema 4:** Implementa uma soma de BigInt com um comportamento especial de transbordo, ajustando a soma conforme necessário.


## [📘 Implementação de Funções Recursivas e Iterativas](./Ativ%203%20-%20Prog/)

Esta atividade contém funções recursivas e iterativas em **C** para manipulação de strings e a criação de figuras geométricas. Veja um resumo das funções implementadas:

### Funções Implementadas

- **Triângulo**: Cria um triângulo de asteriscos com altura `n`. Testes são realizados comparando as versões recursiva e iterativa.
  
- **Retângulo**: Gera um retângulo de dimensões `n` x `m` utilizando versões recursiva e iterativa.

- **Letra "V"**: Desenha a letra "V" com altura `n`. Testes garantem a equivalência entre as abordagens recursiva e iterativa.

- **Bandeira**: Desenha uma bandeira com `n` linhas, tanto de forma recursiva quanto iterativa.

- **Verificação de Ordenação**: Verifica se um vetor está ordenado utilizando versões recursiva e iterativa.

- **Inversão de String**: Inverte uma string, comparando as versões recursiva e iterativa.


## [📘 Manipulação de Lista Encadeada](./Ativ%204%20-%20Prog/)

Esta atividade contém a implementação de diversos algoritmos em C com foco em manipulação de listas encadeadas, recursão e operações relacionadas. A seguir, um resumo dos problemas resolvidos:

- **Problema 1:** Conta o número de elementos em uma lista encadeada menores que um valor `k`.
- **Problema 2:** Remove todos os elementos de uma lista encadeada menores que um valor `k`.
- **Problema 3:** Conta o número de inversões em uma lista encadeada (pares de elementos consecutivos em ordem decrescente).
- **Problema 4:** Troca pares consecutivos de elementos em uma lista encadeada.
- **Problema 5:** Duplica cada nó em uma lista encadeada.
- **Problema 6:** Realiza a fusão de duas listas encadeadas ordenadas em uma lista ordenada.
  
  ## [📘 Notação Polonesa Reversa](./Ativ%205%20-%20Prog/)

Esta atividade contém a implementação de algoritmos para a conversão de expressões matemáticas para Notação Polonesa Reversa (RPN) e avaliação dessas expressões. O foco está no uso de pilhas e na manipulação de listas de tokens. A seguir, um resumo dos problemas resolvidos:

- **Problema 1:** Converte uma expressão infixa (usando parênteses e operadores) para a Notação Polonesa Reversa.
- **Problema 2:** Avalia uma expressão em Notação Polonesa Reversa usando uma pilha.
  

## [📘 Árvore Binária de Busca (BST)](./Ativ%206%20-%20Prog/)

Esta atividade implementa operações em uma Árvore Binária de Busca (BST), incluindo inserção, remoção, busca e verificação de propriedades da árvore. A seguir, um resumo dos problemas resolvidos:

- **Problema 1:** Raliza a busca de um valor `k` em uma árvore binária de busca, retornando 1 se o valor for encontrado, e 0 caso contrário.
- **Problema 2:** Verifica se uma árvore binária segue as regras de uma árvore binária de busca (BST), onde o valor de cada nó à esquerda é menor e à direita é maior que o valor do nó raiz.
- **Problema 3:** Insere um novo valor em uma árvore binária de busca. A árvore é reorganizada automaticamente para manter a propriedade da BST.
- **Problema 4:** Retorna o menor valor em uma árvore binária de busca, que é o nó mais à esquerda da árvore.
- **Problema 5:** Remove o nó com o menor valor da árvore e retorna a árvore atualizada.
- **Problema 6:** Encontra o sucessor de um valor na árvore, ou seja, o menor valor maior que o valor dado.
- **Problema 7:** Conta quantos valores da árvore estão dentro de um intervalo dado `[N, M]`.


## [📘 Árvore Binária de Busca (BST) - Altura e Folhas](./Ativ%207%20-%20Prog/)

Esta atividade implementa operações em uma Árvore Binária de Busca (BST), incluindo o cálculo da altura e o número de folhas. A seguir, um resumo dos problemas resolvidos:

- **Problema 1:** Calcula a altura de cada nó da árvore e preenche o campo `altura` de cada nó com o valor correspondente. A função `checa_altura_arvore` valida se a altura dos nós foi corretamente preenchida.

- **Problema 2:** Calcula o número de folhas de cada nó da árvore e preenche o campo `num_folhas` de cada nó com o valor correspondente. A função `checa_folhas_arvore` valida se o número de folhas dos nós foi corretamente preenchido.
