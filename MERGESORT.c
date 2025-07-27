#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
void merge(int *b,int *c,int *a,int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        count++;
        if(b[i]<=c[j])
        {
            a[k]=b[i++];
        }
        else
        a[k]=c[j++];
        k++;
    }
    if(i==p)
    {
        while(j<q&&k<(p+q))
        a[k++]=c[j++];
    }
    else
    while(i<p&&k<(p+q))
    a[k++]=b[i++];
}
void mergesort(int *a,int n)
{
    int *b,*c,p,q;
    p=n/2;
    q=n-p;
    b=(int*)malloc(p*sizeof(int));
    c=(int*)malloc(q*sizeof(int));
    if(b==NULL||c==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    if(n<=1)
    return;
    else{
        for(int i=0;i<p;i++)
        {
            b[i]=a[i];
        }
        for(int j=0;j<q;j++)
        {
            c[j]=a[p+j];

        }
        mergesort(b,p);
        mergesort(c,q);
        merge(b,c,a,p,q);
    }
}
void generateWorstCase(int *a, int beg, int end)
{
    if (beg >= end)
        return;

    int mid = (beg + end) / 2;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Interleaving to force worst-case merge comparisons
    for (int i = 0; i < n1; i++)
        L[i] = a[beg + 2 * i];

    for (int j = 0; j < n2; j++)
        R[j] = a[beg + 2 * j + 1];

    generateWorstCase(L, 0, n1 - 1);
    generateWorstCase(R, 0, n2 - 1);

    // Copying back to original array from beg
    for (int i = 0; i < n1; i++)
        a[beg + i] = L[i];
    for (int j = 0; j < n2; j++)
        a[beg + n1 + j] = R[j];

    free(L);
    free(R);
}
void tester()
{
     int *a,n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,n);
    printf("Sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void plotter()
{
    int *a,iter;
    FILE *fp1,*fp2;
    srand(time(NULL));
    fp1=fopen("mnums.txt","w");
    fp2=fopen("mcount.txt","w");
    for(int iter=10;iter<=100;iter+=10)
    {
        count=0;
        a=(int*)malloc(iter*sizeof(int));
        if(a==NULL)
        {
            printf("no memory\n");
            exit(0);
        }
        fprintf(fp1,"Iteration-%d\n",iter/10);
        //Best case
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        mergesort(a,iter);
        fprintf(fp2,"%d %d ",iter,count);
        fprintf(fp1,"Best case sorted order=");
        for(int i=0;i<iter;i++)
        fprintf(fp1,"%d ",a[i]);
        fprintf(fp1,"\n");
        count=0;
        //Average case
        for(int i=0;i<iter;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        mergesort(a,iter);
        fprintf(fp2,"%d ",count);
        fprintf(fp1,"Average case sorted order=");
        for(int i=0;i<iter;i++)
        fprintf(fp1,"%d ",a[i]);
        fprintf(fp1,"\n");
        count=0;
        //Worst case
        a[0]=rand()%100;
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+rand()%10;
        }
        generateWorstCase(a,0,iter-1);
        for(int i=0;i<iter;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        mergesort(a,iter);
        fprintf(fp2,"%d\n",count);
        fprintf(fp1,"Worst case sorted order=");
        for(int i=0;i<iter;i++)
        fprintf(fp1,"%d ",a[i]);
        fprintf(fp1,"\n");
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
        default:printf("Invalid chocie..\n");
        break;
    }
}