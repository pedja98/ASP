#pragma once

#include<iostream>
#include<string>
using namespace std;
typedef struct Listovi
{
	int pod;
	Listovi *Otac;
	Listovi ** Sinovi;
	int red;
	int indi;
	Listovi(int redd, int podd)
	{
		Otac = nullptr;
		indi = 0;
		pod = podd;
		red = redd;
		Sinovi = new Listovi*[redd];
		for (int i = 0; i < redd; i++) 
		{
			Sinovi[i] = nullptr;
		}

	}
}List;
