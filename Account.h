#pragma once
#include <vector>
#include <iostream>
#include <string>

class Money
{
public:
	Money() : mvalue{}, myear{}, mmonth{}, mdate{}, mmemo{} {}
	Money(const Money& other)
	{
		mvalue = other.mvalue;
		myear = other.myear;
		mmonth = other.mmonth;
		mdate = other.mdate;
		mmemo = other.mmemo;
	}

	int value() const { return mvalue; }
	int year() const { return myear; }
	int month() const { return mmonth; }
	int date() const { return mdate; }

	friend std::istream& operator>> (std::istream& is, Money& r);
	friend std::ostream& operator<< (std::ostream& os, const Money& r);

private:
	int mvalue;
	int myear;
	int mmonth;
	int mdate;
	std::string mmemo;
};

class Account
{
public:
	Account() {}

	void add(Money m) { mmoney.push_back(m); }
	void show(std::ostream& os = std::cout) const
	{
		for (auto& money : mmoney)
		{
			if (money.value() != 0)
				os << money << std::endl;
		}
	}

	int sum() const
	{
		int sum = 0;
		for (auto& money : mmoney) { sum += money.value(); }
		return sum;
	}

	friend std::istream& operator>> (std::istream& is, Account& r);
	friend std::ostream& operator<< (std::ostream& os, const Account& r);

private:
	std::vector<Money> mmoney;	// 収入・支出の集まり
};
