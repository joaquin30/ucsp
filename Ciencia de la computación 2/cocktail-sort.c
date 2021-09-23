#include <stdio.h>

void print_array(int *arr, int len)
{
    int i;
    for (i=0; i<len; ++i)
        printf("%d ", *(arr+i));
    puts("");
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void cocktail_sort(int *arr, int len)
{
    int i, cnt;
    if (len < 2)
        return;
    while (1) {
        cnt = 0;
        for (i = 1; i < len; ++i) {
            if (*(arr+i-1) > *(arr+i)) {
                swap(arr+i-1, arr+i);
                cnt++;
            }
        }
        if (cnt == 0)
            return;
        cnt = 0;
        for (i = len-1; i > 0; --i) {
            if (*(arr+i-1) > *(arr+i)) {
                swap(arr+i-1, arr+i);
                cnt++;
            }
        }
        if (cnt == 0)
            return;
    }
}

int main(void) {
    int a[] = {4,6,2,9,1,7,3,2,6,8,3,4,3,2,6,7,4,3,2,4,5,0,8,1,2};
    int len_a = sizeof(a)/sizeof(*a);
    print_array(a, len_a);
    cocktail_sort(a, len_a);
    print_array(a, len_a);
    return 0;
}