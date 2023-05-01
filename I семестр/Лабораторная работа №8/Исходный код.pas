Const
	MaxMatrix = 100;				{ Максимальный размер строки (столбца) матрицы }
	MaxN = 50;

Type
	TRange = 1..MaxMatrix;				{ Тип индекса элемента матрицы }
	TElement = Integer;				{ Тип значения элемента матрицы }
	TVector = Array[TRange] Of TElement;		{ Тип вектор }
	TMatrix = Array[TRange] Of TVector;		{ Тип матрица }



{ Ввод матрицы }
Function MatrixInput(n: TRange):TMatrix;
Var
	i, j: TRange;
	M: TMatrix;

Begin
	WriteLn('Введите матрицу по строкам:');

	For i := 1 To 2 * n
	Do Begin
		For j := 1 To 2 * n Do
			Read(M[i, j]);
		ReadLn;
	End;

	MatrixInput := M;
End;



{ Поиск суммы абсолютных значений элементов, лежащих ниже главной диагонали }
Function UnderMain(n: TRange; M: TMatrix):TElement;
Var
	i, j: TRange;

Begin
	For j := 1 To 2 * n Do
		For i := j + 1 To 2 * n Do
			UnderMain += M[i, j];
End;



{ Поиск суммы абсолютных значений элементов, лежащих ниже побочной диагонали }
Function UnderSide(n: TRange; M: TMatrix):TElement;
Var
	i, j: TRange;

Begin
	For j := 1 To 2 * n Do
		For i := 2 * n - j + 2 To 2 * n Do
			UnderSide += M[i, j];
End;



Var
	n: Integer;
	M: TMatrix;

Begin
	{ Ввод }
	Write('Размер матрицы: 2n×2n. Введите значение n (от 1 до ', MaxN,') -> ');
	Readln(n);
	If n In [1..MaxN] Then
		M := MatrixInput(n)
	Else
	Begin
		Write('Ошибка ввода. 1 <= n <= ', MaxN);
		Exit;
	End;



	{ Вывод }
	WriteLn('Сумма абсолютных значений элементов, лежащих ниже главной диагонали: ', UnderMain(n, M));
	WriteLn('Сумма абсолютных значений элементов, лежащих ниже побочной диагонали: ', UnderSide(n, M));
	Read;
End.