#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<char> vectorizator(unsigned long long n);

std::vector<char> factorial(const std::vector <char> n);

std::vector<char> factorial_iteration_cycle(unsigned long long n);

std::vector<char> operator + (std::vector <char> x, std::vector <char> y);

std::vector<char> operator * (const std::vector <char>& x, const std::vector <char>& y);

void operator *= (std::vector <char>& x, std::vector<char>&& y);

std::vector<char> operator - (std::vector <char> x, std::vector <char> y);

