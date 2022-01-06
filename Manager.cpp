#include "Manager.h"
using namespace std;

istream& operator>> (istream& is, Manager& l)
{
	char c;
	is >> c;
	if (is) {
		if (c == 'c' || c == 'C')
			is >> l.mcash;
		else if (c == 'b' || c == 'B')
			is >> l.mbank;
		else if (c == 'a' || c == 'A')
			is >> l.mothers;
	}
	return is;
}

void Manager::print_cash(ostream& os) const
{
	os << "---- cash ----\n";
	mcash.show(os);
}

void Manager::print_bank(ostream &os) const
{
	os << "---- bank ----\n";
	mbank.show(os);
}

void Manager::print_others(ostream &os) const
{
	os << "---- others ----\n";
	mothers.show(os);
}

int Manager::total() const
{
	return mcash.sum() + mbank.sum() + mothers.sum();
}

ostream& operator<< (ostream& os, const Manager& l)
{
	os << "===========================\n";
	os << "cash  : " << l.mcash.sum() << endl;
	os << "bank  : " << l.mbank.sum() << endl;
	os << "others: " << l.mothers.sum() << endl;
	os << "---------------------------\n";
	os << "total : " << l.total() << endl;
	os << "===========================\n";
	return os;
}
