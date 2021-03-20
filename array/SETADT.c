#include<stdio.h>

struct array{
    int *A;
    int length;
    int size;
};

void init(struct array *arr)
{
    int i;
    printf("\nEnter how many numbers you wanna add in this array :");
    scanf("%d",&arr->length);
    printf("\nEnter the elements: \n");
    for(i=0;i<arr->length;i++)
    {
        scanf("%d",&arr->A[i]);
    }
}

int issorted(struct array *arr)
{
    int i;
    for(i=0;i<arr->length-1;i++)
    {
        if(arr->A[i]>arr->A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void merge(struct array *arr1, struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array ar3;
    ar3.A=(int*)malloc(((arr1->size)+(arr2->size))*sizeof(int));
    ar3.length=arr1->length + arr2->length;
    ar3.size=arr1->size + arr2->size;
    if(issorted(arr1)&& issorted(arr2))
    {

    printf("\n\nMerging these SORTED Arrays......\n\nThe New Merged Array is");
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            ar3.A[k++]=arr1->A[i++];
        }
        else
        {
            ar3.A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
    {
        ar3.A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        ar3.A[k++]=arr2->A[j];
    }
    }
    else
    {
        printf("\n\nMerging these UNSORTED Arrays......\n\nThe New Merged Array is");
        for(i=0;i<arr1->length;i++)
        {
            ar3.A[k++]=arr1->A[i];
        }
        for(i=0;i<arr2->length;i++)
        {
            ar3.A[k++]=arr2->A[i];
        }
    }

    display(&ar3);
}



void unionn(struct array *ar1, struct array *ar2)
{
    struct array ar3;
    int i=0,j=0,k=0;
    ar3.A=(int*)malloc(((ar1->size)+(ar2->size))*sizeof(int));
    ar3.size=(ar1->size)+(ar2->size);
    if(issorted(ar1)&&issorted(ar2))
    {
    printf("\n\nTaking UNION of these SORTED Arrays\n\nAfter doing UNION, The newly created Array is");

    while(i<ar1->length && j<ar2->length)
    {
        if(ar1->A[i]==ar2->A[j])
        {
            ar3.A[k++]=ar1->A[i++];
            j++;
        }
        else if(ar1->A[i]<ar2->A[j])
        {
            ar3.A[k++]=ar1->A[i++];
        }
        else
        {
            ar3.A[k++]=ar2->A[j++];
        }
    }
    for(;i<ar1->length;i++)
    {
        ar3.A[k++]=ar1->A[i];
    }
    for(;j<ar2->length;j++)
    {
        ar3.A[k++]=ar2->A[j];
    }
    ar3.length=k;
    display(&ar3);
    }
    else
    {
        int flag=0;
        printf("\n\nTaking UNION of these UNSORTED Arrays......\n\nAfter doing UNION, The new SET created after Union is");
        for(i=0;i<ar1->length;i++)
        {
            ar3.A[k++]=ar1->A[i];
        }
        ar3.length=k;
        for(j=0;j<ar2->length;j++)
        {
            for(i=0;i<ar3.length;i++)
            {
                if(ar2->A[j]==ar3.A[i])
                {
                    flag++;
                }
            }
            if(flag==0)
            {
                ar3.A[k++]=ar2->A[j];
            }
            flag=0;
        }
        ar3.length=k;
        display(&ar3);
    }

}


void inter(struct array *ar1,struct array *ar2)
{
    struct array ar3;
    ar3.A=(int*)malloc((ar1->size)*sizeof(int));
    ar3.size=ar1->size;
    int i=0,j=0,k=0;
    if(issorted(ar1) && issorted(ar2))
    {
        printf("\n\nTaking Intersection of both the SORTED Arrays......\n\nThe New SET created after Intersection is");
        while(i<ar1->length && j<ar2->length)
        {
             if(ar1->A[i]==ar2->A[j])
             {
                 ar3.A[k++]=ar1->A[i++];
                 j++;
             }
             else if(ar1->A[i]<ar2->A[j])
             {
                 i++;
             }
             else
             {
                 j++;
             }
        }
        ar3.length=k;
        display(&ar3);
    }
    else
    {
        int flag=0;
        printf("\n\nTaking Intersection of both the UNSORTED Arrays......\n\nThe New SET created after Intersection is");
        for(i=0;i<ar1->length;i++)
        {
            for(j=0;j<ar2->length;j++)
            {
                if(ar1->A[i]==ar2->A[j])
                {
                    flag++;
                }
            }
            if(flag>0)
            {
                ar3.A[k++]=ar1->A[i];
            }
            flag=0;
        }
        ar3.length=k;
        display(&ar3);
    }

}



void diff(struct array *ar1,struct array *ar2)
{
    struct array ar3;
    ar3.A=(int*)malloc((ar1->size)*sizeof(int));
    ar3.size=ar1->size;
    int i=0,j=0,k=0;
    if(issorted(ar1) && issorted(ar2))
    {
        printf("\n\nTaking Difference of both the SORTED Arrays......\n\nThe New SET created after Difference is");
        while(i<ar1->length && j<ar2->length)
        {
             if(ar1->A[i]==ar2->A[j])
             {
                 i++;
                 j++;
             }
             else if(ar1->A[i]<ar2->A[j])
             {
                 ar3.A[k++]=ar1->A[i++];
             }
             else
             {
                 j++;
             }
        }
        ar3.length=k;
        display(&ar3);
    }
    else
    {
        int flag=0;
        printf("\n\nTaking DIFFERENCE of both the UNSORTED Arrays......\n\nThe New SET created after Difference is");
        for(i=0;i<ar1->length;i++)
        {
            for(j=0;j<ar2->length;j++)
            {
                if(ar1->A[i]==ar2->A[j])
                {
                    flag++;
                }
            }
            if(flag==0)
            {
                ar3.A[k++]=ar1->A[i];
            }
            flag=0;
        }
        ar3.length=k;
        display(&ar3);
    }

}



void display(struct array *arr)
{
    int i;
    printf("\n\nThe elements of this array are:\n");
    for(i=0;i<arr->length;i++)
    {
        printf("%d\n",arr->A[i]);
    }

}



int main()
{
    struct array arr1,arr2;
    int D;

    printf("Enter size of the 1st array you wanna create :");
    scanf("%d",&arr1.size);
    arr1.A=(int*)malloc(arr1.size*sizeof(int));
    init(&arr1);
    if(issorted(&arr1)==1)
    {
        printf("\nYOU CREATED A SORTED ARRAY\n");
    }


    printf("\n\nEnter size of the 2nd array you wanna create :");
    scanf("%d",&arr2.size);
    arr2.A=(int*)malloc(arr2.size*sizeof(int));
    init(&arr2);
    if(issorted(&arr2)==1)
    {
        printf("\nYOU CREATED A SORTED ARRAY\n");
    }

    do{
    printf("\n\nMenu:\n\n");
    printf("1.Merge \n2.Union \n3.Intersection \n4.Difference \n5.EXIT\n");
    scanf("%d",&D);
    switch(D)
    {
        case 1: merge(&arr1,&arr2); break;

        case 2: unionn(&arr1,&arr2); break;

        case 3: inter(&arr1,&arr2); break;

        case 4: diff(&arr1,&arr2); break;
    }
    }while(D!=5);

}