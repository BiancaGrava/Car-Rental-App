#include "Validator.h"

ostream& operator<<(ostream& out, const ValidateException& ex) {
	for (const auto& msg : ex.msgs) {
		out << msg << " ";
	}
	return out;
}

void Validator::validate(const Medicament& m)
{
	vector<string> erori;

	if (m.getInmatriculare().length() != 7)
		erori.push_back("Numarul de inmatriculare este nevalid! se cer numere de Romania: <BH11ABC> <B111BIA>\n");
	if (!(m.getInmatriculare()[0] <= 'Z' && m.getInmatriculare()[0] >= 'A' && m.getInmatriculare()[1] <= 'Z' && m.getInmatriculare()[1] >= 'A'))
	{
		if ((m.getInmatriculare()[0] == 'B') && (m.getInmatriculare()[2] >= '0' && m.getInmatriculare()[2] <= '9' && m.getInmatriculare()[1] >= '0' && m.getInmatriculare()[1] <= '9' && m.getInmatriculare()[3] >= '0' && m.getInmatriculare()[3] <= '9'))
			;

		else
			erori.push_back("Numarul de inmatriculare este nevalid! se cer numere de Romania: <BH11ABC> <B111BIA>\n");
	}
	else {
		if (!(m.getInmatriculare()[2] >= '0' && m.getInmatriculare()[2] <= '9' && m.getInmatriculare()[3] >= '0' && m.getInmatriculare()[3] <= '9'))
			erori.push_back("Numarul de inmatriculare este nevalid! se cer numere de Romania: <BH11ABC> <B111BIA>\n");
	}
	if (!(m.getInmatriculare()[4] <= 'Z' && m.getInmatriculare()[4] >= 'A' && m.getInmatriculare()[5] <= 'Z' && m.getInmatriculare()[5] >= 'A' && m.getInmatriculare()[6] <= 'Z' && m.getInmatriculare()[6] >= 'A'))
		erori.push_back("Numarul de inmatriculare este nevalid! se cer numere de Romania: <BH11ABC> <B111BIA>\n");
	if (m.getProducator().length() == 0)
		erori.push_back("Nume de producator nevalid!\n");
	if (m.getModel().length() == 0)
		erori.push_back("Introduceti un model nevid!\n");
	if (m.getTip().length() == 0)
		erori.push_back("Introduceti un tip nevid!\n");

	if (erori.size() > 0)
	{
		throw ValidateException(erori);
	}
}