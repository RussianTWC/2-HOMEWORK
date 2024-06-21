#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NameAndSurname {
    char* name;
    char* surname;
}NameAndSurname;

typedef int(*PredFunc)(NameAndSurname, NameAndSurname);

int PredicateName(NameAndSurname a, NameAndSurname b);
int PredicateSurname(NameAndSurname a, NameAndSurname b);

void SortArray(NameAndSurname* arr, size_t array_size, PredFunc predicate);
void AddElement(NameAndSurname** array, size_t* size, char* name, char* surname);