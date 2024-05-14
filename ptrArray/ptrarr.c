#include <stdio.h>


void changeArrayValue(int* array, int index, int value) {
	array[index] = value;
}

void printArray(int array[], int length) {
	for(int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}
}

int main() {
	int array[5] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(array[0]);

	printf("Alterando o valor do array\n");

	changeArrayValue(array, 2, 100);
	printArray(array, length);
	return 0;
}