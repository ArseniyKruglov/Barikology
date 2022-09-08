#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;



double Sin(double x, double Epsilon, unsigned int &n)
{
    double Previous = x * x, Sin = Previous, Current;
    for (n = 2; n <= INT_MAX; n++)
    {
        Current = Previous * -1 * (2 * 2 * x * x) / ((2 * n) * (2 * n - 1));

        if (abs(Current) > Epsilon)
        {
            Sin += Current;
            Previous = Current;
        }
        else
        {
            break;
        };
    };

    return Sin;
}



int main()
{
    unsigned int n;

    double x;
    cout << "Введите изначальное значение аргумента: ";
    cin >> x;
    if (abs(x) >= 1)
    {
        cout << "Ошибка. |x| < 1";
        exit(EXIT_FAILURE);
    };

    double xMax;
    cout << "Введите конечное значение аргумента: ";
    cin >> xMax;
    if (abs(xMax) >= 1 || x >= xMax)
    {
        cout << "Ошибка. |xMax| < 1 и больше начального значения";
        exit(EXIT_FAILURE);
    };

    double xStep;
    cout << "Введите шаг изменения аргумента: ";
    cin >> xStep;
    if (xStep <= 0)
    {
        cout << "Ошибка. xStep > 0";
        exit(EXIT_FAILURE);
    };

    double Epsilon;
    cout << "Введите точность вычисления ε: " ;
    cin >> Epsilon ;
    if (Epsilon <= 0 || Epsilon > 0.1)
    {
        cout << "Ошибка. 0 < ε ≤ 0.1";
        exit(EXIT_FAILURE);
    };

    cout << endl;



    cout << "Аргумент | Сумма        | Кол.слаг. | Контрольное значение" << endl;

    cout.setf(ios::left, ios::adjustfield);
    for ( ; x <= xMax; x += xStep)
        cout << setw(8) << x << "   " << setw(12) << setprecision(8) << Sin(x, Epsilon, n) << "   " << setw(9) << (n - 1) << "   " << pow(sin(x), 2) << endl;

    return 0;
}