#include "Export.h"
#include "Repository.h"

void exportToCSV(const string& filename, const vector<Medicament>& meds)
{
	ofstream fout(filename, ios::trunc);
	if (!fout.is_open())
	{
		throw RepositoryException{ "Eroare la deschiderea fisierului!" };
	}

	for (const auto& med : meds)
	{
		fout << med.getInmatriculare() << ", ";
		fout << med.getProducator() << ", ";
		fout << med.getModel() << ", ";
		fout << med.getTip() << '\n';
	}

	fout.close();
}

void exportToHTML(const string& filename, const vector<Medicament>& meds)
{
	int count = 0;
	ofstream fout(filename, ios::trunc);
	if (!fout.is_open())
	{
		throw RepositoryException{ "Eroare la deschiderea fisierului!" };
	}

	fout << "<html><body>" << "\n";
	fout << "<table border=\"1\" bgcolor = #cc0000 style=\"width: 100% \">" << "\n";

	fout << "<tr bgcolor = #ff4d4d>" << "\n";
	fout << "<td>" << " <b> NR </b> " << "</td>" << "\n";
	fout << "<td>" << " <b> NR INMATRICULARE </b> " << "</td>" << "\n";
	fout << "<td>" << " <b> PRODUCATOR </b> " << "</td>" << "\n";
	fout << "<td>" << " <b> MODEL </b> " << "</td>" << "\n";
	fout << "<td>" << " <b> TIP </b> " << "</td>" << "\n";
	fout << "</tr>" << "\n";

	for (const auto& med : meds)
	{
		count++;
		fout << "<tr bgcolor = #ffcccc text-align=center>" << "\n";
		fout << "<td>" << count << "</td>" << "\n";
		fout << "<td>" << med.getInmatriculare() << "</td>" << "\n";
		fout << "<td>" << med.getProducator() << "</td>" << "\n";
		fout << "<td>" << med.getModel() << "</td>" << "\n";
		fout << "<td>" << med.getTip() << "</td>" << "\n";
		fout << "</tr>" << "\n";
	}

	fout << "</table>" << "\n";
	fout << "</body></html>" << "\n";
	fout.close();
}