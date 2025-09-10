#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *name;
    char *number;
}Contact;

void searchContact(Contact c[], int qtd) {
    char searchName[50];
    char resp=' ';

do {
    printf("Do u want to look for a contact? (y/n)");
    scanf(" %c",&resp);
    resp=tolower(resp);
    if (resp=='y') {
        printf("Enter Name: ");
        scanf(" %49[^\n]",searchName);
        int found=0;
        for (int i=0;i<qtd;i++) {
            if (strcmp(searchName,c[i].name)==0) {
                printf("contact found at index the number is %s\n",c[i].number);
                found =1;
                break;
            }
        }if (!found)
            printf("Contact not found\n");
    }
}while (resp!='n');


}


int main() {
    printf("how many contacts do u want to register: ");
    int n=0;
    scanf("%d",&n);

    Contact *contact;
    contact = (Contact*) malloc(n*sizeof(Contact));
    if (contact == NULL) {
        printf("Memory Error");
        return 1;
    }

    char name[50];
    char number[15];

    for (int i=0;i<n;i++) {
        printf("Enter Name : ");
        scanf(" %49[^\n]",name);
        contact[i].name=malloc((strlen(name)+1));
        if (contact[i].name==NULL) {
            printf("Memory Error");
            for (int j=0;j<n;j++) {
                free(contact[j].name);
                free(contact[j].number);

            }free(contact);
            return 1;
        }
        strcpy(contact[i].name,name);
        printf("Enter Number : ");
        scanf(" %14[^\n]",number);
        contact[i].number=malloc((strlen(number)+1));
        if (contact[i].number==NULL) {
            printf("Memory Error");
            for (int j=0;j<n;j++) {
                free(contact[j].name);
                free(contact[j].number);

            }free(contact);
            return 1;
        }
        strcpy(contact[i].number,number);
    }

    searchContact(contact,n);

    for (int i=0;i<n;i++) {
        free(contact[i].name);
        free(contact[i].number);
    }
    free(contact);



    return 0;
}
