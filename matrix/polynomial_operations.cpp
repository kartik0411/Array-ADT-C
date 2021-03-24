//THIS PROGRAM IS FOR BASIC OPERATIONS LIKE ADDITION, SUBTRACTION OF 2 POLYNOMIALS AND EVALUATING THE POLYNOMIAL FUNCTION VALUE BY GIVNG THE X VALUE AS INPUT
//Note: Please store polynomial terms by decreasing value of exponent

#include<iostream>
#include<math.h>

using namespace std;

class term{ //just to store the values of every term of the polynomial in an (exponent, coefficient) tuple
public:
    int exp;
    int coeff;
};

class polynomial{

    int n;
    term* A;

public:
    polynomial(int n)
    {
        if(n>0)
        {
            this->n=n;
            A=new term[n];
        }
    }

    ~polynomial()
    {
        delete []A;
    }

    void create();
    void display();
    void evaluate();
    void add(polynomial poly2);
    void sub(polynomial poly2);

};



void polynomial::create()
{
    int coeff,exp,k=0;
    cout<<"\nEnter the terms: (coefficient and exponent of every term)";
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter for element no. "<<i+1<<" : ";
        cin>>coeff>>exp;
        if(coeff!=0) // if coefficient is non zero then only it will store the term in the term tuple
        {
            A[k].coeff = coeff;
            A[k++].exp = exp;
        }
    }
    n=k;
}


void polynomial::display()
{
    cout<<"\nThe Polynomial is : ";
    for(int i=0;i<n;i++)
    {
        if(i>0) //if not the first term then only give spaces and + sign for positive coefficients
        {
            if(A[i].coeff>0)
            {
                cout<<" +"; // printing + because the positive numbers are not printed with + sign
            }
            else if(A[i].coeff<0)
            {
                cout<<" ";
            }
        }

        if((A[i].exp==0) || (A[i].coeff!=1 && A[i].coeff!=-1)) //if exponent of the term is 0 then it will execute , if not 0 then the term should not have coefficient as 1 or -1
        {
            cout<<A[i].coeff; //printing only the coefficient first
        }
        else if(A[i].coeff==-1) //if coefficient is -1 we would just print '-'before the term
        {
            cout<<"-";
        }

        if(A[i].exp!=0) //if exponent is non zero then only we will print the values of the term that comes after coefficient
        {
            cout<<"x";
            if(A[i].exp!=1)
            {
                cout<<"^"<<A[i].exp;
            }
        }
    }
    cout<<endl<<endl<<endl;
}


void polynomial::evaluate()
{
    int x,sum=0;
    cout<<"\nEnter the value of x for evaluation : ";
    cin>>x;

    for(int i=0;i<n;i++)
    {
        sum+=A[i].coeff*pow(x,A[i].exp); //calculating the value of the term after assigning value of x
    }
    cout<<"\nThe Result after evaluating the polynomial with value "<<x<<" is "<<sum<<endl;
}



void polynomial::add(polynomial poly2)
{
    polynomial sum(n+poly2.n);
    int i,j,k;
    i=j=k=0;

    while(i<n && j<poly2.n)
    {
        if(A[i].exp>poly2.A[j].exp)//first polynomial term's exponent is bigger
        {
            sum.A[k++]=A[i++];
        }
        else if(poly2.A[j].exp>A[i].exp) //second polynomial term's exponent is bigger
        {
            sum.A[k++]=poly2.A[j++];
        }
        else{ //both polynomial term's exponent is same
            sum.A[k]=A[i++]; //first copying first polynomial's complete term
            sum.A[k++].coeff+=poly2.A[j++].coeff; //adding only the coefficient of the 2nd polynomial's term
        }
    }
    //now copying rest of the terms of either polynomial which is left
    for(;i<n;i++)
    {
        sum.A[k++]=A[i];
    }
    for(;j<poly2.n;j++)
    {
        sum.A[k++]=poly2.A[j];
    }

    sum.n=k; //k is the number of terms after incrementing previously

    cout<<"\n\n\n\nOPERATION DONE SUCCESSFULLY .........\n\nThe new polynomial created:\n";
    sum.display();
}


void polynomial::sub(polynomial poly2) //It only inverts the sign of every term of the second polynomial and then pass both the polynomials for adding, still works like subtracting both
{
    for(int i=0;i<poly2.n;i++)
    {
        poly2.A[i].coeff=-1*poly2.A[i].coeff;
    }
    add(poly2); //adding the first polynomial with the negative of second polynomial
}



int main()
{
    int k,n;
    cout<<"Enter the number of terms of the polynomial you wanna store :";
    cin>>n;
    polynomial poly1(n);
    poly1.create();
    poly1.display();

    cout<<"MENU:\n1.EVALUATING ITS VALUE BY GIVING INPUT\n2.ADDING WITH ANOTHER POLYNOMIAL\n3.SUBTRACTING WITH ANOTHER POLYNOMIAL\n\n";
    cin>>k;
    cout<<endl;
    switch(k)
    {
    case 1:
        {
            poly1.evaluate();
            break;
        }

    case 2:
        {
            cout<<"Enter the number of terms of the polynomial you wanna store in the 2nd polynomial:";
            cin>>n;
            polynomial poly2(n);
            poly2.create();
            poly2.display();
            poly1.add(poly2);
            break;
        }

    case 3:
        {
            cout<<"Enter the number of terms of the polynomial you wanna store in the 2nd polynomial:";
            cin>>n;
            polynomial poly2(n);
            poly2.create();
            poly2.display();
            poly1.sub(poly2);
            break;
        }
    }

    return 0;
}
