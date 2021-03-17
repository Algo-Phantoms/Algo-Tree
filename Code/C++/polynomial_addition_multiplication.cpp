/*
C++ implementation of polynomial addition and multiplication using Linked List
Implementation of polynomial addition and multiplication is one of the application
linked list.
polynomial addition :
To add two polynomials P and Q and to
get a resultant polynomial R
polynomial multiplication :
Multiply two polynomials P and Q and
store the product in resultant polynomial
R.
*/

#include <iostream>

using namespace std;

typedef struct node
{
    int exp;
    int coef;
    struct node *next;
} node;
node *getNode()
{
    node *New = (node *)malloc(sizeof(node));
    New->next = NULL;
    return New;
}

// function to input polynomials and store it

void input(node *ptr, int n)
{
    node *Hptr = ptr;
    ptr = ptr->next;
    int temp;
    int e = n;
    while (n--)
    {
        cin >> temp;
        if (temp != 0)
        {
            node *New = getNode();
            New = getNode();
            New->coef = temp;
            New->exp = e - n - 1;
            New->next = ptr;
            ptr = New;
        }
    }
    Hptr->next = ptr;
}

// function to compare the exponents

int compare(node *Pptr, node *Qptr)
{
    if (Pptr->exp == Qptr->exp)
    {
        return 0;
    }
    else if (Pptr->exp > Qptr->exp)
    {
        return 1;
    }
    return -1;
}

void printOpp(node *ptr)
{
    ptr = ptr->next;
    printf("(");
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%dx^%d", ptr->coef, ptr->exp);
        }
        else
        {
            printf("%dx^%d+", ptr->coef, ptr->exp);
        }
        ptr = ptr->next;
    }
    printf(")");
}

void printRes(node *ptr)
{
    ptr = ptr->next;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%dx^%d", ptr->coef, ptr->exp);
        }
        else
        {
            printf("%dx^%d+", ptr->coef, ptr->exp);
        }
        ptr = ptr->next;
    }
}

// function to print the result of polynomial addition

void printAdd(node *ptr1, node *ptr2, node *ptr3)
{
    printOpp(ptr1);
    printf("+");
    printOpp(ptr2);
    printf(" = ");
    printRes(ptr3);
}

//function to add two polynomials

void AddPolynomials(node *HEADER_1, node *HEADER_2)
{
    node *Pptr, *Qptr;
    int sum = 1;
    node *HEADER_3 = getNode();
    node *Rptr;
    Pptr = HEADER_1->next;
    Qptr = HEADER_2->next;
    Rptr = HEADER_3;
    while ((Pptr != NULL) && (Qptr != NULL))
    {
        int c = compare(Pptr, Qptr);
        node *New = getNode();
        switch (c)
        {
        case 1:
            New->coef = Pptr->coef;
            New->exp = Pptr->exp;
            Rptr->next = New;
            Pptr = Pptr->next;
            Rptr = Rptr->next;
            break;
        case 0:
            sum = Pptr->coef + Qptr->coef;
            if (sum)
            {
                New->coef = sum;
                New->exp = Pptr->exp;
                Rptr->next = New;
                Pptr = Pptr->next;
                Qptr = Qptr->next;
                Rptr = Rptr->next;
            }
            else
            {
                free(New);
            }
            break;
        case -1:
            New->coef = Qptr->coef;
            New->exp = Qptr->exp;
            Rptr->next = New;
            Qptr = Qptr->next;
            Rptr = Rptr->next;
            break;
        }
    }
    while ((Pptr != NULL) && (Qptr == NULL))
    {
        while (Pptr != NULL)
        {
            node *New = getNode();
            New->coef = Pptr->coef;
            New->exp = Pptr->exp;
            Rptr = New;
            Rptr = Rptr->next;
            Pptr = Pptr->next;
        }
    }
    while ((Pptr == NULL) && (Qptr != NULL))
    {
        while (Qptr != NULL)
        {
            node *New = getNode();
            New->coef = Qptr->coef;
            New->exp = Qptr->exp;
            Rptr = New;
            Rptr = Rptr->next;
            Qptr = Qptr->next;
        }
    }
    printf("result of polynomial addition\n");
    printAdd(HEADER_1, HEADER_2, HEADER_3);
}

//function to print the result of polynomial multiplication

void printMUL(node *ptr1, node *ptr2, node *ptr3)
{
    printOpp(ptr1);
    printf("*");
    printOpp(ptr2);
    printf(" = ");
    printRes(ptr3);
}

//function to multiply two polynomials

void MultiplyPolynomails(node *HEADER_1, node *HEADER_2)
{
    node *HEADER_3 = getNode();
    node *ptr3 = HEADER_3->next;
    node *ptr1 = HEADER_1->next;
    node *ptr2 = HEADER_2->next;
    node *Rptr3;
    if ((ptr1 == NULL) || (ptr2 == NULL))
    {
        return;
    }
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int c = ptr1->coef * ptr2->coef;
            int x = ptr1->exp + ptr2->exp;
            ptr3 = HEADER_3->next;
            Rptr3 = HEADER_3;
            while ((ptr3 != NULL) && (ptr3->exp > x))
            {
                Rptr3 = ptr3;
                ptr3 = ptr3->next;
            }
            if (ptr3 == NULL)
            {
                node *New = getNode();
                New->coef = c;
                New->exp = x;
                Rptr3->next = New;
            }
            else
            {
                if (ptr3->exp == x)
                {
                    ptr3->coef += c;
                }
                else
                {
                    node *New = getNode();
                    New->coef = c;
                    New->exp = x;
                    Rptr3->next = New;
                    New->next = ptr3;
                }
            }

            ptr2 = ptr2->next;
        }
        ptr2 = HEADER_2->next;
        ptr1 = ptr1->next;
    }
    printf("Result of polynomial multiplication :\n");
    printMUL(HEADER_1, HEADER_2, HEADER_3);
}
int main()
{
    node *HEADER_1, *HEADER_2;
    HEADER_1 = getNode();
    HEADER_2 = getNode();
    int n1, n2;
    printf("Enter the number of coefficients in the first polynomial\n");
    cin >> n1;
    printf("Enter the of coeficients in the first polynomial\n");
    input(HEADER_1, n1);
    printf("Enter the number of coefficients in the second polynomial\n");
    cin >> n2;
    printf("Enter the of coeficients in the second polynomial\n");
    input(HEADER_2, n2);
    int choice;
    printf("Enter the choice for polynomial multiplication (1) , polynomial addition (2) \n");
    cin >> choice;
    switch (choice)
    {
    case 1:
        MultiplyPolynomails(HEADER_1, HEADER_2);
        break;
    case 2:
        AddPolynomials(HEADER_1, HEADER_2);
        break;
    }
    return 0;
}

/*
Sample I/O :
1)

Enter the number of coefficients in the first polynomial
3
Enter the of coeficients in the first polynomial
4 5 2
Enter the number of coefficients in the second polynomial
3
Enter the of coeficients in the second polynomial
6 5 8
Enter the choice for polynomial multiplication (1) , polynomial addition (2)
1
Result of polynomial multiplication :
(2x^2+5x^1+4x^0)*(8x^2+5x^1+6x^0) = 16x^4+50x^3+69x^2+50x^1+24x^0

Time complexity for polynomial multiplication : O(n^3)

2)

Enter the number of coefficients in the first polynomial
4
Enter the of coeficients in the first polynomial
5 6 7 8
Enter the number of coefficients in the second polynomial
4
Enter the of coeficients in the second polynomial
1 2 3 4
Enter the choice for polynomial multiplication (1) , polynomial addition (2)
2
result of polynomial addition
(8x^3+7x^2+6x^1+5x^0)+(4x^3+3x^2+2x^1+1x^0) = 12x^3+10x^2+8x^1+6x^0

Time complexity for polynomial addition : O(n)

*/
