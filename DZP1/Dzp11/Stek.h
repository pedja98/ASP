#pragma once

#include"Listovi.h"
class Stek
{
private:
	struct elemS {

		List *l;
		struct elemS *pred;
		elemS(List *ll)
		{
			//l = new List(ll->red,ll->pod);
			l = ll;
			pred = nullptr;
		}

	};
	elemS *top = nullptr;
	void BrisiSS();
	void PremestiSS(Stek & s);
	void KopirajSS(const Stek &);
public:
	Stek() = default;
	~Stek()
	{
		BrisiSS();
	}
	Stek(const Stek& s)
	{
		KopirajSS(s);
	}
	Stek(Stek&& s)
	{
		PremestiSS(s);
	}

	Stek& operator=(const Stek& s)
	{

		if (this != &s)
		{
			BrisiSS();
			KopirajSS(s);
		}
		return *this;
	}
	Stek& operator=(Stek &&s)
	{
		if (this != &s)
		{
			BrisiSS();
			PremestiSS(s);
		}
		return *this;
	}
	Stek& PUSH(List *l)
	{
		elemS *p = new elemS(l);
		p->pred = top;
		top = p;
		return *this;
	}
	List* POP()
	{
		if (top == nullptr)
		{
			cout << "Stek je prazan" << endl;
		}
		else
		{
			List *ll = top->l;
			elemS *pod = top;
			top = top->pred;
			delete pod;
			return ll;
		}
	}
	bool Empty() const
	{
		if (top == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
