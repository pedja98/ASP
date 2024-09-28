#pragma once

#include"Listovi.h"
class Red
{
private:
	struct elem
	{
		List *l;
		struct elem*sled;
		elem(List *ll)
		{
			//l = new List(ll->red, ll->pod);
			l = ll;
			sled = nullptr;
		}
	};
	void Brisi();
	void Premesti(Red &s);
	void Kopiraj(const Red &s);
	elem *front = nullptr, *rear = nullptr;
public:
	Red() = default;
	~Red()
	{
		Brisi();
	}
	Red(Red &&s)
	{
		Premesti(s);
	}
	Red(const Red &s)
	{
		Kopiraj(s);
	}
	Red& operator=(Red &&r)
	{
		if (this != &r)
		{
			Brisi();
			Premesti(r);
		}
		return *this;
	}
	Red& operator=(Red const &r)
	{
		if (this != &r)
		{
			Brisi();
			Kopiraj(r);
		}
		return *this;
	}
	Red& operator+=(List *ll)
	{
		if (front == nullptr)
		{
			front = rear = new elem(ll);
		}
		else
		{
			elem *p = new elem(ll);
			rear->sled = p;
			rear = rear->sled;
		}
		return *this;
	}
	List *izbaci()
	{
		if (front != nullptr)
		{
			elem *pod;
			pod = front;
			front = front->sled;
			List *l = pod->l;
			delete pod;
			if (front == nullptr)
			{
				rear = front;
			}
			return l;
		}
		else
		{
			cout << "Red je prazan" << endl;
		}
	}
	bool Empty() const
	{
		if (front == nullptr)
		{
			return true;
		}
		else
			return false;
	}
};