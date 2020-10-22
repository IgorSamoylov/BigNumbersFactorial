#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <short int> operator + (const vector <short int> &v1, const vector <short int> &v2) // Функция перегружает штатный оператор сложения для использования с векторами
{
	
	
	vector <short int> x, y, result;
	x = v1; y = v2; 
	if (x.size() > y.size()) swap(x, y);  // Длина вектора y всегда максимальна
	x.insert(x.end(), y.size() - x.size(), 0); // Дополняем вектор x до длины вектора y нулями в конце

	for (size_t i = 0; i < y.size(); ++i) {

		result.push_back(x [i] + y [i]);           // Простое сложение элементов векторов

	}
	
short int k;

size_t Logic;
	do                                            // Поиск переполненных разрядов и перенос в старший разряд
	{
	   for (size_t i = 0; i < result.size(); ++i) {

	        k = result [i];
	        
			if (k > 9) {

	             result [i] = k % 10;
				 if (i < result.size() - 1) result[i + 1] += k / 10;
	             else result.emplace(result.end(), k / 10); // Дополняем результирующий вектор новым разрядом в конце
	        }
	    }
	    Logic = 0;
	    for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] < 10) ++Logic;            // Тестируем, чтобы во всем результирующем векторе не было неперенесенных разрядов больше 9
	    }
	
	}
	while (Logic < result.size() - 1);

return result;
}



vector <short int> operator * (const vector <short int> &x, const vector <short int> &y)     // Функция перегружает штатный оператор умножения для использования с векторами
{
	vector <short int> term_one, term_two;
	
	for (size_t i = 0; i < x.size(); ++i) {

		for (size_t k = 0; k < y.size(); ++k) {
		
			term_one.push_back(x[i] * y[k]);     //Наполняем вектор текущей суммы умножением каждого разряда
		
		}

		term_one.insert(term_one.begin(), i, 0); // Добавляем нули в начало вектора текущей суммы для сдвига
		term_two = term_one + term_two;          // Сложение двух векторов перегруженным оператором +
		term_one.clear();                        // Очистка вектора текущей суммы
	}

return term_two;
}

vector <short int> operator - (const vector <short int> &v1, const vector <short int> &v2) { // Перегруженный оператор вычитания для поразрядных векторов чисел

vector <short int> x, y, result;

x = v1; y = v2;

if (x.size() < y.size()) swap(x, y); // // Длина вектора x всегда максимальна

y.insert (y.end(), x.size() - y.size(), 0); // Добавляем нули в конец вектора к меньшему числу до длины большего

	for (size_t i = 0; i < x.size(); ++i) {
	   
			result.push_back(x[i] - y[i]);             //Простое вычитание векторов по элементам, дающее отрицательные значения в некоторых случаях
	}

size_t Logic = 0;
	                            // Поиск отрицательных значений и последовательный перенос единиц из старших разрядов
	while (Logic < result.size() - 1 ) {

		for (size_t i = 0; i < result.size(); ++i) {

			if (result [i] < 0 && i < result.size() - 1 ) {result [i + 1] -= 1; result [i] += 10;}				
		}

		Logic = 0;	                                          //Проверка на наличие отрицательных значений
		for (size_t i = 0; i < result.size(); ++i) {

			if (result [i] >= 0) Logic++;
		
		}
	}

return result;
}




vector <short int> Vectorizator(short int n) {    //Функция преобразует входящее натуральное число в вектор по разрядам

vector <short int> result;

		while (n > 0) {

			result.push_back (n % 10);
			n = n / 10;
		}

return result;
}



vector <short int> Factorial(const vector <short int> n) {  //Факториал через рекурсию. Работает на порядки!!! быстрее обычного цикла.

	vector <short int> One = { 1 };

	size_t null = 0;

	for (size_t i = 0; i < n.size(); ++i) { if (n [i] == 0) ++null;}   // Проверка всех элементов на равенство нулю
	
	if (null == n.size()) return One;      // Конец рекурсии

	return n * Factorial (n - One);            //Рекурсивная функция факториала!

}


vector <short int> Factorial_easy (short int n) { //Факториал через цикл

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
	
	
		//if (n < 2501) output_vector = Factorial (Vectorizator(n)); // До 2500 расчет быстрым методом рекурсии, больше - медленным, но бесконечным циклом
		//else output_vector = Factorial_easy (n);
	
	

	for (short int i = output_vector.size() - 1; output_vector [i] == 0; --i) {  //Удаление образующихся нулей в старших разрядах, сокращение длины вектора

			output_vector.resize (output_vector.size() - 1);

			}

	reverse(output_vector.begin(), output_vector.end()); // Разворачиваем вектор для чтения старшими разрядами сначала

	for (size_t i = 0; i < output_vector.size(); ++i) {

		cout << output_vector[i] << " ";                  // Выводим в поток вектор результата
	}

	cout << endl << "Factorial has " << output_vector.size() << " digits!";


	return 0;
}
