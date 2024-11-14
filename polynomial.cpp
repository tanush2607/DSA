#include <iostream>
using namespace std;

typedef struct node
{
    int coeff;
    int exp;
    node *next;
} node;

node *insert(int c, int e, node *head)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->coeff = c;
    ptr->exp = e;
    ptr->next = NULL;
    if (head == NULL)
    {
        return ptr;
    }
    else
    {
        node *p =head;
        while (p->next != NULL)
        {
            p = p->next;
        }
            p->next = ptr;
    }
    return head;
}

node *add(node *poly1, node *poly2)
{
    node *poly3 = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        int c, e;
        if (poly1->exp > poly2->exp)
        {
            c = poly1->coeff;
            e = poly1->exp;
            poly1 = poly1->next;
        }
        else if (poly2->exp > poly1->exp)
        {
            c = poly2->coeff;
            e = poly2->exp;
            poly2 = poly2->next;
        }
        else
        {
            c = poly1->coeff + poly2->coeff;
            e = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly3 = insert(c, e, poly3);
    }
    while (poly1 != NULL)
    {
        poly3 = insert(poly1->coeff, poly1->exp, poly3);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        poly3 = insert(poly2->coeff, poly2->exp, poly3);
        poly2 = poly2->next;
    }

    return poly3;
}



node* multiply(node* poly1, node* poly2) {
    node* poly3 = NULL;

    // Iterate over each term of poly1
    for (node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        // For each term of poly1, iterate over each term of poly2
        for (node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            int c = ptr1->coeff * ptr2->coeff;
            int e = ptr1->exp + ptr2->exp;
            poly3 = insert(c, e, poly3);
        }
    }

    return poly3;
}

void printPoly(node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->exp;
        if (head->next != NULL) {
            cout << " + ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating first polynomial 3x^2 + 5x^1 + 6
    node* poly1 = NULL;
    poly1 = insert(3, 3, poly1);
    poly1 = insert(5, 1, poly1);
    poly1 = insert(6, 0, poly1);

    // Creating second polynomial 4x^2 + 2x^1 + 3
    node* poly2 = NULL;
    poly2 = insert(4, 2, poly2);
    poly2 = insert(2, 1, poly2);
    poly2 = insert(3, 0, poly2);

    // Adding the two polynomials
    node* poly3 = add(poly1, poly2);

    // Printing the resultant polynomial
    cout << "Polynomial 1: ";
    printPoly(poly1);

    cout << "Polynomial 2: ";
    printPoly(poly2);

    cout << "Sum of the two polynomials: ";
    printPoly(poly3);

     // Multiplying the two polynomials
    node* poly4 = multiply(poly1, poly2);

    // Printing the resultant polynomial
    cout << "Polynomial 1: ";
    printPoly(poly1);

    cout << "Polynomial 2: ";
    printPoly(poly2);

    cout << "Product of the two polynomials: ";
    printPoly(poly4);

    return 0;
}