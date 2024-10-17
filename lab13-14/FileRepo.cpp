#include "FileRepo.h"

#include<sstream>
#include<fstream>

using std::stringstream;
using std::ifstream;
using std::ofstream;

void FileRepo::loadFromFile()
{

	ifstream file(this->filename);
	if (!file.is_open())
		throw RepositoryException{ "Eroare la deschiderea fisierului:" };
	string line;
	while (getline(file, line)) {
		stringstream linestream(line);
		string denumire, producator, model, tip;
		int itn = 0;
		string itc;
		while (getline(linestream, itc, ',')) {
			if (itn == 0) denumire = itc;
			if (itn == 1) producator = itc;
			if (itn == 2) model = itc;
			if (itn == 3) tip = itc;
			itn++;
		}
		Medicament p{ denumire, producator, model, tip };
		Repo::add(p);
	}
	file.close();
}

void FileRepo::storeToFile()
{
	ofstream fout(filename);
	if (!fout.is_open())
	{
		throw RepositoryException{ "Eroare la deschiderea fisierului!" };
	}

	for (const auto& med : getMeds())
	{
		fout << med.getInmatriculare() << ",";
		fout << med.getProducator() << ",";
		fout << med.getModel() << ",";
		fout << med.getTip() << "\n";
	}

	fout.close();
}

void FileRepo::add(const Medicament& m)
{
	Repo::add(m);
	storeToFile();
}

void FileRepo::modify(const Medicament& m, int camp)
{
	Repo::modify(m, camp);
	storeToFile();
}

void FileRepo::del(const Medicament& m)
{
	Repo::del(m);
	storeToFile();
}

void FileRepo::meds()
{
	storeToFile();
}