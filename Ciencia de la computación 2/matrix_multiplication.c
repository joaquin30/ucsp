#include <stdio.h>

void mulMats(int mats[3][3][3])
{
    /* A * B = C */
    int (*A)[3] = *mats;
    int (*B)[3] = *(mats + 1);
    int (*C)[3] = *(mats + 2);
    int *p = *A, *q = *B, *r = *C;
    /* limpiar C con 0s*/
    for (; r < *C + 9; r++)
        *r = 0;
    r = *C;
    /* multiplicar mats */
    while (p < *(A + 3)) {
        if (r == *(C + 1)) {
            r -= 3;
            p++;
        }
        if (q == *(B + 3)) {
            q = *B;
            r = *(C + 1);
            C++;
        }
        *r += *p * *q;
        q++;
        r++;
    }
}

void printMat(int mat[3][3])
{
    int i, j, *ptr = *mat;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++, ptr++)
            printf("%d ", *ptr);
        puts("");
    }
}

int main(void)
{
    int mats[3][3][3] = {
        {{1, 2, 3},
         {3, 2, 1}, /* A */
         {1, 1, 2}},
        {{4, 5, 4},
         {6, 5, 6}, /* B */
         {3, 5, 3}},
        {{1, 1, 1},
         {1, 1, 1}, /* C */
         {1, 1, 1}}
    };
    mulMats(mats);
    printMat(*(mats+2));
    return 0;
}