#include"Red.h"
void Red::Brisi()
{
	elem *tek;
	while (front)
	{
		tek = front;
		tek->l = nullptr;
		front = front->sled;
		delete tek;
	}
	rear = nullptr;
}
void Red::Premesti(Red &s)
{
	front = s.front;
	rear = s.rear;
	s.front = s.rear = nullptr;
}
void Red::Kopiraj(const Red &s)
{
	elem *tek = s.front;
	while (tek)
	{
		if (front == nullptr)
		{
			front = rear = new elem(tek->l);
		}
		else
		{
			elem *p = new elem(tek->l);
			rear->sled = p;
			rear = rear->sled;
		}
		tek->sled;
	}
}


