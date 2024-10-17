#include "Repository.h"

ostream& operator<<(ostream& out, const RepositoryException& ex)
{
	out << ex.eroare;
	return out;
}

Repo::Repo(double errorPercentage)
{
	error = errorPercentage;
}

double Repo::getErrorPercentage() const
{
	return error;
}

Medicament Repo::findMed(string denumire) const
{
	auto it = meds.find(denumire);
	if (it == meds.end())
		throw RepositoryException("Nu exista medicamentul cautat!");
	else
		return it->second;
}

bool Repo::exist(const Medicament& m) const
{
	try
	{
		Medicament med = findMed(m.getInmatriculare());
		return true;
	}
	catch (RepositoryException&)
	{
		return false;
	}
}

auto Repo::getPozitie(const Medicament& m) const
{
	return meds.find(m.getInmatriculare());
}

void Repo::add(const Medicament& m)
{
	if (exist(m))
	{
		throw RepositoryException("Medicamentul pe care doriti sa il adaugati exista deja!");
	}
	meds.insert(pair<string, Medicament>(m.getInmatriculare(), m));
	notify();
}

void Repo::modify(const Medicament& m, int camp)
{
	if (exist(m) == false)
		throw RepositoryException("Medicamentul pe care doriti sa il modificati nu exista!");

	Medicament med = findMed(m.getInmatriculare());
	if (camp == 1)
	{
		med.setModel(m.getModel());
		meds.insert_or_assign(m.getInmatriculare(), med);
	}

	if (camp == 2)
	{
		med.setTip(m.getTip());
		meds.insert_or_assign(m.getInmatriculare(), med);
	}

	if (camp == 3)
	{
		med.setModel(m.getModel());
		med.setTip(m.getTip());
		meds.insert_or_assign(m.getInmatriculare(), med);
	}
	notify();
}

void Repo::del(const Medicament& m)
{
	if (exist(m) == false)
		throw(RepositoryException("Nu exista medicamentul pe care doriti sa il stergeti!"));

	auto it = getPozitie(m);
	meds.erase(it);
	notify();
}

vector<Medicament> Repo::getMeds()
{
	vector<Medicament> vect;
	vect.reserve(meds.size());
	std::transform(meds.begin(), meds.end(), back_inserter(vect), [](pair<string, Medicament> const& pair) { return pair.second; });
	return vect;
}

// Reteta:

void Reteta::addReteta(const Medicament& m)
{
	reteta.push_back(m);
	notify();
}

void Reteta::stergeInReteta(const Medicament& m)
{
	int poz = getPozitieReteta(m);
	if (poz == -1)
	{
		throw RepositoryException{ "Medicamentul nu exista!" };
	}
	reteta.erase(reteta.begin() + poz);
	notify();
}

void Reteta::clearAll()
{
	reteta.clear();
	notify();
}

vector<Medicament> Reteta::getReteta()
{
	return reteta;
}

Medicament Reteta::findMed(const string& denumire)
{
	Medicament med{ denumire, "Producator", "Model", "Tip"};
	int poz = getPozitieReteta(med);
	if (poz == -1)
		throw RepositoryException("Nu exista medicamentul dorit!");
	return reteta[poz];
}

size_t Reteta::sizeReteta() const
{
	return reteta.size();
}

int Reteta::getPozitieReteta(const Medicament& m) const
{
	int poz = 0;
	for (const auto& med : reteta)
	{
		if (m.getInmatriculare() == med.getInmatriculare())
			return poz;
		poz++;
	}
	return -1;
}