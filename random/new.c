#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void printList(node *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node *reverse(node *head){
    node *p = NULL, *q = NULL, *r = head;
    while(r){
        q = p;
        p = r;
        r = r->next;
        p->next = q;
    }
    return p;
}

int main(){
    int n, i;
    scanf("%d",&n);
    node *head = NULL;
    node *ptr = head;
    for(i=0; i<n; i++){
        node *tmp = (node*)malloc(sizeof(node));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if(head==NULL)
            head = tmp;
        else
            ptr->next = tmp;
        ptr = tmp;
    }
    printList(head);
    node *rev = reverse(head);
    printList(rev);
    
}

//g++ "new.c" && a