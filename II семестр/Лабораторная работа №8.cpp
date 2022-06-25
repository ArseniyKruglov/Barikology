#include <iostream>

using namespace std;



const int MaxSize = 100;
typedef int TElement;
typedef TElement TMatrix[MaxSize][MaxSize];



void Input(int &n, TMatrix Matrix)
{
    cout << "Введите половину размера матрицы ≤ " << MaxSize / 2 << ": ";
    cin >> n;
    if (n <= 0 || 2 * n > MaxSize)
    {
        cout << "Введено недопустимое значение размера матрицы";
        exit(EXIT_FAILURE);
    };
    
    cout << "Введите построчно через пробел элементы матрицы размера " << 2 * n << "×" << 2 * n << "." << endl << "После ввода строки нажимайте <Enter>." << endl;
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            cin >> Matrix[i][j];
}

void Output(int n, TMatrix Matrix)
{
    cout << endl << "Матрица после преобразования:" << endl;
    
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cout << Matrix[i][j] << " ";
        
        cout << endl;
    };
}

int GetRowIndex(int n, TMatrix Matrix)
{
    int RowIndex = 0;
    int ColumnIndex = 0;
    
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            if (abs(Matrix[i][j]) < abs(Matrix[RowIndex][ColumnIndex]))
            {
                RowIndex = i;
                ColumnIndex = j;
            };
            
    return RowIndex;
}

void Process(int n, TMatrix Matrix)
{
    int RowIndex = GetRowIndex(n, Matrix);
    
    for (int i = 0; i < 2 * n; i++)
        swap(Matrix[n * 2 - 1][i], Matrix[RowIndex][i]);
}

int main()
{
    int n;
    TMatrix Matrix;
    
    Input(n, Matrix);
    
    Process(n, Matrix);
    
    Output(n, Matrix);

    return 0;
}

