/*THIS PROGRAM IMPLEMENTS FACTORIAL CALCULATION FOR A VERY BIG NUMBERS USING VECTORS THAT
PRESENT A DIGITS OF NUMBER IN EACH ELEMENT
@author Igor Samoylov
2021
*/

#include "BigFactorialProject.h"

void main()
{
	std::vector <char> output_vector;
	unsigned long long n;
	std::cout << "Enter the number" << std::endl;
	std::cin >> n;
	//TODO: check the number input
	

	//If n < 1301 program will use fast recursion method, else will use more slow cycle 
	if (n < 1301) output_vector = factorial(vectorizator(n));
	
	else output_vector = factorial_iteration_cycle(n); 

	//Removes appeared zeros in a higher bits and provide length reduction for the output vector
	for (size_t i = output_vector.size() - 1; output_vector[i] == 0; --i) { 
		output_vector.resize(output_vector.size() - 1);
	}

	//std::reverse(output_vector.begin(), output_vector.end()); 

	//Reverse ouput vector reading with higher bits in a left
	for (size_t i = output_vector.size(); i > 0; --i) {
		std::cout << (int)output_vector[i - 1];  
	}

	std::cout << std::endl << "Factorial has " << output_vector.size() << " digits!";
	
}


// Transforms the input integer number into char vector that contains one digit in each element
std::vector <char> vectorizator(unsigned long long n) {    

	std::vector <char> result;

	while (n > 0) {

		result.push_back(n % 10);
		n = n / 10;
	}

	return result;
}

// Recursive implementation of Factorial calculating for a big numbers
std::vector <char> factorial(const std::vector <char> n) {  

	std::vector <char> One{ 0b1 };
	//std::vector <char>* One_ptr = &One;

	size_t nullElem = 0;

	//Checks that the all elements in the vector are zero equals
	for (size_t i = 0; i < n.size(); ++i) { if (n[i] == 0) ++nullElem; }   

	//The end of recursion
	if (nullElem == n.size()) return One;      

	//Provide recursive invoke
	return n * factorial(n - One);          

}

//  Returns factorial of a big number using simple iteration cycle
std::vector <char> factorial_iteration_cycle(unsigned long long n) {

	std::vector <char> T{ 0b1 };
	std::vector <char> iter;

	for (unsigned long long k = 1; k < n + 1; ++k) {

		iter = vectorizator(k);
		T = T * iter;

	}
	return T;
}
