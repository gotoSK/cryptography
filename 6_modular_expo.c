//WAP to compute b^n mod m using modular exponential algo.
#include <stdio.h>

int  power_mod(int  b, int  n,  int m) {
    int result = 1;
    while (n > 0) {
        // If n is odd, multiply result with b
        if (n % 2 == 1) {
            result = (result * b) % m;
        }
        // Square b and reduce n by half
        b = (b * b) % m;
        n /= 2;
    }
    return result;
}

int main() {
    int  b, n, m;
    printf("Enter the base (b): ");
    scanf("%d", &b);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);
    printf("Enter the modulus (m): ");
    scanf("%d", &m);

     int result = power_mod(b, n, m);
    printf("%d^%d mod %d = %d\n", b, n, m, result);

    return 0;
}


