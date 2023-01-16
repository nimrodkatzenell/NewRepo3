#include <iostream>
using namespace std;
//q1
int reverseNum(int num, int* countOdd);
int tu(int t);
//returns the size of the number for exapmple 123 will return 100


//q2
int maxSequence(int num);
int sum(int num);//returns the amount of numbers at the end
int dif(int num);//example-->>1122 will return 11
bool doub(int num, int sum0);//will return true if sum0 is the biggest combo in the number

//q3
bool smallestDigit(int num);
int op(int num);
int zop(int num);

int main()
{
	//q1
	int countOdd = 0, num = 12345;
	cout << "q1\n" << reverseNum(num, &countOdd);
	cout << endl << countOdd << endl;
	//q2
	cout << "\nq2\n" << maxSequence(111154522) << endl;
	//q3
	cout << "\nq3\n" << smallestDigit(4327);

}


//q2
int maxSequence(int num)
{


	if (num <= 0)
	{
		return 1;
	}
	if (!doub(num, sum(num)))
	{

		return  maxSequence(dif(num));
	}
	else
	{
		return sum(num);

	}
}
bool doub(int num, int sum0)
{
	if (num <= 0)
	{
		return true;
	}
	else
	{
		int x = sum(dif(num));
		if (x <= sum0)
		{

			return doub(dif(num), sum0);
		}
		else
		{
			return false;
		}
	}


}
int sum(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num % 10 == num / 10 % 10)
	{
		return 1 + sum(num / 10);
	}
	else
	{
		return 1;
	}
}
int dif(int num)
{
	if (num % 10 == num / 10 % 10)
	{
		return dif(num / 10);
	}
	else
	{
		return num / 10;
	}

}


//q1
int reverseNum(int num, int* countOdd)
{


	if (num <= 0)
	{
		return 0;
	}
	else
	{
		if (num % 2 != 0)
		{
			*countOdd += num % 10;

		}
		int a = tu(num);
		int c = num % 10;
		int d = a * c;

		return d + reverseNum(num / 10, countOdd);

	}

}

int tu(int t)
{
	if (t < 10)
	{
		return 1;
	}
	else
	{
		return 10 * tu(t / 10);
	}

}


//q3
int op(int num)
{
	if (num / 10 == 0)
	{
		return num;
	}
	else
	{
		return op(num / 10);
	}
}
int zop(int num)
{
	if (num <= 10)
	{
		return 1;
	}
	else
	{
		return 10 * zop(num / 10);

	}

}
bool smallestDigit(int num)
{
	if (num <= 0)
	{
		return true;
	}

	if (num % 10 > op(num))
	{
		return false;
	}
	else
	{
		return smallestDigit(num % zop(num));
	}


}
