#define _CRT_SECURE_NO_WARNINGS

#include "NameAndSurname.h"

int main() {
	NameAndSurname* array = NULL; 

	size_t array_size = 0;

	AddElement(&array, &array_size, "K", "S");
	AddElement(&array, &array_size, "R", "P");
	AddElement(&array, &array_size, "A", "G");
	AddElement(&array, &array_size, "M", "K");

	int choice = 0;
	printf("Sort by name or surname?\n1 - Name\n2 - Surname\n3 - Print array\n4 - Exit\n");
	scanf_s("%d", &choice);

	PredFunc func1 = NULL;

	if (choice == 1) {
		func1 = &PredicateName;
	}
	else if (choice == 2) {
		func1 = &PredicateSurname;
	}
	else if (choice == 3) {
		for (int i = 0; i < array_size; ++i) {
			printf("%s %s\n", array[i].name, array[i].surname);
		}
		return 0;
	}
	else if (choice == 4) {
		return 0;
	}

	system("cls");

	SortArray(array, array_size, func1);

	for (int i = 0; i < array_size; ++i) {
		printf("%s %s\n", array[i].name, array[i].surname);
	}

	free(array);
	return 0;
}