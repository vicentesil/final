#include "comboios.h"

LISTA_LINHAS* adiciona_linha_lista(LISTA_LINHAS *topo, char nome_linha[20]){
	LISTA_LINHAS *NovoBloco;
	LISTA_LINHAS *linha_anterior;
	LISTA_LINHAS *linha_atual;
	/* Aloca memoria */
 	NovoBloco = (LISTA_LINHAS*) calloc(1, sizeof(LISTA_LINHAS));
 	if (NovoBloco == NULL) {
 		printf("Falta de memoria durante o processo de adicionar linha a lista\n");
 		exit(0);
 	}

	strcpy(NovoBloco->nome_linha,nome_linha);
//	NovoBloco->linha=(LINHA*) NULL;
	NovoBloco->prox = NULL;

	//if(NULL)
	linha_anterior=NULL;			//encontra a ultima linha na lista de linhas, que e o TOPOLINHA que e usada para adicionar novos pontos
	linha_atual=topo;
	while(linha_atual!=NULL){
		linha_anterior=linha_atual;
		linha_atual=linha_atual->prox;}
	linha_anterior->prox=NovoBloco;

	return topo;
}

void mostra_linhas(LISTA_LINHAS *topo){
	LISTA_LINHAS *lista=topo;
	LINHA *linha;
	PONTO *ponto;
	//IF(NULL / 1 LINHA)
	while(lista->prox!=NULL){
		printf("Nome da linha: %s\n", lista->nome_linha);
		linha=&(lista->linha);
		while(linha->prox!=NULL){
			ponto=&(linha->ponto);
			printf("Ponto: %s %d %d %s %s \n",  ponto->id, ponto->coord[0], ponto->coord[1], ponto->cor, ponto->tipo);
			linha=linha->prox;
		lista=lista->prox;}
	}
}

LISTA_LINHAS* adiciona_ponto_lista(LISTA_LINHAS *topo, PONTO NovoPonto){

	LISTA_LINHAS *linha_anterior, *linha_atual;


	LINHA *NovoBloco; //novo ponto, a adicionar

	LINHA *Topo_Linha;  //topo linha
	LINHA *ponto_anterior, *ponto_atual; //encontrar ponto de insercao na linha
 	/* Aloca memoria */
 	NovoBloco = (LINHA*) calloc(1, sizeof(LINHA));
 
 	if (NovoBloco == NULL) {
 		printf("Falta de memoria durante o processo de adicionar ponto a linha\n");
 		exit(0);
 }


	linha_anterior=NULL;			//encontra a ultima linha na lista de linhas, que e o TOPOLINHA que e usada para adicionar novos pontos
	linha_atual=topo;
	while(linha_atual!=NULL){
		linha_anterior=linha_atual;
		linha_atual=linha_atual->prox;}

	Topo_Linha = &(linha_anterior->linha);



	NovoBloco->ponto = NovoPonto; /* preenche os campos de dados */
	NovoBloco->prox = NULL;

	if (Topo_Linha == NULL) {
		Topo_Linha=NovoBloco; /* A lista esta vazia */
		return topo;
	}

	ponto_anterior=NULL;
	ponto_atual=Topo_Linha;
	while(ponto_atual!=NULL){
		ponto_anterior=ponto_atual;
		ponto_atual=ponto_atual->prox;}

	ponto_anterior->prox = NovoBloco;
	return topo;
}


