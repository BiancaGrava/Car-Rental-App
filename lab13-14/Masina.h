#pragma once
#include <string>
using std::string;

class Medicament
{
private:
	string denumire;
	string producator;
	string pret;
	string substantaActiva;

public:
	/* Getter pentru denumire */
	string getInmatriculare() const;

	/* Getter pentru producator */
	string getProducator() const;

	/* Getter pentru pret */
	string getModel() const;

	/* Getter pentru cantitatea de substanta activa */
	string getTip() const;

	/* Setter pentru pret */
	void setModel(string value);

	/* Setter pentru cantitatea de substanta activa */
	void setTip(string value);

	/* Constructor */
	Medicament(const string denumire, const string producator, const string pret, const string substantaActiva) :denumire{ denumire }, producator{ producator }, pret{ pret }, substantaActiva{ substantaActiva } {}

};

/* Compara denumirile a doua medicamente si returneaza true daca sunt in ordine alfabetica */
bool cmpDenumire(const Medicament& m1, const Medicament& m2);

/* Compara producatorii a doua medicamente si returneaza true daca sunt in ordine alfabetica */
bool cmpProducator(const Medicament& m1, const Medicament& m2);

/* Compara substanta activa si pretul a doua medicamente */
bool cmpSubstantaSiPret(const Medicament& m1, const Medicament& m2);