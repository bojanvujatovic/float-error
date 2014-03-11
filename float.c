#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float.h"

int main (void)
{
	char broj[100];
	int pomocna_valjanost = 0, izbor;
	float float_broj;

	printf("************************ FLOATING POINT - ERROR ************************\n\n");

	do
	{
		printf("\n=================================================\n\n");
		printf(" Glavni izbornik:\n\n");
		printf(" 1 Zapis realnog broja u IEEE standardu (softverski proracun)\n");
		printf(" 2 Stvarni zapis realnog broja (float preciznosti)\n");
		printf(" 3 Izlaz iz programa\n\n");
		printf(" Izbor: ");
		scanf("%d", &izbor);

		printf("\n=================================================\n\n");

		/* Glavni izbornik */
		switch(izbor)
		{
			case 1: /* Provjra zapisa realnog broja */
				printf(" Upisite broj: ");
				scanf("%s", broj);
				printf("\n=================================================");

				if(valjanost_unesenog_broja(broj))
				{
					pomocna_valjanost++;
					IEEE(broj);
				}
				else
					printf("\n\n Krivo unseni broj, probajte ponovo.\n");
				break;

			case 2: /* Stvarni zapis realnog broja */
				printf(" Upisite broj: ");
				scanf("%f", &float_broj);
				printf("\n=================================================");

				printf("\n\n Stvarni zapis broja: %.15f\n", float_broj);

				break;

			case 3: /* Izlaz iz programa */
				printf(" Izlaz iz programa...\n\n");
				break;

			default: /* Krivi odabir */
				printf(" Krivi odabir, molimo probajte ponovo.\n");
				break;
		}

	}while(izbor != 3);

	system("pause");
	return 0;
}