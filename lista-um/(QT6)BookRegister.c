#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int year;

}Book;

void printBook(Book r[],int qtd) {
    printf("Enter the Year to the Search:");
    int y;
    scanf("%d",&y);


    printf("Book Released after the Year: %d\n",y);
    for (int i=0;i<qtd;i++) {
        if(r[i].year>y)
        printf("%s\n",r[i].title);
    }


}

int main() {
    printf("Enter the Number of Books that will be Registered: ");
    int n=0;
    scanf("%d",&n);

    char title[51];
    char author[51];

    Book *books;
    books=malloc(n*sizeof(Book));
    if(books==NULL) {
        printf("Memory Error");

        return 1;
    }

    for(int i=0;i<n;i++) {
        printf("Enter the Title of the book:");
        scanf(" %50[^\n]",title);
        books[i].title=malloc((strlen(title)+1));
        if(books[i].title==NULL) {
            printf("Memory Error");
            for (int j = 0; j < i; j++) {
                free(books[j].title);
                free(books[j].author);
            }free(books);
            return 1;
        }
        strcpy(books[i].title,title);
        printf("Enter the Author of the book:");
        scanf(" %50[^\n]",author);
        books[i].author=malloc((strlen(author)+1));
        if(books[i].author==NULL) {
            printf("Memory Error");
            for (int j = 0; j < i; j++) {
                free(books[j].title);
                free(books[j].author);
            }free(books);
            return 1;
        }
        strcpy(books[i].author,author);

        printf("Enter the Year of the book:");
        scanf("%d",&books[i].year);
        printf("\n");

    }

        printBook(books,n);


    for(int i=0;i<n;i++) {
        free(books[i].title);
        free(books[i].author);
    }
    free(books);

    return 0;
}