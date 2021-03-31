#include <locale>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void insere(int codigo[], int& t, int tamanho);
void exibe(int codigo[], int t);
void elemento(int codigo[], int t);

int main() {
	setlocale(LC_ALL, "ptb");
	
	int codigoProduto[5];
	int tam, op;
	
	//Inicialização
	
	tam = 0;
	
	do{
		//Obter a Opção
		system("cls");
		
		cout << "\nMenu - Lista \n";
		cout << "\n0- Reiniciar LISTA";
		cout << "\n1- Inserir Código na LISTA";
		cout << "\n2- Exibir LISTA";
		cout << "\n3- Exibir Tamanho da LISTA";
		cout << "\n4- Exibir um Elemento da LISTA";
		cout << "\n5- Sair";
		cout << "\n\nDigite a Opção: ";
		cin >> op;
		
		system("cls");
		
		switch (op) {
			
			case 0: //Reinicia a Lista
				tam = 0;
				break;
				
			case 1:
				insere(codigoProduto, tam, 5);
				break;
				
			case 2:
				exibe(codigoProduto, tam);
				break;	
				
			case 3:
				cout << "\nTamanho da LISTA: " << tam;
				break;	
					
			case 4:
				elemento(codigoProduto, tam);
				break;
				
			case 5:
				cout << "\nFinalizando o Programa...\n";
				break;
				
			default:
				cout << "\nOpção INVÁLIDA!!\n";
				break;
		}
		
		cout << "\n\n";
		system("pause");
		
	}while(op != 5);
}

void insere(int codigo[], int& t, int tamanho) {
	int prod;
	
	//Verifica se a LISTA esta cheia
	if (tamanho == t) {
		cout << "\nAtenção! \nLista Cheia.\n";
		
	} else {
		cout << "\nDigite o Código do produto a ser inserido: ";
		cin >> prod;
		
		codigo[t] = prod;
		t++;
	}
}

void exibe(int codigo[], int t) {
	int x;
	
	//Verifica se tem algum elemento na lista
	if (t == 0) {
		cout << "\nAtenção! \nLista Vazia.\n";
		
	} else {
		cout << "\nRelação dos Códigos.\n";
		
		for (x = 0; x < t; x++) {
			cout << "\n" << codigo[x];
		}
	}
}

void elemento(int codigo[], int t) {
	int prod, posicao; 
	
	if (t == 0) {
		cout << "\nAtenção! \nLista Vazia.\n";
		
	} else {
		cout << "\nDigite a Posição Desejada: ";
		cin >> posicao;
		posicao--;
		
		if (posicao >= t) {
			cout << "\nAtenção! \nNenhum Código Armazenado ou Posição Inexistente.\n";
		} else {
			cout << "\nCódigo: " << codigo[posicao] << "\n";
		}
	}
}
