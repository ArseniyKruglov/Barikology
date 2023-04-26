{ Определение максимального или минимального значения с использованием структур «выбор» и «обход». Вычислить  x = max(min(a, c) - b, min(b, d)). }

Var
	a, b, c, d: Integer;		{ Исходные данные }
	MinOfAC, MinOfBD: Integer;		{ Промежуточные значения }
	x: Integer;		{ Результат вычисления }

Begin
	{ Ввод данных }
	WriteLn('Введите значения a, b, c, d: ');
	ReadLn(a, b, c, d);



	{ Решение задачи с использованием структуры «Выбор» }
	If a < c Then
		MinOfAC := a
	Else
		MinOfAC := c;

	If b < d Then
		MinOfBD := b
	Else
		MinOfBD := d;

	If MinOfAC - b > MinOfBD Then
		x := MinOfAC - b
	Else
		x := MinOfBD;

	{ Вывод результата решения с использованием структуры «Выбор» }
	WriteLn('Использование структуры «Выбор»: x = ', x);



	{ Решение задачи с использованием структуры «Обход» }
	MinOfAC := a;
	If c < MinOfAC Then
		MinOfAC := c;

	MinOfBD := b;
	If d < MinOfBD Then
		MinOfBD := d;

	x := MinOfAC - b;
	If MinOfBD > x Then
		x := MinOfBD;

	{ Вывод результата решения с использованием структуры «Обход» }
	WriteLn('Использование структуры «Обход»: x = ', x);



	ReadLn;
End.