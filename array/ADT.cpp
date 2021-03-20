#include<iostream>
using namespace std;

class array{
    int *A;
    int size;
    int length;
    int issorted();
    void display();

public:
    array()
    {
        size=10;
        A= new int[10];
        length=0;
    }
    array(int size)
    {
        this->size=size;
        A= new int[size];
        length=0;
    }
    ~array()
    {
        delete []A;
    }

    void get();
    void set();
    void max();
    void min();
    void sum();
    void avg();
    void init();
    void insert();
    void append();
    void del();
    void search();
    void sort();
    void lshift();
    void rshift();
    void rev();
    void arrangeneg();

};

void array::get()
{
    int ind;
    cout<<"\nEnter the index of the element you wanna get :";
    cin>>ind;
    cout<<"\nThe number at the index "<<ind<<" is "<<A[ind-1];
}


void array::set()
{
    int ind,x;
    cout<<"\nEnter the index of the element you wanna change :";
    cin>>ind;
    cout<<"\nEnter the number you wanna have at index "<<ind<<" : ";
    cin>>x;
    A[ind-1]=x;
    printf("\n\nThe new array:");
    display();

}


void array::max()
{
    if(issorted()==1)
    {
        cout<<"Maximum element is "<<A[length-1]<<" and is at index "<<length;
    }
    else
    {
    int i=0;
    int max=A[0],ind=1;
    for(i=0;i<length;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
            ind=i+1;
        }
    }
    cout<<"Maximum element is "<<max<<" and is at index "<<ind;
    }
}


void array::min()
{
    if(issorted()==1)
    {
        cout<<"Minimum element is "<<A[0]<<" and is at index 1";
    }
    else
    {
    int i=0;
    int min=A[0],ind=1;
    for(i=0;i<length;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
            ind=i+1;
        }
    }
    cout<<"Minimum element is "<<min<<" and is at index "<<ind;
    }

}


void array::sum()
{
    int i=0;
    int sum=0;
    for(i=0;i<length;i++)
    {
        sum=sum+(A[i]);
    }
    cout<<"\n\nThe sum of all elements of the array is "<<sum;
}


void array::avg()
{
    int i=0;
    int sum=0;
    for(i=0;i<length;i++)
    {
        sum=sum+A[i];
    }
    cout<<"\n\nThe average of all elements of the array is "<<(float)sum/length;
}


void array::init()
{
    int i=0;
    cout<<"\n\nEnter how many numbers you wanna add: ";
    cin>>length;
    printf("\n\nEnter the numbers:\n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&A[i]);
    }
    if(issorted()==1)
    {
        cout<<"\nYOU CREATED A SORTED ARRAY\n";
    }


}

void array::insert()
{
    if(length<size) //size available for insertion
    {

    int flag=0;
    if(issorted()==1)
    {
        flag++;//implies array is sorted
        char ch;
        cout<<"\nDo you wanna insert a number at a specific index in this sorted array? [Y:yes]\n";
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
           flag--;//user wants to insert at a position of his/her own choice
        }
    }

    if(flag==1)
    {
        int i=0,x;
        cout<<"\n\nEnter the element you wanna insert in this sorted array :";
        cin>>x;
        i=length-1;
        while(i>=0 && A[i]>x)
        {
            A[i+1]=A[i];
            i--;
        }
        if(i<0)
        {
            A[0]=x;
        }
        A[i+1]=x;
        length++;
        printf("\n\nThe new array:");
        display();
    }


    else if(flag==0)
    {
    int i=0;
    int ind,x;
    cout<<"\nEnter the index at which you want to insert the element: ";
    cin>>ind;
    cout<<"\nEnter the element: ";
    cin>>x;
    if(ind<=(length+1))
    {
        for(i=length;i>(ind-1);i--)
        {
            A[i]=A[i-1];
        }
        A[ind-1]=x;
        length++;
        printf("\n\nThe new array:");
        display();
    }

    else //insertion can create gaps between array
    {
            cout<<"\nElement cannot be inserted at this index";
    }

    }
    }


    else //array size already full
    {
        cout<<"\nArray size full!!!!!!";
    }
}


void array::append()
{
    int x;
    cout<<"\n\nEnter the Number you wanna append in the array :";
    cin>>x;
    if(length<size)
    {
        A[length]=x;
        length++;
        printf("\n\nThe new array:");
        display();
    }
    else{
        cout<<"Array size full!!!!!!!";
    }
}


void array::del()
{
    int i=0;
    char ch;
    int ind;
    cout<<"Enter the index of the element you want to delete\n";
    scanf("%d",&ind);
    if(ind<=length)
    {
        for(i=ind-1;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        printf("\n\nThe new array:");
        display();
    }
    else
    {
        cout<<"Element not present at this index";
    }
}


void array::search()
{

    if(issorted()==1)//iterative binary search if sorted array
    {
    int x,l=0,h=length-1,mid;
    cout<<"\nWrite the number for which the index you wanna search in this sorted array : ";
    cin>>x;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(x==(A[mid]))
        {
            cout<<"\n\nThe index of "<<x<<" is "<<mid+1<<"\n";
            break;
        }
        else if(x<A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(l>h)
    {
        cout<<"\n\nElement you entered is not present in this SORTED array!!!!!!!\n";
    }
    }


    else{ //Linear search if array not sorted
    int i=0;
    int x,flag=0,temp;
    char ch;
    cout<<"\nEnter the number you wanna search: ";
    cin>>x;
    for(i=0;i<length;i++)
    {
        if(A[i]==x)
        {
            flag++;
            cout<<"\n\nThe element that you searched for is at index: "<<i+1<<"\n";
        }

    }
    if(flag==0)
    {
        cout<<"\n\nElement you entered is not present in the array!!!!!";
    }
    }
}


void array::sort()
{
    int i,j,temp;
    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(A[i]>A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    printf("\n\nThe new array:");
    display();
}


void array::lshift()
{
    int i=0;
    int temp=A[0];
    for(i=0;i<length-1;i++)
    {
        A[i]=A[i+1];
    }
    A[length-1]=temp;
    printf("\n\nThe new array:");
    display();
}


void array::rshift()
{
    int i=0;
    int temp=A[length-1];
    for(i=length-1;i>0;i--)
    {
        A[i]=A[i-1];
    }
    A[0]=temp;
    printf("\n\nThe new array:");
    display();
}


void array::rev()
{
    int i=0;
    int temp;
    for(i=0;i<length/2;i++)
    {
        temp=A[i];
        A[i]=A[length-i-1];
        A[length-i-1]=temp;
    }
    printf("\n\nThe new array:");
    display();
}


int array::issorted()
{
    int flag=0;
    int i=0;
    while(i<(length-1))
    {
        if(A[i+1]<A[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}


void array::display()
{
    int i=0;
    if(length>0)
    {
    cout<<"\nThe elements are:";
    for(i=0;i<length;i++)
    {
        cout<<"\n"<<A[i];
    }
    }
    else{
        cout<<"\n\nEmpty array!!!!!!";
    }
}


void array::arrangeneg()
{
    int temp;
    int i=0,j=length-1;
    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    printf("\n\nThe new array:");
    display();
}


int main()
{
    char ch;
    int d,sz;

    cout<<"Enter size of the array you wanna create: ";
    cin>>sz;
    array arr(sz);

    arr.init();

    do{

    cout<<"\n\n\nMENU: \n\n1.Append \n2.Insert \n3.Delete \n4.Search (Get Index for any element) \n5.Sort \n6.Get (Get the Element by index) \n7.Set (Set the Element by index) \n8.Maximum \n9.Minimum \n10.Sum \n11.Average \n12.Left Shift \n13.Right Shift \n14.Reverse \n15.Arrange (Move negative numbers on the left side) \n16.EXIT\n\n";
    cin>>d;

    switch(d)
    {
        case 1: arr.append(); break; //insert at the last
        case 2: arr.insert(); break;

        case 3: arr.del(); break;

        case 4: arr.search(); break;
        case 5: arr.sort(); break;

        case 6: arr.get(); break; //get element by its index in array
        case 7: arr.set(); break; //set an index with a value

        case 8: arr.max(); break;
        case 9: arr.min(); break;

        case 10: arr.sum(); break;
        case 11: arr.avg(); break;

        case 12: arr.lshift(); break; //left shift by one element
        case 13: arr.rshift(); break; //right shift by one element

        case 14: arr.rev(); break;//reverse array
        case 15: arr.arrangeneg(); break; // take all negative numbers on the left side

    }
    }while(d!=16);

    return 0;
}