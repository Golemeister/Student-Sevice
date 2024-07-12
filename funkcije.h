#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Predmet {
	char naziv[20];
	int sifra;
	struct Predmet* next,* prev;
	int ocena;
}Predmet;

typedef struct Student {
	char ime[15], prezime[15];
	int index;
	struct Predmet* pp;
	struct Student* next;
}Student;

typedef struct Vektor {
	int* red;
	int* kolona;
	int* vrednost;
	int brv;
}Vektor;