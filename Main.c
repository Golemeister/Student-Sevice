#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

int brpredmeta = 0;
int brstudenata = 0;
Student *studenti;
Predmet *predmeti;
Vektor vektor;
int main() {
	int izbor = 0;
	studenti = malloc(sizeof(Student));
	predmeti = malloc(sizeof(Predmet));
	while (1) {
		printf("[1]Ucitaj novog studenta\n[2]Dodaj polozen predmet\n[3]Prikazi predmete studenta sa odredjenom ocenom\n[4]Brisanje predmeta\n[5]Brisanje svih polozenih predmeta\n[6]Ispisivanje polozenih predmeta\n[7]Dodaj predmete\n[8]Unija polozenih predmeta\n[9]Napravi vektor matrice\n[10]Transponuj matricu\n");
		scanf("%d", &izbor);
		switch (izbor)
		{
		case 1: brstudenata = ucitaj_novog_Studenta(&studenti, brstudenata);
			break;
		case 2: dodaj_pp(&studenti, predmeti);
			break;
		case 3: ispisi_predmete_po_oceni(studenti);
			break;
		case 4: obrisi_predmet(&predmeti);
			break;
		case 5: obrisi_polozene_predmete(&studenti);
			break;
		case 6: ispisi_polozene_predmete(studenti);
			break;
		case 7: brpredmeta = ucitaj_Predmete(&predmeti, brpredmeta);
			break;
		case 8: unija_predmeta(studenti);
			break;
		case 9: kreiraj_vektor(&vektor);
			break;
		case 10: transponuj(vektor);
			break;
		}
	}

	return 0;
}