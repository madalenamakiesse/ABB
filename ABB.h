//Estrutura ABB
typedef struct Abb abb;
//Criar n�
abb *criarno(int chave);
//Fun��o que insere chave na ABB
abb *insere(int chave, abb *a);
//Fun��o libera ABB
void libera(abb *a);
//Fun��o recursiva que conta os n�s existentes de uma ABB
int contaNos(abb *a, int nivel);
//Fun��o que retorna o ponteiro do maior elemento do ABB
abb *abbMax(abb * a);
//Fun��o que procura e retorna o ponteiro da chave na �rvore
abb *procura(int chave, abb *a);
//Fun��o que retorna o ponteiro do antecessor da chave
abb *antecessor(int chave, abb *a);

