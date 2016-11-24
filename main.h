/**
 * @file   main.h
 * @Author Jonas, Hevid, Francisco
 * @date   March, 2016
 * @brief  Biblioteca para uso exclusivo da aplica��o. Cont�m todos os prot�tipos das fun��es do main.cpp
 */

 /// Inclus�es das bibliotecas necess�rias para todos os projetos
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>  
#include <stdlib.h>
#include <fstream>


/*
*Defini��o de vari�veis e seus valores que poder�o ser usadas em qualquer projetos que tenha esta biblioteca inclu�da
*Algo como "vari�veis globais"
*/
#define SIM  0
#define NAO  1
#define VERDADEIRO  1
#define FALSO  0
#define FRACASSO 0
#define SUCESSO 1

///Inclus�o dos namespaces
using namespace std; //para utiliazar cin e cout

///Enumera��o com tipo do im�vel
enum tiposImoveis {
	casa = 0,
	apartamento = 1
};

///Estrutura que ser� utilizada para grava��o e leitura dos dados dos programas
typedef struct Imoveis Imoveis;
struct Imoveis {
	long long int codImovel;
	tiposImoveis tipoImovel;
	string endereco;
	int nrQuartos;
	float precoAluguel;
	tm dataDisponibilidade;
};

///Defini��o dos prot�tipos das fun��es do main.cpp
void main();
void menu();
void converteMBemReg(long int &tamanhoMB, long int &numeroReg);
int geraArquivo(long int &quantBlocos, long int &tamUltBloco);
void divideBlocos(long int &numeroReg, long int &quantBlocos, long int &tamUltBloco);
void leArquivo();
void leArrquivoCompleto();



