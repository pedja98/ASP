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
		cout << l->pod << " ";
		if (l->Sinovi[koren->red - 1] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
			{
				s.PUSH(l->Sinovi[i]);
			}
		}
		else if (l->Sinovi[0] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
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
		cout << l->pod << " ";
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
		if (l->Sinovi[koren->red - 1] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
			{
				s.PUSH(l->Sinovi[i]);
			}
		}
		else if (l->Sinovi[0] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
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
		l->Otac = nullptr;
		delete[] l->Sinovi;
		delete l;
	}
	while (s1.Empty() != true)
	{
		l = s1.POP();
		l->Otac = nullptr;
		delete[] l->Sinovi;
		delete l;
	}
	koren = nullptr;
}
/*int Visina(List* Koren)
{
	int br = 0;
	Red q;
	q += Koren;
	while (q.Empty() != true)
	{
		List *l;
		l = q.izbaci();
		if (l->Sinovi[0] != nullptr)
		{
			q += l->Sinovi[0];
			br++;
		}
		else
		{
			break;
		}
	}
	return br;
}*/

List* Ubaci(List *koren, List *pod)
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
			koren->Sinovi[0] = pod;
			pod->Otac = koren;
		}
		else
		{
			Red q;
			q += koren;
			while (q.Empty() != true)
			{
				int i;
				List *pom = q.izbaci();
				for (i = 0; i < pod->red; i++)
				{
					if (pom->Sinovi[i] != nullptr)
					{
						q += pom->Sinovi[i];
					}
					else
					{
						pod->Otac = pom;
						pom->Sinovi[i] = pod;
						break;
					}
				}
				if (i < pod->red)
				{
					break;
				}
			}
			while (q.Empty() != true)
			{
				q.izbaci();
			}
		}
	}
	return koren;
}
/*void pisi1(List *koren)
{
	cout << koren->Sinovi[2]->pod;
}*/

int Visina2(List *koren)
{
	int max = koren->indi;
	Stek s;
	s.PUSH(koren);
	List *l;
	int i = 0;
	while (s.Empty() != true)
	{
		l = s.POP();
		if (max < l->indi)
		{
			max = l->indi;
		}
		if (l->Sinovi[koren->red - 1] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
			{
				l->Sinovi[i]->indi = l->indi + 1;
				s.PUSH(l->Sinovi[i]);
			}
		}
		else if (l->Sinovi[0] != nullptr)
		{
			for (i = koren->red - 1; i >= 0; i--)
			{
				if (l->Sinovi[i] != nullptr)
				{
					l->Sinovi[i]->indi = l->indi + 1;
					s.PUSH(l->Sinovi[i]);
				}
			}

		}
		else
		{
			break;
		}

	}
	return max;
}