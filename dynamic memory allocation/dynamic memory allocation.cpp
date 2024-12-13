#pragma warning (disable : 4996)
#include <stdio.h>
#include <cstdlib>
#include <string.h>
struct student
{
	char imie[10];
	char nazwisko[20];
	int rok;
};

student* dynamic_alloc(int liczba)
{
	student* tab = (student*)malloc(liczba * sizeof(student));

	if (!tab)
	{
		printf("Blad przy alokacji pamieci!!!");
		return NULL;
	}

	return tab;
}

void wypelnij(student* tab, int liczba)
{
	for (int i = 0; i < liczba; i++)
	{
		printf("Podaj swoje imie: ");
		scanf("%s", &tab[i].imie);
		printf("Podaj swoje nazwisko: ");
		scanf("%s", &tab[i].nazwisko);
		printf("Podaj rok na ktorym jestes: ");
		scanf("%d", &tab[i].rok);
	}
}

void wyswietl(student* tab, int liczba)
{
	printf("\n \t\t\t\t\t\t Lista studentow: \n\n");
	for (int i = 0; i < liczba; i++)
	{
		printf("%d. Imie: %s Nazwisko %s, Rok %d \n", i + 1, tab[i].imie, tab[i].nazwisko, tab[i].rok);
	}
}

void zwolnij_pamiec(student* tab)
{
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

student* polaczenie(int num, student* tab1, student* tab2, int rozmiar1, int rozmiar2)
{
	if (num < 0)
	{
		printf("Zle przekazana wartosc!");
		return NULL;
		exit(0);
	}

	int nowy_rozmiar = rozmiar1 + rozmiar2;

	student* nowa_tablica = (student*)malloc(nowy_rozmiar * sizeof(student));

	if (!nowa_tablica)
	{
		printf("Blad przy alokacji pamieci");
		return NULL;
	}
	int j = 0;

	for (int i = 0; i <= num; i++)
	{
		nowa_tablica[j++] = tab1[i];
	}

	for (int i = 0; i < rozmiar2; i++)
	{
		nowa_tablica[j++] = tab2[i];
	}

	for (int i = num + 1; i < rozmiar1; i++)
	{
		nowa_tablica[j++] = tab1[i];
	}

	return nowa_tablica;

}




int main()
{
	int liczba1, liczba2, liczba3;

	printf("Podaj liczbe studentow informatyki: ");
	scanf("%d", &liczba1);
	printf("Podaj liczbe studentow inzynierii komputerowej: ");
	scanf("%d", &liczba2);

	student* tab1 = dynamic_alloc(liczba1);

	wypelnij(tab1, liczba1);
	wyswietl(tab1, liczba1);


	student* tab2 = dynamic_alloc(liczba2);

	wypelnij(tab2, liczba2);
	wyswietl(tab2, liczba2);

	printf("Po ktorym elemencie chcesz wstawic: ");
	scanf("%d", &liczba3);

	student* nowa_tablica = polaczenie(liczba3, tab1, tab2, liczba1, liczba2);

	wyswietl(nowa_tablica, liczba1 + liczba2);

	zwolnij_pamiec(nowa_tablica);
	zwolnij_pamiec(tab1);
	zwolnij_pamiec(tab2);


	return 0;
}
