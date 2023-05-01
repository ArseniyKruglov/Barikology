Const
	MaxArrayLength = 100;				{ Максимальный размер массива }

Type
	TRange = 1..MaxArrayLength;			{ Тип индекса элементов массива }
	TElement = Integer;				{ Тип значений элементов массива }
	TArray = Array[TRange] Of TElement;		{ Тип массив }

Var
	A: TArray;
	i, UserArrayLength: TRange;
	K, MaxArrayValue: TElement;
	KInArray: Boolean;

Begin
	{ Ввод }
	Write('Задайте количество элементов массива не более ', MaxArrayLength, ' -> ');
	ReadLn(UserArrayLength);

	Write('Введите одной строкой ', UserArrayLength, ' чисел через пробел -> ');
	For i := 1 To UserArrayLength Do
		Read(A[i]);

	Write('Задайте значение K -> ');
	Read(K);



	{ Поиск максимального значения массива,
	  проверка на нахождение в массиве элемента со значением K }
	KInArray := false;
	MaxArrayValue := A[1];
	For i := 1 To UserArrayLength
	Do Begin
		If (A[i] = K)
		Then Begin
			KInArray := true;
			break;
		End;

		If (A[i] > MaxArrayValue) Then
			MaxArrayValue := A[i];
	End;

	{ Если в массиве нет ни одного элемента с заданным значением K,
	  то значение первого по порядку элемента этого массива,
	  не меньшее значений всех остальных элементов, заменить значением K }
	If Not KInArray Then
		For i := 1 To UserArrayLength Do
			If A[i] = MaxArrayValue
			Then Begin
				A[i] := K;
				Break;
			End;



	{ Вывод }
	Write('Результирующий массив: ');
	For i := 1 To UserArrayLength Do
		Write(A[i], ' ');



	ReadLn;
End.