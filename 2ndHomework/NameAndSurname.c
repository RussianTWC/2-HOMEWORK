#include "NameAndSurname.h"

int PredicateName(NameAndSurname a, NameAndSurname b) {
    if (!a.name || !b.name) {
        printf("Name is empty!\n");
        return -1;
    }

    return strcmp(a.name, b.name);
}

int PredicateSurname(NameAndSurname a, NameAndSurname b) {
    if (!a.surname || !b.surname) {
        printf("Surname is empty!\n");
        return -1;
    }

    return strcmp(a.surname, b.surname);
}

void SwapStruct(NameAndSurname* a, NameAndSurname* b) {
    if (!a || !b) {
        return;
    }

    NameAndSurname tmp = *a;
    *a = *b;
    *b = tmp;
}

void SortArray(NameAndSurname* arr, size_t array_size, PredFunc predicate) {
    if (!arr) {
        printf("Array pointer is NULL!\n");
        return;
    }

    if (array_size < 2) {
        printf("Array is empty or have 1 element!\n");
        return;
    }

    for (int i = 0; i < array_size; ++i) {
        for (int j = 0; j + 1 < array_size - i; ++j) {
            if (predicate(arr[j], arr[j + 1]) > 0) {
                SwapStruct(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void AddElement(NameAndSurname** array, size_t* size, char* name, char* surname) {
    if (name == NULL || surname == NULL) {
        return;
    }

    *size += 1;
    *array = realloc(*array, sizeof(NameAndSurname) * *size);
    if (*array == NULL) {
        return;
    }

    (*array)[*size - 1].name = malloc(strlen(name) + 1);
    if ((*array)[*size - 1].name == NULL) {
        free(*array);
        *array = NULL;
        return;
    }

    size_t name_len = strlen(name);
    for (size_t i = 0; i < name_len; ++i) {
        (*array)[*size - 1].name[i] = name[i];
    }
    (*array)[*size - 1].name[name_len] = '\0';

    (*array)[*size - 1].surname = malloc(strlen(surname) + 1);
    if ((*array)[*size - 1].surname == NULL) {
        free((*array)[*size - 1].name);
        free(*array);
        *array = NULL;
        return;
    }
    size_t surname_len = strlen(surname);
    for (size_t i = 0; i < surname_len; ++i) {
        (*array)[*size - 1].surname[i] = surname[i];
    }
    (*array)[*size - 1].surname[surname_len] = '\0';
}