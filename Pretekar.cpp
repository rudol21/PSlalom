#include "Pretekar.h"




Pretekar::Pretekar(int pporadieSvR, string ppriezvisko, string pmeno, string pkrajina, int ppocetBodov)
{
	poradieSvR = pporadieSvR;
	priezvisko = ppriezvisko;
	meno = pmeno;
	krajina = pkrajina;
	pocetBodov = ppocetBodov;
}

Pretekar::~Pretekar()
{
}

int Pretekar::getPoradieSvR()
{
	return poradieSvR;
}

string Pretekar::getMeno()
{
	return meno;
}

string Pretekar::getPriezvisko()
{
	return priezvisko;
}

string Pretekar::getKrajina()
{
	return krajina;
}

int Pretekar::getPocetBodou()
{
	return pocetBodov;
}

void Pretekar::setPocetBodov(int prirastok)
{
	pocetBodov = pocetBodov + prirastok;
}
