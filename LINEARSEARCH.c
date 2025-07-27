#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int linearsearch(int *a,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        count++;
        if(key==*(a+i))
        return i;
    }
    return -1;
}
void tester()
{
    int *a,n,key;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memoy\n");
        exit(0);
    }
    printf("ENter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("ENter the key element: ");
    scanf("%d",&key);
    int k=linearsearch(a,n,key);
    if(k!=-1)
    printf("Search successful and key found at index %d \n",k);
    else
    printf("Unsuccessful search\n");
}
void plotter()
{
    FILE *fp1=fopen("lsearch.txt","w");
    FILE *fp2=fopen("lcount.txt","w");
    int *a,key;
    srand(time(NULL));
    for(int i=10;i<=100;i+=10)
    {
        a=(int*)malloc(i*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        fprintf(fp1,"Iteration - %d\n",i/10);
        fprintf(fp1,"Input array is : \n");
        for(int j=0;j<i;j++)
        {
            a[j]=rand()%100;
            fprintf(fp1,"%d ",a[j]);
        }
        //Best case
        count=0;
        key=a[0];
        fprintf(fp1,"\nBest case Key is %d\n",key);
        linearsearch(a,i,key);
        fprintf(fp2,"%d %d ",i,count);
        count=0;
        //Average case
        key=a[i/2];
        fprintf(fp1,"Average case key is %d\n",key);
        linearsearch(a,i,key);
        fprintf(fp2,"%d ",count);
        count=0;
        //Worst case
        key=555;
        fprintf(fp1,"Worst case key is %d\n",key);
        linearsearch(a,i,key);
        fprintf(fp2,"%d\n",count);
    }
}
int main()
{
    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:printf("Invalid choice..\n");
        break;
    }
}