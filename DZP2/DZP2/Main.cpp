#include"Stablo.h"
#include<iostream>
using namespace std;
void main()
{
	while (1)
	{
		int ee=0;
		char **c, c1, c2;
		int randBr;
		int j;
		int k = 0;
		srand(time(0));
		randBr = rand() % 25 + 1;
		c = KreirajMatricu();

		cout << randBr << endl;
		if (randBr % 2 != 0)
		{
			c1 = 'P';
			c2 = 'C';
			cout << "Igrac 1 je dobio plavu boju, a igrac 2 crvenu" << endl;
		}
		else
		{
			c1 = 'C';
			c2 = 'P';
			cout << "Igrac 1 je dobio crvenu boju, a igrac 2 plavu" << endl;
		}

		//cout << "Pocetno stanje igre" << endl;
		//cout << "---------------------------" << endl;

		int i = 0;
		while (i < randBr)
		{

			if (i % 2 == 0)
			{
				while (1)
				{
					cout << "Unesite kolonu u koju zelite da stavite zeton" << endl;
					cin >> j;
					if (j > -1 and j < 5 and PopunjenaKolona(c, j) == true)
					{
						Ubacii(c, c1, j);
						break;
					}
					cout << "Uneli ste nevalidan podatak pokusajte ponovo. Postoji mogucnost dda je data kolona popunjena " << endl << endl;
				}
				i++;
			}
			else
			{
				while (1)
				{
					cout << "Unesite kolonu u koju zelite da stavite zeton" << endl;
					cin >> j;
					if (j > -1 and j < 5 and PopunjenaKolona(c, j) == true)
					{
						Ubacii(c, c2, j);
						break;
					}
					cout << "Uneli ste nevalidan podatak pokusajte ponovo. Postoji mogucnost dda je data kolona popunjena" << endl << endl;
				}
				i++;
			}
			if (Pobeda(c, c1) == true)
			{
				k = 1;
				cout << "Prvi igrac je pobedio" << endl;
				break;

			}
			else if (Pobeda(c, c2) == true)
			{
				k = 1;
				cout << "Drugi igrac je pobedio" << endl;
				break;
			}
			else if (Nereseno(c) == true)
			{
				k = 1;
				cout << "Nereseno je" << endl;
				break;
			}
			else
			{
				
			}
		}

		cout << "Pocetno stanje igre" << endl;
		cout << "---------------------------" << endl;
		IspisiMatricu(c);

		cout << "---------------------------" << endl;

	
		/*List *koren = new List(c);
		List *pom = new List(c);
		Ubaci(koren, pom, koren->c, 2, 'a');
		Pisi(koren);*/
		if (k == 0)
		{
			while (1)
			{
			    ee = 0;
				i = randBr;
				int y = 1;
				List *koren = new List(c);
				char cc;
				if (i % 2 == 0)
				{
					cc = c1;
				}
				else
				{
					cc = c2;
				}
				int ix = 0;
				while (i < 25)
				{
					
				    
					if (ix+1 % 5 == 0)
					{
						cc = c1;
					}
					else
					{
						cc = c2;
					}
					char c3;

					cout << "Unesite karakter da bi odradili jednu od ponudjenih akcija" << endl;
					cout<<"U za umetanje cvora\nB za brisanje stabla\nP za pisanje stabla\nAko odaberete opciju brisanje pocetno stanje se brise i kreira se novo"<<endl;
					cin >> c3;
					switch (c3)
					{
					case 'U':
					{
						i++;
						while (1)
						{
							cout << "Unesite kolonu u koju zelite da stavite zeton" << endl;
							cin >> j;
							if (j > -1 and j < 5 and PopunjenaKolona(c, j) == true)
							{
								List *l = new List(c);
								Ubaci(koren, l, j, cc);
								if (Pobeda(l->c, cc) == true)
								{
									l->pot = 0;
									if (cc=c1)
									{
										l->indi = 1;
										cout << "U ovom slucaju igrac 1 pobedjuje" << endl;
									}
									else if (cc = c2)
									{
										l->indi = -1;
										cout << "U ovom slucaju igrac 2 pobedjuje" << endl;
									}
									else if (Nereseno(l->c))
									{
										l->indi = -1;
										cout << "U ovom slucaju je nereseno pobedjuje" << endl;
									}

								}
								break;
							}
							cout << "Uneli ste nevalidan podatak pokusajte ponovo." << endl << endl;
						}

						break;
					}
					case 'B':
					{
						ee = 1;
						BrisiS(koren);
						break;
					}
					case'P':
					{
						Pisi(koren);
						break;
					}
					}
					
					if (ee == 1)
					{
						break;
					}
					if (i == 25)
					{
						y = 0;
					}
				}
				if(y==0)
				{
					BrisiS(koren);
					break;
				}
				if (ee == 1)
				{
					break;
				}
			}
			
		}
		if (ee == 0)
		{
			char o;
			cout << "Ukoliko zelite da prekine igru pritisnite 1" << endl;
			cin >> o;
			if (o == '1')
			{
				break;
			}
		}
	}
	system("Pause");
}