Program Kepler;

Var
  m, q, epsilon, xPast, xCurrent: Real;
  n: Integer;
  
Begin
  { Ввод }
  WriteLn('Для заданных m и q найти приближенное решение уравнения Кеплера X - q * sin(X) = m');
  
  Write('Задайте значение m -> ');
  ReadLn(m);
  
  Write('Задайте значение q -> ');
  ReadLn(q);
  If (q <= 0) OR (q >= 1)
  Then Begin
    Write('Ошибка ввода. 0 < q < 1');
    Exit;
  End;
  
  Write('Задайте значение точности ɛ -> ');
  ReadLn(epsilon);
  
  
  
  { Цикл While }
  xPast := m;
  xCurrent := m + q * sin(xPast);
  n := 2;
  
  While (Abs(xCurrent - xPast) < epsilon) AND (n < MAXINT)
  Do Begin
    xCurrent := m + q * sin(xPast);
    xPast := xCurrent;
    n += 1;
  End;
  
  If (n = MAXINT) Then
    WriteLn('Точность не достигнута.')
  Else
    WriteLn('Для цикла While решение уравнения: ', xCurrent);
  
  
  
  { Цикл Repeat }
  xPast := m;
  xCurrent := m + q * sin(xPast);
  n := 2;
  
  Repeat
    xCurrent := m + q * sin(xPast);
    xPast := xCurrent;
    n += 1;
  Until (Abs(xCurrent - xPast) < epsilon) AND (n <= MAXINT);
  
  If (n = MAXINT) Then
    WriteLn('Точность не достигнута.')
  Else
    WriteLn('Для цикла Repeat решение уравнения: ', xCurrent);
  
  
  
  { Цикл For }
  xPast := m;
  xCurrent := m + q * sin(xPast);
  
  For n := 2 To MAXINT
  Do Begin
    xCurrent := m + q * sin(xPast);
    xPast := xCurrent;
    
    If (Abs(xCurrent - xPast) < epsilon) Then
      Break;
  End;
  
  If (n = MAXINT) Then
    WriteLn('Точность не достигнута.')
  Else
    WriteLn('Для цикла For решение уравнения: ', xCurrent);
  
  

  ReadLn;
End.