#include <stdio.h>

// declare and define the function here
void* read_int(void* number) {
    int* ret = (int*)number;
    if (scanf("%d", ret) != 1) {
        return NULL;
    }
    return ret;
}

int main(void)
{
    int a;
    int* ret = read_int(&a);
    printf("return value: %p\n", ret);
    if (ret)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");

    return 0;
}
