//IN THIS PROGRAM WE TRY TO STORE SPARSE MATRIX BY STORING ONLY THE NON-ZERO ELEMENTS AS THE (POSITION,ELEMENT) TUPLE AND AFTER THAT WE ALSO HAVE DONE ADDITION OF 2 SPARSE MATRICES
// NOTE::: While taking input to create a matrix, store the elements in order of their row and column positions. EXAMPLE: For storing elements at positions : (1,1),(2,1),(1,2), First store element at (1,1) then (1,2) and at last (2,1) [order should be maintained]
#include<iostream>
using namespace std;


class element{ //tuple to store the position of every non zero element

public:
    int i;
    int j;
    int x;
};



class sparse{
public:
    int m;
    int n;
    int num;
    element* A;

    ~sparse()
    {
        delete []A;
    }


    void create()
    {
        cout<<"Enter the dimension of the sparse matrix you wanna create : ";
        cin>>m>>n;
        cout<<"Enter the number of non zero elements :";
        cin>>num;
    }

    void read()//this function is to read non zero elements from the user and store them into an array of tuple(position,element) structures
    {
        A=new element[num];

        cout<<"\nEnter the position of the non zero elements and as well the non zero element itself :\n";
        for(int k=0;k<num;k++)
        {
            cout<<"\nEnter for element number "<<k+1<<": ";
            cin>>A[k].i>>A[k].j>>A[k].x;
        }
    }

    void display()
    {
        int k=0;
        for(int a=0;a<m;a++)
        {
            for(int b=0;b<n;b++)
            {
                if(A[k].i==(a+1) && A[k].j==(b+1))
                {
                    cout<<A[k++].x<<" ";
                }
                else{
                    cout<<"0 ";
                }
             }
             cout<<endl;
        }
    }
};



sparse add(sparse* mat1, sparse* mat2)
{
    int k=0,u=0,v=0;
    sparse matrix;

    (mat1->m>mat2->m)?(matrix.m=mat1->m):(matrix.m=mat2->m);
    (mat1->n>mat2->n)?(matrix.n=mat1->n):(matrix.n=mat2->n);

    matrix.A= new element[mat1->num + mat2->num];

    while(u<mat1->num && v<mat2->num)
    {
        if(mat1->A[u].i<mat2->A[v].i)
        {
            matrix.A[k++]=mat1->A[u++];
        }
        else if(mat2->A[v].i<mat1->A[u].i)
        {
            matrix.A[k++]=mat2->A[v++];
        }
        else{ //if row number of the non zero element of both the sparse matrix are equal, we will check the column number then

            if(mat1->A[u].j<mat2->A[v].j)
            {
                matrix.A[k++]=mat1->A[u++];
            }
            else if(mat2->A[v].j<mat1->A[u].j)
            {
                matrix.A[k++]=mat2->A[v++];
            }
            else{ //if column number of the non zero element of both the sparse matrix are also equal we would then add the similar position elements of both the matrices and then increment the counter of the array of both the matrices

                matrix.A[k]=mat1->A[u++]; //first matrix element is copied
                matrix.A[k++].x+=mat2->A[v++].x; //second matrix element is added to it
            }
        }
    }

    for(;u<mat1->num;u++)
    {
        matrix.A[k++]=mat1->A[u];
    }
    for(;v<mat2->num;v++)
    {
        matrix.A[k++]=mat2->A[v];
    }

    matrix.num=k;
    return matrix;
}




int main()
{

    sparse mat1;
    mat1.create();//to initialize the matrix size and count of non zero elements values
    mat1.read();//to read the non zero elements of the matrix and store it order wise in an array of tuples having element and its position
    cout<<"\n\nMTRIX YOU CREATED =\n";
    mat1.display();

    printf("\n\n");

    sparse mat2;
    mat2.create();
    mat2.read();
    cout<<"\n\nMTRIX YOU CREATED =\n";
    mat2.display();


    sparse mat=add(&mat1,&mat2); //calling sparse matrix addition function
    cout<<"\n\n\n\nTHE MATRIX CREATED AFTER ADDING BOTH THE MATRICES IS:\n";
    mat.display();
    printf("\n\nXXXXXXXXXXXXXXXXXXXXXXX MATRICES ADDED SUCCESSFULLY XXXXXXXXXXXXXXXXXXXXXXX");

    return 0;

}
