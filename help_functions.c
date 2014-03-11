int vrati_indeks_manjeg_broja_iste_velicine(char *broj1, char *broj2)
{
	int i1 = strlen(broj1), i2 = strlen(broj2), n, i;

	i1 < i2 ? n = i1 : n = i2;

	/* Vrti broj dok se ne naiðe na znamenke koje su razlièite */
	for(i = 0; i < n; i++)
	{
		if(broj1[i] == '.') continue;

		if(broj1[i] > broj2[i])
			return 2;
		if(broj1[i] < broj2[i])
			return 1;
	}

	if(broj1[i] == NULL && broj2[i] == NULL)
		return 0;
	else if(broj1[i] == NULL)
		return 1;
	else
		return 2;


	return 1;
}

int valjanost_unesenog_broja(char *broj)
{
	int broj_tocaka = 0, i;

	/* Broj je nevaljan ako: */

	/* Poèinje s znamenkama 00xxxx */

	/* Je jednak nuli */
	if(strlen(broj) == 1 && broj[0] == '0')
		return 0;

	/* Ako sadrži na prvom mjestu bilo koje druge znakove osim znamenaka i minusa  */
	if((broj[0] > '9' || broj[0] < '0') && broj[0] != '-') return 0;
	if(broj[0] == '-' && (broj[1] > '9' || broj[1] < '0')) return 0;

	/* Poèinje s znamenkama 00xxxx */
	if(broj[0] == '0' && broj[1] == '0') return 0;

	/* Ako sadrži više od jedne decimalne toèke ili sadrži bilo koji znak koji nije znamenka (ili toèka) */
	for(i = 1; i < strlen(broj); i++)
	{
		if(broj[i] == '.') 
			broj_tocaka++;

		else if(broj[i] > '9' || broj[i] < '0') 
			return 0;
	}

	/* Ako sadrži više od jedne decimalne toèke */
	if(broj_tocaka > 1)
		return 0;

	return 1;
}

char *iz_10_u_string(double broj)
{
	/* Deklaracija i inicijalizacija varijabli */
	int cijeli_dio = (int)(broj - (double)(broj - (int)broj)), brojac = 0, brojac2 = 0;
	double decimalni_dio = broj - cijeli_dio;
	char rjesenje[300];

	/* Zapis znamenaka cijelog dijela */
	do
	{
		rjesenje[brojac++] = cijeli_dio % 10 + '0';
		cijeli_dio /= 10;
	}while(cijeli_dio > 0);

	/* Završi zapis, okreni ga i dodaj na kraju toèku */
	rjesenje[brojac] = NULL;
	strcpy(rjesenje, strrev(rjesenje));
	rjesenje[brojac++] = '.';

	/* Zapiši znamenke decimalnog dijela */
	do
	{
		decimalni_dio *= 10;
		rjesenje[brojac++] = (int)(decimalni_dio - (double)(decimalni_dio - (int)decimalni_dio)) + '0';
		decimalni_dio = (double)(decimalni_dio - (int)decimalni_dio);
	}while(brojac2++ < 14);

	/* Kraj zapisa */
	rjesenje[brojac] = NULL;

	return rjesenje;
}

char *oduzimanje_2_broja_iste_duljine(char *veci_broj, char *manji_broj)
{
	/* Deklaracija i inicijalizacija varijabli */
	int ostatak1 = 0, ostatak2 = 0, i, n, znamenka1, znamenka2;
	char rezultat[300], pomocni_veci_broj[300], pomocni_manji_broj[350];

	strcpy(pomocni_veci_broj, veci_broj);
	strcpy(pomocni_manji_broj, manji_broj);

	/* Odredi koji broj ima manji broj decimala (pod pretpostavkom da imaju isti broj znamenaka prije toèke) */
	/* Broj koji ima manje, ako postoji, andopuni sa nulama do dužine dužeg broja */
	if(strlen(pomocni_veci_broj) < strlen(pomocni_manji_broj))
	{
		i = strlen(pomocni_manji_broj);
		n = strlen(pomocni_veci_broj);

		for(; i >= n; i--)
			pomocni_veci_broj[i] = '0';
	}
	else
	{
		i = strlen(pomocni_veci_broj);
		n = strlen(pomocni_manji_broj);

		for(; i >= n; i--)
			pomocni_manji_broj[i] = '0';
	}

	/*  */
	if(strlen(pomocni_veci_broj) < strlen(pomocni_manji_broj))
		i = strlen(pomocni_veci_broj);
	else
		i = strlen(pomocni_manji_broj);

	rezultat[i--] = NULL;

	/* Algoritam oduzimanja */
	for(; i >= 0; i--)
	{
		znamenka1 = pomocni_veci_broj[i] - '0';
		znamenka2 = pomocni_manji_broj[i] - '0' + ostatak1;

		if(znamenka1 + '0' == '.' || znamenka2 + '0' == '.') /* Ako se naiðe na toèku, zapiši je i u rješenju */
		{
			rezultat[i] = '.';
			continue;
		}

		if(znamenka1 - znamenka2 < 0)
		{
			znamenka1 += 10;
			ostatak2++;
		}

		rezultat[i] = znamenka1 - znamenka2 + '0';

		ostatak1 = ostatak2;
		ostatak2 = 0;
	}

	/* Ako su na poèetku dvije nule, prebriši jednu pomicanje ulijevo */
	while(rezultat[0] == '0' && rezultat[1] == '0')
	{
		for(i = 1; i <= strlen(rezultat); i++)
			rezultat[i - 1] = rezultat[i];
	}

	/* Ako su na kraju dvije nule, prebriši jednu pomicanjem kraja zapisa */
	while(rezultat[strlen(rezultat) - 1] == '0' && rezultat[strlen(rezultat) - 2] == '0')
		rezultat[strlen(rezultat) - 1] = NULL;

	return rezultat;
}

char *dodaj_1_binarnom_broju(char *binarni_broj)
{
	/* Inicijalizacija i deklaracija varijabli */
	char pomocni_binarni_broj[33];
	strcpy(pomocni_binarni_broj, binarni_broj);
	int ostatak = 1, i;

	/* Algoritam dodavanja jedinice (zbrajanja sa jedinicom) - dodavaj ostatak jedan dok se ne naiðe na nulu */
	for(i = strlen(binarni_broj) - 1; ostatak; i--)
	{
		if(pomocni_binarni_broj[i] == '0')
		{
			pomocni_binarni_broj[i] = '1';
			ostatak = 0;
		}
		else
			pomocni_binarni_broj[i] = '0';
	}
	return pomocni_binarni_broj;
}

double potencija_2(int potencija)
{
	double rjesenje = 1;
	int i;

	/* Raèunaj potenciju broja 2 */
	if(potencija < 0)
		for(i = 0; i < -potencija; i++)
			rjesenje /= 2;
	else
		for(i = 0; i < potencija; i++)
			rjesenje *= 2;

	return rjesenje;
}

double iz_IEEE_u_10(char *IEEE, int potencija)
{
	/* Deklaracija i inicijalizacija varijabli */
	int potencije_2[30], pomocni_indeks = 1, i;
	double rjesenje = 0;
	
	/* Postavi vrijednost niza u kojem se pamte sve potencija broja 2 na nulu */
	memset(potencije_2, 0, sizeof(potencije_2));

	/* Zapiši u niz sve potencija broja 2 */
	for(i = 9; i <= 32; i++)
		if(IEEE[i] == '1')
			potencije_2[pomocni_indeks++] = -(i - 8);

	/* Zbroji sve potencije s eksponentom u normaliziranom zapisu broja te dobij rezultat kao zbroj svih dobivenih potencija broja 2 */
	for(i = 0; i < pomocni_indeks; i++)
		rjesenje += potencija_2(potencije_2[i] + potencija);

	/* U sluèaju negativnog broja */
	if(IEEE[0] == '1')
		rjesenje *= -1;

	/* Sigurni smo da konaèno rješenje neæe generirati grešku u zapisu jer se radi o potencijama broja 2, odnosno konaènim zapisima u registru */
	return rjesenje;
}

void ispis_IEEE(char *IEEE)
{
	int i;
	
	/* Ispiši registar pomoæu nula i jedinica, odvoji znakom ' | ' predznak, eksponent i mantisu */
	printf("%c", IEEE[0]);

	printf(" | ");

	for(i = 1; i < 9; i++)
		printf("%c", IEEE[i]);

	printf(" | ");

	for(i = 9; i <= 32; i++)
		printf("%c", IEEE[i]);

	printf("\n");
}

char *pretvori_potenciju_u_binarno(int potencija)
{
	/* Deklaracija i inicijalizacija varijabli */
	char potencija_binarno[9], pomocno_binarno[9];
	int pomocni_indeks = 0, i;

	/* Algoritam dijeljenja s 2 radi pretvorbe u binarni sustav */
	do
	{
		pomocno_binarno[pomocni_indeks++] = potencija % 2 + '0';
		potencija /= 2;
	}while(potencija != 0 && pomocni_indeks < 8);	

	/* Zavrsi zapis i okreni ga */
	pomocno_binarno[pomocni_indeks] = NULL;
	strcpy(pomocno_binarno, strrev(pomocno_binarno));

	/* Postavi sve znamenke rezultata na nulu */
	memset(potencija_binarno, '0', sizeof(potencija_binarno));

	/* Prepiši sve znamenke potencije u rezultat */
	for(i = 0; i < strlen(pomocno_binarno); i++)
		potencija_binarno[i + 8 - strlen(pomocno_binarno)] = pomocno_binarno[i];

	/* Kraj zapisa */
	potencija_binarno[8] = NULL;

	return potencija_binarno;
}

char *podijeli_cjelobrojno_s_2(char *cijeli_dio)
{
	/* Deklaracija i inicijalizacija varijabli */
	char pomocno_cijeli_dio[100];
	int i, ostatak = 0, znamenka;

	/* Algoritam dijeljenja s 2 */
	for(i = 0; i < strlen(cijeli_dio); i++)
	{
		znamenka = cijeli_dio[i] - '0' + ostatak * 10;
		ostatak = znamenka % 2;
		pomocno_cijeli_dio[i] = znamenka / 2 + '0';
	}
	pomocno_cijeli_dio[i] = NULL;

	/* Ako je prva znamenka jednaka nuli, prebrišimo je pomiæiæi sve znamenke jedno mjesto ulijevo */
	if(pomocno_cijeli_dio[0] == '0')
		for(i = 1; i <= strlen(pomocno_cijeli_dio); i++)
			pomocno_cijeli_dio[i - 1] = pomocno_cijeli_dio[i];

	return pomocno_cijeli_dio;
}

char *pomnozi_decimalni_dio_s_2(char *decimalni_dio)
{
	/* Deklaracija i inicijalizacija varijabli */
	char pomocno_decimalni_dio[100];
	int i, ostatak_1 = 0, ostatak_2, znamenka;

	/* Algoritam za množenje s 2 */
	for(i = strlen(decimalni_dio) - 1; i >= 0; i--)
	{
		znamenka = decimalni_dio[i] - '0';

		if(znamenka  >= 5)
			ostatak_2 = 1;
		else
			ostatak_2 = 0;
		pomocno_decimalni_dio[i] = (znamenka * 2) % 10 + '0' + ostatak_1;
		ostatak_1 = ostatak_2;
	}

	/* Ako je zadnja znamenka nula, prebrišimo je stavljanjem kraja */
	if(pomocno_decimalni_dio[strlen(decimalni_dio) - 1] == '0')
		pomocno_decimalni_dio[strlen(decimalni_dio) - 1] = NULL;
	else
		pomocno_decimalni_dio[strlen(decimalni_dio)] = NULL;

	return pomocno_decimalni_dio;
}

char *pretvori_u_binarno_cijeli_dio(char *cijeli_dio)
{
	/* Inicijalizacija i deklaracija varijabli */
	char binarno_cijeli_dio[100];
	int pomocni_indeks = 0, zadnja_znamenka;

	/* Algoritam pretvaranja u binarni sustav - dijeljenjem s 2 dok se ne dobije nula */
	do
	{
		zadnja_znamenka = cijeli_dio[strlen(cijeli_dio) - 1] - '0';
		binarno_cijeli_dio[pomocni_indeks++] = zadnja_znamenka % 2 + '0';

		strcpy(cijeli_dio, podijeli_cjelobrojno_s_2(cijeli_dio));
	}while(strlen(cijeli_dio) != 0);
	
	/* Završi zapus i okreni dobiveni broj */
	binarno_cijeli_dio[pomocni_indeks] = NULL;
	strcpy(binarno_cijeli_dio, strrev(binarno_cijeli_dio));

	return binarno_cijeli_dio;
}

char *pretvori_u_binarno_decimalni_dio(char *decimalni_dio)
{
	/* Inicijalizacija i deklaracija varijabli */
	char binarno_decimalni_dio[300];
	int pomocni_indeks = 0, prva_znamenka;

	/* Algoritam pretvaranja u binarni sustav - množenjem sa 2 */
	do
	{
		prva_znamenka = decimalni_dio[0] - '0';

		if(prva_znamenka >= 5)
			binarno_decimalni_dio[pomocni_indeks++] = '1';
		else
			binarno_decimalni_dio[pomocni_indeks++] = '0';

		strcpy(decimalni_dio, pomnozi_decimalni_dio_s_2(decimalni_dio));
	}while(strlen(decimalni_dio) != 0 && pomocni_indeks < 270); /* Radi dok se algoritam ne izvrši ili dok se ne zapiše 270 decimala */

	/* Kraj zapisa */
	binarno_decimalni_dio[pomocni_indeks] = NULL;

	return binarno_decimalni_dio;
}

char *pretvori_10_u_binarno_string(char *broj)
{
	/* Deklaracija i inicijalizacija varijabli */
	char cijeli_dio[100], decimalni_dio[100], binarno_cijeli_dio[100], binarno_decimalni_dio[300], binarno[400];
	int pomocni_indeks = 0, i = 0;

	/* Odvoji cijeli dio - dio koji je do decimalne toèke ili do kraja zapisa broja */
	for(i = 0; broj[i] != '.' && broj[i] != NULL; i++)
		cijeli_dio[i] = broj[i];
	cijeli_dio[i] = NULL;

	/* Ako ne postoji decimalni dio, stavi ga na nulu, u suprotnom odvoji ga */
	if(broj[i++] == NULL)
	{
		decimalni_dio[0] = '0';
		decimalni_dio[1] = NULL;
	}
	else
		do
		{
			decimalni_dio[pomocni_indeks++] = broj[i];
		}while(broj[i++] != NULL);

	/* Pretvori posebno cijeli dio, posebno decimalni u binarni sustav */
	strcpy(binarno_cijeli_dio, pretvori_u_binarno_cijeli_dio(cijeli_dio));
	strcpy(binarno_decimalni_dio, pretvori_u_binarno_decimalni_dio(decimalni_dio));

	/* U rješenje prvo zapiši cije dio */
	for(i = 0; i < strlen(binarno_cijeli_dio); i++)
		binarno[i] = binarno_cijeli_dio[i];
	binarno[i] = NULL;

	/* Ako je decimalni dio razlièit od nule, dodaj toèku na kraj stringa te dodaj sve decimale iza toèke */
	if(binarno_decimalni_dio[0] != '0' || binarno_decimalni_dio[1] != NULL)
	{
		binarno[i++] = '.';
		for(pomocni_indeks = 0; pomocni_indeks <= strlen(binarno_decimalni_dio); pomocni_indeks++)
			binarno[i + pomocni_indeks] = binarno_decimalni_dio[pomocni_indeks];
	}

	return binarno;
}

void IEEE(char *broj)
{
	/* Deklaracija i inicijalizacija varijabli */
	char broj_binarno[400], binarno_potencija[9], rjesenje1_IEEE[33], rjesenje2_IEEE[33];
	char razlika_rjesenja_1[300], razlika_rjesenja_2[300], rjesenje1_IEEE_string[300], rjesenje2_IEEE_string[300];
	int potencija, pocetak_mantise, i, i2, manji_indeks;
	enum pozitivnost {minus, plus};
	double rjesenje1_IEEE_double, rjesenje2_IEEE_double;
	pozitivnost predznak;

	/* Ako je broj negativan, zapamti i pretvori ga i pozitivan */
	if(broj[0] == '-')
	{
		predznak = minus;
		for(i = 1; i <= strlen(broj); i++)
			broj[i - 1] = broj[i];
	}
	else /* U suprtonom, samo zapamti da je pozitivan */
		predznak = plus;

	/* Pretvori broj u binarni sustav */
	strcpy(broj_binarno, pretvori_10_u_binarno_string(broj));

	/* Raèunanje potencije broja u normaliziranom obliku */
	if(broj_binarno[0] == '1' && broj_binarno[1] == '.') /* Ako je oblika 1.xxx... onda je potencija jednaka 0 */
		potencija = 0;
	else if(broj_binarno[0] == '0') /* Ako je broj oblika 0.xxxxx, onda je potencija jednaka negativnom indeksu jedinice/kraja broja + 1 */
	{
		for(i = 2; broj_binarno[i] != '1' && broj_binarno[i] != NULL; i++) ;
			potencija = -(i - 1);
	}
	else /* Ako je oblika 1xxxx.xxxx, onda je potencija jednaka indeksu decimalne tocke/kraja broja - 1 */
	{
		for(i = 1; broj_binarno[i] != '.' && broj_binarno[i] != NULL; i++) ;
			potencija = i - 1;
	}

	/* Raèunanje indeksa znamenke od koje se poèinje zapisivati mantisa */
	if(potencija >= 1) /* Ako je potencija veæa od 1, onda poèni prepisivati mantisu od druge znamenke */
		pocetak_mantise = 1;
	else /* U suprtonom indeks pocetka mantise je jednak indeksu decimalne tocke + 3 ili 2 - potencija */
		pocetak_mantise = -potencija + 2;

	/* Za kodiranje potencije je potrebno dodati pomak od 127 */
	potencija += 127;

	/* Kodiranje potencije */
	strcpy(binarno_potencija, pretvori_potenciju_u_binarno(potencija));

	/* Ispis podataka */
	printf("\n\n Binarno: %.50s\n Potencija: %d (Binarno: %s)\n Mantisa od: %d\n\n", broj_binarno, potencija - 127, binarno_potencija, pocetak_mantise);

	/* Postavi sve znamenke rjesenja na nulu */
	memset(rjesenje1_IEEE, '0', sizeof(rjesenje1_IEEE));

	/* Bit za predznak */
	if(predznak == plus)
		rjesenje1_IEEE[0] = '0';
	else
		rjesenje1_IEEE[0] = '1';

	/* Zapis potencije */
	for(i = 0; i < 8; i++)
		rjesenje1_IEEE[i + 1] = binarno_potencija[i];

	/* Zapis mantise u rjesenje */
	i2 = 9;
	for(i = pocetak_mantise; i < strlen(broj_binarno) && i2 <= 32; i++) /* Zapisuj u rjesenje dok broj ne stane ili dok se registar ne popuni */
	{
		if(broj_binarno[i] == '.') continue; /* Ako se naiðe na decimalnu toèku, preskoèi ju */
		rjesenje1_IEEE[i2++] = broj_binarno[i];
	}
	rjesenje1_IEEE[32] = NULL; /* Kraj zapia */

	/* Ispis ovako dobivenog rjesenja (rjesenje 1) */
	printf(" IEEE - 1. zapis:     ");
	ispis_IEEE(rjesenje1_IEEE);

	/* Pretvori ovakav zapis u realni broj i ispiši ga */
	rjesenje1_IEEE_double = iz_IEEE_u_10(rjesenje1_IEEE, potencija - 127);
	printf(" Dekadski ekvivalent: %.15f\n", rjesenje1_IEEE_double);

	/* Pretvori ovako dobiven broj u string da bi mogli odrediti apsolutnu razliku izmeðu ovog broja i poèetnog, ispiši tu razliku */
	if(rjesenje1_IEEE_double < 0) 
		rjesenje1_IEEE_double *= -1;
	strcpy(rjesenje1_IEEE_string, iz_10_u_string(rjesenje1_IEEE_double));
	strcpy(razlika_rjesenja_1, oduzimanje_2_broja_iste_duljine(broj, rjesenje1_IEEE_string));
	printf(" Apsolutna razlika:   %s\n\n", razlika_rjesenja_1);

	/* Drugo moguæe rješenje jest ono koje je najmanje moguæe, a veæe od prvog, odnosno potrebno je na mantisu probrojiti jedinicu  */
	strcpy(rjesenje2_IEEE, dodaj_1_binarnom_broju(rjesenje1_IEEE));

	/* Ispis ovako dobivenog rjesenja (rjesenje 1) */
	printf(" IEEE - 2. zapis:     ");
	ispis_IEEE(rjesenje2_IEEE);

	/* Pretvori ovakav zapis u realni broj i ispiši ga */
	rjesenje2_IEEE_double = iz_IEEE_u_10(rjesenje2_IEEE, potencija - 127);
	printf(" Dekadski ekvivalent: %.15f\n", rjesenje2_IEEE_double);

	/* Pretvori ovako dobiven broj u string da bi mogli odrediti apsolutnu razliku izmeðu ovog broja i poèetnog, ispiši tu razliku */
	if(rjesenje2_IEEE_double < 0) 
		rjesenje2_IEEE_double *= -1;
	strcpy(rjesenje2_IEEE_string, iz_10_u_string(rjesenje2_IEEE_double));
	strcpy(razlika_rjesenja_2, oduzimanje_2_broja_iste_duljine(rjesenje2_IEEE_string, broj));
	printf(" Apsolutna razlika:   %s\n", razlika_rjesenja_2);

	/* Odredi koji je broj bolji za zapis poèetnog broja tako da se usporede apolutne razlike */
	manji_indeks = vrati_indeks_manjeg_broja_iste_velicine(razlika_rjesenja_1, razlika_rjesenja_2);

	/* Ispis konaènog rješenja */
	switch(manji_indeks)
	{
		case 1:
			printf("\n Apsolutna razlika u %d. zapisu je manja, pa je stvarni zapis:\n\n %.15f\n", manji_indeks, rjesenje1_IEEE_double);
			break;

		case 2:
			printf("\n Apsolutna razlika u %d. zapisu je manja, pa je stvarni zapis:\n\n %.15f\n", manji_indeks, rjesenje2_IEEE_double);
			break;

		default:
			printf("\n Apsolutne razlike su iste, pa je stvarni zapis:\n\n %.15f\n", rjesenje2_IEEE_double);
	}
	
}