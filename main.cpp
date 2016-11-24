/**
 * @file   main.cpp
 * @Author Jonas, Hevid, Francisco
 * @date   March, 2016
 * @brief  Arquivo principal da aplica��o. Cont�m todas as fun��es que ir� fazer o programa funcionar
 */

#include "stdafx.h"
///inclus�o da biblioteca de recursos (main.h)
#include "main.h"
	
	///Fun�ao principal, a execu��o do programa come�a por aqui.
	void main()
	{
		///Chamada do menu principal.
		menu();
		///pausa no final da execu��o aguardando um comando.
		system("PAUSE");
	}

	///funcao responsavel por gerar o arquivo.
	int geraArquivo(long int &quantBlocos, long int &tamUltBloco)
	{
		FILE *arquivo;
		Imoveis arrayImoveis[10000];
		int y = 0, x = 0;
		long int auxiliar = 10000;
		if ((arquivo = fopen("Imoveis.bin", "w+b")) == NULL)
		{
			cout << "\nErro ao criar arquivo.\n";
			return FRACASSO;
		}
		else
		{
			for (y = 0; y < quantBlocos; y++)
			{
				system("CLS");
				cout << "Progresso: ";
				cout << y*100/quantBlocos;
				cout << "%\n";	
				if (y == quantBlocos - 1)
				{
					auxiliar = tamUltBloco;
				}
				for (x = 0; x < auxiliar; x++)
				{
					arrayImoveis[x].endereco = "lalala";
					arrayImoveis[x].nrQuartos = 3;
					arrayImoveis[x].precoAluguel = 123;
					arrayImoveis[x].tipoImovel = casa;
				}
				fwrite(&arrayImoveis, sizeof(Imoveis), auxiliar, arquivo);
			}
		}
		fclose(arquivo);
		return SUCESSO;
	}

	///fun��o que retorna o numero de bloco que ser�o gerados e os registros sobrando
	void divideBlocos(long int &numeroReg, long int &quantBlocos,long int &tamUltBloco)
	{
		quantBlocos = numeroReg / 10000;
		tamUltBloco = numeroReg % 10000;
	}

	///fun�ao que converte quantidade informada em MB para numero de registros
	void converteMBemReg(long int &tamanhoMB, long int &numeroReg)
	{
		numeroReg = tamanhoMB / 0.000076;
	}

	///funcao que le quantidade especifica de registros
	void leArquivo()
	{
		FILE *arquivo;
		if ((arquivo = fopen("Imoveis.bin", "rb")) == NULL)
		{
			cout << "\nErro ao abrir arquivo.\n";
			system("EXIT");
		}
		rewind(arquivo);
		Imoveis imovel;
		int x = 0;
		int nrRegs;//numero registros
		cin >> nrRegs;
		for (x = 0; x < nrRegs; x++)
		{
			if (!feof(arquivo))
			{
				fread(&imovel, sizeof(Imoveis), 1, arquivo);
				cout << imovel.endereco;
				cout << "\n";
			}
		}
		fcloseall();
		system("PAUSE");
			menu();
	}

	//funcao que le o arquivo inteiro
	void leArrquivoCompleto()
	{
		FILE *arquivo;
		if ((arquivo = fopen("Imoveis.bin", "rb")) == NULL)
		{
			cout << "\nErro ao abrir arquivo.\n";
			system("EXIT");
		}
		rewind(arquivo);
		Imoveis imovel;
		while (!feof(arquivo))
		{
			fread(&imovel, sizeof(Imoveis), 1, arquivo);
			cout << imovel.endereco;
			cout << "\n";
		}
		fcloseall();
		system("PAUSE");
		menu;
	}

	/*
	*Fun��o que executa o menu e armazena na vari�vel tamanhoMB ou tamanhoReg o quantos registros ser�o criados
	*Os par�metros s�o passados por refer�ncia para n�o ter copia de vari�veis
	*E para os valores serem utilizados na fun��o principal
	*Menu trabalha de forma recursiva, quando n�o � selecionada uma op��o v�lida ele retorna pra ele mesmo
	*/
	void menu()
	{
		system("CLS");//Limpa a tela
		cout << "                ========Menu========\n\n";
		cout << "O que deseja fazer?\n\n";
		cout << " 1 - Informar o tamanho do arquivo a ser gerado em megabytes.\n";
		cout << " 2 - Informar o numero de registros a serem gerados.\n";
		cout << " 3 - Ler arquivo inteiro.\n";
		cout << " 4 - Ler quantidade de registros.\n";
		cout << " 5 - Alterar arquivo de saida.\n";    --->Nao esta funcionando
		cout << " 9 - Sair\n-->";
		short opcaoMenu;//guarda o valor digitado como op��o no menu
		cin >> opcaoMenu;//Leitura do menu
		long int  tamanhoMB = 0;
		long int numeroReg = 0;
		long int quantBlocos = 0;
		long int tamUltBloco = 0;
		switch (opcaoMenu) {
		case 1:
			cout << "\nQuantos MEGABYTES tera o arquivo final? \n--> ";
			cin >> tamanhoMB;
			converteMBemReg(tamanhoMB, numeroReg);
			divideBlocos(numeroReg, quantBlocos, tamUltBloco);
			geraArquivo(quantBlocos, tamUltBloco);
			break;
		case 2:
			cout << "\nQuantos REGISTROS tera o arquivo final? \n--> ";
			cin >> numeroReg;
			divideBlocos(numeroReg, quantBlocos, tamUltBloco);
			geraArquivo(quantBlocos, tamUltBloco);
			break;
		case 3:
			leArrquivoCompleto();
			break;
		case 4:
			cout << "\nQuantos registros serao lidos? \n-->";
			leArquivo();
			break;
		case 5:
			break;
		case 9:
			system("EXIT");
			break;
		default:
			menu();
			break;
		}
		system("PAUSE");
		menu();
	}