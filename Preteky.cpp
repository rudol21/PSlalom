#include "Preteky.h"
#include <time.h>


Preteky::Preteky()
{
	srand(time(NULL));
}


Preteky::~Preteky()
{
}

void Preteky::nacitajPretekarov(const char * menoSuboru)
{
	ifstream cin(menoSuboru);
	int poradieSvR;
	string priezvisko;
	string meno;
	string krajina;
	int pocetBodov;

	while (cin >> poradieSvR >> priezvisko >> meno >> krajina >> pocetBodov)
	{
		zoznamPretekarov.push_back(new Pretekar(poradieSvR, priezvisko, meno, krajina, pocetBodov));
	}
}

void Preteky::startPretekovPrveKolo()
{
	int pocet = zoznamPretekarov.size();
	//vector<int> rozlosovanie;
	int generovanyCas1 = 0;
	int generovanyCas2 = 0;
	vector<int> pole;
	
	for (int i = 0; i < pocet; i++)
	{
		pomZoznamPretekarov.push_back(i);
	}
	random_shuffle(pomZoznamPretekarov.begin(), pomZoznamPretekarov.end());
	
	

	int i = -1;
	while(i < pocet-1)
	{
		
		generovanyCas1 = rand() % 10;
		generovanyCas1 = generovanyCas1 + 30;
		generovanyCas2 = rand() % 10;
		generovanyCas2 = generovanyCas2 + 30;
		if (generovanyCas1 < generovanyCas2)
			pole.push_back(i + 2);
		if (generovanyCas1 > generovanyCas2)
			pole.push_back(i + 1);
		if (generovanyCas1 == generovanyCas2)
		{
			if(zoznamPretekarov[pomZoznamPretekarov[i + 1]]->getPocetBodou() < zoznamPretekarov[pomZoznamPretekarov[i + 2]]->getPocetBodou())
				pole.push_back(i + 1);
			else
				pole.push_back(i + 2);
		}

		i++;
		cout << zoznamPretekarov[pomZoznamPretekarov[i]]->getPriezvisko() << " " << zoznamPretekarov[pomZoznamPretekarov[i]]->getMeno() << " ("<< generovanyCas1 << ") " << " : "   ;
		i++;
		cout << zoznamPretekarov[pomZoznamPretekarov[i]]->getPriezvisko() << " " << zoznamPretekarov[pomZoznamPretekarov[i]]->getMeno() << " ("<< generovanyCas2 << ") " << ":" << endl  ;

		
	}
	cout << endl;
	for (int i = pole.size()-1; i >= 0; i--)
	{		
		pomZoznamPretekarov.erase(pomZoznamPretekarov.begin() + pole[i]);
	}



}

void Preteky::startPretekovDalsieKola()
{

	int pocet = pomZoznamPretekarov.size();
	int generovanyCas1 = 0;
	int generovanyCas2 = 0;
	vector<int> pole;

	if (pocet == 4)//pripisovanie bodov
	{
		zoznamPretekarov[pomZoznamPretekarov[0]]->setPocetBodov(40);
		zoznamPretekarov[pomZoznamPretekarov[1]]->setPocetBodov(40);
		zoznamPretekarov[pomZoznamPretekarov[2]]->setPocetBodov(40);
		zoznamPretekarov[pomZoznamPretekarov[3]]->setPocetBodov(40);
	}

	int i = -1;
	while (i < pocet - 1)
	{
		generovanyCas1 = rand() % 10;
		generovanyCas1 = generovanyCas1 + 30;
		generovanyCas2 = rand() % 10;
		generovanyCas2 = generovanyCas2 + 30;
		if (generovanyCas1 < generovanyCas2)
			pole.push_back(i + 2);
		if (generovanyCas1 > generovanyCas2)
			pole.push_back(i + 1);
		if (generovanyCas1 == generovanyCas2)
		{
			if (zoznamPretekarov[pomZoznamPretekarov[i + 1]]->getPocetBodou() < zoznamPretekarov[pomZoznamPretekarov[i + 2]]->getPocetBodou())
				pole.push_back(i + 1);
			else
				pole.push_back(i + 2);
		}
		i++;
		cout << zoznamPretekarov[pomZoznamPretekarov[i]]->getPriezvisko() << " " << zoznamPretekarov[pomZoznamPretekarov[i]]->getMeno() << " (" << generovanyCas1 << ") " << " : ";
		i++;
		cout << zoznamPretekarov[pomZoznamPretekarov[i]]->getPriezvisko() << " " << zoznamPretekarov[pomZoznamPretekarov[i]]->getMeno() << " (" << generovanyCas2 << ") " << endl;
	}
	cout << endl;

	if (pocet == 2) //pripisovanie bodov
	{
		if (pole[0] == 0)
		{
			zoznamPretekarov[pomZoznamPretekarov[0]]->setPocetBodov(10);			
			zoznamPretekarov[pomZoznamPretekarov[1]]->setPocetBodov(60);
		}
		else
		{
			zoznamPretekarov[pomZoznamPretekarov[1]]->setPocetBodov(10);
			zoznamPretekarov[pomZoznamPretekarov[0]]->setPocetBodov(60);
		}
		
	}

	for (int i = pole.size()-1; i >= 0; i--)
	{
		pomZoznamPretekarov.erase(pomZoznamPretekarov.begin() + pole[i]);
	}
	

	
}

bool wayToSort(Pretekar *s1, Pretekar *s2) { return s1->getPocetBodou() > s2->getPocetBodou(); };

void Preteky::zapisDoSuboru(const char * menoSuboru)
{
	sort(zoznamPretekarov.begin(), zoznamPretekarov.end(), wayToSort);
	fstream zapisovac(menoSuboru);
	
	int poradieSvR;
	string priezvisko;
	string meno;
	string krajina;
	int pocetBodov;
	

	for (int i = 0; i < zoznamPretekarov.size(); ++i)
	{
		poradieSvR = zoznamPretekarov[i]->getPoradieSvR();
		priezvisko = zoznamPretekarov[i]->getPriezvisko();
		meno = zoznamPretekarov[i]->getMeno();
		krajina = zoznamPretekarov[i]->getKrajina();
		pocetBodov = zoznamPretekarov[i]->getPocetBodou();
		zapisovac << poradieSvR << priezvisko << meno << krajina << pocetBodov << endl;
	}
}
