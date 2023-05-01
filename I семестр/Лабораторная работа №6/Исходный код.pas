Var
	m, q, Epsilon, xPast, xCurrent, xDifference: Real;
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
	ReadLn(Epsilon);



	{ Цикл While }
	xPast := m;
	xCurrent := m + q * sin(xPast);
	xDifference := Abs(xCurrent - xPast);
	n := 1;

	While (xDifference >= Epsilon) AND (n < MAXINT)
	Do Begin
		xPast := xCurrent;
		xCurrent := m + q * sin(xPast);
		xDifference := Abs(xCurrent - xPast);
		n += 1;
	End;

	If (n = MAXINT) Then
		WriteLn('Точность не достигнута.')
	Else
		WriteLn('Для цикла While решение уравнения: ', xCurrent);



	{ Цикл Repeat }
	xCurrent := m;
	n := 0;

	Repeat
		xPast := xCurrent;
		xCurrent := m + q * sin(xPast);
		xDifference := Abs(xCurrent - xPast);
		n += 1;
	Until (xDifference < Epsilon) OR (n >= MAXINT);

	If (n = MAXINT) Then
		WriteLn('Точность не достигнута.')
	Else
		WriteLn('Для цикла Repeat решение уравнения: ', xCurrent);



	{ Цикл For }
	xPast := m;

	For n := 1 To MAXINT
	Do Begin
		xCurrent := m + q * sin(xPast);

		If (Abs(xCurrent - xPast) < Epsilon) Then
			Break;

		xPast := xCurrent;
	End;

	If (n = MAXINT) Then
		WriteLn('Точность не достигнута.')
	Else
		WriteLn('Для цикла For решение уравнения: ', xCurrent);



	ReadLn;
End.