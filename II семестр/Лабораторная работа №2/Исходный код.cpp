#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x, y;
    cout << "Введите координаты точки: x, y ";
    cin >> x >> y;
    
    
    
    cout.precision(4);
    
    if
    (
        pow((x + 1), 2) + pow((y - 1), 2) < 1 &&
        pow((x + 1), 2) + pow(y, 2) > 1 &&
        y < 1 &&
        x < -1
    )
        cout << "Точка находится в области М1. S = " << (M_PI / 12) - (M_PI / 3 - sqrt(3) / 2) / 2;
    else if
    (
        pow(x, 2) + pow((y - 1), 2) < 1 &&
        pow((x + 1), 2) + pow((y - 1), 2) < 1 &&
        pow(x, 2) + pow(y, 2) < 1 &&
        pow((x + 1), 2) + pow(y, 2) < 1
    )
        cout << "Точка находится в области М2. S = " << (pow((sqrt(3) - 1), 2) / 2) + 4 * ((M_PI / 6 - 0.5) / 2);
    else if
    (
        pow((x - 1), 2) + pow(y, 2) < 1 &&
        pow(x, 2) + pow((y - 1), 2) > 1 &&
        pow(x, 2) + pow((y + 1), 2)
    )
        cout << "Точка находится в области М3. S = " << (M_PI / 2) + 2 * (1 - M_PI / 4);
    else if
    (
        pow(x, 2) + pow(y, 2) < 1 &&
        pow(x, 2) + pow((y + 1), 2) &&
        pow((x + 1), 2) + pow((y + 1), 2) < 1
    )
        cout << "Точка находится в области М4. S = " << (M_PI / 12) + 2 * ((M_PI / 3 - sqrt(3) / 2) / 2);
    else if
    (
        pow((x + 1), 2) + pow((y + 1), 2) < 1 &&
        pow(x, 2) + pow((y + 1), 2) > 1 &&
        pow((x + 1), 2) + pow(y, 2) > 1
    )
        cout << "Точка находится в области М5. S = " << (M_PI / 4) + 2 * (M_PI / 12 - ((M_PI / 3 - sqrt(3) / 2) / 2));
    else
        cout << "Точка находится вне выделенных областей";

    return 0;
}

