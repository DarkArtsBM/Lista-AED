#include <stdio.h>

int regressiveCount(int a) {
    if (a>=0) {
        printf("%d ",a);
        return regressiveCount(a-1);
    }
}

int main() {
    regressiveCount(5);

    return 0;
}