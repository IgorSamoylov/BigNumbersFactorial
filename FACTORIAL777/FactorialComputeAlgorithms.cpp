#include "Factorial.h"

// Basic contants for counting
const std::vector <char> One{ 0b1 };
const std::vector <char>* One_ptr = &One;

// Recursive implementation of Factorial calculating for a big numbers
std::vector <char> factorial(const std::vector <char> n) {

	size_t nullElem = 0;

	//Checks that the all elements in the vector are zero equals
	for (size_t i = 0; i < n.size(); ++i) { if (n[i] == 0) ++nullElem; }

	//The end of recursion
	if (nullElem == n.size()) return *One_ptr;

	//Provide recursive invoke
	return n * factorial(n - *One_ptr);

}

//  Returns factorial of a big number using simple iteration cycle
std::vector <char> factorial_iteration_cycle(unsigned long long n) {

	std::vector <char> T{ 0b1 };

	for (unsigned long long k = 1; k < n + 1; ++k) {

		T *= vectorizator(k);
	}
	return T;
}