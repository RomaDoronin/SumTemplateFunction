#pragma once

#include "iostream"

using namespace std;


// ��������� ������� �������� ����� ������������� ���������� ��������� ������������� ����
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

// ������� ����������� ���������� ����� �������� ����� 'a' � 'b'
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

// ����� ������������ �����
class Rational
{
private:
	int n; // ���������
	int m; // �����������

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

	// �������� �� �� ��� ����������� �� 0 � ������ �� 1 ��� �������������
	void CheckZero()
	{
		if (m == 0)
			m = 1;
	}

	// �������� �� ������������ �����
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

	// ��������������� ��������� ������
	friend ostream& operator<<(ostream& os, const Rational& dt)
	{
		os << dt.n << '/' << dt.m;
		return os;
	}

	// ��������������� ��������� ��������
	Rational operator+(Rational val)
	{
		CheckZero();
		return Rational(n * val.m + val.n * m, m * val.m);
	}

	// ��������������� ��������� +=
	Rational& operator+=(Rational val)
	{
		CheckZero();
		n = n * val.m + val.n * m;
		m = m * val.m;
		CheckContractilities();
		return *this;
	}

	// ��������������� ��������� ����������
	Rational& operator=(Rational & val)
	{
		CheckZero();
		n = val.n;
		m = val.m;
		CheckContractilities();
		return *this;
	}

	// ��������������� ��������� ���������
	bool operator==(const Rational & val) const
	{
		return((val.n == n) && (val.m == m));
	}
};

