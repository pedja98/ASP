#include"Stek.h"

void Stek::BrisiSS()
{
	elemS *tek;
	while (top)
	{
		tek = top;
		tek->l = nullptr;
		top = top->pred;
		delete tek;
	}
}
void Stek::PremestiSS(Stek & s)
{
	top = s.top;
	s.top = nullptr;
}
void Stek::KopirajSS(const Stek &s)
{
	elemS *tek = s.top;
	while (tek)
	{
		elemS *p = new elemS(tek->l);
		this->PUSH(p->l);
		tek = tek->pred;
	}
}