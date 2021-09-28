#include <stdio.h>
#include <stdlib.h>

/* cambiar segun' plataforma */
typedef unsigned u32;
typedef unsigned long u64;

char *bin(u32 n, u32 len)
{
    char *number;
    u32 i;
    number = (char *) malloc(len+1);
    number[len] = '\0';
    for (i=0; i<len; i++) {
        number[len-1-i] = n & 1 ? '1' : '0';
        n >>= 1;
    }
    return number;
}

void binary_division(u32 dividendo, u32 divisor,
                     u32 *cociente, u32 *residuo,
                     u32 count)
{
    u32 bitlen = count;
    u32 A = 0;
    u32 Q = dividendo;
    u64 AQ = Q;
    u32 M = divisor;
    while (count > 0) {
        AQ <<= 1;
        A = AQ >> bitlen;
        Q = (AQ & ((1ul << bitlen) - 1));
        A += ~M + 1; /*resta complemento 2*/
        if ((A >> 31) & 1) { /*msb para comprobar si es < 0*/
            if (Q & 1) Q--;
            A += M;
        } else if (!(Q & 1)) Q++;
        count--;
        AQ = ((u64) A << bitlen) + Q;
    }
    *cociente = Q;
    *residuo = A;
}

int main(void)
{
    u32 D, d, q, r, n;
    printf("Dividendo: ");
    scanf("%u", &D);
    printf("Divisor: ");
    scanf("%u", &d);
    printf("Nro. de bits (<= 32): ");
    scanf("%u", &n);
    binary_division(D, d, &q, &r, n);
    printf("Cociente: %u\nResiduo: %u\n", q, r);
    return 0;
}