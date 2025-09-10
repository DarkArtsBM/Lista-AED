#include <stdio.h>

int regressiveCount(int a) {
    if (a>=0) {
        for (int i=0; i<=a; i++) {
            printf("%d ",a-i);
        }
    }return 0;
}

int main() {
    regressiveCount(5);
    return 0;
}