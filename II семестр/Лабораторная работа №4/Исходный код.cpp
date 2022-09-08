#include <iostream>
#include <climits>
#include <math.h>

using namespace std;



double For(unsigned int &n, double Epsilon, double Y0, double Y1, double Y2)
{
    double Y3 = (1.9 * Y0 + 1.5 * Y1) / (2 * n * n * n + 4 * Y2);

    for ( ; fabs(Y3 - Y2) > Epsilon && n < INT_MAX; )
    {
        n++;
        Y0 = Y1;
        Y1 = Y2;
        Y2 = Y3;
        Y3 = (1.9 * Y0 + 1.5 * Y1) / (2 * n * n * n + 4 * Y2);
    };

    return Y3;
}

double While(unsigned int &n, double Epsilon, double Y0, double Y1, double Y2)
{
    double Y3 = (1.9 * Y0 + 1.5 * Y1) / (2 * n * n * n + 4 * Y2);

    while (fabs(Y3 - Y2) > Epsilon && n < INT_MAX)
    {
        n++;
        Y0 = Y1;
        Y1 = Y2;
        Y2 = Y3;
        Y3 = (1.9 * Y0 + 1.5 * Y1) / (2 * n * n * n + 4 * Y2);
    };

    return Y3;
}

double DoWhile(unsigned int &n, double Epsilon, double Y1, double Y2, double Y3)
{
    double Y0;

    do
    {
        n++;
        Y0 = Y1;
        Y1 = Y2;
        Y2 = Y3;
        Y3 = (1.9 * Y0 + 1.5 * Y1) / (2 * n * n * n + 4 * Y2);
    }
    while (fabs(Y3 - Y2) > Epsilon && n < INT_MAX);

    return Y3;
}



int main()
{
    double Epsilon, Y0, Y1, Y2;
    unsigned int n;



    cout << "Введите точность вычисления ε: ";
    cin >> Epsilon;
    if (Epsilon <= 0 || Epsilon > 1)
    {
        cout << "Ошибка. 0 < ε ≤ 1";
        exit(EXIT_FAILURE);
    };

    cout << "Введите значения Y0, Y1, Y2: ";
    cin >> Y0 >> Y1 >> Y2;



    double Result_For = For(n = 3, Epsilon, Y0, Y1, Y2);
    if (Result_For == INT_MAX)
        cout << "Цикл For: Точность не достигнута" << endl;
    else
        cout << "Цикл For: Результат = " << Result_For << ", n = " << n << endl;

    double Result_While = While(n = 3, Epsilon, Y0, Y1, Y2);
    if (Result_While == INT_MAX)
        cout << "Цикл While: Точность не достигнута" << endl;
    else
        cout << "Цикл While: Результат = " << Result_While << ", n = " << n << endl;

    double Result_DoWhile = DoWhile(n = 2, Epsilon, Y0, Y1, Y2);
    if (Result_DoWhile == INT_MAX)
        cout << "Цикл DoWhile: Точность не достигнута";
    else
        cout << "Цикл DoWhile: Результат = " << Result_DoWhile << ", n = " << n;



    return 0;
}