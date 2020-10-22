#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> operator + (const vector <char> &v1, const vector <char> &v2) // ������� ����������� ������� �������� �������� ��� ������������� � ���������
{
	
	
	vector <char> x, y, result;
	x = v1; y = v2; 
	if (x.size() > y.size()) swap(x, y);  // ����� ������� y ������ �����������
	x.insert(x.end(), y.size() - x.size(), 0); // ��������� ������ x �� ����� ������� y ������ � �����

	for (size_t i = 0; i < y.size(); ++i) {
	result.push_back(x [i] + y [i]);           // ������� �������� ��������� ��������
	}
	
int k;
size_t Logic;
	do                                            // ����� ������������� �������� � ������� � ������� ������
	{
	   for (size_t i = 0; i < result.size(); ++i) {

	        k = result [i];
	        
			if (k > 9) {
	             result [i] = k % 10;
				 if (i < result.size() - 1) result[i + 1] += k / 10;
	             else result.emplace(result.end(), k / 10); // ��������� �������������� ������ ����� �������� � �����
	        }
	    }
	    Logic = 0;
	    for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] < 10) ++Logic;            // ���������, ����� �� ���� �������������� ������� �� ���� �������������� �������� ������ 9
	    }
	
	}
	while (Logic < result.size() - 1);

return result;
}



vector <char> operator * (const vector <char> &x, const vector <char> &y)     // ������� ����������� ������� �������� ��������� ��� ������������� � ���������
{
	vector <char> term_one, term_two;
	
	for (size_t i = 0; i < x.size(); ++i) {
		for (size_t k = 0; k < y.size(); ++k) {
		
			term_one.push_back(x[i] * y[k]);     //��������� ������ ������� ����� ���������� ������� �������
		
		}
		term_one.insert(term_one.begin(), i, 0); // ��������� ���� � ������ ������� ������� ����� ��� ������
		term_two = term_one + term_two;          // �������� ���� �������� ������������� ���������� +
		term_one.clear();                        // ������� ������� ������� �����
	}
return term_two;
}

vector <char> operator - (const vector <char> &v1, const vector <char> &v2) { // ������������� �������� ��������� ��� ����������� �������� �����

vector <char> x, y, result;

x = v1; y = v2;

y.insert(y.end(), x.size() - y.size(), 0); // ��������� ���� � ����� ������� � �������� ����� �� ����� ��������

	for (size_t i = 0; i < v1.size(); ++i) {   
	result.push_back(x[i] - y[i]);             //������� ��������� �������� �� ���������, ������ ������������� �������� � ��������� �������
	}

size_t Logic = 0;	                            // ����� ������������� �������� � ���������������� ������� ������ �� ������� ��������
	while (Logic < result.size() - 1) {
		for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] < 0) {
				if (i < result.size() - 1 || result [i + 1] > 0) {result [i + 1] -= 1; result [i] += 10;}				
				else {result.erase (result.end() + 1); result[i] += 10;}
				}
			}
		Logic = 0;	                                          //�������� �� ������� ������������� ��������
		for (size_t i = 0; i < result.size(); ++i) {
		if (result [i] >= 0) Logic++;
		}
	}
return result;
}




vector <char> Vectorizator(int n) {    //������� ����������� �������� ����������� ����� � ������ �� ��������

vector <char> result;

while (n > 0) {
			result.push_back (n % 10);
		n = n / 10;
		}
return result;
}



vector <char> Factorial(vector <char> n) {  //��������� ����� ��������. �������� �� �������!!! ������� �������� �����.

	vector <char> One = { 1 };

	size_t null = 0;
	for (size_t i = 0; i < n.size(); ++i) { if (n [i] == 0) ++null;}   // �������� ���� ��������� �� ��������� ����
	
	if (null == n.size()) return One;      // ����� ��������

	return n * Factorial (n - One);            //����������� ������� ����������!

}


vector <char> Factorial_easy (int n) { //��������� ����� ����

vector <char> T = {1};
vector <char> iter (1);

	for (int k = 1; k < n + 1; ++k) {

		iter = Vectorizator (k);
	T = T * iter; 

	}
return T;	
}


int main()
{
	vector <char> vector1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector <char> vector2 = { 0, 2, 3, 4, 5, 6, 7, 8 };
	vector <char> output_vector;
	int n;
	cout << "Enter the number" << endl;
	cin>> n;
	//output_vector = vector1 - vector2;
	//output_vector = Factorial_easy (n);
	output_vector = Factorial (Vectorizator(n));
	reverse(output_vector.begin(), output_vector.end());
	for (size_t i = 0; i < output_vector.size(); ++i) {
		cout << cout.setf(ios::dec) << output_vector[i] << " ";
	}
	//cout << endl << "Factorial has " << output_vector.size() << " digits!";

	cin>>n;
	return 0;
}
