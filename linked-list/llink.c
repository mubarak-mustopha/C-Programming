# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;


void print_list(node_t * head){
    node_t * current = head;

    while (current!=NULL){
        printf("%d->", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void push(node_t * head, int val){
    node_t * current = head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push_v1(node_t **head, int val){
    node_t * node = (node_t *) malloc(sizeof(node_t));
    node->val = val;
    node->next = *head;
    *head = node;
}  

int pop(node_t **head){
    node_t * node_1 = *head;
    *head = node_1->next;
    node_1->next = NULL;

    free(node_1);
}

int main(){
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));

    head->next->val = 2;
    head->next->next = (node_t *) malloc(sizeof(node_t));

    head->next->next->val = 3;
    head->next->next->next = (node_t *) malloc(sizeof(node_t));

    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    push(head, 5);
    push(head, 6);
    push(head, 7);

    print_list(head);
}