Const
  maxArrayLength = 100;   { Максимальный размер массива }
  
Var
  A: Array[1..maxArrayLength] Of Integer;
  i, userArrayLength, K, maxArrayValue: Integer;
  KInArray: Boolean;
  
Begin
  { Ввод }
  Write('Задайте количество элементов массива не более ', maxArrayLength, ' -> ');
  ReadLn(userArrayLength);
  
  Write('Введите одной строкой ', userArrayLength, ' чисел через пробел -> ');
  For i := 1 To userArrayLength Do
    Read(A[i]);
  
  Write('Задайте значение K -> ');
  Read(K);
  
  
  
  { Поиск максимального значения массива,
    проверка на нахождение в массиве элемента со значением K }
  KInArray := false;
  maxArrayValue := A[1];
  For i := 1 To userArrayLength
  Do Begin
    If (A[i] = K)
    Then Begin
      KInArray := true;
      break;
    End;
    
    If (A[i] > maxArrayValue) Then
      maxArrayValue := A[i];
  End;
  
  { Если в массиве нет ни одного элемента с заданным значением K,
    то значение первого по порядку элемента этого массива,
    не меньшее значений всех остальных элементов, заменить значением K }
  If Not KInArray Then
    For i := 1 To userArrayLength Do
      If A[i] = maxArrayValue
      Then Begin
         A[i] := K;
         break;
      End;
   
   
      
  { Вывод }
  Write('Результирующий массив: ');
  For i := 1 To userArrayLength Do
    Write(A[i], ' ');
  
  
  
  ReadLn;
End.