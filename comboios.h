#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[4];
	int coord[2];
	char cor[10];  //ver se nao e int
	char tipo[3];
	int dim;
	int vias_in;
	int vias_out;
}PONTO;

typedef struct linha {
	PONTO ponto;
	struct linha *prox; //DOIS PROXS
}LINHA;

typedef struct{
	char id[2];
	int dim_comboio;
	int dim_bolas;
	char cor[10];  //int?
	PONTO pos_inicial;  //vetor PONTO + LINHA?
	PONTO pos_final;
}COMBOIO;

typedef struct lista_linhas{
	char nome_linha[20];   //defines
	LINHA linha;
	struct lista_linhas *prox;
}LISTA_LINHAS;

LISTA_LINHAS* adiciona_linha_lista(LISTA_LINHAS *topo, char nome_linha[20]);
LISTA_LINHAS* adiciona_ponto_lista(LISTA_LINHAS *topo, PONTO NovoPonto);

void mostra_linhas(LISTA_LINHAS *topo);