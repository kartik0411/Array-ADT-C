#include<stdio.h>
#include<stdlib.h>


struct array{
    int *A;
    int size;
    int length;

};

void get(struct array *arr )
{
    int ind;
    int i=0;
    printf("\nEnter the index of the element you wanna get :");
    scanf("%d",&ind);
    printf("\nThe number at the index %d is %d",ind,arr->A[ind-1]);
}

void set(struct array *arr )
{
    int ind,x;
    int i=0;
    printf("\nEnter the index of the element you wanna change :");
    scanf("%d",&ind);
    printf("\nEnter the number you wanna have at index  %d : ",ind);
    scanf("%d",&x);
    arr->A[ind-1]=x;

}

void max(struct array *arr)
{
    if(issorted(arr)==1)
    {
        printf("Maximum element is %d and is at index &d",arr->A[arr->length-1],arr->length);
    }


    else
    {
    int i=0;
    int max=arr->A[0],ind=1;
    for(i=0;i<arr->length;i++)
    {
        if(arr->A[i]>max)
        {
            max=arr->A[i];
            ind=i+1;
        }
    }
    printf("Maximum element is %d and is at index %d",max,ind);
    }
}


void min(struct array *arr)
{
    if(issorted(arr)==1)
    {
        printf("Minimum element is %d and is at index 1",arr->A[0]);
    }
    else
    {
    int i=0;
    int min=arr->A[0],ind=1;
    for(i=0;i<arr->length;i++)
    {
        if(arr->A[i]<min)
        {
            min=arr->A[i];
            ind=i+1;
        }
    }
    printf("Minimum element is %d and is at index %d",min,ind);
    }

}

void sum(struct array *arr)
{
    int i=0;
    int sum=0;
    for(i=0;i<arr->length;i++)
    {
        sum=sum+(arr->A[i]);
    }
    printf("\n\nThe sum of all elements of the array is %d",sum);
}

void avg(struct array *arr)
{
    int i=0;
    int sum=0;
    for(i=0;i<arr->length;i++)
    {
        sum=sum+(arr->A[i]);
    }
    printf("\n\nThe average of all elements of the array is %f",(float)sum/(arr->length));
}


void init(struct array *arr)
{
    int i=0;
    printf("\n\nEnter how many numbers you wanna add: ");
    scanf("%d",&arr->length);
    printf("\n\nEnter the numbers:\n");
    for(i=0;i<arr->length;i++)
    {
        scanf("%d",&arr->A[i]);
    }

}

void insert(struct array *arr)
{
    int i=0;
    char cha;
    if(arr->length<arr->size)
    {
    int ind,x;
    printf("\nEnter the index at which you want to insert the element: ");
    scanf("%d",&ind);
    printf("\nEnter the element: ");
    scanf("%d",&x);
    if(ind<=(arr->length+1))
    {
        for(i=arr->length;i>(ind-1);i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[ind-1]=x;
        arr->length++;
    }
    else{
        if(arr->length>=arr->size)
        {
            printf("\nArray size not sufficient to insert the element");
        }
        else{
            printf("\nElement cannot be inserted at this index");
        }
    }
    }
    else{
        printf("\nArray size full!!!!!!");
    }
}


void append(struct array *arr)
{
    int x;
    printf("\n\nEnter the Number you wanna append in the array :");
    scanf("%d",&x);
    if(arr->length<arr->size)
    {
        arr->A[arr->length]=x;
        arr->length++;
    }
    else{
        printf("Array size full!!!!!!!");
    }
}

void del(struct array *arr)
{
    int i=0;
    if(arr->length>0)
    {
    char ch;
    int ind;
    printf("Enter the index of the element you want to delete\n");
    scanf("%d",&ind);
    if(ind<=arr->length)
    {
        for(i=ind-1;i<(arr->length-1);i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    else
    {
        printf("Element not present at this index");
    }
    }

    else
    {
        printf("No elements to delete!!!!!!");
    }
}


void binsearchiter(struct array *arr)
{
    int x,l=0,h=(arr->length)-1,mid;
    printf("\nWrite the number for which the index you wanna search in this sorted array : ");
    scanf("%d",&x);
    while(l<=h)
    {
        mid=(l+h)/2;
        if(x==(arr->A[mid]))
        {
            printf("\n\nThe index of %d is %d\n",x,mid+1);
            break;
        }
        else if(x<arr->A[mid])
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
        printf("\n\nElement you entered is not present in the array!!!!!!!\n");
    }
}

void search(struct array *arr)
{
    int i=0;
    int x,flag=0,temp;
    char ch;
    printf("\nEnter the number you wanna search: ");
    scanf("%d",&x);
    for(i=0;i<arr->length;i++)
    {
        if(arr->A[i]==x)
        {
            flag++;
            printf("\n\nThe element that you searched for is at index: %d\n",i+1);
        }

    }
    if(flag==0)
    {
        printf("\n\nElement you entered is not present in the array!!!!!");
    }
}

void sort(struct array *arr)
{
    int i,j,temp;
    for(i=0;i<arr->length-1;i++)
    {
        for(j=i+1;j<arr->length;j++)
        {
            if(arr->A[i]>arr->A[j])
            {
                temp=arr->A[i];
                arr->A[i]=arr->A[j];
                arr->A[j]=temp;
            }
        }
    }
}

void lshift(struct array *arr)
{
    int i=0;
    int temp=arr->A[0];
    for(i=0;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=temp;
}

void rshift(struct array *arr)
{
    int i=0;
    int temp=arr->A[arr->length-1];
    for(i=arr->length-1;i>0;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=temp;
}

void rev(struct array *arr)
{
    int i=0;
    int temp;
    for(i=0;i<arr->length/2;i++)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[arr->length-i-1];
        arr->A[arr->length-i-1]=temp;
    }
}

int issorted(struct array *arr)
{
    int flag=0;
    int i=0;
    while(i<(arr->length-1))
    {
        if(arr->A[i+1]<arr->A[i])
        {
            return 0;
        }
        i++;
    }
    return 1;

}

void inserts(struct array *arr)
{
    int i=0;
    if(arr->length<arr->size)
    {
        int x;
        printf("\n\nEnter the element you wanna insert in this sorted array :");
        scanf("%d",&x);
        i=arr->length;
        while(i>=0&&arr->A[i]>x)
        {
            arr->A[i+1]=arr->A[i];
            i--;
        }
        if(i<0)
        {
            arr->A[0]=x;
        }
        arr->A[i+1]=x;
        arr->length++;

    }

    else{
        printf("\n\nArray size FULL!!!!!!!!!");

    }

}

void display(struct array *arr)
{
    int i=0;
    if(arr->length>0)
    {
    printf("\n\nThe elements are:");
    for(i=0;i<arr->length;i++)
    {
        printf("\n%d",arr->A[i]);
    }
    }
    else{
        printf("\n\nEmpty array!!!!!!");
    }
}


void arrangeneg(struct array *arr)
{
    int temp;
    int i=0,j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}


int main()
{
    struct array arr;
    char ch;
    int d;

    printf("Enter size of the array you wanna create: ");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));



    init(&arr);



    if(issorted(&arr)==1)
    {
        printf("\nYOU CREATED A SORTED ARRAY\n");
    }


    do{
    printf("\n\n\nMENU: \n\n1.Append \n2.Insert \n3.Delete \n4.Search (Get Index for any element) \n5.Sort \n6.Get (Get the Element by index) \n7.Set (Set the Element by index) \n8.Maximum \n9.Minimum \n10.Sum \n11.Average \n12.Left Shift \n13.Right Shift \n14.Reverse \n15.Arrange (Move negative numbers on the left side) \n16.EXIT\n\n");
    scanf("%d",&d);

    switch(d)
    {
        case 1: append(&arr); display(&arr); break;


        case 2:
        if(issorted(&arr)==1)
        {
            printf("\nDo you wanna insert a number at a specific index in this sorted array? [Y:yes]\n");
            scanf(" %c",&ch);
            if(ch=='y'||ch=='Y')
            {
                insert(&arr);
            }
            else
            {
                inserts(&arr);
            }
        }
        else
        {
            insert(&arr);
        }
        display(&arr);
        break;


        case 3: del(&arr); display(&arr); break;


        case 4:
        if(issorted(&arr)==1)
        {
            binsearchiter(&arr);
        }
        else
        {
            search(&arr);
        }
        break;


        case 5: sort(&arr); display(&arr); break;


        case 6: get(&arr); break;
        case 7: set(&arr); display(&arr); break;

        case 8: max(&arr); break;
        case 9: min(&arr); break;

        case 10: sum(&arr); break;
        case 11: avg(&arr); break;

        case 12: lshift(&arr); display(&arr); break;
        case 13: rshift(&arr); display(&arr); break;

        case 14: rev(&arr); display(&arr); break;
        case 15: arrangeneg(&arr); display(&arr); break;

    }
    }while(d!=16);

    return 0;
}
