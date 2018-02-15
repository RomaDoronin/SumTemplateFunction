#include "gtest\gtest.h"
#include "Rational_plus_func.h"

// Для удобного заполнения массива по умолчанию
void IntArrInitVal(int *arr, size_t Size)
{
	for (int i = 0; i < Size; i++)
		arr[i] = i;
}

// Сумма ряда натуральных чисел
int SumNumOfN(int n)
{
	return ( ((n+1) * n) / 2);
}

/*------------------------------------------------------------------------------------------*/
TEST(Different_Types, IntSum)
{
	const size_t intSize = 7;
	int intArr[intSize] = {8, 6, 6, 2, 4, 7, 5};

	EXPECT_EQ(38, SumOfElement(intArr, intSize));
}

TEST(Different_Types, DoubleSum)
{
	const size_t doubleSize = 7;
	double doubleArr[doubleSize] = { 6.2, 2.4, 8.5, 7.9, 6.3, 5.0, 1.4 };

	EXPECT_EQ(37.699999999999996, SumOfElement(doubleArr, doubleSize));
}

TEST(Different_Types, FloatSum)
{
	const size_t floatSize = 7;
	float floatArr[floatSize] = { 6.5f, 8.4f, 0.7f, 4.2f, 3.0f, 2.5f, 1.0f };

	EXPECT_EQ(26.3f, SumOfElement(floatArr, floatSize));
}

TEST(Different_Types, RationalSum)
{
	const size_t rationalSize = 3;

	Rational rationalArr[rationalSize] = { Rational(2, 3), Rational(5, 10), Rational(6, 5) };

	EXPECT_EQ(Rational(71, 30), SumOfElement(rationalArr, rationalSize));
}

/*------------------------------------------------------------------------------------------*/
TEST(Different_Size, SmallSize)
{
	const size_t intSize = 10;
	int intArr[intSize];
	IntArrInitVal(intArr, intSize);

	EXPECT_EQ(SumNumOfN(intSize - 1), SumOfElement(intArr, intSize));
}

TEST(Different_Size, MiddleSize)
{
	const size_t intSize = 30;
	int intArr[intSize];
	IntArrInitVal(intArr, intSize);

	EXPECT_EQ(SumNumOfN(intSize - 1), SumOfElement(intArr, intSize));
}

TEST(Different_Size, BigSize)
{
	const size_t intSize = 50;
	int intArr[intSize];
	IntArrInitVal(intArr, intSize);

	EXPECT_EQ(SumNumOfN(intSize - 1), SumOfElement(intArr, intSize));
}

/*------------------------------------------------------------------------------------------*/

