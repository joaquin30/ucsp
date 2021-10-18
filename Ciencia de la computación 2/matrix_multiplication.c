#include <stdio.h>
/*
void mulMats(int mats[3][3][3])
{
    int *ptr1 = **mats;
    int *ptr2 = **(mats + 1);
    int *ptr3 = **(mats + 2);
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *(ptr3 + (i * 3 + j)) = 0;
            for (k = 0; k < 3; k++) {
                *(ptr3 + (i * 3 + j)) += *(ptr1 + (i * 3 + k)) *
                                         *(ptr2 + (k * 3 + j));
            }
        }
    }
}
*/

void mulMats(int mats[3][3][3])
{
    int (*A)[3] = *mats;
    int (*B)[3] = *(mats + 1);
    int (*C)[3] = *(mats + 2);
    int *p = *A, *q = *B, *r = *C;
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
        *r = *r + (*p) * (*q);
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
         {3, 2, 1},
         {1, 1, 2}},
        {{4, 5, 4},
         {6, 5, 6},
         {3, 5, 3}},
        {{0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}}
    };
    mulMats(mats);
    printMat(*(mats+2));
    return 0;
}