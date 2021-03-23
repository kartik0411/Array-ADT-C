//THIS PROGRAM IS FOR BASIC OPERATIONS LIKE ADDITION, SUBTRACTION OF 2 POLYNOMIALS AND EVALUATING THE POLYNOMIAL FUNCTION VALUE BY GIVNG THE X VALUE AS INPUT
//Note: Please store polynomial terms by decreasing value of exponent

#include<stdio.h>
#include<math.h>

struct term{ //just to store the values of every term of the polynomial in an (exponent, coefficient) tuple
    int exp;
    int coeff;
};

struct polynomial{
    int n;
    struct term* A;
};


void create(struct polynomial* poly)
{
    printf("Enter the number of terms of the polynomial you wanna store :");
    scanf("%d",&poly->n);
    poly->A=(struct term*)malloc(poly->n*sizeof(struct term));
}

void read(struct polynomial* poly)
{
    int coeff,exp,k=0;
    printf("\nEnter the terms: (coefficient and exponent of every term)");
    for(int i=0;i<poly->n;i++)
    {
        printf("\nEnter for element no. %d : ",i+1);
        scanf("%d%d",&coeff,&exp);
        if(coeff!=0) // if coefficient is non zero then only it will store the term in the term tuple
        {
            poly->A[k].coeff = coeff;
            poly->A[k++].exp = exp;
        }
    }
    poly->n=k;
}


void display(struct polynomial poly)
{
    printf("\nThe Polynomial is : ");
    for(int i=0;i<poly.n;i++)
    {
        if(i>0)
        {
            if(poly.A[i].coeff>0)
            {
                printf(" +"); // printing + because the positive numbers are not printed with + sign
            }
            else if(poly.A[i].coeff<0)
            {
                printf(" ");
            }
        }

        if((poly.A[i].exp==0) || (poly.A[i].coeff!=1 && poly.A[i].coeff!=-1)) //if exponent of the term is 0 then it will execute , if not 0 then the term should not have coefficient as 1 or -1
        {
            printf("%d",poly.A[i].coeff); //printing only the coefficient first
        }
        else if(poly.A[i].coeff==-1) //if coefficient is -1 we would just print '-'before the term
        {
            printf("-");
        }

        if(poly.A[i].exp!=0) //if exponent is non zero then only we will print the values of the term that comes after coefficient
        {
            printf("x");
            if(poly.A[i].exp!=1)
            {
                printf("^%d",poly.A[i].exp);
            }
        }
    }
    printf("\n\n\n");
}


void evaluate(struct polynomial poly)
{
    int x,sum=0;
    printf("\nEnter the value of x for evaluation : ");
    scanf("%d",&x);

    for(int i=0;i<poly.n;i++)
    {
        sum+=poly.A[i].coeff*pow(x,poly.A[i].exp); //calculating the value of the term after assigning value of x
    }
    printf("\nThe Result after evaluating the polynomial with value %d is %d\n",x,sum);
}



void add(struct polynomial poly1, struct polynomial poly2)
{
    struct polynomial sum;
    int i,j,k;
    i=j=k=0;
    sum.A=(struct term*)malloc((poly1.n+poly2.n)*sizeof(struct term));

    while(i<poly1.n && j<poly2.n)
    {
        if(poly1.A[i].exp>poly2.A[j].exp)//first polynomial term's exponent is bigger
        {
            sum.A[k++]=poly1.A[i++];
        }
        else if(poly2.A[j].exp>poly1.A[i].exp) //second polynomial term's exponent is bigger
        {
            sum.A[k++]=poly2.A[j++];
        }
        else{ //both polynomial term's exponent is same
            sum.A[k]=poly1.A[i++]; //first copying first polynomial's complete term
            sum.A[k++].coeff+=poly2.A[j++].coeff; //adding only the coefficient of the 2nd polynomial's term
        }
    }
    //now copying rest of the terms of either polynomial which is left
    for(;i<poly1.n;i++)
    {
        sum.A[k++]=poly1.A[i];
    }
    for(;j<poly2.n;j++)
    {
        sum.A[k++]=poly2.A[j];
    }

    sum.n=k; //k is the number of terms after incrementing previously

    printf("\n\n\n\nOPERATION DONE SUCCESSFULLY .........\n\nThe new polynomial created:\n");
    display(sum);
    free(sum.A);
}


void sub(struct polynomial poly1, struct polynomial poly2) //It only inverts the sign of every term of the second polynomial and then pass both the polynomials for adding, still works like subtracting both
{
    for(int i=0;i<poly2.n;i++)
    {
        poly2.A[i].coeff=-1*poly2.A[i].coeff;
    }
    add(poly1,poly2);
}



int main()
{
    struct polynomial poly1,poly2;
    int k;
    create(&poly1);
    read(&poly1);
    display(poly1);

    printf("MENU:\n1.EVALUATING ITS VALUE BY GIVING INPUT\n2.ADDING WITH ANOTHER POLYNOMIAL\n3.SUBTRACTING WITH ANOTHER POLYNOMIAL\n\n");
    scanf("%d",&k);
    printf("\n");
    switch(k)
    {
    case 1:
        evaluate(poly1);
        break;

    case 2:
        create(&poly2);
        read(&poly2);
        display(poly2);
        add(poly1,poly2);
        break;

    case 3:
        create(&poly2);
        read(&poly2);
        display(poly2);
        sub(poly1,poly2);
        break;
    }

    return 0;
}
