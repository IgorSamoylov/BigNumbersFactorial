/*
	* This programm implements factorial calculation for a big integer numbers.
*/

#include "Factorial.h"

void main()
{
	std::vector <char> output_vector;
	unsigned long long n;
	std::cout << "Enter the number" << std::endl;
	std::cin >> n;
	
	//If n < 1301 programm will use fast recursion method, else will use more slow cycle 
	if (n < 1301) output_vector = factorial(vectorizator(n));
	
	else output_vector = factorial_iteration_cycle(n); 

	//Removes appeared zeros in a higher bits and provide length reduction for the output vector
	for (size_t i = output_vector.size() - 1; output_vector[i] == 0; --i) { 
		output_vector.resize(output_vector.size() - 1);
	}

	// Reverse output vector with higher bits to left for reading
	std::reverse(output_vector.begin(), output_vector.end()); 

	// Print result
	std::for_each(output_vector.begin(), output_vector.end(),
		[](char x) { std::cout << (int)x;  });

	std::cout << "\nFactorial has " << output_vector.size() << " digits.";

	std::cin >> n; // Enter positive integer number to close console window
}
