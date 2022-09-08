Program Log_Oper;
{ Выполнение поразрядных логических операций над целыми числами }

Var
  answer: Byte;

Begin
  answer := 109 AND 18;
  WriteLn('109 AND 18 = ', answer, ' (контр. значение 0)');

  answer := 109 OR -18;
  WriteLn('109 OR -18 = ', answer, ' (контр. значение 239)');

  answer := 109 SHR 3;
  WriteLn('109 >> 3 = ', answer, ' (контр. значение 13)');

  answer := 109 OR NOT -18 AND (NOT 58 XOR -65);
  WriteLn('109 OR NOT -18 AND (NOT 58 XOR -65) = ', answer, ' (контр. знач. 125)');

  ReadLn;
End.