#include <stdio.h>


void drawMenu(int *option) {
	printf("---- To-do App ----\n");
	printf("(1) Adicionar tarefa\n");
	printf("(2) Concluir tarefa\n");
	printf("(3) Remover tarefa\n");
	printf("(4) Listar todas tarefas\n");
	printf("(5) Sair\n");
	printf("\n> Selecione uma opção: ");

	scanf("%d", option);
}


int main() {
	int option;

	do{
		drawMenu(&option);
	} while(option != 5);

	return 0;
}

