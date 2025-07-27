#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int m, A[MAX][MAX],count=0,R[MAX][MAX];

void display(int R[][MAX], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Warshall(int A[][MAX], int m)
{
    //int R[MAX][MAX];
    count=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            R[i][j] = A[i][j];
        }
    }

    printf("Initial matrix is : \n");
    display(R, m);

    for (int k = 0; k < m; k++)
    {
        printf("Matrix %d \n", k + 1);
        for (int i = 0; i < m; i++)
        {
           // if (R[i][k])
            //{
                for (int j = 0; j < m; j++)
                {
                    count++;
                    R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
                }
            //}
        }
        display(R, m);
    }
}
void tester()
{
     printf("Enter the size: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    Warshall(A, m);
    printf("Final transitive closure matrix is: \n");
    display(R,m);
}
void plotter() {
    FILE *fp = fopen("warshall.txt", "w");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    for (int size = 1; size <= 10; size++) {
        int n = size;

        // Create complete graph (except self-loops)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = (i != j) ? 1 : 0;

        Warshall(A, n);
        fprintf(fp, "%d %d\n", size,count);
    }

    fclose(fp);
    printf("Operation data written to warshall.txt\n");
}
int main()
{
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:
        printf("Invalid choice\n");
        break;
    }
}
