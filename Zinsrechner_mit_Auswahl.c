#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)
int main()
{
	double Startkapital = 0;
	double Zinssatz_Dezimal;
	int Auszahlung;
	int Zeitraum;
	double Zinssatz_Richtig = 0;
	double Ergebnis = 0;
	double gerundet = 0;
	double Zwischenschritt;
	int Auswahl;

	Anfang:

	printf("\nBitte Beachte das in diesem Programm die Zinsen so berechnet werden mit der vorraussetzung das dass Geld");
	printf("\nfur den ausgewahlten Zeitraum nicht abgehoben wird und auf dem Konto verbleibt!");
	printf("\n---------------------------------------------------------------------------------------------");
	printf("\nBitte geb deinen Startbetrag in Euro ein\n");
	scanf("%lf", &Startkapital); //Hier gibt der User Sein Startkapital an welches im double Startkapital gespeichert wird
	if (Startkapital < 0)
	{
		printf("\nBitte gib eine Zahl ein die sich im positiven bereich befindet!\n");
		scanf("%lf", &Startkapital);
	}

	else {
	}
	printf("\nWas ist dein Zinssatz in Prozent? (Nur Zahl angeben!)\n");
	scanf("%lf", &Zinssatz_Dezimal); //Hier gibt der User den Zinssatz an welches im double Zinssatz gespeichert wird
	if
		(Zinssatz_Dezimal < 0)
	{
		printf("\nBitte gib eine Zahl ein die sich im positiven bereich befindet!\n");
		scanf("%lf", &Zinssatz_Dezimal);
	}

	else {
	}
	printf("\nWie oft werden die Zinsen im Jahr ausgezahlt?\n");
	scanf("%d", &Auszahlung); //Hier gibt der User an wie oft die Zinsen ausgezahlt werden
	if
		(Auszahlung < 0)
	{
		printf("\nBitte gib eine Zahl ein die sich im positiven bereich befindet!\n");
		scanf("%d", &Auszahlung);
	}
	else {
	}
	printf("\nUber wie viele Jahre hinweg sollen dir Zinsen ausgezahlt werden?\n");
	scanf("%d", &Zeitraum); //Hier gibt der User zum schluss an wie lange er Zinsen aufs Konto einzahl welche direkt mitberechnet werden
	if
		(Zeitraum < 0)
	{
		printf("\nBitte gib eine Zahl ein die sich im positiven bereich befindet!\n");
		scanf("%d", &Zeitraum);
	}
	else {
	}
	printf("\n1 = Dir wird der Einfache Zins ausgerechnet");
	printf("\n2 = Dir wird der Zusammengesetzte Zins ausgerechnet");
	printf("\n3 = Dir wird der Kontinuierlicher Zins ausgerechnet");
	printf("\n4 = Du kannst deine Werte nochmal ändern");
	printf("\nDeine Wahl: ");
	scanf("%d", &Auswahl);
		Zinssatz_Richtig = Zinssatz_Dezimal / 100; //Hier wird die Dezimalzahl vom Zinssatz zu einer verwendetbaren Zahl verrechnet da 0,01 als 1% in der Formel steht

		switch ((int)Auswahl)
		{
		case 1:
			printf("\nDu hast den einfachen Zins ausgewaehlt\n");
			Ergebnis = Startkapital * ( 1+ Zinssatz_Richtig ) * Zeitraum;
			break;

		case 2:
			printf("\nDu hast den Zusammengesetzten Zins ausgewaehlt\n");
			Ergebnis = Startkapital * pow(1 + Zinssatz_Richtig / Auszahlung, Auszahlung * Zeitraum); //Hier wird Das Startkapital * 1 + Zinssatz / Auszahlung hoch Auszahlung * Zeitraum gerechnet
			break;

		case 3:
			printf("\nDu hast den Kontinuierlichen Zins ausgewaehlt\n");
			Ergebnis = Startkapital * exp(Zinssatz_Richtig * Zeitraum);				
			break;

		case  4:
			printf("\nDu hast die Option zum ändern der Werte gewählt und wirst zum Anfang des Programmes geleitet");
			goto Anfang;
			break;
		}
		gerundet = round(Ergebnis * 100) / 100; //hier iwrd das Ergebnis auf 2 Nachkommastellen gerunded

		printf("\nDein Geld auf dem Konto nach %d Jahren ist %.2f Euro\n", Zeitraum, gerundet);
		return 0;
}
