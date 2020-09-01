#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node_t;

node_t * head = NULL, *prev;

void print_list(node_t * head) {
    
	node_t * current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void insert_node() {
	node_t * temp;
	
	temp = malloc(sizeof(node_t));
       scanf("%d", &temp -> data);
       temp -> next = NULL;
       if(head==NULL)
           head = temp;
       else
           prev -> next = temp;
       prev = temp;
 
}
void delete_node (node_t * before_del) {
	node_t * temp;
	temp = before_del -> next;
	before_del -> next = temp -> next;
	free (temp);
	
}

int main () {
	node_t *temp;
	int n;
	printf ("Enter the number of elements in the list:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
		insert_node ();
    
    print_list (head);
    printf("\n");
    delete_node(head -> next); // node that will be deleted is head->next->next
    print_list (head);
	
	return 0;
}
