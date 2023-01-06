#include <stdio.h>
#include <stdlib.h>

int extended_euclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_euclidean(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int modular_inverse(int a, int m) {
    int x, y;
    int gcd = extended_euclidean(a, m, &x, &y);

    if (gcd != 1) {
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int main() {
    int num_congruences;
    printf("Enter the number of congruences: ");
    scanf("%d", &num_congruences);

    printf("\nEnter one number and hit (space or enter) then enter another number\nExample 3 4\n\n");
    int a[num_congruences], m[num_congruences];
    for (int i = 0; i < num_congruences; i++) {
        printf("Enter a and m for congruence %d: ", i + 1);
        scanf("%d %d", &a[i], &m[i]);
    }

    int M = 1;
    for (int i = 0; i < num_congruences; i++) {
        M *= m[i];
    }

    int x = 0;
    for (int i = 0; i < num_congruences; i++) {
        int Mi = M / m[i];
        int Mi_inv = modular_inverse(Mi, m[i]);
        x += a[i] * Mi * Mi_inv;
    }

    printf("\nThe solution is : x congruent to %d (mod %d)\n", x % M, M);

    return 0;
    
}
