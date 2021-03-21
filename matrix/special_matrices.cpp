//THIS PROGRAM USES SMALLER ARRAYS FOR SAVING SPACE TO STORE SPECIAL TYPE OF MATRICES AND STILL WORKS LIKE STORING THE WHOLE MATRIX
//SWITCH CASES FOR EACH CLASS FUNCTION IS USED TO DIFFERENTIATE BETWEEN WHICH MATRIX IS BEEN USED

#include<iostream>
using namespace std;

int k; //for checking which matrix has been created by the user



class matrix{

private:
    int n;
    int *A;

public:
    matrix(); //Default constructor gives a default value to create the array and also to allocate memory for the array for different type of special matrices based on the default size
    matrix(int n); //takes matrix size as a parameter and allocates memory for different types of matrices based on the size
    ~matrix()
    {
        delete []A;
    }
    void set(int i,int j,int x); //setting the values at a specific index whose position is given as a parameter and also the value that has to be stored at that index
    int get(int i,int j); //returns the value at a specific index whose position is sent as a parameter
    void display(); //display the matrix

};




matrix::matrix()
    {
        n=2;
        switch(k)
        {
            case 1: {A= new int[n]; break;}
            case 2: {A= new int[n*(n+1)/2]; break;}
            case 3: {A= new int[n*(n+1)/2]; break;}
            case 4: {A= new int[n*(n+1)/2]; break;}
            case 5: {A= new int[3*n-2]; break;}
            case 6: {A= new int[(2*n)-1]; break;}
        }
    }
matrix::matrix(int n)
    {
        this->n=n;
        switch(k)
        {
            case 1: {A= new int[n]; break;}
            case 2: {A= new int[n*(n+1)/2]; break;}
            case 3: {A= new int[n*(n+1)/2]; break;}
            case 4: {A= new int[n*(n+1)/2]; break;}
            case 5: {A= new int[3*n-2]; break;}
            case 6: {A= new int[(2*n)-1]; break;}
        }
    }


void matrix::set(int i,int j,int x)
    {
        switch(k)
        {
        case 1:
            {
                if(i==j)
                {
                     A[i-1]=x;
                }
                break;
            }
        case 2:
            {
                if(i>=j)
                {
                     A[i*(i-1)/2 + (j-1)]=x;
                }
                break;
            }
        case 3:
            {
                if(i<=j)
                {
                     A[j*(j-1)/2 + (i-1)]=x;
                }
                break;
            }
        case 4:
            {
                if(i>=j)
                {
                     A[i*(i-1)/2 + (j-1)]=x;
                }
                else{
                    A[j*(j-1)/2 + (i-1)]=x;
                }
                break;
            }
        case 5:
            {
                if(i==j)
                {
                     A[(n-1)+(i-1)]=x;
                }
                else if(i-j==-1)
                {
                     A[(n)+(n-1)+(i-1)]=x;
                }
                else if(i-j==1)
                {
                     A[i-2]=x;
                }
                break;
            }
        case 6:
            {
                if(i<=j)
                {
                    A[j-i]=x;

                }
                else
                {
                    A[n+i-j-1]=x;
                }
                break;
            }
        }
    }
int matrix::get(int i,int j)
    {
        switch(k)
        {
        case 1:
            {
                if(i==j)
                {
                    return A[i-1];
                }
                else{
                    return 0;
                }
                break;
            }
        case 2:
            {
                if(i>=j)
                {
                    return A[i*(i-1)/2 + (j-1)];
                }
                else{
                    return 0;
                }
                break;
            }
        case 3:
            {
                if(i<=j)
                {
                    return A[j*(j-1)/2 + (i-1)];
                }
                else{
                    return 0;
                }
                break;
            }
        case 4:
            {
                if(i>=j)
                {
                    return A[i*(i-1)/2 + (j-1)];
                }
                else
                {
                    return A[j*(j-1)/2 + (i-1)];
                }
                break;
            }
        case 5:
            {
                if(i==j)
                {
                    return A[(n-1)+(i-1)];
                }
                else if(i-j==-1)
                {
                    return A[(n)+(n-1)+(i-1)];
                }
                else if(i-j==1)
                {
                    return A[i-1];
                }
                else{
                    return 0;
                }
                break;
            }
        case 6:
            {
                if(i<=j)
                {
                    return A[j-i];
                }
                else{
                    return A[n+i-j-1];
                }
                break;
            }
        }
    }
void matrix::display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                switch(k)
                {
                case 1:
                    {
                        if(i==j)
                        {
                            cout<<A[i]<<" ";
                        }
                        else{
                            cout<<"0 ";
                        }
                        break;
                    }
                case 2:
                    {
                        if(i>=j)
                        {
                            cout<<A[i*(i+1)/2 + (j)]<<" ";
                        }
                        else{
                            cout<<"0 ";
                        }
                        break;
                    }
                case 3:
                    {
                        if(i<=j)
                        {
                            cout<<A[j*(j+1)/2 + (i)]<<" ";
                        }
                        else{
                            cout<<"0 ";
                        }
                        break;
                    }
                case 4:
                    {
                        if(i>=j)
                        {
                             cout<<A[i*(i+1)/2 + j]<<" ";
                        }
                        else{
                             cout<<A[j*(j+1)/2 + i]<<" ";
                        }
                        break;
                    }
                case 5:
                    {
                        if(i==j)
                        {
                            cout<<A[(n-1)+(i)]<<" ";
                        }
                        else if(i-j==-1)
                        {
                            cout<<A[(n)+(n-1)+(i)]<<" ";
                        }
                        else if(i-j==1)
                        {
                            cout<<A[i-1]<<" ";
                        }
                        else{
                            cout<<"0 ";
                        }
                        break;
                    }
                case 6:
                    {
                        if(i<=j)
                        {
                            cout<<A[j-i]<<" ";
                        }
                        else
                        {
                            cout<<A[n+i-j-1]<<"  ";
                        }
                        break;
                    }
                }
            }
            cout<<endl;
        }
    }



int main()
{
    int n,i,j;

    cout<<"Menu for the matrix:\n1.Diagonal\n2.Lower Triangular\n3.Upper Triangular\n4.Symmetric\n5.Tridiagonal\n6.Toeplitz\nEnter the type of matrix you wanna create :";
    cin>>k; //getting the input by the user as to which special matrix to create based on the options given in the menu to the user
    cout<<"\nEnter the size of the matrix you wanna create :";
    cin>>n;
    matrix mat(n);

    int m=0; //just for taking input from the user for the functions of the menu
    do{
    cout<<"\n\nMenu :\n1.Set\n2.Get\n3.Display\n4.EXIT\n";
    cin>>m;

    switch(m)
    {
        case 1:
            {
                cout<<"\nEnter values of row and column of the element you wanna insert :";
                cin>>i>>j;
                int val;
                cout<<"\nEnter the value of the element :";
                cin>>val; //storing the value that the user wanna set at a specific index to send this as a parameter
                mat.set(i,j,val);
                break;
            }



        case 2:
            {
                cout<<"\nEnter the values of row and column of element you wanna get :";
                cin>>i>>j;
                cout<<"\nThe element at index "<<i<<","<<j<<" is "<<mat.get(i,j);
                break;
            }



        case 3:
            {
                mat.display();
                break;
            }
    }

    }while(m!=4);//menu will be shown again and again until user selects EXIT option of the menu

    return 0;
}
