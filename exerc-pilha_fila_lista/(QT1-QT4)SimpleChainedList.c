#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* prox;
    struct Node* prev;


}Node;

// para ordernar
void swap(Node* head, Node* temp) {
    int temp_buffer = head->data;
    head->data = temp->data;
    temp->data = temp_buffer;

}
int sortList(Node* head) {
    Node* temp = head->prox;
    if (head->data > temp->data) {
        swap(head, temp);
        return 1;
    }return 0;
}
int orderList(Node* head) {
    int flag = 0;
    Node* actual = head;

    while (actual != NULL && actual->prox != NULL) {
        if (sortList(actual)) {
            flag = 1;
        }
        actual = actual->prox;
    }
    return flag; // retorna se houve alguma troca nesse passe
}
void sortAll(Node* head) {
    while (orderList(head)); // repete até não haver mais trocas
}
//**********************************************************????????????????????????????????


//Inserir e Liberar
Node* insertInFirst(Node* head,int value) {
    Node* new =malloc(sizeof(Node));
    if(new == NULL) {
        printf("Memory Error");
        exit(1);
    }
    new->data = value;
    new->prox = head;
    new->prev = NULL;
    if (head!= NULL) {
        head->prev= new;
        Node*temp = head->prev;
        if (head->data < temp->data) {
            swap(head, temp);
        }
    }sortAll(head);
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

    if(head==NULL) {
        new->prev = NULL;
        return new;
    }
    Node* actual=head;
    while(actual->prox!=NULL) {
        actual=actual->prox;
    }
    actual->prox = new;
    new->prev = actual;
    sortAll(head);
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
//**************************************************//


//Imprimir
void printList(Node* h) {
    Node* actual = h;
    if (h == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    while (actual != NULL) {
        printf("%d -> ", actual->data);
        actual = actual->prox;
    }
    printf("NULL\n");
}
void printListInvert(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    // vamos pegar o ultimo endereco
    Node* last = head;
    while (last->prox != NULL) {
        last = last->prox;
    }

    // agora vamos imprmir de tras para frente
    Node* actual = last;
    while (actual != NULL) {
        printf("%d -> ", actual->data);
        actual = actual->prev;
    }
    printf("NULL\n");
}

//************************************************//



Node* rmv(Node* head, int val) {
    //Se a lista estiver vazia, retorna NULL.
    if (head == NULL) {
        return NULL;
    }
    //Conta quantos Elementos tenhos na lista
    Node* actual = head;
    int sum=0;
    while (actual != NULL) {
        actual = actual->prox;
        sum++;
    }

    // Parte que Encontra o valor na Lista
    //for para entrar na lista varias vezes para rmv valores repetidos.
    for (int i=0; i<sum; i++) {
        if (head->data == val) {
            Node* proxNode = head->prox;
            proxNode->prev = head->prev;
            free(head);
            return proxNode;
        }
        head->prox = rmv(head->prox, val);
    }
        return head;
}

void howMany(Node* head) {
    Node* actual = head;
    int sum=0;
    while (actual != NULL) {
        actual = actual->prox;
        sum++;
    }
    printf("There is %d elements in the list\n",sum);
}



int main() {

    Node* head=NULL;
    head=insertInFirst(head,1);
    head=insertInFirst(head,10);
    head=insertInFirst(head,60);
    head=insertInFirst(head,20);
    head=insertInFirst(head,30);
    head=insertInFirst(head,50);
    head=insertInEnd(head,25);
    head=insertInEnd(head,40);
    rmv(head,20);




    howMany(head);
    printList(head);
    printListInvert(head);

    FreeList(head);


    return 0;
}