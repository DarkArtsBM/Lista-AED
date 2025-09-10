#include <stdio.h>

int sumOfDigits(int n) {
    if (n < 0) n = -n;
    if (n < 10) return n%10;
    return n%10 + sumOfDigits(n/10);
}

int main() {
    printf("%d",sumOfDigits(9));
    return 0;
}

