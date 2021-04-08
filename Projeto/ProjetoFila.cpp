#include <iostream>
#include <locale>
#include <stdio.h>
#include <string>
#include <cstdlib>

#define TAM 5

using namespace std;

struct queuque {
	float f[TAM];
	int inicio, fim;
};

void enfileira(queuque &fil);
void desinfileira(queuque &fil);
void elemPrimeiro(queuque &fil);
void situacaoFila(queuque &fil);

int main() {
	setlocale(LC_ALL, "ptb");
	char resp[10];
	int op;
	queuque fila;
	
	fila.inicio = 0;
	fila.fim = -1;
	
	do {
		system("cls");
		system("color 2f");
		
		cout << "\nFila (FIFO - Fist In - Fist Out)\n\n";
		cout << "\n1. Inserir Valor na Fila";
		cout << "\n2. Remover Valor na Fila";
		cout << "\n3. Mostrar o Elemento Inicial da Fila";
		cout << "\n4. Situação da Fila";
		cout << "\n5. Sair";
		cin >> resp;
		op = atoi (resp);
		
		system("cls");
		
		switch (op) {
			case 1:
				enfileira(fila);
				break;
				
			case 2:
				desinfileira(fila);
				break;
				
			case 3:
				elemPrimeiro(fila);
				break;
				
			case 4:
				situacaoFila(fila);
				break;
				
			case 5:
				cout << "\nPrograma Basico de Fila\n";
				break;
				
			default:
				cout << "\nOPÇÃO INVÁLIDO\n";
				break;
		}
		cout << "\n\n";
		system("pause");
	} while (op!=5);
}

void enfileira(queuque &fil) {
	float valor;
	if (fil.fim == TAM - 1) {
		cout << "\nAtenção Fila CHEIA!\n";
	} else {
		cout << "Digite o Valor a ser Enfileirado: ";
		cin >> valor;
		fil.fim++;
		fil.f[fil.fim] = valor;
	}
}

void desinfileira(queuque &fil) {
	if (fil.inicio > fil.fim) {
		cout << "\nAtenção Fila VAZIA\n";
	} else {
		cout << "\nValor REMOVIDO: " << fil.f[fil.inicio];
		fil.inicio++;
	}
}

void elemPrimeiro(queuque &fil) {
	if (fil.inicio > fil.fim) {
		cout << "\nAtenção Fila VAZIA\n";
	} else {
		cout << "\nElemento do Inicio da Fila: " << fil.f[fil.inicio];		
	}
}

void situacaoFila(queuque &fil) {
	if (fil.inicio > fil.fim) {
		cout << "\nAtenção Fila VAZIA\n";
	} else {
		cout << "\nTotal de Elementos na FILA: " << fil.fim - fil.inicio+1 << "\n";
		cout << "\n\nEspaço Disponível na FILA: " << TAM-(fil.fim+1) << "\n";
		cout << "\n\nPosição do Primeiro Elemento da FILA: " << fil.inicio << "\n";
		cout << "\n\nPosição do Último Elemento da Fila: " << fil.fim << "\n";
		cout << "\nAtenção Lista VAZIA\n";
	}
}
