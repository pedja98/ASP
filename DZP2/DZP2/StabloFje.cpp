
#include"Stablo.h"
void Pisi(List* koren)
{
	Stek s;
	s.PUSH(koren);
	List *l;
	int i = 0;
	while (s.Empty() != true)
	{
		l = s.POP();
		//cout << l->pod << " ";
		IspisiMatricu(l->c);
		cout << endl;
		if (l->Sinovi[5-1] != nullptr)
		{
			for (i = 5 - 1; i >= 0; i--)
			{
				s.PUSH(l->Sinovi[i]);
			}
		}
		else if (l->Sinovi[0] != nullptr)
		{
			for (i = 5 - 1; i >= 0; i--)
			{
				if (l->Sinovi[i] != nullptr)
				{
					s.PUSH(l->Sinovi[i]);
				}
			}

		}
		else
		{
			break;
		}

	}
	while (s.Empty() != true)
	{
		l = s.POP();
		IspisiMatricu(l->c);
		cout << endl;
	}
}
void BrisiS(List* koren)
{
	Stek s;
	s.PUSH(koren);
	List *l;
	int i = 0;
	Stek s1;
	while (s.Empty() != true)
	{
		l = s.POP();
		s1.PUSH(l);
		//cout << l->pod << " ";
		if (l->Sinovi[5 - 1] != nullptr)
		{
			for (i = 5 - 1; i >= 0; i--)
			{
				s.PUSH(l->Sinovi[i]);
			}
		}
		else if (l->Sinovi[0] != nullptr)
		{
			for (i = 5 - 1; i >= 0; i--)
			{
				if (l->Sinovi[i] != nullptr)
				{
					s.PUSH(l->Sinovi[i]);
				}
			}

		}
		else
		{
			break;
		}

	}
	while (s.Empty() != true)
	{
		l = s.POP();
		BrisiMatricu(l->c);
		l->Otac = nullptr;
		delete[] l->Sinovi;
		delete l;
	}
	while (s1.Empty() != true)
	{
		l = s1.POP();
		BrisiMatricu(l->c);
		l->Otac = nullptr;
		delete[] l->Sinovi;
		delete l;
	}
	koren = nullptr;
}

List* Ubaci(List *koren, List *pod, int j, char cc)
{
	if (koren == nullptr)
	{
		cout << "Napravite koren" << endl;
	}
	else
	{
		if (koren->Sinovi[0] == nullptr)
		{
			//cout << 1 << endl;
			//koren->Sinovi[0] = pod;
			//pod->Otac = koren;
			if (PopunjenaKolona(koren->c, j) == true)
			{
				
				pod->Otac = koren;
				koren->Sinovi[0] = pod;
				char **c1;
				c1 = NapraviNovuMatricu(koren->c);
				Ubacii(c1, cc, j);
				pod->c = c1;
				pod->Otac = koren;
				koren->Sinovi[0] = pod;
				if (pod->indi != -2)
				{
					pod->pot = 1;
				}
			}
			else
			{
				pod->pot = 1;
				pod->Otac = koren;
				koren->Sinovi[0] = pod;

			}
		}
		else
		{


			Red q;
			q += koren;
			while (q.Empty() != true)
			{
				int i;
				List *pom = q.izbaci();
				if (pom->pot == 0)
				{
					for (i = 0; i < 5; i++)
					{
						if (pom->Sinovi[i] != nullptr)
						{
							q += pom->Sinovi[i];
						}
						else
						{
							if (PopunjenaKolona(koren->c, j) == true)
							{
								
								pod->Otac = pom;
								koren->Sinovi[i] = pom;
								char **c1;
								c1 = NapraviNovuMatricu(pom->c);
								//Ubacii(c1, cc, j);
								pod->c = c1;
								Ubacii(pod->c, cc, j);
								pod->Otac = pom;
								koren->Sinovi[i] = pod;
								if (pod->indi != -2)
								{
									pod->pot = 1;
								}
							}
							else
							{
								pod->pot = 1;
								pod->Otac = pom;
								pom->Sinovi[i] = pod;

							}
							break;
						}
						if (i < 5)
						{
							break;
						}
					}
					
				}
			}

		}
		return koren;
	}
}
