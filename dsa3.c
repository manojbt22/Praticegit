#include <stdio.h>
#include <stdlib.h>
// global data

struct poly
{
    float coef;
    double exp;
    struct poly *next;
} *head, *temp;

void *create_node()
{
    struct poly *newnode = (struct poly *)malloc(sizeof(struct poly));
    return newnode;
}

void insert(struct poly **head, struct poly *newnode, int exp, float coef)
{
    if (!*head)
    {
        *head = newnode;
        newnode->coef = coef;
        newnode->exp = exp;
        newnode->next = NULL;
    }
    else
    {
        temp = *head;
        while (temp != NULL)
        {
            temp = temp->next;
        }
        newnode->coef = coef;
        newnode->exp = exp;
        newnode->next = NULL;
        temp->next = newnode;
    }
}

void display(struct poly *head)
{
    temp = head;

    while (temp != NULL)
    {
        printf("%fx^%d + ", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("+ 0\n");
}
int main()
{
    int i = 0, n = 0;

    printf("Enter the degree of the polynommial = ");
    scanf("%d\n", &n);

    // taking the coefficients

    for (i = n; i >= 0; i--)
    {
        float coef=00.0;
        printf("Enter the coefficient of the term x^%d", i);
        scanf("%d", &coef);

        insert(&head, create_node(), i, coef);
    }
};