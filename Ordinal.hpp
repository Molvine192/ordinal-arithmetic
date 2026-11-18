#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Ordinal {
public:
	// term structure (CNF)
	struct Term {
		std::unique_ptr<Ordinal> beta; // exponent
		unsigned int coeff;            // coefficient

		bool operator<(const Term& other) const {
			if (*beta != *(other.beta)) return *beta < *(other.beta); // compare exponents first
			return coeff < other.coeff;
		}

		bool operator==(const Term& other) const {
			return *beta == *(other.beta) && coeff == other.coeff;
		}
	};

private:
	// terms in descending order
	std::vector<Term> terms;

public:
	// empty ordinal (0)
	Ordinal();
	// finite number
	Ordinal(unsigned int n);
	
	// static metod for w^beta * coeff
	static Ordinal omega_power(Ordinal beta, unsigned int coeff = 1);

	// boolean operators
	bool operator<(const Ordinal& other) const;
	bool operator==(const Ordinal& other) const;
	bool operator!=(const Ordinal& other) const;

	// arithmetic operators
	Ordinal operator+(const Ordinal& other) const;
	Ordinal operator*(const Ordinal& other) const;

	//stringify for debbuging
	std::string to_string() const;
};