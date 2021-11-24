// LAB-6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// LAB_06_1.cpp
// Сушинський Ігор
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом.
// Варіант 18

#include <iostream>
#include <iomanip>
#include <ctime> // аналог time.h в мові C
#include <cstdlib> // заголовок стандартної бібліотеки загального призначення

using namespace std;

void Random(int* r, int n, int a, int b)
{
	for (int i = 0; i < n; i++) // i - додаткова змінна
		r[i] = rand() % (b - a + 1) + a;
}

int Count(int* r, int n) // функція обчислення к-ті елементів
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (r[i] % 2 != 0 || r[i] % 7 == 0)
			count++;
	return count;
}

int Sum(int* r, int n) // функція обчислення суми елементів
{
	int S = 0;
	for (int i = 0; i < n; i++)
		if (r[i] % 2 != 0 || r[i] % 7 == 0)
			S += r[i];
	return S;
}

void Replace(int* r, int n) // функція заміни нюлями цих елементів
{
	for (int i = 0; i < n; i++)
		if (r[i] % 2 != 0 || r[i] % 7 == 0)
			r[i] = 0;
}

void Print(int* r, int n) // форматне виведення
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << r[i] << " ";
	cout << "\n";
}

int main()
{
	srand((unsigned)time(0));

	const int n = 26; // поточна розмірність масиву n = 1..26
	int r[n]; // заданий масив
	int a = 3, b = 92; // діапазон

	Random(r, n, a, b);
	Print(r, n);

	cout << "count = " << Count(r, n) << "\n";
	cout << "S = " << Sum(r, n) << "\n";

	Replace(r, n);
	Print(r, n);

	return 0;
}