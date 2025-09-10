#include <stdio.h>
#include <string.h>

int isPalindrome(char *a,int qtd) {
    if (qtd==0||qtd==1) {
        return 1;
    }if (a[qtd-1]!=a[0])
        return 0;

    return isPalindrome(a+1,qtd-2);
}


int main() {
    char original[100];
    printf("Digite uma frase ou palavra: ");
    scanf(" %99[^\n]", original);
    int len = strlen(original);
    printf("%d",isPalindrome(original,len));

    return 0;
}
