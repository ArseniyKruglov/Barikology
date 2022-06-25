#include <iostream>

using namespace std;



const int MaxSize = 100;
typedef int TElement;
typedef TElement TMatrix[MaxSize][MaxSize];



void Input(int &n, TMatrix Matrix)
{
    cout << "Введите половину размера матрицы <= " << MaxSize / 2 << ": ";
    cin >> n;
    if (n <= 0 || 2 * n > MaxSize)
    {
        cout << "Введено недопустимое значение размера матрицы";
        exit(EXIT_FAILURE);
    };
    
    cout << "Введите построчно через пробел элементы матрицы размера " << 2 * n << "x" << 2 * n << "." << endl << "После ввода строки нажимайте Enter." << endl;
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            cin >> Matrix[i][j];
}

float Process(int n, TMatrix Matrix, int &Count)
{
    TElement Sum = 0;
    
    for (int Row = 0; Row < n - 1; Row++)
        for (int Column = Row + 1; Column < n; Column++)
        {
            Sum += Matrix[Row][Column];
            Count++;
        };

    return Sum / float(Count);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    TMatrix Matrix;
    
    Input(n, Matrix);
    
    int Count = 0;
    float Result = Process(n, Matrix, Count);
    if (Count == 0)
        cout << "В области нет элементов";
    else
        cout << "Среднее арифметическое: " << Result;

    return 0;
}
