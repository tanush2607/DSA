#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *insert(int data, node *head) {
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        return ptr;
    } else {
        node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

node *list(node *head) {
    printf("Enter the long number: ");
    long int n;
    scanf("%ld", &n);
    while (n) {
        int req = n % 10;
        n = n / 10;
        head = insert(req, head);
    }
    return head;
}

node *add(node *num1, node *num2) {
    node *result = NULL;
    node *p1 = num1;
    node *p2 = num2;
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        int sum = carry;

        if (p1 != NULL) {
            sum += p1->data;
            p1 = p1->next;
        }

        if (p2 != NULL) {
            sum += p2->data;
            p2 = p2->next;
        }
carry = sum / 10;
       
         int digit = sum % 10;

        result = insert(digit, result);
    }

    return result;
}

void printList(node *head) {
    if (head == NULL) {
        return;
    }
    //recurssion usage for reversing the output for desired result
    printList(head->next);
    printf("%d", head->data);
}

int main() {
    node *n1 = NULL;
    node *n2 = NULL;

    n1 = list(n1);
    n2 = list(n2);

    node *result = add(n1, n2);

    printf("The sum is: ");
    printList(result);
    printf("\n");

    return 0;
}
