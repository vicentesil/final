/* gcc main.c -g -I/usr/include/SDL2 -D_REENTRANT -Wall -pedantic -std=c99 -L/usr/lib/i386-linux-gnu -lm -lSDL2 -o main */
/* gcc -Wall -pedantic -ansi -std=c99 comboios.c -o comboios */
/*gcc -g -I/usr/include/SDL2 -D_REENTRANT -o programa main.c comboios.c */


/* 
  * 
  * 
  *   ________________________
  *  |                        |
  *  |   COMBOIOS  			  |
  *  |________________________|
  * 
  * Descricao: 
  * 
  *     Este programa simula o movimento de comboios, consoante um conjunto de parametros fornecidos pelo utilizador
  *     Permite ainda a visualizacao grafica e interativa dos comboio e das linhas
  *     Foi realizado no contexto da disciplina de Programacao do Mestrado Integrado de Engenharia Aeroespacial (MEAer)
  *     Instituto Superior Tecnico 2018/2019
  *
  * Autores:
  *     Guilherme Almeida 92
  *     Vicente Silvestre 92730
  * 
  * Docente responsavel:
  *     Bertinho Costa											
  * 															
  */ 															


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#include <SDL.h>
#include "comboios.h"

#define NL 100


int menu(int *inicio){         /*Funcao que apresenta as opcoes do menu inicial e retorna o valor escolhido pelo utilizador */

    int opcao, nconv;

    if(*inicio==1){
        printf("\n\n*   ________________________   *\n");
        printf("*  |                        |  *\n");
        printf("*  |        COMBOIOS        |  *\n");
        printf("*  |________________________|  *\n");
        printf("*                              *\n");
        *inicio=0;
    }
    printf("\nLista de opcoes:\n");
    printf("0 - Terminar o programa\n");
    printf("1 - Mostrar a informacao de uma ferrovia\n");
    printf("2 - Eliminar uma ferrovia\n");
    printf("3 - Mostrar  a informacao de um comboio\n");
    printf("4 - Eliminar um comboio\n");
    printf("5 - Criar um comboio\n");
    printf("6 - Simulacao dos comboios\n");
    printf("Selecione a opcao:");
    
    do{
        nconv = scanf("%d", &opcao);
    
        if (nconv == 0|| opcao < 0 || opcao > 6){
            printf("Erro: Escolha um valor entre 0 e 6\n\n");
            char ch;
            printf("Selecione a opcao:");
            do{
                ch=getchar();
            }while(ch!='\n');            
        }
    }while (nconv == 0|| opcao < 0 || opcao > 6);

    return opcao;
}


void leitura_config(char nome_ficheiro[NL], int dim_janela[2]){

    FILE *config;
    char carater;
    char nome_linha[20];
    char linha[NL];
    LISTA_LINHAS *topo;
    topo=NULL;			//=???
    PONTO NovoPonto;

    /*Abertura e teste do ficheiro*/
    config = fopen(nome_ficheiro, "r");
    if (config == NULL){
        fprintf(stdout, "Erro na abertura do ficheiro. \n");
        return;
    }

    /*Leitura do ficheiro*/
	while (fgets(linha, NL, config) !=NULL)
	{	
		sscanf(linha, "%c", &carater);
		if((carater!='%') && (carater!='\n') && (carater!= ' '))
		{
            sscanf(linha, "JANELA: %d %d",&dim_janela[0], &dim_janela[1]); //leitura da dim_janela
            
            if(sscanf(linha, "LINHA: %s", nome_linha)==1){
            	topo = adiciona_linha_lista(topo, nome_linha);
            }
            
           	if(sscanf(linha, "%s %d %d %s %s", NovoPonto.id, &(NovoPonto.coord[0]), &(NovoPonto.coord[1]), NovoPonto.cor, NovoPonto.tipo)==5){
//        		printf("SUCESSO: %s %d %d %s %s \n",  NovoPonto.id, NovoPonto.coord[0], NovoPonto.coord[1], NovoPonto.cor, NovoPonto.tipo);
            	topo = adiciona_ponto_lista(topo, NovoPonto);
        	}

    	}
    }
    mostra_linhas(topo);
    fclose(config);
}


int main(int argc, char *argv[])
{
	char nome_ficheiro[100];
//	int inicio=1;
//	int opcao;
	int dim_janela[2];

	if(argc!=2){
		printf("Parametros incorretos\n");
		printf("Tente '> sim_linhas ficheiro.txt\n");
		return 0;
	}	

	strcpy(nome_ficheiro, argv[1]);
	leitura_config(nome_ficheiro, dim_janela);
/*
	do
	{
    	opcao=menu(&inicio);
    	if(opcao==1){

    	}
    	if(opcao==2){

        }

        if(opcao==3){

        }
	}while(opcao != 0);*/
    return 0;
}
