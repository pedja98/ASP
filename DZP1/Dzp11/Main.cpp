#include"Stablo.h"
void main()
{
	try
	{
		int m;
		while (1)
		{
			cout << "Unesite red stabla::";
			cin >> m;
			if (m >= 2)
			{
				break;
			}
			else
			{
				cout << "Greska red stabla treba da bude veci ili jednak 2 ,pokusajte ponovo" << endl << endl;
			}
		}
		char c;

		int i = 0;
		int j = 0;
		while (1)
		{
			j = 0;
			i = 0;
			int p;
			cout << "Kreirajte stablo uneste vrednost korena::" << endl;
			cin >> p;
			List *Koren = new List(m, p);
			while (1)
			{
				cout << "Unesite slovo da bi odabrali jednu od operacija" << endl;
				cout << "K ubaci novi cvor u stablo\nV odredi visinu stabla\nP pisi stablo\nB brisi stablo\nTek posle brisanja stabla moze da se kreira novo, biranje karaktera koji nije definisan oznacava kraj rada  " << endl;
				cin >> c;
				if (c != 'K' && c != 'V' &&c != 'P' && c != 'B')
				{
					i = 1;
					break;
				}
				else
				{
					switch (c)
					{
					case 'P': { cout << "Stablo " << endl; Pisi(Koren); cout << " " << endl; cout << " " << endl; break; };
					case 'K': {

						int pp;
						cout << "Kreirajte list dodelite mu podatak::" << endl;
						cin >> pp;
						List *l = new List(m, pp);
						Ubaci(Koren, l);
						break;
					}
					case 'B':
					{
						BrisiS(Koren);
						j = 1;
						break;
					}
					case 'V':
					{
						cout << "Visina stabla je::" << Visina2(Koren) << endl;
						break;
					}
					}
				}
				if (j == 1)
				{
					break;
				}
				if (i == 1)
				{
					break;
				}
			}
			if (i == 1)
			{
				BrisiS(Koren);
				break;
			}
		}
		

	}
	catch (bad_alloc)
	{
		cout << "Greska pri alokaciji" << endl;
	}
	cout << "" << endl;
	cout << "Kraj programa" << endl;
	system("Pause");
}
