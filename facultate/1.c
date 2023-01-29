#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
	return (*(int*)b - *(int*)a);
}

int verificare(int x)
{
	if (x >= 1 && x <= 100)
		return 0;
	return 1;
}

void citire_vector(int* M, int n)
{
	int i;
	for (i = 0; i < n-1; i++)
	{
		printf("a[%d]=", i);
		do {
			scanf("%d", (M + i));
		} while (verificare(*(M+i)));
	}
	*(M + i) = n;
}

void afisare_vector(int* M, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d " ,*(M + i));
	}
	printf("\n");
}
void salvare(int* M, int n)
{
	int x, i, k = 0;
	FILE* F;
	char nume_fisier[30];
	printf("Introduce-ti numele fisierului: ");
	scanf("%s", &nume_fisier);
	strcat(nume_fisier, ".txt");
	F = fopen(nume_fisier, "w");
	printf("introduceti o valoare :");
	scanf("%d", &x);
	for (i = 0; i < n; i++)
	{
		if (*(M + i) > x)
			k++;
	}
	fprintf(F, "%d", k);
	fclose(F);
	
}
int main()
{
	int n, opt;
	int* M;
	do {
		printf("Nr de el(maxim 100) n=");
		scanf("%d", &n);
	} while (n <= 1 || n >= 100);
	M = (int*)malloc(n * sizeof(int));
	if (M == NULL)
	{
		printf("Alocarea nu a reusit");
		exit(0);
	}
	citire_vector(M, n);
	do
	{
		printf("0.Iesire\n");
		printf("1.Afisarea elementor multimii in ordine descrescatoare\n");
		printf("2.Afisarea elementelor multimii care sunt mai mici cu 1 decat o putere a lui 2\n");
		printf("3.Salveaza intr-un fisier text cu numele dat de la tastatura,numarul de elemente mai mari decat o valoare citita de la tastatura\n");
		printf("Optiune aleasa:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			free(M);
			exit(0);
			break;

		case 1:
			printf("Sortare in ordine descrescatoare: ");
			qsort(M, n, sizeof(int), cmp);
			afisare_vector(M, n);
			break;
		case 2:
			break;
		case 3:
			salvare(M, n);
			break;
		default:
			printf("Optiune incorecta\n");
			break;
		}


	} while (1);



	system("pause");
	return 0;
}