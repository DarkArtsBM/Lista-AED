#include <stdio.h>

int count(int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    return 1 + count(n/10);
}

int main() {
    printf("%d",count(20));
}
