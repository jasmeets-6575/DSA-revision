#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void create ( struct Poly *p )
{
    int i;
    printf("Enter the non zero terms");
    scanf("%d", &p->n);

    p->t = (struct Term *)malloc( p->n * sizeof(struct Term));
    printf("Enter the coefficient and the expression of x");
    for (i=0; i<p->n; i++)
        scanf("%d%d", &p->t[i].coeff, &p->t[i].exp);
}

void display (struct Poly p)
{
    int i,x, sum=0;
    for( i =0; i<p.n ; i++)
        printf("%dx%d+",p.t[i].coeff, p.t[i].exp);
    // {
    //     sum += p.t[i].coeff * pow(x , p.t[i].exp);
    // }
    // printf("The expression is: %dx", sum);
}

struct Poly* add( struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    i=j=k=0;

    struct Poly *sum;

    sum = (struct Poly*)malloc(sizeof(struct Poly));
    sum->t= (struct Term *)malloc((p1->n+p2->n) * sizeof(struct  Term));

    while ( i < p1->n && j < p2->n)
    {
        if(p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
                sum->t[k++] = p2->t[j++];
        else {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }

    for (; i< p1->n; i++) 
        sum->t[k++] = p1->t[i];
    for (; j< p2->n; j++) 
        sum->t[k++] = p2->t[j];

    sum->n=k;

    return sum;
}

int main ()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);
    return 0;
}