#include <stdio.h>



int main()
{
	unsigned char a;



	a = 119 & 18;
	printf("119 ˄ 18 = (18) = %i\n", a);

	a = 119 & -18;
	printf("119 ˄ -18 = (102) = %i\n", a);

	a = 119 >> 3;
	printf("119 >> 3 = (14) = %i\n", a);

	a = 80 | -119 & (~48 ^ -15);
	printf("80 ˅ -119 ˄ (¬48 ∆ -15) = (88) = %i\n", a);



	return 0;
}