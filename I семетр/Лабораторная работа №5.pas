Program Seq;

Var
  P: Real;
  m, i: Integer;

Begin
  { Ввод }
  WriteLn('Для введенного с клавиатуры значения m вычислить P.');
  Write('Задайте значение m -> ');
  ReadLn(m);



  { Решение с использованием управляющей структуры While-Do }
  i := 1;
  P := 1;
  While (i <= m) Do Begin
    P *= (m * (0.5 + 0.25 * i)) / (m - i + 2);
    i += 1;
  End;
  
  WriteLn('While:  P = ', P);
  
  

  { Решение с использованием управляющей структуры Repeat-Until }
  i := 1;
  P := 1;
  Repeat
    P *= (m * (0.5 + 0.25 * i)) / (m - i + 2);
    i += 1;
  Until i > m;
  
  WriteLn('Repeat:  P = ', P);
  
  

  { Решение с использованием управляющей структуры For-To-Do }
  P := 1;
  for i := 1 to m Do
    P *= (m * (0.5 + 0.25 * i)) / (m - i + 2);
  
  WriteLn('For:  P = ', P);



  ReadLn;
End.