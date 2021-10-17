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

/*
cmp return value:
- > 0: a `cmp` b is true
- = 0: a equals b
- < 0: a `cmp` b is false
*/
void cocktailSort(int *left, int *right, int(*cmp)(int *, int *))
{
    int *lptr, *rptr, cnt = 1;
    while (left <= right && cnt) {
        cnt = 0;
        lptr = left;
        rptr = right;
        for (; lptr < rptr; lptr++) {
            if (cmp(lptr, lptr + 1) < 0) {
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
            if (cmp(rptr - 1, rptr) < 0) {
                swap(rptr - 1, rptr);
                cnt++;
            }
        }
        left++;
    }
}

int lessThan(int *a, int *b)
{
    if (*a < *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

int greaterThan(int *a, int *b)
{
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

int main(void)
{
    int a[] = {4,6,2,9,1,7,3,2,6,8,3,4,3,2,6,7,4,3,2,4,5,0,8,1,2};
    int len = sizeof(a) / sizeof(*a) - 1;
    printArray(a, a + len);
    cocktailSort(a, a + len, lessThan);
    printArray(a, a + len);
    cocktailSort(a, a + len, greaterThan);
    printArray(a, a + len);
    return 0;
}