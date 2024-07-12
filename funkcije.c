#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"


int ucitaj_novog_Studenta(Student **studenti, int brstudenata) {

	if (brstudenata != 0)
	{

		brstudenata++;
	}
	else
	{	
		*studenti = NULL;
		Student* novi = NULL;
		Student* pomocni = NULL;
		int i = 0;
		printf("Unesi broj studenata:");
		scanf("%d", &brstudenata);
		pomocni = malloc(sizeof(Student));
		for (i = 0; i < brstudenata; i++)
		{
			novi = malloc(sizeof(Student));
			printf("Unesi broj indexa: ");
			scanf("%d", &novi->index);
			printf("Unesi ime i prezime studenta: ");
			scanf("%s%s", &novi->ime, &novi->prezime);
			novi->pp = NULL;
			
			if (*studenti == NULL)
			{
				*studenti = novi;
				(*studenti)->next = novi;
			}
			else
			{
				pomocni->next = novi;

			}
			pomocni = novi;
			novi->next = NULL;
		}
	}
	return brstudenata;
}

int ucitaj_Predmete(Predmet **predmeti, int brpredmeta) {

	if (brpredmeta != 0)
	{

	}
	else
	{
		*predmeti = NULL;
		Predmet* novi = NULL;
		Predmet* pomocni = NULL;
		int i = 0;
		printf("Unesi broj predmeta:");
		scanf("%d", &brpredmeta);
		pomocni = malloc(sizeof(Predmet));
		for (i = 0; i < brpredmeta; i++)
		{
			novi = malloc(sizeof(Predmet));
			printf("Unesi sifru predmeta: ");
			scanf("%d", &novi->sifra);
			printf("Unesi naziv predmeta: ");
			scanf("%s", &novi->naziv);
			if (*predmeti == NULL)
			{
				*predmeti = novi;
				(*predmeti)->next = novi;
			}
			else
			{
				pomocni->next = novi;

			}
			pomocni = novi;
			novi->next = NULL;
		}
	}
	return brpredmeta;

}

void dodaj_pp(Student** studenti, Predmet* predmeti) {

	int index, sifra;
	Student* pstudent;
	Predmet* ppredmet, * pomocni;
	while (1)
	{
		pstudent = *studenti;

		printf("Unesi index studenta: ");
		scanf("%d", &index);

		if (index == -1) break;

		while (index != pstudent->index && pstudent->next != NULL)
		{
			pstudent = pstudent->next;
		}

		while (1)
		{
			ppredmet = predmeti;
			printf("Unesite sifru polozenog predmeta za studenta pod imenom %s %s\n", pstudent->ime, pstudent->prezime);
			scanf("%d", &sifra);

			if (sifra == -1) break;
			int kontrolni = 0;
			
			while (ppredmet != NULL)
			{
				if (ppredmet->sifra == sifra)
				{
					kontrolni++;
					break;
				}
				ppredmet = ppredmet->next;
			}

			if (kontrolni == 0)
			{
				printf("Nema predmeta sa tom sifrom!");
			}

			else
			{
				kontrolni = 0;

				if (pstudent->pp == NULL)
				{
					pstudent->pp = malloc(sizeof(Predmet));
					pstudent->pp->sifra = ppredmet->sifra;
					strcpy(pstudent->pp->naziv, ppredmet->naziv);
					pstudent->pp->next = pstudent->pp;
					printf("Unesite ocenu studenta za ovaj predmet: ");
					scanf("%d", &pstudent->pp->ocena);
				}
				else
				{
					Predmet* novi = malloc(sizeof(Predmet));
					if (pstudent->pp->next == pstudent->pp)
					{
						novi->sifra = ppredmet->sifra;
						strcpy(novi->naziv, ppredmet->naziv);
						pstudent->pp->next = novi;
						pstudent->pp->prev = novi;
						novi->prev = pstudent->pp;
						novi->next = pstudent->pp;
					}
					else
					{
						novi->sifra = ppredmet->sifra;
						strcpy(novi->naziv, ppredmet->naziv);
						pstudent->pp->prev->next = novi;
						novi->prev = pstudent->pp->prev;
						pstudent->pp->prev = novi;
						novi->next = pstudent->pp;
					}
				
					printf("Unesite ocenu studenta za ovaj predmet: ");
					scanf("%d", &novi->ocena);
				
				}
			}

		}

	}
}
void ispisi_predmete_po_oceni(Student* studenti) {
	
	Student* pstudent = studenti;
	Predmet* head;
	int index,ocena;

	printf("Unesite index studenta: ");
	scanf("%d", &index);

	while (index != pstudent->index)
	{
		pstudent = pstudent->next;
	}

	printf("Unesi ocenu: ");
	scanf("%d", &ocena);

	head = pstudent->pp;

	do {
		
		if (pstudent->pp->ocena == ocena) 
		{
			printf("%s\n", pstudent->pp->naziv);
		}
		
		pstudent->pp = pstudent->pp->next;

	} while (pstudent->pp != head);

}
void obrisi_predmet(Predmet** predmeti) {
	
	int sifra, kontrolni=0;
	Predmet* pomocni = *predmeti;
	Predmet* novi = NULL;
	printf("Unesi sifru predmeta koji zelis da obrises: ");
	scanf("%d", &sifra);
	
	while (pomocni != NULL)
	{
		
		if (sifra == pomocni->sifra)
		{
			kontrolni++;
			break;
		}
		else if (sifra == pomocni->next->sifra)
		{
			novi = pomocni;
		}
			
		pomocni = pomocni->next;

	}

	if (kontrolni != 0)
	{
		kontrolni = 0;
		if(novi != NULL) novi->next = pomocni->next;
		pomocni = NULL;
		printf("Predmet izbrisan!");
	}
	else
	{
		printf("Nema tog predmeta!");
	}

}

void obrisi_polozene_predmete(Student** studenti) {

	int index;
	Student* pstudent = *studenti;

	printf("Unesi index:");
	scanf("%d", &index);
	
	while (index != pstudent->index)
	{
		pstudent = pstudent->next;
	}

	free(pstudent->pp);

}

void ispisi_polozene_predmete(Student* studenti) {

	int index;
	Student* pstudent = studenti;
	Predmet* head;

	printf("Unesi index:");
	scanf("%d", &index);

	while (index != pstudent->index)
	{
		pstudent = pstudent->next;
	}

	head = pstudent->pp;

	do {
		
		printf("%s\n", pstudent->pp->naziv);
		pstudent->pp = pstudent->pp->next;

	} while (pstudent->pp != head);
}

void unija_predmeta(Student* studenti) {

	int index1, index2,kontrolni = 0;
	Student* prvi, *drugi;
	Predmet* h1, *h2;

	printf("Unesi index prvog: ");
	scanf("%d", &index1);

	printf("Unesi index drugog: ");
	scanf("%d", &index2);

	if (index1 == index2)
	{
		printf("Greska");
	}
	else
	{
		prvi = studenti;
		drugi = studenti;

		while (index1 != prvi->index)
		{
			prvi = prvi->next;
		}

		while (index2 != drugi->index)
		{
			drugi = drugi->next;
		}

		h1 = prvi->pp;
		h2 = drugi->pp;

		do {
			
			printf("%s\n", prvi->pp->naziv);
			prvi->pp = prvi->pp->next;

		} while (prvi->pp != h1);

		do {
			
			
			prvi->pp = h1;

			do {
				
				if (drugi->pp->sifra == prvi->pp->sifra)
				{
					kontrolni++;
				}

				prvi->pp = prvi->pp->next;

			} while (prvi->pp != h1);

			if (kontrolni == 0)
			{
				printf("%s\n", drugi->pp->naziv);
			}
			
			kontrolni = 0;
			drugi->pp = drugi->pp->next;

		} while (drugi->pp != h2);
	}
}

void kreiraj_vektor(Vektor* vektor) {

	int red, kolona,brv,pos;
	printf("Unesi dimenzije matrice:");
	scanf("%d%d", &red, &kolona);
	
	int** matrica;

	matrica = malloc(red * sizeof(int*));
	for (int i = 0; i < red; i++)
	{
		matrica[i] = malloc(kolona * sizeof(int));
	}

	brv = 0;

	for (int i = 0 ; i < red ; i++)
	{
		for (int j = 0; j < kolona ; j++)
		{
			printf("Unesi vrednost matrice na poziciji (%d,%d)\n", i, j);
			scanf("%d", &matrica[i][j]);
			if (matrica[i][j] != 0) brv++;
		}
	}

	vektor->brv = brv;
	vektor->red = malloc(brv * sizeof(int));
	vektor->kolona = malloc(brv * sizeof(int));
	vektor->vrednost = malloc(brv * sizeof(int));

	pos = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (matrica[i][j] != 0)
			{
				vektor->red[pos] = i;
				vektor->kolona[pos] = j;
				vektor->vrednost[pos] = matrica[i][j];
				pos++;
			}
		}
	}
}

void transponuj(Vektor vektor) {

	

}