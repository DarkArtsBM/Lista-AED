#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *diagnoses;
}Patient;

void printPatient(Patient p[], int qtd) {
    printf("Name of patients over 60:\n");
    for (int i = 0; i < qtd; i++) {
        if (p[i].age>60)
        printf("%s\n", p[i].name);
    }
}

void freePatient(Patient p[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        free(p[i].name);
        free(p[i].diagnoses);
    }
}
int main() {
    int n=0;
    printf("How many Patients will be registered? ");
    scanf("%d",&n);

    Patient *p;
    p=(Patient*)malloc(n*sizeof(Patient));
    if (p==NULL) {
        printf("Memory Error!\n");
        return 1;
    }

    char name[50];
    char diagnoses[100];

    for(int i=0;i<n;i++) {
        printf("Enter Patient name: ");
        scanf(" %49[^\n]",name);
        p[i].name=malloc((strlen(name)+1));
        if (p[i].name==NULL) {
            printf("Memory Error");
            for (int j=0;j<i;j++) {
                free(p[j].name);
                free(p[j].diagnoses);
            }free(p);
            return 1;
        }strcpy(p[i].name,name);

        printf("Enter Patient Age:");
        scanf("%d",&p[i].age);

        printf("Enter Patient diagnoses: ");
        scanf(" %99[^\n]",diagnoses);
        p[i].diagnoses=malloc((strlen(diagnoses)+1));
        if (p[i].diagnoses==NULL) {
            printf("Memory Error");
            for (int j=0;j<i;j++) {
                free(p[j].name);
                free(p[j].diagnoses);
            }free(p);
            return 1;
        }strcpy(p[i].diagnoses,diagnoses);

    }

    printPatient(p,n);
    freePatient(p,n);
    free(p);

    return 0;
}