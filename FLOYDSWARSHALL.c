#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<time.h>
#define MAX 100

int m, W[MAX][MAX], D[MAX][MAX],count=0,istester;;

void display(int D[MAX][MAX], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (D[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FloydWarshall(int W[MAX][MAX], int m)
{
    count=0;
    // Initialize D with W
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (W[i][j] == -1)
                D[i][j] = INT_MAX;
            else
                D[i][j] = W[i][j];
        }
    }

    if(istester)
    {
         printf("Matrix 0 (Initial):\n");
    display(D, m);
    }

    // Floyd-Warshall Main Algorithm
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count++;
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX &&
                    D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
        if(istester)
        {
            printf("Matrix %d (after including node %d):\n", k + 1, k);
        display(D, m);
        }
    }
}
void tester()
{
    istester=1;
    printf("Enter the size of the matrix: ");
    scanf("%d", &m);

    printf("Enter the weights (use -1 to represent INF):\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &W[i][j]);
        }
    }

    FloydWarshall(W, m);
}
void plotter()
{
    istester=0;
    FILE *fp1=fopen("FloydWarshall.txt","w");
    for(int p=1;p<=10;p++)
    {
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(i!=j)
                {
                    W[i][j]=rand()%10;
                }
                else
                W[i][j]=0;
            }
        }
        int m=p;
        FloydWarshall(W,m);
        fprintf(fp1,"%d %d\n",p,count);
    }
}
int main()
{
    int choice;
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:printf("Invalid choice: ");
        break;
    }
}
