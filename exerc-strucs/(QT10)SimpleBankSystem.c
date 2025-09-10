#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int number;
    float balance;
}BankAccount;

void deposit(BankAccount b[],int number,float money) {
    if (number==b->number) {
        b->balance += money;
        printf("Deposit has benn done with success\n");
    }else {
        printf("Failed to deposit\n");
    }
}

void withdraw(BankAccount b[],int number,float money) {
    if (number==b->number) {
        if (b->balance<money) {
            printf("Failed to withdraw\n");
        }else {
            b->balance -= money;
            printf("Withdraw has been done with success\n");
        }
    }else {
        printf("Failed to withdraw\n");
    }
}

void printBalance(BankAccount b[],int number) {
    if (number==b->number)
    printf("Balance: %.2f\n",b->balance);
}

int main() {
    printf("Welcome to the Bank System\n");
    int n=0;
    printf("how manny account will be created today?");
    scanf("%d",&n);
    char name[50];

    BankAccount *b;
    b=(BankAccount*)malloc(n*sizeof(BankAccount));
    if(b==NULL) {
        printf("Memory Error\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        printf("Enter the Bank Account Number %d\n",i+1);
        scanf("%d",&b[i].number);

        printf("Enter the Bank Account Balance %d\n",i+1);
        scanf("%f",&b[i].balance);

        printf("Enter the Bank Account Name %d\n",i+1);
        scanf(" %49[^\n]",name);
        b[i].name=malloc((strlen(name)+1)*sizeof(char));
        if(b[i].name==NULL) {
            printf("Memory Error\n");
            for (int j=0;j<n;j++) {
                free(b[j].name);
            }free (b);
            return 1;
        }strcpy(b[i].name,name);
    }

    deposit(b,100,2000);
    printBalance(b,100);

    for(int i=0;i<n;i++) {
        free(b[i].name);
    }
    free (b);
}