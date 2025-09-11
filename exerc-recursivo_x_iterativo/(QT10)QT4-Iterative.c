#include <stdio.h>

int product(int a, int b) {
    int sum=0;
    if (b==0) {
        return 0;
    }
    if (b>0) {
        for (;b>0; b--) {
            sum+=a;
        }
        return sum;
    }else {
        for (;b<0; b++) {
            sum+=-a;
        }return sum;
    }

}

int main() {

    printf("%d",product(5,-3));
}

