#include "Account.h"
using namespace std;

// value yyyy/mm/dd
istream& operator>> (istream& is, Money& r)
{
	is >> r.mvalue;
	is >> r.myear;
	char c1;
	if (is >> c1 && c1 == '/') {
		is >> r.mmonth;
		if (is >> c1 && c1 == '/') {
			is >> r.mdate;
			if (is.get(c1) && c1 != '\n') {
				const int buffer_size = 50;
				char buffer[buffer_size];
				is.getline(buffer, buffer_size);
				r.mmemo = string(buffer);
			}
		}
	}
	return is;
}

ostream& operator<< (ostream& os, const Money& r)
{
	// 収入なら "+" を前に付ける
	os << ((r.mvalue > 0) ? "+" : "");
	os << r.mvalue << "\t" << r.myear << "/";
	if (r.mmonth < 10)
		os << "0";
	os << r.mmonth << "/";
	if (r.mdate < 10)
		os << "0";
	os << r.mdate;
	if (r.mmemo.size() != 0)
		os << " " << r.mmemo;

	return os;
}

istream& operator>> (istream& is, Account& r)
{
	Money m{};
	is >> m;
	r.add(m);
	return is;
}

ostream& operator<< (ostream& os, const Account& r)
{
	os << r.sum();
	return os;
}
