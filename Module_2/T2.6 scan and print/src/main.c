#include <stdio.h>

int main() {
    int a;
    double f;

    int num = scanf("%d %lf", &a, &f);

    printf("Captured %d\n", num);

    printf("Integer is 0x%08x\n", a);

    printf("Floating-point number is %8.3f\n", f);

    return 0;
}

