Program Ship;
{ Определение курса корабля }

Var
    shipDirection, orderDirection: Byte;        { shipDirection - Изначальный курс корабля, orderDirection - направление приказа }

Begin
  { Ввод изначального курса }
  WriteLn('Задайте изначальный курс корабля:');
  Write('0 – север, 1 – восток, 2 – юг, 3 – запад? -> ');
  ReadLn(shipDirection);

  If shipDirection in [0..3] Then
  Begin
    { Ввод приказа на изменение курса }
    WriteLn('Задайте приказ на изменение курса:');
    Write('0 – вперед, 1 – право, 2 – назад, 3 – влево? -> ');
    ReadLn(orderDirection);

    If orderDirection in [0..3] Then
    Begin
      { Вычисление нового курса }
      shipDirection += orderDirection;
      shipDirection := shipDirection mod 4;

      { Вывод }
      Write('Теперь курс корабля – на ');
      Case shipDirection Of
        0: Write('север');
        1: Write('восток');
        2: Write('юг');
        3: Write('запад');
      End;
    End
    Else
      Write('Значение вне диапазона');
  End
  Else
    Write('Значение вне диапазона');



End.