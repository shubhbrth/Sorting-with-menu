#include<stdio.h>
#include<conio.h>
//Used for variable declaration
int ar[20],radarr[10][10],hash[20],i,x,j,q,n,hash_size,lar,l,r,piv,pi,collision;
void bubble();
void insertion();
void selection();
void build_maxheap();
void max_heapify();
void swap(int ,int );
void print();
void def_arr(int );
void quicksort();
int partition();
void radix_sort();
void hashing();
void hash_collision(int ,int );
void main()
{
    int ch;
do{
    printf("\nMenu:\n1.BUBBLE SORT\n2.Selection Sort\n3.Insertion Sort\n4.HEAP SORT\n5.Quick Sort\n6.Perform Hashing\n7.Radix Sort\n8.Exit\nEnter Your Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        def_arr(0);
        bubble();
        print(0);
        break;
    case 2:
        def_arr(0);
        selection();
        print(0);
        break;
    case 3:
        def_arr(0);
        insertion();
        print(0);
        break;
    case 4:
        def_arr(1);
        build_maxheap();
        print(1);
        break;
    case 5:
        def_arr(0);
        quicksort(0,n-1);
        print(0);
        break;
    case 6:
        def_arr(0);
        //hashing();
        print(2);
        break;
    case 7:
        def_arr(0);
        radix_sort();
        //print(0);
        break;
    case 8:
        exit(0);
        break;
    }}while(ch>=0&&ch<8);
    getch();
}
void bubble()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ar[j]>ar[j+1])
                swap(j,j+1);
        }
    }
}
void selection()
{
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
                swap(i,j);
        }
    }
}
void insertion()
{
    for(i=1;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
            if(ar[j]<ar[j-1])
                swap(j,j-1);
        }

    }
}
void build_maxheap()
{
    for(i=n/2;i>=1;i--)
        max_heapify(i);
        //printf("%d",i);

}
void max_heapify(int i)
{
    lar=i;
    l=2*i;
    r=(2*i)+1;
    if(l<=n&&ar[l]>ar[i])
        lar=l;

    else if(r<=n&&ar[r]>ar[lar])
        lar=r;
    else
        lar=i;
    if(lar!=i)
    {
        swap(i,lar);
    max_heapify(lar);

    }

}
void swap(int p1,int p2)
{
    int temp;
    temp=ar[p1];
    ar[p1]=ar[p2];
    ar[p2]=temp;
}

void quicksort(int p,int r)
{
    if(p<r)
    {
        pi=partition(p,r);
        quicksort(p,pi-1);
        quicksort(pi+1,r);
    }
}
int partition(int p,int r)
{
    piv=ar[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(ar[j]<=piv)
        {
            i++;
            swap(i,j);
        }
    }
    swap(i+1,r);
    return (i+1);
}
/*void hashing()
{
    int hash_index;
    printf("Enter Hash Table Size:");
    scanf("%d",&hash_size);
    for(i=0;i<hash_size;i++)
        hash[i]=-1;
    for(i=0;i<n;i++)
    {
        hash_index=ar[i]%hash_size;
        if(hash[hash_index]==-1)
        {
            hash[hash_index]=ar[i];
        }
        else if(hash[hash_index]!=-1)
        {
            collision=1;
            hash_collision(hash_index,i);
        }
    }
}
void hash_collision(int index,int i)
{
    int val;
    val=index+pow(c,2)*hash_size;
    if(hash[val==]!=-1)
        hash[val]=ar[i];
    else
        collision++;
        hash_collision(index,i);

}*/

void radix_sort()
{
    int mod,condi;
    for(i=0;i<10;i++)
    {
        radarr[i][0]=i;
        for(j=1;j<10;j++)
        {
            radarr[i][j]=-1;
        }
    }
    for(i=0;i<n;i++)
    {
        j=1;
        condi=0;
        mod=ar[i]%10;
        while(condi!=-1)
        {
            if(radarr[mod][j]==-1)
            {
                radarr[mod][j]=ar[i];
                condi=-1;
            }
            else
            {
                j++;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=1;j<10;j++)
        {
            if(radarr[i][j]!=-1)
            printf("%d",radarr[i][j]);
        }
    }
    /*for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d  ",radarr[i][j]);
        }
        printf("\n");
    }*/
}

void def_arr(int defarr)
{
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements: ");
    if(defarr==0)
    {
        for(i=defarr;i<n;i++)
            scanf("%d",&ar[i]);
    }
    else if(defarr==1)
    {
        for(i=defarr;i<=n;i++)
            scanf("%d",&ar[i]);
    }
}

void print(int ch)
{
    if(ch==0)
    {
        for(i=0;i<n;i++)
            printf("%d\t",ar[i]);
    }
    else if(ch==1)
    {
            for(i=1;i<=n;i++)
                printf("%d\t",ar[i]);
    }
    else if(ch==2)
    {
        for(i=0;i<hash_size;i++)
            printf("%d\t",hash[i]);
    }
}
