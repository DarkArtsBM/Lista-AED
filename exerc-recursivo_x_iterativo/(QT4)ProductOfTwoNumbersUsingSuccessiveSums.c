#include <stdio.h>

int product(int a, int b) {
    if (b==0) {
        return 0;
    }
    if (b>0) {
        return a+product(a,b-1);
    }else {
        return -a+product(a,b+1);
    }

}
int main() {

    printf("%d",product(5,3));
}

