#include <stdio.h>

void mulMats(int mats[3][3][3])
{
    int (*mat1)[3] = *mats;
    int (*mat2)[3] = *(mats + 1);
    int (*res)[3] = *(mats + 2);
    int row, col, i, sum;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            sum = 0;
            for (i = 0; i < 3; i++)
                sum += *(*(mat1 + row) + i) * *(*(mat2 + i) + col);
            *(*(res + row) + col) = sum;
        }
    }
}

void printMat(int mat[3][3]) {
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j)
            printf("%d ", *(*(mat+i)+j));
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