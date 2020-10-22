#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <short int> operator + (const vector <short int> &v1, const vector <short int> &v2) // ������� ����������� ������� �������� �������� ��� ������������� � ���������
{
	
	
	vector <short int> x, y, result;
	x = v1; y = v2; 
	if (x.size() > y.size()) swap(x, y);  // ����� ������� y ������ �����������
	x.insert(x.end(), y.size() - x.size(), 0); // ��������� ������ x �� ����� ������� y ������ � �����

	for (size_t i = 0; i < y.size(); ++i) {

		result.push_back(x [i] + y [i]);           // ������� �������� ��������� ��������

	}
	
short int k;

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



vector <short int> operator * (const vector <short int> &x, const vector <short int> &y)     // ������� ����������� ������� �������� ��������� ��� ������������� � ���������
{
	vector <short int> term_one, term_two;
	
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

vector <short int> operator - (const vector <short int> &v1, const vector <short int> &v2) { // ������������� �������� ��������� ��� ����������� �������� �����

vector <short int> x, y, result;

x = v1; y = v2;

if (x.size() < y.size()) swap(x, y); // // ����� ������� x ������ �����������

y.insert (y.end(), x.size() - y.size(), 0); // ��������� ���� � ����� ������� � �������� ����� �� ����� ��������

	for (size_t i = 0; i < x.size(); ++i) {
	   
			result.push_back(x[i] - y[i]);             //������� ��������� �������� �� ���������, ������ ������������� �������� � ��������� �������
	}

size_t Logic = 0;
	                            // ����� ������������� �������� � ���������������� ������� ������ �� ������� ��������
	while (Logic < result.size() - 1 ) {

		for (size_t i = 0; i < result.size(); ++i) {

			if (result [i] < 0 && i < result.size() - 1 ) {result [i + 1] -= 1; result [i] += 10;}				
		}

		Logic = 0;	                                          //�������� �� ������� ������������� ��������
		for (size_t i = 0; i < result.size(); ++i) {

			if (result [i] >= 0) Logic++;
		
		}
	}

return result;
}




vector <short int> Vectorizator(short int n) {    //������� ����������� �������� ����������� ����� � ������ �� ��������

vector <short int> result;

		while (n > 0) {

			result.push_back (n % 10);
			n = n / 10;
		}

return result;
}



vector <short int> Factorial(const vector <short int> n) {  //��������� ����� ��������. �������� �� �������!!! ������� �������� �����.

	vector <short int> One = { 1 };

	size_t null = 0;

	for (size_t i = 0; i < n.size(); ++i) { if (n [i] == 0) ++null;}   // �������� ���� ��������� �� ��������� ����
	
	if (null == n.size()) return One;      // ����� ��������

	return n * Factorial (n - One);            //����������� ������� ����������!

}


vector <short int> Factorial_easy (short int n) { //��������� ����� ����

vector <short int> T = {1};
vector <short int> iter (1);

	for (short int k = 1; k < n + 1; ++k) {

		iter = Vectorizator (k);
		T = T * iter; 

	}
return T;	
}


short int main()
{
	vector <short int> vector1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector <short int> vector2 = { 9, 9, 9, 9, 9, 9, 6, 8 };
	vector <short int> output_vector;
	short int n;
	cout << "Enter the number" << endl;
	cin >> n;
	output_vector = Factorial (Vectorizator(n)); 
	//catch (const std::string &str) {
	//output_vector = Factorial_easy(n); 
	//output_vector = vector1 - vector2;
	
	
		//if (n < 2501) output_vector = Factorial (Vectorizator(n)); // �� 2500 ������ ������� ������� ��������, ������ - ���������, �� ����������� ������
		//else output_vector = Factorial_easy (n);
	
	

	for (short int i = output_vector.size() - 1; output_vector [i] == 0; --i) {  //�������� ������������ ����� � ������� ��������, ���������� ����� �������

			output_vector.resize (output_vector.size() - 1);

			}

	reverse(output_vector.begin(), output_vector.end()); // ������������� ������ ��� ������ �������� ��������� �������

	for (size_t i = 0; i < output_vector.size(); ++i) {

		cout << output_vector[i] << " ";                  // ������� � ����� ������ ����������
	}

	cout << endl << "Factorial has " << output_vector.size() << " digits!";


	return 0;
}
