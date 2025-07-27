#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int *H,n,count=0;
void Heap(int *H,int n)
{
    for(int i=n/2;i>=1;i--)
    {
        int parent=i;
        int P=H[parent];
        int heap=0;
    while(!heap&&2*parent<=n)
    {
        int child=2*parent;
        if(child<n)
        {
            count++;
            if(H[child+1]>H[child])
            {
                child=child+1;
            }
        }
        count++;
        if(P>=H[child])
        {
            heap=1;
        }
        else{
            H[parent]=H[child];
            parent=child;
        }
    }
    H[parent]=P;
}
}
void sort(int *H,int n)
{
    Heap(H,n);
    int i=n;
    while(i>=1)
    {
        int temp=H[1];
        H[1]=H[i];
        H[i]=temp;
        Heap(H,i-1);
        i--;
    }
}
void tester()
{
    printf("Enter the size of the input array: ");
    scanf("%d",&n);
    H=(int*)malloc((n+1)*sizeof(int));
    if(H==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the elements: ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&H[i]);
    }
    sort(H,n);
    printf("Sorted array is : \n");
    for(int i=1;i<=n;i++)
    printf("%d ",H[i]);
    printf("\n");
}
void plotter()
{
    //int *H, n,count;
    FILE *fp1, *fp2;
    fp1 = fopen("heapnums.txt", "w");
    fp2 = fopen("heapcount.txt", "w");
    if(fp1 == NULL || fp2 == NULL) {
    printf("File open failed\n");
    exit(1);
    }
    srand(time(NULL));
    for(int k=10;k<=100;k+=10)
    {
         H=(int*)malloc((k+1)*sizeof(int));
    if(H==NULL)
    {
        printf("No memoryy\n");
        exit(0);
    }
    //Best case 
    count=0;
    fprintf(fp1,"Best case input: ");
    H[1]=rand()%1000;
    fprintf(fp1,"%d ",H[1]);
    for(int i=2;i<=k;i++)
    {
        H[i]=H[i-1]-50;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    sort(H,k);
    fprintf(fp2,"%d %d ",k,count);
    //Average case 
    count=0;
    fprintf(fp1,"Average case input: ");
    for(int i=1;i<=k;i++)
    {
        H[i]=rand()%100;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    sort(H,k);
    fprintf(fp2,"%d ",count);
    //Worst case 
    count=0;
    fprintf(fp1,"Worst case input: ");
    H[1]=rand()%100;
    fprintf(fp1,"%d ",H[1]);
    for(int i=2;i<=k;i++)
    {
        H[i]=H[i-1]+5;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    sort(H,k);
    fprintf(fp2,"%d\n",count);
    }
}
int main()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:printf("Invalid choice..");
        break;
    }
}
