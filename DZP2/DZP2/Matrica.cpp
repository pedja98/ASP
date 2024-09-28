#include"Matrice.h"
char** KreirajMatricu()
{
	char **c = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		c[i] = new char[5];
		for (int j = 0; j < 5; j++)
		{
			c[i][j] = ' ';
		}
	}
	return c;
}


void IspisiMatricu(char **c)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (c[i][j] == ' ')
			{
				cout << "_" << " ";
			}
			else
			{
				cout << c[i][j] << " ";
			}
		}
		cout << endl;
	}
}
bool PopunjenaKolona(char **c, int jj)
{
	if (c[0][jj] == ' ')
	{
		return true; // Ima praznog mesta
	}
	else
	{
		return false;
	}
}
bool PobedaPoKoloni(char **c, char chr)
{
	int i1, i2, i3;
	int j; bool b = false;
	for (j = 0; j < 5; j++)
	{
		i1 = 0; i2 = 1; i3 = 2;
		for (; i3 < 5; i3++, i2++, i1++)
		{
			if (c[i1][j] == c[i2][j] && c[i2][j] == c[i3][j] && c[i3][j] == chr)
			{
				b = true;
				break;
			}
		}
		if (b == true)
		{
			break;
		}
	}
	return b;
}

bool PobedaPoVrsti(char **c, char chr)
{
	int i1, i2, i3;
	int j; bool b = false;
	for (j = 0; j < 5; j++)
	{
		i1 = 0; i2 = 1; i3 = 2;
		for (; i3 < 5; i3++, i2++, i1++)
		{
			if (c[j][i1] == c[j][i2] && c[j][i2] == c[j][i3] && c[j][i3] == chr)
			{
				b = true;
				break;
			}
		}
		if (b == true)
		{
			break;
		}
	}
	return b;
}

bool PoDijag1(char **c, char chr)
{
	bool  b = false;
	int i1 = 0, i2 = 1, i3 = 2, j1 = 2, j2 = 1, j3 = 0;
	for (; i3 < 5; i3++, i2++, i1++)
	{
		j1 = 2; j2 = 1; j3 = 0;
		int br = 1;
		while (br < 4)
		{
			br++;
			if (c[i1][j1] == c[i2][j2] && c[i2][j2] == c[i3][j3] && c[i3][j3] == chr)
			{
				b = true;
				break;
			}
			j1++; j2++; j3++;
		}
		if (b == true)
		{
			break;
		}
	}
	return b;
}

bool PoDijag2(char **c, char chr)
{
	bool b = false;
	int i1 = 0, i2 = 1, i3 = 2, j1 = 0, j2 = 1, j3 = 2;
	for (; i3 < 5; i3++, i2++, i1++)
	{
		j1 = 0; j2 = 1; j3 = 2;
		int br = 1;
		while (br < 4)
		{
			br++;
			if (c[i1][j1] == c[i2][j2] && c[i2][j2] == c[i3][j3] && c[i3][j3] == chr)
			{
				b = true;
				break;
			}
			j1++; j2++; j3++;
		}
		if (b == true)
		{
			break;
		}
	}
	return b;
}
void BrisiMatricu(char **c)
{
	for (int i = 0; i < 5; i++)
	{
		delete c[i];
	}
	delete[] c;
}

bool Pobeda(char **c, char chr)
{
	if (PobedaPoKoloni(c, chr) == true)
	{
		return true;
	}
	else if (PobedaPoVrsti(c, chr) == true )
	{
		return true;
	}
	else if (PoDijag1(c, chr) == true )
	{
		return true;
	}
	else if (PoDijag2(c, chr) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Nereseno(char **c)
{
	bool b = true;
	for (int i = 0; i < 5; i++)
	{
		if (c[0][i] == ' ')
		{
			b = false;
			break;
		}
	}
	return b;

}
char **Ubacii(char **c, char chr, int jj)
{
	if (jj >= 0)
	{
		for (int i = 4; i > -1; i--)
		{
			if (c[i][jj] == ' ')
			{
				c[i][jj] = chr;
				break;
			}
		}
	}
	return c;
}
char **NapraviNovuMatricu(char **c)
{
	char **c1 = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		c1[i] = new char[5];
		for (int j = 0; j < 5; j++)
		{
			c1[i][j] = c[i][j];
		}
	}
	return c1;
}
bool VratiVrstu(char **c, int jj)
{
	int i;
	bool b = false;
	for (i = 0; i < 5; i++)
	{
		if (c[i][jj] != ' ')
		{
			b = true;
			break;
		}
	}
	return b;
}

char **UbaciNaPocetak(char **c, char chr, int jj)
{
	if (jj > 0)
	{
		int i;
		for (i = 0; i <5; i++)
		{
			if (c[i][jj] != ' ')
			{
				c[i][jj] = chr;
				break;
			}
		}
		c[i-1][jj] = chr;
	}
	return c;
}