#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int code;
    float price;

}Product;

void printProduct(Product product) {
    printf("Product Name: %s\n",product.name);
    printf("Product Code: %d\n",product.code);
    printf("Product Price: %.2f\n",product.price);
}

int main() {

    Product p1;
    char name[31];
    printf("Write the product name:");
    scanf(" %30[^\n]",name);
    p1.name=malloc((strlen(name)+1));
    if (p1.name == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    strcpy(p1.name,name);
    printf("Write the product code:");
    scanf("%d",&p1.code);
    printf("Write the product price:");
    scanf("%f",&p1.price);

    printProduct(p1);

    free(p1.name);
    p1.name=NULL;


    return 0;
}