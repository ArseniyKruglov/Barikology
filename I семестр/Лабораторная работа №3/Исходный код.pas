Program Tochka;
{ Определение местоположения точки на плоскости. }

Var
  x, y: Real;     { Координаты точки }

Begin
  { Ввод координат точки }
  Write('Введите координаты точки x и y: ');
  ReadLn(x, y);
  
  { Анализ координат }
  If (x = 0) And (y = 0) Then
    WriteLn('Точка находится в начале координат')
  Else If ((x + 1) * (x + 1) + (y - 1) * (y - 1) < 1) AND (x > -1) AND (y > x + 2) Then     { Область М1? }
    WriteLn('Точка находится в области M1')
  Else If (x > 1) AND (x < 2) AND (y > 1) AND (y < 2) AND ((x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) Then      { Область М2? }
    WriteLn('Точка находится в области M2')
  Else If ((x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) AND ((x + 1) * (x + 1) + (y - 1) * (y - 1) > 1) AND (y > 0) AND (y < 1) AND (x > -1) AND (x < 1) Then     { Область М3? }
    WriteLn('Точка находится в области M3')
  Else If (x * x + y * y > 1) AND (y < 0) AND (x < 0) AND (y > -1) AND (y > -x - 2) Then      { Область М4? }
    WriteLn('Точка находится в области M4')
  Else If (x * x + y * y > 1) AND (x > 0) AND (y > x - 2) AND ((x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) AND (y < x) Then      { Область М5? }
    WriteLn('Точка находится в области M5')
  Else
    WriteLn('Точка находится вне всех обозначенных плоскостей');

  ReadLn;
End.
