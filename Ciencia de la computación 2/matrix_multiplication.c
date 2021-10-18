#include <stdio.h>

void mulMats(int mats[3][3][3])
{
    int (*mat1)[3] = *mats;
    int (*mat2)[3] = *(mats + 1);
    int (*res)[3] = *(mats + 2);
}

void printMat(int mat[3][3]) {
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