#include <stdio.h>

int count(int vect[],int n) {
    if (n==1) {
        return vect[0];
    }
    int largest = count(vect + 1, n - 1);

    if (vect[0]>largest) {
        return vect[0];
    }else {
        return largest;
    }


}

int main() {

    int number[8]={10,5,25,65,80,10,3};
    printf("%d",count(number,8));



    return 0;
}