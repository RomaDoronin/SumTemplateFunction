#pragma once

#include "iostream"

using namespace std;


// Шаблонная функция подсчета суммы произвольного количества элементов произвольного типа
template <typename T>
T SumOfElement(T *arr, int Size)
{
	T sum = {};

	for (int i = 0; i < Size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

// Функция вычисляющая наибольший общий делитель чисел 'a' и 'b'
int NOD(int a, int b)
{
	a = abs(a);
	b = abs(b);

	while (a > 0 && b > 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}

	return a + b;
}

// Класс рациональных чисел
class Rational
{
private:
	int n; // Числитель
	int m; // Знаменатель

public:
	Rational() : n(0), m(1)
	{}

	Rational(int _n, int _m)
	{
		n = _n;
		if (_m == 0)
			m = 1;
		else
			m = _m;
		CheckContractilities();
	}

	// Проверка на то что знаменатель не 0 и замена на 1 при необходимости
	void CheckZero()
	{
		if (m == 0)
			m = 1;
	}

	// Проверка на сократимость дроби
	void CheckContractilities()
	{
		int _nod = NOD(n, m);

		if (n > 0 && m > 0)
			if (_nod != 1)
			{
				n /= _nod;
				m /= _nod;
			}
	}

	void SetRational(int _n, int _m)
	{
		n = _n;
		if (_m == 0)
			m = 1;
		else
			m = _m;
		CheckContractilities();
	}

	// Переопределение оператора вывода
	friend ostream& operator<<(ostream& os, const Rational& dt)
	{
		os << dt.n << '/' << dt.m;
		return os;
	}

	// Переопределение оператора сложения
	Rational operator+(Rational val)
	{
		CheckZero();
		return Rational(n * val.m + val.n * m, m * val.m);
	}

	// Переопределение оператора +=
	Rational& operator+=(Rational val)
	{
		CheckZero();
		n = n * val.m + val.n * m;
		m = m * val.m;
		CheckContractilities();
		return *this;
	}

	// Переопределение оператора присвоения
	Rational& operator=(Rational & val)
	{
		CheckZero();
		n = val.n;
		m = val.m;
		CheckContractilities();
		return *this;
	}

	// Переопределение оператора сравнения
	bool operator==(const Rational & val) const
	{
		return((val.n == n) && (val.m == m));
	}
};

