#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *name;
    int age;
    float height;
} Pessoa;



int main() {
    Pessoa p;
    char nome[50];
    printf("Enter the name of the pessoa:");
    scanf(" %[^\n]", nome);
    p.name=malloc(strlen(nome)+1);
    strcpy(p.name,nome);
    printf("Enter the age of the pessoa:");
    scanf("%d",&p.age);
    printf("Enter the height of the pessoa:");
    scanf("%f",&p.height);


    printf("%s",p.name);
    printf("\n");
    printf("%d",p.age);
    printf("\n");
    printf("%.2f",p.height);
    free(p.name);

    return 0;
}