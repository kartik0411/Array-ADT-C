
//THIS PROGRAM WOULD STILL DISPLAY AND WORK AS THE DIAGONAL MATRIX PROGRAM EVEN THOUGH WE ARE STORING ONLY DIAGONAL VALUES OF THE DIAGONAL MATRIX

#include<stdio.h>

struct diagonal{
    int n;
    int *A; //pointer to create array for storing only the diagonal values of the diagonal matrix to save space
};


void set(struct diagonal* diag, int i, int j, int x) //set a specific value to an index whose position is sent as a parameter along with the value that user wanna set that position with
{
    if(i==j)
    {
        diag->A[i-1]=x;
    }
}


int get(struct diagonal diag,int i, int j) //get the value at a specific index whose position is sent as a parameter
{
    if(i==j)
    {
        return diag.A[i-1];
    }
    else{
        return 0;
    }
}



void display(struct diagonal diag) //display the diagonal matrix
{
    int i,j;
    printf("\n\n");
    for(i=0;i<diag.n;i++)
    {
        for(j=0;j<diag.n;j++)
        {
            if(i==j)
            {
                printf("%d ",diag.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}




void create(struct diagonal* diag)//initializing all the diagonal values of the diagonal matrix
{
    printf("\nEnter all the diagonal elements you wanna add in this matrix\n");
    for(int i=0;i<diag->n;i++)
    {
        scanf("%d",&diag->A[i]);
    }
}





int main()
{

    struct diagonal diag;
    int i,j;
    printf("Enter the size of the diagonal matrix you wanna create :");
    scanf("%d",&diag.n);
    diag.A= (int*)malloc(sizeof(diag.n*sizeof(int))); //allocating memory for the array to store the diagonal values of the matrix
    for(i=0;i<diag.n;i++)
    {
        diag.A[i]=0;
    }

    int m=0;
    do{
    printf("\n\nMenu :\n1.Create\n2.Set\n3.Get\n4.Display\n5.EXIT\n");
    scanf("%d",&m);


    if(m==1)
    {
        create(&diag);
    }


    else if(m==2)
    {
        printf("\nEnter values of row and column of the element you wanna insert :");
        scanf("%d%d",&i,&j);
        int val;
        printf("\nEnter the value of the element :");
        scanf("%d",&val); //storing the value that the user wanna set at a specific index to send this as a parameter
        set(&diag,i,j,val);
    }


    else if(m==3)
    {
        printf("\nEnter the values of row and column of element you wanna get :");
        scanf("%d%d",&i,&j);
        printf("\nThe element at index %d,%d is %d",i,j,get(diag,i,j));
    }


    else if(m==4)
    {
        display(diag);
    }
    }while(m!=5); //menu will be shown again and again until user selects EXIT option of the menu

    return 0;
}

