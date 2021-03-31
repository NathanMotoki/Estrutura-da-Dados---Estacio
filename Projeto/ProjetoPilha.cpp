#include <iostream>
#include <locale>
#include <stdio.h>
#include <string>

#define TAM 5

using namespace std;

void empilha(int p[], int &t, int v);
int desempilha(int p[], int &t, int &v);
void acessoTopo(int p[], int &t);
void situacaoPilha(int p[], int &t);

int main() {
	int op, val, topo = -1, pilha[TAM], resp;
	
	do {
		
		system("cls");
		system("color f0");
		cout << "\nPilha (LIFO - Last in - First Out)\n\n";
		cout << "\n1 - Inserir um valor na pilha";
		cout << "\n2 - Remover um valor na pilha";
		cout << "\n3 - Mostrar elemento no topo da pilha";
		cout << "\n4 - Mostrar situacao da pilha";
		cout << "\n5 - Sair";
		cout << "\nOpcao: ";
		cin >> op;
		system("cls");
		
		switch (op) {
			case 1:
				cout << "\nDigite o valor a ser empilhado: ";
				cin >> val;
				
				empilha(pilha, topo, val);
				break;
				
			case 2:
				resp = desempilha(pilha, topo, val);
				if (resp == 0) {
					cout << "\n\nAtenção. \nPilha Vazia. \n";
				} else {
					cout << "\nValor removido: " << val;
				}
				break;
				
			case 3:
				acessoTopo(pilha, topo);
				break;
				
			case 4:
				situacaoPilha(pilha, topo);
				break;
				
			case 5:
				cout << "\nPrograma básico PILHA.\n";
				break;
				
			default:
				cout << "\nOpção Inválida!\n";
				break;
		}
		
		cout << "\n\n";
		system("pause");
		
	} while(op != 5);
}

//Inserir
void empilha(int p[], int &t, int v) {
	if(t == TAM - 1) {
		cout << "\nAtenção. \nPilha Cheia!\n";
	} else {
		t++; //Atualiza o Topo
		p[t] = v; //Pilha recebe valor
	}
}

//remove
int desempilha(int p[], int &t, int &v) {
	if (t == -1) {
		return 0;
	} else {
		v = p[t]; //Guarda valor do Topo
		t--; //Atualiza o Topo
		return 1;
	}
}

//Mostra o Topo
void acessoTopo(int p[], int &t) {
	if (t == -1) {
		cout << "\nAtenção. \nPilha Vazia. \n";
	} else {
		cout << "\nElemento do Topo da PILHA: " << p[t];
	}
}

//Situacao Pilha
void situacaoPilha(int p[], int &t) {
	if (t == -1) {
		cout << "\nAtenção. \nPilha Vazia. \n";
	} else if (t == TAM - 1) {
	 	cout << "\nAtenção. \nPilha Cheia. \n";
	} else {
		cout << "\nTotal de Elementos da PILHA: " << t + 1 << "\n";
		cout << "\n\nEspaço de Elementos da PILHA: " << TAM - (t + 1) << "\n";
	}
}
