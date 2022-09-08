Program Extremum;
{ Определение максимального или минимального значения с использованием структур "выбор" и "обход". Вычислить  x = max(min(a, c) - b, min(b, d)) }

Var
  a, b, c, d: Integer;              { Исходные данные }
  max, min_ac, min_bd: Integer;     { Промежуточные значения }
  x: Integer;                       { Результат вычисления }

Begin
  { Ввод данных }
  WriteLn('Введите значения a, b, c, d: ');
  ReadLn(a, b, c, d);



  { Решение задачи с использованием структуры "Выбор" }
  If a < c Then
    min_ac := a
  Else
    min_ac := c;

  If b < d Then
    min_bd := b
  Else
    min_bd := d;

  If min_ac - b > min_bd Then
    x := min_ac - b
  Else
    x := min_bd;

  { Вывод результата решения с использованием структуры "Выбор" }
  WriteLn('Использование структуры "Выбор": x = ', x);



  { Решение задачи с использованием структуры "Обход" }
  min_ac := a;
  If c < min_ac Then
    min_ac := c;

  min_bd := b;
  If d < min_bd Then
    min_bd := d;

  x := min_ac - b;
  If min_bd > x Then
    x := min_bd;

  { Вывод результата решения с использованием структуры "Обход" }
  WriteLn('Использование структуры "Обход": x = ', x);



  ReadLn;
End.