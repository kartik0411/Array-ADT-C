#include<stdio.h>
#include<limits.h>
struct node{
    int data;
    struct node* next;
}* first=NULL;

struct node* create(int A[], int n)
{
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    struct node* last=first;
    for(int i=1;i<n;i++)
    {
        last->next=(struct node*)malloc(sizeof(struct node));
        last->next->data=A[i];
        last->next->next=NULL;
        last=last->next;
    }
    return first;
}

void display(struct node* t)
{
    while(t!=0)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}

void Rdisplay(struct node* t) //recursive
{
    if(t==NULL)
    {
        return;
    }
    printf("%d ",t->data);
    display(t->next);
}


int count(struct node* t)
{
    int cnt=0;
    while(t!=0)
    {
        cnt++;
        t=t->next;
    }
    return cnt;
}


int Rcount(struct node* t) //recursive
{
    if(t==NULL)
    {
        return;
    }
    return 1+count(t->next);
}


int sums(struct node* t)
{
    int sum=0;
    while(t!=0)
    {
        sum=sum+t->data;
        t=t->next;
    }
    return sum;
}


int Rsums(struct node* t) //recursive
{
    if(t==NULL)
    {
        return;
    }
    return t->data+sums(t->next);
}


int max(struct node* t)
{
    int max=t->data;
    t=t->next;
    while(t!=NULL)
    {
        if(t->data>max)
        {
            max=t->data;
        }
        t=t->next;
    }
    return max;
}

int Rmax(struct node* t) //recursive
{
    static int m=INT_MIN;
    if(t==NULL)
    {
        return;
    }
    max(t->next);
    if(t->data>m)
    {
        m=t->data;
    }
    return m;
}



int search(struct node* t,int x)
{
    int i=0;
    while(t!=0)
    {
        i++;
        if(t->data==x)
        {
            return i;
        }
        t=t->next;
    }
    return 0;
}


int isearch(struct node* t,int x)
{
    int i=0;
    struct node* p=NULL;
    while(t!=0)
    {
        i++;
        if(t->data==x)
        {
            p->next=t->next;
            t->next=first;
            first=t;
            return i;
        }
        p=t;
        t=t->next;
    }
    return 0;
}

int Rsearch(struct node* t,int x) //recursive
{
    static int i=0;
    if(t==NULL)
    {
        return 0;
    }
    i++;
    if(t->data==x)
    {
        return i;
    }
    search(t->next,x);
}


int iRsearch(struct node* t,int x) //recursive
{
    static int i=0;
    if(t==NULL)
    {
        return 0;
    }
    i++;
    if(t->data==x)
    {
        return i;
    }
    search(t->next,x);
}








int main()
{
    int A[]={1200,256,3676,49,257};
    first=create(A,5);
    display(first);
    int cnt=count(first);
    printf("\nNo of elements :%d",cnt);
    int sum=sums(first);
    printf("\nSum of elements :%d",sum);
    int mx=max(first);
    printf("\nMaximum Element :%d",mx);
    int x;
    printf("\nEnter the element you wanna search");
    scanf("%d",&x);
    int ind=isearch(first,x);
    if(ind>0)
    {
        printf("Element %d is found at index %d\n\n",x,ind);
    }
    else{
        printf("Element not found!\n\n");
    }
    printf("New Improved Linked List : ");
    display(first);

    return 0;
}


