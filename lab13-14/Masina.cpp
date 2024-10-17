#include "Masina.h"

string Medicament::getInmatriculare() const
{
	return denumire;
}

string Medicament::getProducator() const
{
	return producator;
}

string Medicament::getModel() const
{
	return pret;
}

string Medicament::getTip() const
{
	return substantaActiva;
}

void Medicament::setModel(string value)
{
	pret = value;
}

void Medicament::setTip(string value)
{
	substantaActiva = value;
}

bool cmpDenumire(const Medicament& m1, const Medicament& m2)
{
	return m1.getInmatriculare() < m2.getInmatriculare();
}

bool cmpProducator(const Medicament& m1, const Medicament& m2)
{
	return m1.getProducator() < m2.getProducator();
}

bool cmpSubstantaSiPret(const Medicament& m1, const Medicament& m2)
{
	if (m1.getTip() == m2.getTip())
		return m1.getModel() < m2.getModel();
	return m1.getTip() < m2.getTip();
}