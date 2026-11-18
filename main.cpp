#include "Ordinal.hpp"

int main() {
	Ordinal one(1u);
	Ordinal two(2u);
	Ordinal five(5u);
	Ordinal omega = Ordinal::omega_power(Ordinal(1u));
	Ordinal omega_5 = Ordinal::omega_power(Ordinal(1u), 5);
	Ordinal two_omega_omega = Ordinal::omega_power(Ordinal::omega_power(Ordinal(1u)), 2);
	
	std::cout << "One: " << one.to_string() << "\n";
	std::cout << "Two: " << two.to_string() << "\n";
	std::cout << "Five: " << five.to_string() << "\n";
	std::cout << "Omega: " << omega.to_string() << "\n";
	std::cout << "5 omega: " << omega_5.to_string() << "\n";
	std::cout << "2 omega^omega: " << two_omega_omega.to_string() << "\n\n";

	std::cout << "Five < One: " << (five < one ? "true" : "false") << "\n";
	std::cout << "Two < Omega: " << (two < omega ? "true" : "false") << "\n";
	std::cout << "Omega == 5 omega: " << (omega == omega_5 ? "true" : "false") << "\n";
	std::cout << "Omega < 2 omega^omega: " << (omega < two_omega_omega ? "true" : "false") << "\n";
}