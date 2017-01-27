// Bwinf_Landnahme.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h" //vorkompilierter Header
#include <iostream> //Ein-/Ausgabe
#include <vector>   //Vektorbefehle
#include <cstdlib>  //System("...")-Befehle



int Anzahl;											//Anzahl der zu testenden Grundstücke
int xCoord1, yCoord1, xCoord2, yCoord2;				//Koordinaten der Punkte
int breite, hoehe;									//Breite und Höhe der Grundstücke
std::vector<int> X, Y;								//Alle X- / Y-Koordinaten eines Rechtecks
char Feld[100][100] = { 0 };					    //Das Feld
bool erlaubt = true;	

void Berechnung()
{
	/*VARIABLEN*/

	erlaubt = true;
	breite = xCoord2 - xCoord1;	//Breite des Rechtecks berechnen
	hoehe = yCoord2 - yCoord1;	//Höhe des Rechtecks berechnen
	int breitenCheck = xCoord1;
	int hoehenCheck = yCoord1;


	/*X UND Y VECTOR BERECHNEN*/

	for (xCoord1; breitenCheck <= xCoord2; breitenCheck++)
	{
		X.push_back(breitenCheck);
	}

	for (yCoord1; hoehenCheck <= yCoord2; hoehenCheck++)
	{
		Y.push_back(hoehenCheck);
	}


	/*ÜBERPRÜFUNG OB ÜBERLAPPUNG VORLIEGT*/

	for (int i = 0; i < X.size(); i++)
	{
		int x = X[i];

		for (int i = 0; i < Y.size(); i++)
		{
			int y = Y[i];

			if (Feld[y][x] == '+' && Feld[y - 1][x] == '+' && Feld[y][x - 1] == '+' && Feld[y + 1][x] == '+' && Feld[y][x + 1] == '+') //damit die Grenzen nicht als Sperre gelten
			{
				erlaubt = false;
			}


		}
	}
	/*SPEICHERN DER BELEGTEN PUNKTE*/
	if (erlaubt == true)
	{
		for (int j = xCoord1; j <= xCoord2; j++)
		{
			for (int i = yCoord1; i <= yCoord2; i++)
			{
				Feld[i][j] = '+';
			}
		}
	}
}


void Ausgabe()
{

	//system("cls");

	for (unsigned int i(0); i != 20; ++i)
	{
		for (unsigned int j(0); j != 20; ++j)
		{
			std::cout << Feld[i][j] << " "; // Elemente einer "Arrayzeile" nebeneinander ausgeben
		}
		std::cout << "\n"; // Jede neue "Arrayzeile" in neuer Zeile ausgeben
	}
}
int _tmain(int argc, _TCHAR* argv[])
{	
	std::cout << "Wie viele Grundstuecke moechten Sie anlegen?\n";
	
	std::cin >> Anzahl;
	
	system("cls");

	for (Anzahl > 0; Anzahl--;)
	{
		
		std::cout << "---------------------2\n"
			<< "l--------------------l\n"
			<< "l--------------------l\n"
			<< "1---------------------\n\n";
		std::cout << "Bitte geben Sie nacheinander die (ganzzahligen) Koordinaten der Punkte 1/2 ein. (x,y <= 100) \n";
		
		std::cin >> xCoord1
			>> yCoord1
			>> xCoord2
			>> yCoord2;
		
		
		Berechnung();
		
		std::cout <<"Punkt 1: (" << xCoord1 << "/"
			 << yCoord1 << ")\nPunkt 2: ("
			 << xCoord2 << "/"
			 << yCoord2 << ")\n"
			 <<"Breite: " << breite <<"\n Hoehe: "
			 << hoehe << "\n";
			 std::cout<< "\n";
		
			 if (erlaubt == true)
		{
			std::cout << "Claim akzeptiert!\n";
		}
		
		if (erlaubt == false )
		{
			std::cout << "Claim abgelehnt!\n";
		}
		
		Ausgabe();

		X.clear();
		Y.clear();
		
		system("pause");
	}
	return 0;
}

