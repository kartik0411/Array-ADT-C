//IN THIS PROGRAM WE TRY TO STORE SPARSE MATRIX BY STORING ONLY THE NON-ZERO ELEMENTS AS THE (POSITION,ELEMENT) TUPPLE AND AFTER THAT WE ALSO HAVE DONE ADDITION OF 2 SPARSE MATRICES
// NOTE::: While taking input to create a matrix, store the elements in order of their row and column positions. EXAMPLE: For storing elements at positions : (1,1),(2,1),(1,2), First store element at (1,1) then (1,2) and at last (2,1) [order should be mantained]
#include<stdio.h>

struct element{
    int i;
    int j;
    int x;
};

struct sparse{
    int m;
    int n;
    int num;
    struct element *A;
};



void create(struct sparse* mat)
{
    printf("Enter the dimension of the sparse matrix you wanna create :");
    scanf("%d%d",&mat->m,&mat->n);
    printf("Enter the number of non zero elements :");
    scanf("%d",&mat->num);
    mat->A = (struct element*)malloc(mat->num*sizeof(struct element));
    printf("\nEnter the position of the non zero elements and as well the non zero element itself :\n");
    for(int k=0;k<mat->num;k++)
    {
        printf("\nEnter for element number %d:\n",k+1);
        scanf("%d%d%d",&mat->A[k].i,&mat->A[k].j,&mat->A[k].x);
    }
}




void display(struct sparse matrix)
{
    int k=0;
    for(int a=0;a<matrix.m;a++)
    {
        for(int b=0;b<matrix.n;b++)
        {
            if(matrix.A[k].i==(a+1) && matrix.A[k].j==(b+1))
            {
                printf("%d ",matrix.A[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}




struct sparse add(struct sparse mat1, struct sparse mat2)
{
    int k=0,u=0,v=0;
    struct sparse matrix;
    (mat1.m>mat2.m)?(matrix.m=mat1.m):(matrix.m=mat2.m);
    (mat1.n>mat2.n)?(matrix.n=mat1.n):(matrix.n=mat2.n);

    matrix.A=(struct element*)malloc((mat1.num+mat2.num)*sizeof(struct element));
    while(u<mat1.num && v<mat2.num)
    {
        if(mat1.A[u].i<mat2.A[v].i)
        {
            matrix.A[k++]=mat1.A[u++];
        }
        else if(mat2.A[v].i<mat1.A[u].i)
        {
            matrix.A[k++]=mat2.A[v++];
        }
        else{ //if row number of the non zero element of both the sparse matrix are equal, we will check the column number then

            if(mat1.A[u].j<mat2.A[v].j)
            {
                matrix.A[k++]=mat1.A[u++];
            }
            else if(mat2.A[v].j<mat1.A[u].j)
            {
                matrix.A[k++]=mat2.A[v++];
            }
            else{ //if column number of the non zero element of both the sparse matrix are also equal we would then add the similar position elements of both the matrices and then increment the counter of the array of both the matrices

                matrix.A[k]=mat1.A[u++]; //first matrix element is copied
                matrix.A[k++].x+=mat2.A[v++].x; //second matrix element is added to it
            }

        }
    }
    for(;u<mat1.num;u++)
    {
        matrix.A[k++]=mat1.A[u];
    }
    for(;v<mat2.num;v++)
    {
        matrix.A[k++]=mat2.A[v];
    }

    matrix.num=k;
    return matrix;
}



void main()
{
    struct sparse mat1,mat2;

    create(&mat1);
    printf("\n\nMTRIX YOU CREATED =\n");
    display(mat1);

    printf("\n\n");

    create(&mat2);
    printf("\n\nMTRIX YOU CREATED =\n");
    display(mat2);


    struct sparse mat=add(mat1,mat2); //calling sparse matrix addition function
    printf("\n\n\n\nTHE MATRIX CREATED AFTER ADDING BOTH THE MATRICES IS:\n");
    display(mat);
    printf("\n\nXXXXXXXXXXXXXXXXXXXXXXX MATRICES ADDED SUCCESSFULLY XXXXXXXXXXXXXXXXXXXXXXX");

    free(mat1.A);
    free(mat2.A);
    free(mat.A);
}
