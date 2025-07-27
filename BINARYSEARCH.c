#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int binarysearch(int *a,int l,int h,int key)
{
    int mid=(l+h)/2;
    if(l>h)
    return -1;
    else{
        count++;
    if(*(a+mid)==key)
    return mid;
    else{
        if(key<a[mid])
        {
            binarysearch(a,l,mid-1,key);
        }
        else
        binarysearch(a,mid+1,h,key);
    }
}
    return -1;
}
int tester()
{
    int *a,n,key,k;
    printf("Enter the  size of the array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No meory\n");
        exit(0);
    }
    printf("Enter the elements of the array(ascending order): \n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("ENter the key: ");
    scanf("%d",&key);
    k=binarysearch(a,0,n-1,key);
    if(k!=-1)
    printf("Search successful and index is %d\n",k);
    else
    printf("Unsuccessful search\n");
}
void plotter()
{
    FILE *fp1,*fp2;
    int *a,key;
    fp1=fopen("binarynum.txt","w");
    fp2=fopen("binarycount.txt","w");
    srand(time(NULL));
    for(int n=11;n<=101;n+=10)
    {
        a=(int*)malloc(n*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        fprintf(fp1,"Iteration %d\n",(n-1)/10);
        fprintf(fp1,"Array inputs: \n");
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+20;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        //Best case key
        count=0;
        key=a[(n-1)/2];
        fprintf(fp1,"Best case key - %d\n",key);
        binarysearch(a,0,n-1,key);
        fprintf(fp2,"%d %d ",n,count);
        //Average case key
        count=0;
        key=a[(n-1)/4];
        fprintf(fp1,"Average case key - %d\n",key);
        binarysearch(a,0,n-1,key);
        fprintf(fp2,"%d ",count);
        //Worst case key
        count=0;
        key=9999;
        fprintf(fp1,"Worst case key -%d\n",key);
        binarysearch(a,0,n-1,key);
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
        default:printf("Invalid choice\n");
        break;
    }
}
