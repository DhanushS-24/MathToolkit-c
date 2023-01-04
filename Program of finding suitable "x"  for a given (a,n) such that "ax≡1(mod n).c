#include <stdio.h>
#include <stdlib.h>

int extended_euclidean(int a, int n, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return n;
    }

    int x1, y1;
    int gcd = extended_euclidean(n % a, a, &x1, &y1);

    *x = y1 - (n / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, n;
    printf("Enter a and n: ");
    scanf("%d %d", &a, &n);

    int x, y;
    int gcd = extended_euclidean(a, n, &x, &y);

    if (gcd != 1) {
        printf("Modular inverse does not exist\n");
    } else {
        printf("Modular inverse of %d modulo %d is %d\n", a, n, (x % n + n) % n);
    }

    return 0;
}
