#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "source.h"

int main()
{
    int arr[] = { 1, 3, 7 };
    printf("array_sum with values { 10, 100, 1000 } returned: ");
    int sum = array_sum(arr, 3);
    printf("%d\n", sum);

    if (sum == 1110) {
        printf("%d -- OK!\n", sum);
    } else {
        printf("%d, but should have been 1110\n", sum);
    }

    return 0;
}
