{ Выполнение поразрядных логических операций над целыми числами }

Var
	Answer: Byte;

Begin
	Answer := 109 AND 18;
	WriteLn('109 AND 18 = ', Answer, ' (контр. значение 0)');

	Answer := 109 OR -18;
	WriteLn('109 OR -18 = ', Answer, ' (контр. значение 239)');

	Answer := 109 SHR 3;
	WriteLn('109 >> 3 = ', Answer, ' (контр. значение 13)');

	Answer := 109 OR NOT -18 AND (NOT 58 XOR -65);
	WriteLn('109 OR NOT -18 AND (NOT 58 XOR -65) = ', Answer, ' (контр. знач. 125)');

	ReadLn;
End.