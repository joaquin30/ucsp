#include <stdio.h>
#include <stdlib.h>

char *bin(int n, int len)
{
	char *number;
	int i;
	number = malloc(len+1);
	number[len] = '\0';
	for (i=0; i<len; i++) {
		number[len-1-i] = n & 1 ? '1' : '0';
		n >>= 1;
	}
	return number;
}

/* count < 32 */
void binary_division(int dividendo, int divisor,
		int *cociente, int *residuo, int count)
{
	int bitlen = count;
	int A = 0;
	int Q = dividendo;
	unsigned long AQ = Q;
	int M = divisor;
	while (count > 0) {
		AQ <<= 1;
		A = AQ >> bitlen;
		Q = (AQ & ((1ul << bitlen) - 1));
		/*printf("%s\n%s %s\n", bin(AQ, bitlen*2), bin(A, bitlen), bin(Q, bitlen*2));*/
		A -= M;
		if (A < 0) {
			if (Q & 1) Q--;
			A += M;
		} else {
			if (!(Q & 1)) Q++;
		}
		count--;
		AQ = ((unsigned long) A << bitlen) + (unsigned long) Q;
		/*printf("%s\n%s %s\n\n", bin(AQ+Q, bitlen*2), bin(A, bitlen), bin(Q, bitlen));*/
	}
	*cociente = Q;
	*residuo = A;
}

int main(void)
{
	int d, D, q, r, n;
	puts("nro de bits < 32");
	scanf("%d%d%d", &d, &D, &n);
	binary_division(d, D, &q, &r, n);
	printf("Q = %d\nR = %d\n", q, r);
	return 0;
}