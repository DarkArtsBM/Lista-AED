#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *model;
    int year;
    float price;
}Car;

void printCar(Car *car) {
    printf("Car Model: %s\n",car->model);
    printf("Car year: %d\n",car->year);
    printf("Car Price: %.2f\n",car->price);
}

int main() {

    Car *r;
    r=(Car*)malloc(sizeof(Car));

    if(r==NULL) {
        printf("Memory Error");
        return 1;
    }

    char name[31];
    printf("Write the car Model: ");
    scanf(" %30[^\n]",name);
    r->model=malloc((strlen(name)+1));
    if(r->model==NULL) {
        printf("Memory Error");
        return 1;
    }
    strcpy(r->model,name);
    printf("Write the car Year: ");
    scanf("%d",&r->year);
    printf("Write the car Price: ");
    scanf("%f",&r->price);

    printCar(r);
    free(r->model);
    free(r);




    return 0;
}


