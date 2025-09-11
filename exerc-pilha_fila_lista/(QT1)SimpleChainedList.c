#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int qtd;
    struct Node* prox;

}Node;

Node* insertInFirst(Node* h,int v) {
    Node* new =malloc(sizeof(Node));
    if(new == NULL) {
        printf("Memory Error");
        exit(1);
    }
    new->data = v;
    new->prox = h;
    new->qtd++;
    return new;
}

Node* insertInEnd(Node* head,int v) {
    Node* new =malloc(sizeof(Node));
    if(new == NULL) {
        printf("Memory Error");
        exit(1);
    }
    new->data = v;
    new->prox = NULL;
    new->qtd++;

    if(head==NULL) {
        return new;
    }
    Node* actual=head;
    while(actual->prox!=NULL) {
        actual=actual->prox;
    }
    actual->prox = new;
    return head;

}

void FreeList(Node* h) {
    Node* actual =h;
    while(actual!=NULL) {
        Node* temp = actual->prox;
        free(actual);
        actual = temp;
    }

}

void printList(Node* h) {
    Node* actual = h;
    while (actual != NULL) {
        printf("%d -> ", actual->data);
        actual = actual->prox;
    }
    printf("NULL\n");
}

Node* rmv(Node* head, int val) {
    //Se a lista estiver vazia, retorna NULL.
    if (head == NULL) {
        return NULL;
    }

    // Parte que Encontra o valor na Lista
    for (int i=0; i<head->qtd; i++) {
        if (head->data == val) {
            Node* proxNode = head->prox;
            free(head);
            return proxNode;
        }
        head->prox = rmv(head->prox, val);
    }
        return head;
}

int main() {

    Node* head=NULL;
    head=insertInFirst(head,10);
    head=insertInFirst(head,20);
    head=insertInFirst(head,30);
    head=insertInEnd(head,40);
    head=rmv(head,20);





    printList(head);

    FreeList(head);


    return 0;
}