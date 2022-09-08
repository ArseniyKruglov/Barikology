#include <iostream>

using namespace std;



const int MaxLength = 100;
typedef int TElement;
typedef TElement TArray[MaxLength];



void Input(int &n, TArray Array)
{
    cout << "Введите половину размера массива ≤ " << MaxLength / 2 << ": ";
    cin >> n;
    if (n <= 0 || 2 * n > MaxLength)
    {
        cout << "Введено недопустимое значение размера массива";
        exit(EXIT_FAILURE);
    };

    cout << "Введите " << 2 * n << " значений элементов масива: ";
    for (int i = 0; i < 2 * n; i++)
        cin >> Array[i];
}

int GetMinValueIndex(int n, TArray Array)
{
    int Index = 0;

    for (int i = 1; i < 2 * n; i++)
        if (abs(Array[i]) < abs(Array[Index]))
            Index = i;

    return Index;
}

TElement Process(int n, TArray Array)
{
    int MinValueIndex = GetMinValueIndex(n, Array);



    int From, To;
    if (MinValueIndex < n)
    {
        From = MinValueIndex + 1;
        To = (n - 1) - 1;
    }
    else
    {
        From = (n - 1) + 1;
        To = MinValueIndex - 1;
    };



    TElement Result = 0;

    for (int i = From; i <= To; i++)
        if (Array[i] < 0)
            if (Result == 0)
                Result = Array[i];
            else
                Result *= Array[i];

    return Result;
}

int main()
{
    int n;
    TArray Array;

    Input(n, Array);

    cout << "Произведение отрицательных значений элементов массива: " << Process(n, Array);

    return 0;
}