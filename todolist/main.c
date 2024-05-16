#include <stdio.h>

#define TITLE_MAX_LENGTH 100
#define DESC_MAX_LENGTH 255

#define TASK_MAX_COUNT 100


typedef struct {
	char title[TITLE_MAX_LENGTH];
	char description[DESC_MAX_LENGTH];
	int priority;
	int completed;
} Task;


void drawMenu() {
	printf("---- To-do App ----\n");
	printf("(1) Adicionar tarefa\n");
	printf("(2) Concluir tarefa\n");
	printf("(3) Remover tarefa\n");
	printf("(4) Listar todas tarefas\n");
	printf("(5) Sair\n");
	printf("\n> Selecione uma opção: ");
}

Task createTask() {
	Task newTask;

	printf("Título da Task: ");
	scanf("%s", newTask.title);

	printf("\nDescrição: ");
	scanf(" %[^\n]", newTask.description);

	printf("\nPrioridade: ");
	scanf("%d", &newTask.priority);

	printf("\nCompleta? (1 ou 0): ");
	scanf("%d", &newTask.completed);

	return newTask;
}

void addTaskToList(Task taskToAdd, Task *allTasks, int *taskCount) {
	(*taskCount)++;
	if (*taskCount >= TASK_MAX_COUNT) {
		printf("[x] A lista de tasks está cheia!\n");
		return;
	}

	allTasks[((*taskCount) - 1)] = taskToAdd;
}

void readAllTasks(Task *allTasks, int *taskCount) {
	for (int i = 0; i < (*taskCount); i++) {
		printf("[ Task %d ]\n", i);
		printf("- Título: %s\n", allTasks[i].title);
		printf("- Descrição: %s\n", allTasks[i].description);
		printf("- Prioridade: %d\n", allTasks[i].priority);
		printf("- Completa: %d\n\n", allTasks[i].completed);
	}

}

void optionDeal(int option, Task *allTasks, int *taskCount) {
	switch(option) {
	case 1:
		printf("--- Adicionando Nova Tarefa ---\n");
		Task newTask = createTask();
		addTaskToList(newTask, allTasks, taskCount);

	case 4:
		printf("--- Lendo Tarefas ---\n");
		readAllTasks(allTasks, taskCount);
	}
}


int main() {
	int option = 0;
	Task allTasks[TASK_MAX_COUNT];
	int taskCount = 0;

	while(option != 5) {
		drawMenu();		
		scanf("%d", &option);
		optionDeal(option, allTasks, &taskCount);
	}

	return 0;
}

