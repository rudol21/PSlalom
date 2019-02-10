#pragma once
#include "Pretekar.h"

class Preteky
{
	vector <Pretekar*> zoznamPretekarov;
	vector <int> pomZoznamPretekarov;
public:
	Preteky();
	~Preteky();
	void nacitajPretekarov(const char* menoSuboru);
	void startPretekovPrveKolo();
	void startPretekovDalsieKola();
	void zapisDoSuboru(const char* menoSuboru);
};

