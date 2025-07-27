#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
void swap(int *a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int *a,int l,int r)
{
    int i,j,p;
    p=a[l];
    i=l;
    j=r+1;
    do{
        do{
            count++;
            i=i+1;
        }while(a[i]<p);
        do{
            count++;
            j=j-1;
        }while(a[j]>p);
        swap(a,i,j);
    }while(i<j);
    swap(a,i,j);
    swap(a,l,j);
    return j;
}
void quicksort(int *a,int l,int r)
{
    if(l<r)
    {
        int S=partition(a,l,r);
        quicksort(a,l,S-1);
        quicksort(a,S+1,r);
    }
    //return *a;
}
void tester()
{
    int *a,n;
    printf("ENter the size of array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memoy\n");
        exit(0);
    }
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("sorted array is : \n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
void plotter()
{
    int *a,n;
    FILE *fp1,*fp2;
    fp1=fopen("quicknumx.txt","w");
    fp2=fopen("quickcount.txt","w");
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {
        a=(int*)malloc(n*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        fprintf(fp1,"Iteration- %d\n",n/10);
        //Best case
        count=0;
        fprintf(fp1,"Best case inputs: ");
        for(int i=0;i<n;i++)
        {
            a[i]=10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,n-1);
        fprintf(fp2,"%d %d ",n,count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<n;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        //Average case
        count=0;
        fprintf(fp1,"Average case inputs: ");
        for(int i=0;i<n;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,n-1);
        fprintf(fp2,"%d ",count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<n;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        //Worst case
        count=0;
        fprintf(fp1,"Worst case inputs: ");
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,n-1);
        fprintf(fp2,"%d\n",count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<n;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
    }
    fclose(fp1);
    fclose(fp2);
    free(a);
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
        default:printf("Invalid choice..\n");
        break;
    }    
}