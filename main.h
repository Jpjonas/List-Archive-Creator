/**
 * @file   main.h
 * @Author Jonas, Hevid, Francisco
 * @date   March, 2016
 * @brief  Biblioteca para uso exclusivo da aplicação. Contém todos os protótipos das funções do main.cpp
 */

 /// Inclusões das bibliotecas necessárias para todos os projetos
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>  
#include <stdlib.h>
#include <fstream>


/*
*Definição de variáveis e seus valores que poderão ser usadas em qualquer projetos que tenha esta biblioteca incluída
*Algo como "variáveis globais"
*/
#define SIM  0
#define NAO  1
#define VERDADEIRO  1
#define FALSO  0
#define FRACASSO 0
#define SUCESSO 1

///Inclusão dos namespaces
using namespace std; //para utiliazar cin e cout

///Enumeração com tipo do imóvel
enum tiposImoveis {
	casa = 0,
	apartamento = 1
};

///Estrutura que será utilizada para gravação e leitura dos dados dos programas
typedef struct Imoveis Imoveis;
struct Imoveis {
	long long int codImovel;
	tiposImoveis tipoImovel;
	string endereco;
	int nrQuartos;
	float precoAluguel;
	tm dataDisponibilidade;
};

///Definição dos protótipos das funções do main.cpp
void main();
void menu();
void converteMBemReg(long int &tamanhoMB, long int &numeroReg);
int geraArquivo(long int &quantBlocos, long int &tamUltBloco);
void divideBlocos(long int &numeroReg, long int &quantBlocos, long int &tamUltBloco);
void leArquivo();
void leArrquivoCompleto();



