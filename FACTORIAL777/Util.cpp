#include "Factorial.h"

// Transforms the input integer number into char vector that contains one digit in each element
std::vector <char> vectorizator(unsigned long long n) {

	std::vector <char> result;

	while (n > 0) {

		result.push_back(n % 10);
		n = n / 10;
	}

	return result;
}