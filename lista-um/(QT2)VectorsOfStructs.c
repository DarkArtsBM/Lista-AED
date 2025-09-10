//
// Created by robso on 03/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int mat;
    float grade;
} Student;


int main() {
    Student s[5];
    float sum=0;


    for (int i = 0; i < 5; i++) {
        char nome[50];


        printf("Enter the name of student #%d: ",i+1);
        scanf(" %49[^\n]",nome);
        s[i].name = malloc((strlen(nome)+1)*sizeof(char));
        strcpy(s[i].name,nome);



        printf("Write the register of student #%d: ",i+1);
        scanf("%d",&s[i].mat);



        printf("Write the grade of student #%d: ",i+1);
        scanf("%f",&s[i].grade);


    }

    for (int i = 0; i < 5; i++) {
        sum+=s[i].grade;

    }
    printf("The avg grade of the class is %.2f\n", sum/5);

    for (int i = 0; i < 5; i++) {
        free(s[i].name);
    }

    return 0;
}