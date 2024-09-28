#pragma once
#include"Matrice.h"
typedef struct Listovi
{
	char **c;
	//int vrsta, kolona;
	Listovi *Otac;
	Listovi ** Sinovi;
	int indi;
	char igrac;
	int pot;
	int j;
	Listovi(char **cc,int jj=-2)
	{
		Otac = nullptr;
		Sinovi = new Listovi*[5];
		for (int i = 0; i < 5; i++)
		{
			Sinovi[i] = nullptr;
		}
		//vrsta = kolona = -1;
		c = cc;
		indi = -2;
		//igrac = ' ';
		pot = 1;
		j = jj;
		//prim = 1;
	}
}List;