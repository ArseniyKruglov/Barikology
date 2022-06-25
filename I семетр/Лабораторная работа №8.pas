Const
  maxSize = 10;   { Максимальный размер строки (столбца) матрицы }

Var
  M: Array[1..maxSize] Of Array [1..maxSize] of Integer;
  n, i, j, underMain, underSide: Integer;
  
Begin
  { Ввод }
  Write('Размер матрицы: 2n×2n. Введите значение n (от 1 до ', maxSize / 2,') -> ');
  Readln(n);
  
  WriteLn('Введите матрицу по строкам ->');
  For i := 1 To 2 * n
  Do Begin
    For j := 1 To 2 * n Do
      Read(M[i, j]);
    ReadLn;
  End;
  
  
  
  { Под главной диагональю }
  For j := 1 To 2 * n Do
    For i := j + 1 To 2 * n Do
      underMain += M[i, j];
  
  { Под побочной диагональю }
  For j := 1 To 2 * n Do 
    For i := 2 * n - j + 2 To 2 * n Do
      underSide += M[i, j];
    
    
    
  { Вывод }
  WriteLn('Сумма абсолютных значений элементов, лежащих ниже главной диагонали: ', underMain);
  WriteLn('Сумма абсолютных значений элементов, лежащих ниже побочной диагонали: ', underSide);
  Read;
End.