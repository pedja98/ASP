#pragma once

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char** KreirajMatricu();



void IspisiMatricu(char **c);
bool PopunjenaKolona(char **c, int jj);
bool PobedaPoKoloni(char **c, char chr);

bool PobedaPoVrsti(char **c, char chr);

bool PoDijag1(char **c, char chr);

bool PoDijag2(char **c, char chr);
void BrisiMatricu(char **c);

bool Pobeda(char **c, char chr);
bool Nereseno(char **c);
char **Ubacii(char **c, char chr, int jj);
char **UbaciNaPocetak(char **c, char chr, int jj);
bool VratiVrstu(char **c, int jj);
char **NapraviNovuMatricu(char **c);