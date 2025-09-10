#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *position;
    float wage;
}Employee;

void printEmployee(Employee e) {
    printf("Employee name: %s\n",e.name);
    printf("Employee position: %s\n",e.position);
    printf("Employee wage: %.2f\n",e.wage);
}

int main() {
    printf("How many employees will you register: ");
    int n=0;
    scanf("%d",&n);
    Employee e[n];
    char name[51];
    char position[31];
    for(int i=0;i<n;i++) {
        printf("Enter Employee Name: ");
        scanf(" %50[^\n]",name);
        e[i].name=malloc((strlen(name)+1));
        if (e[i].name==NULL) {
            printf("Memory Error!\n");
            return 1;
        }
        strcpy(e[i].name,name);
        printf("Enter Employee Position: ");
        scanf(" %30[^\n]",position);
        e[i].position=malloc((strlen(position)+1));
        if (e[i].position==NULL) {
            printf("Memory Error!\n");
            return 1;
        }
        strcpy(e[i].position,position);

        printf("Enter Employee Wage: ");
        scanf("%f",&e[i].wage);
        printf("\n");

    }
    for(int i=0;i<n;i++) {
        printf("Employee #%d\n",i+1);
        printEmployee(e[i]);
        printf("\n");
    }

    for (int i=0;i<n;i++) {
        free(e[i].name);
        free(e[i].position);
    }
    return 0;
}
