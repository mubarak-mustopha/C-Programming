# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
}node_t ;

node_t * head = NULL;
head = (node_t *) malloc(sizeof(node_t));

head->val = 1;
head->next = (node_t *) malloc(sizeof(node_t));

head->next->val = 2;
head->next->next = NULL;

void print_list_recurse(node_t * head){
    if (head==NULL){
        printf("End of list");
        return;
    }else {
        printf("%d\n", head->val);
        print_list(head->next);
    }
}

void print_list(node_t * head){

    node_t * current = head;
    while(current != null){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val){
    node_t * current = head;
    while (current->next != NULL){
        current = current->next;
    }

    node_t * new_node;
    new_node->val = val;
    new_node->next = NULL;

    current->next = new_node;
}