# include <stdio.h>
# include "source.h"

double fracsum(int x, int y, int a, int b) {
    // Calculate the floating-point values of the fractions
    double fraction1 = (double) x / y;
    double fraction2 = (double) a / b;

    // Calculate the sum of the fractions
    double sum = fraction1 + fraction2;

    return sum;
}
