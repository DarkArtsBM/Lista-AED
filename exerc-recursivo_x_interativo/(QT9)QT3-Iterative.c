#include <stdio.h>
int sumOfDigits(int n) {
    int digit=1;
    if (n < 0) n = -n;
    if (n < 10)
        return n%10;
    while (n>10) {
        digit+= n%10;
        n=n/10;
    }return digit;
}

int main() {
    printf("%d",sumOfDigits(9));
    return 0;
}

