#include "Pretekar.h"
#include "Preteky.h"



int main(int argc, char * argv[])
{
	Preteky *p = new Preteky();
	p->nacitajPretekarov("suborNaCitanie.txt");
	p->startPretekovPrveKolo();
	p->startPretekovDalsieKola();
	p->startPretekovDalsieKola();
	p->zapisDoSuboru("suborNaZapis.txt");
}