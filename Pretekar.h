#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
class Pretekar
{
	int poradieSvR;
	string priezvisko;
	string meno;
	string krajina;
	int pocetBodov;
public:
	Pretekar(int poradieSvR, string priezvisko, string meno, string krajina, int pocetBodov);
	~Pretekar();
	int getPoradieSvR();
	string getMeno();
	string getPriezvisko();
	string getKrajina();
	int getPocetBodou();
	void setPocetBodov(int prirastok);


};

