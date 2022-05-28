//Estrutura ABB
typedef struct Abb abb;
//Criar nó
abb *criarno(int chave);
//Função que insere chave na ABB
abb *insere(int chave, abb *a);
//Função libera ABB
void libera(abb *a);
//Função recursiva que conta os nós existentes de uma ABB
int contaNos(abb *a, int nivel);
//Função que retorna o ponteiro do maior elemento do ABB
abb *abbMax(abb * a);
//Função que procura e retorna o ponteiro da chave na árvore
abb *procura(int chave, abb *a);
//Função que retorna o ponteiro do antecessor da chave
abb *antecessor(int chave, abb *a);

