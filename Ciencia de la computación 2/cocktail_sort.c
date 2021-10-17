#include <stdio.h>

void printArray(int *left, int *right)
{
    for (; left <= right; left++)
	printf("%d ", *left);
    puts("");
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void cocktailSort(int *left, int *right)
{
    int *lptr, *rptr, cnt = 1;
    while (left <= right && cnt) {
        cnt = 0;
        lptr = left;
        rptr = right;
        for (; lptr < rptr; lptr++) {
            if (*lptr > *(lptr + 1)) {
            swap(lptr, lptr + 1);
            cnt++;
            }
        }
        if (!cnt)
            return;
        right--;
        cnt = 0;
        lptr = left;
        rptr = right;
        for (; rptr > lptr; rptr--) {
            if (*(rptr - 1) > *rptr) {
                swap(rptr - 1, rptr);
                cnt++;
            }
        }
        left++;
    }
}

int main(void) {
    int a[] = {4,6,2,9,1,7,3,2,6,8,3,4,3,2,6,7,4,3,2,4,5,0,8,1,2};
    int len = sizeof(a) / sizeof(*a) - 1;
    printArray(a, a + len);
    cocktailSort(a, a + len);
    printArray(a, a + len);
    return 0;
}