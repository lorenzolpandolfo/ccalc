#include "operacoes.h"

double soma(int a, int b) {
	return a + b;
}

double subtracao(int a, int b) {
	return a - b;
}

double divisao(int a, int b) {
	return (double)a / b;
}

double multiplicacao(int a, int b) {
	return a * b;
}

double elevado(int a, int b) {
	int acumulador = 1;

	for(int i = 0; i < b; i++) {
		acumulador *= a;
	}
	return acumulador;
}