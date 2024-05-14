#include <stdio.h>
#include <stdbool.h>

#include "operacoes.h"

int drawMenu() {
	int option = 0;
	printf("--- Calculadora em C ---\n");
	printf("(1) Soma\n");
	printf("(2) Subtração\n");
	printf("(3) Multiplicação\n");
	printf("(4) Divisão\n");
	printf("(5) Elevado\n");
	printf("[6] Sair\n");
	printf("\n> Selecione a opção: ");
	scanf("%d", &option);
	return option;
}

double operationDealing(int option, int a, int b) {
	switch(option) {
	case 1:
		return soma(a, b);
	case 2:
		return subtracao(a, b);
	case 3:
		return multiplicacao(a, b);
	case 4:
		return divisao(a, b);
	case 5:
		return elevado(a, b);
	default:
		return 0;
	}
}

int main() {
	bool mainLoop = true;
	int option;
	const int EXIT_OPTION = 6;

	while(mainLoop) {
		option = drawMenu();
		if(option == EXIT_OPTION) {
			return 0;
		}

		int firstValue = 0;
		int secondValue = 0;

		printf("> Digite um valor inteiro: ");
		scanf("%d", &firstValue);

		printf("> Digite outro valor inteiro: ");
		scanf("%d", &secondValue);

		double resposta = operationDealing(option, firstValue, secondValue);
		
		if(resposta == (int)resposta) {
			printf("A resposta é: %d\n\n", (int)resposta);

		} else {
			printf("A resposta é: %.3f\n\n", resposta);
		}
	}
	return 0;
}