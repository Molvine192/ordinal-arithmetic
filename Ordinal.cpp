#include "Ordinal.hpp"

// empty ordinal (0)
Ordinal::Ordinal() {}

// finite number
Ordinal::Ordinal(unsigned int n) {
	if (n == 0)
		return;

	Term t;
	t.beta = std::make_unique<Ordinal>(0u);
	t.coeff = n;
	terms.push_back(std::move(t));
}

// static metod for w^beta * coeff
Ordinal Ordinal::omega_power(Ordinal beta, unsigned int coeff) {
	if (coeff == 0) // w^beta * 0 = 0 (empty ordinal)
		return Ordinal();

	Ordinal result;

	Term t;
	t.beta = std::make_unique<Ordinal>(std::move(beta));
	t.coeff = coeff;

	result.terms.push_back(std::move(t));

	return result;
}

// boolean operators
bool Ordinal::operator<(const Ordinal& other) const {
	size_t size_this = terms.size();
	size_t size_other = other.terms.size();
	size_t size = std::min(size_this, size_other);
	for (size_t i = 0; i < size; i++)
	{
		if (terms[i] < other.terms[i]) return true;
		if (other.terms[i] < terms[i]) return false;
	}
	return size_this < size_other;
}

bool Ordinal::operator==(const Ordinal& other) const {
	if (terms.size() != other.terms.size()) return false;
	for (size_t i = 0; i < terms.size(); i++)
	{
		if (terms[i] < other.terms[i] || other.terms[i] < terms[i]) return false;
	}
	return true;
}

bool Ordinal::operator!=(const Ordinal& other) const {
	return !(*this == other);
}

// arithmetic operators
Ordinal Ordinal::operator+(const Ordinal& other) const {
	return Ordinal();
}

Ordinal Ordinal::operator*(const Ordinal& other) const {
	return Ordinal();
}

//stringify for debbuging
std::string Ordinal::to_string() const {
	if (terms.empty())
		return "0";

	std::string result = "";


	for (size_t i = 0; i < terms.size(); i++)
	{
		if (i > 0)
			result += " + ";

		const auto& term = terms[i];

		bool has_w = !term.beta->terms.empty();

		if (has_w)
			result += "w^(" + term.beta->to_string() + ")";

		if (has_w)
		{
			if (term.coeff != 1)
				result += "*" + std::to_string(term.coeff);
		}
		else
			result += std::to_string(term.coeff);
	}

	return result;
}