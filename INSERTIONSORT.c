#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
void insertionsort(int *a,int n)
{
    int temp,i,j;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        temp=a[i];
        while(j>=0&&a[j]>temp)
        {
            count++;
            a[j+1]=a[j];
            j--;
        }
        if(j>=0)
        count++;
         a[j+1]=temp;
    }
}
void tester()
{
 int *a,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printf("Sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void plotter()
{
    int *a,n;
    FILE*fp1,*fp2;
    srand(time(NULL));
    fp1=fopen("insertnum.txt","w");
    fp2=fopen("insertcount.txt","w");
    for(n=10;n<=100;n+=10)
    {
        a=(int*)malloc(n*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        fprintf(fp1,"Iteration - %d\n",n/10);
        //Bestc case
        count=0;
        fprintf(fp1,"Best case input: \n");
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+rand()%10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        insertionsort(a,n);
        fprintf(fp2,"%d %d ",n,count);
        //Average case
        fprintf(fp1,"Average case inputs: \n");
        count=0;
        for(int i=0;i<n;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        insertionsort(a,n);
        fprintf(fp2,"%d ",count);
        //Worst case
        count=0;
        fprintf(fp1,"Worst case inputs: \n");
        a[0]=rand()%100;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]-5;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        insertionsort(a,n);
        fprintf(fp2,"%d\n",count);
    }
}
int main()
{
    int choice;
    printf("ENter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:printf("Invalid choice\n");
        break;
    }
}