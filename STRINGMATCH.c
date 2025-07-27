#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int count=0;
int stringmatch(char *T,char *P)
{
    int n=strlen(T);
    int m=strlen(P);
    int i;
    for(i=0;i<=(n-m);i++)
    {
        int j=0;
        while(j<m)
        {
            count++;
            if(P[j]!=T[i+j])
            {
                break;
            }
            j++;
        }
        if(j==m)
        return i;
    }
    return -1;
}
void tester()
{
    char P[1000],T[1000];
    printf("ENter the text : ");
    scanf("%s",T);
    printf("Enter the pattern: ");
    scanf("%s",P);
    int k=stringmatch(T,P);
    if(k!=-1)
    printf("Search successful and position of first caharacter is %d\n",k);
    else
    printf("Search unsuccesfull\n");
}
void plotter()
{
    FILE *fp1, *fp2;
    fp1 = fopen("stringchar.txt", "w");
    fp2 = fopen("stringcount.txt", "w");
    char P[100], T[100];

    for (int k = 10; k <= 100; k += 10)
    {
       // T = (char *)malloc((k + 1) * sizeof(char));
       // P = (char *)malloc((k / 2 + 1) * sizeof(char));

       // if (T == NULL||P==NULL)
       // {
        //    printf("Memory allocation failed.\n");
        //    exit(0);
       // }

        // Fill T with 'a' and null-terminate
        for (int i = 0; i < k; i++) 
            T[i] = 'a';
        T[k] = '\0';

        fprintf(fp1, "Iteration - %d\n", k / 10);
        fprintf(fp1, "Text is:\n%s\n", T);

        // Best Case
       /*for (int i = 0; i <(k/2); i++)
             P[i] = 'a';
        P[k/2] = '\0';

        fprintf(fp1, "Best case pattern:\n%s\n", P);*/
         count = 0;
        stringmatch(T,"aaa");
        fprintf(fp2, "%d %d ", k, count);

        // Average Case
       /*for (int i = 0; i < k / 2; i++)
             P[i] = 'a';
        P[k/4] = 'b';
        P[k/2] = '\0';
        fprintf(fp1, "Average case pattern:\n%s\n", P);*/
        count = 0;
        stringmatch(T,"aba");
        fprintf(fp2, "%d ", count);

        // Worst Case
      /* for (int i = 0; i < k / 2; i++)
             P[i] = 'a';
        P[(k / 2) - 1] = 'b';
        P[k/2] = '\0';

        fprintf(fp1, "Worst case pattern:\n%s\n", P);*/
        count = 0;
        stringmatch(T, "aab");
        fprintf(fp2, "%d\n", count);

        //free(T);
        //free(P);
    }

    fclose(fp1);
    fclose(fp2);
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
