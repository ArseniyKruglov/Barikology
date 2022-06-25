#include <iostream>
#include <cmath>

using namespace std;



float DoWhile(float A, unsigned int m)
{
    float S;
    
    int i = 1;
    do
    {
        float x = -2.5 + 2 * i / m;
        S += (2 * x * x - 5 * i / m) / (sqrt(x * x + 0.5)); 
        i++;
    }
    while (i <= m);
    
    S *= A;
    
    return S;
}

float For(float A, int m)
{
    float S;
    
    for (int i = 1; i <= m; i++)
    {
        float x = -2.5 + 2 * i / m;
        S += (2 * x * x - 5 * i / m) / (sqrt(x * x + 0.5));  
    };
    
    S *= A;
    
    return S;
}

float While(float A, int m)
{
    float S;
    
    int i = 1;
    while (i <= m)
    {
        float x = -2.5 + 2 * i / m;
        S += (2 * x * x - 5 * i / m) / (sqrt(x * x + 0.5)); 
        i++;
    };
    
    S *= A;
    
    return S;
}

int main()
{
    float A;
    cout << "Введите значение A: ";
    cin >> A;
    
    int m;
    cout << "Введите значение m: ";
    cin >> m;
    
    
    
    cout << "S (Цикл While) = " << While(A, m) << endl;
    cout << "S (Цикл Do...While) = " << DoWhile(A, m) << endl;
    cout << "S (Цикл For) = " << For(A, m) << endl;

    return 0;
}
