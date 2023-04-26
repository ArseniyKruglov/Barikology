#include <iostream>

using namespace std;



bool IsPrime(int Number)
{
	for (int i = 2; i < Number; i++)
		if (Number % i == 0)
			return false;

	return true;
}

void IsPrime(int Number, bool *Result)
{
	*Result = true;

	for (int i = 2; i < Number; i++)
		if (Number % i == 0)
		{
			*Result = false;
			break;
		};
}

void IsPrime(int Number, bool &Result)
{
	Result = true;

	for (int i = 2; i < Number; i++)
		if (Number % i == 0)
		{
			Result = false;
			break;
		};
}



int main()
{
	int Numbers[3], Count;

	cout << "Введите три натуральных числа: ";
	cin >> Numbers[0] >> Numbers[1] >> Numbers[2];



	Count = 0;

	for (int i = 0; i < 3; i++)
		if (IsPrime(Numbers[i]))
			++Count;

	cout << "Функция, возвращающая значение: " << Count << endl;



	Count = 0;

	for (int i = 0; i < 3; i++)
	{
		bool Prime;
		IsPrime(Numbers[i], &Prime);
		if (Prime)
			++Count;
	};

	cout << "Функция с дополнительным аргументом-указателем: " << Count << endl;



	Count = 0;

	for (int i = 0; i < 3; i++)
	{
		bool Prime;
		IsPrime(Numbers[i], Prime);
		if (Prime)
			++Count;
	};

	cout << "Функция с дополнительным аргументом-ссылкой: " << Count;



	return 0;
}