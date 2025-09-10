#include <stdio.h>

int count(int vect[],int n) {
    int largest = 0;
    for (int i=0;i<n;i++) {
        if (vect[i]>largest) {
                largest=vect[i];
            }
        }
    return largest;
}

int main() {

    int number[8]={10,5,25,65,80,10,3};
    printf("%d",count(number,8));



    return 0;
}