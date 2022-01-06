#pragma once
#include "Account.h"
#include <iostream>

class Manager
{
public:
	Manager() : mcash{}, mbank{}, mothers{} {}

	void print_cash(std::ostream &os = std::cout) const;
	void print_bank(std::ostream &os = std::cout) const;
	void print_others(std::ostream &os = std::cout) const;

	int total() const;

	friend std::istream& operator>> (std::istream& is, Manager& l);
	friend std::ostream& operator<< (std::ostream& os, const Manager& l);

private:
	Account mcash;
	Account mbank;
	Account mothers;
};
