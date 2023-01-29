#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, opt;
	int* M;
	printf("n=");
	scanf("%d", &n);
	M = (int*)malloc(n * sizeof(int));
	if (M == NULL)
	{
		printf("Alocarea nu a reusit");
		exit(0);
	}
	do
	{
		printf("0.Iesire\n");
		printf("1.Afisarea elementor multimii in ordine descrescatoare\n");
		printf("2.Afisarea elementelor multimii care sunt mai mici cu 1 decat o putere a lui 2\n");
		printf("Optiune aleasa:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			free(M);
			exit(0);
			break;

		case 1:
			break;
		case 2:
			break;
		default:
			printf("Optiune incorecta\n");
			break;
		}


	} while (1);



	system("pause");
	return 0;
}