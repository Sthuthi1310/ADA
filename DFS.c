#include <stdio.h>
#include <stdlib.h>
int n, count = 0, iscyclic = 0, component = 0;
void dfs(int mat[100][100], int visited[100], int src, int parent, int connectedComponents[100])
{
    visited[src] = 1;
    connectedComponents[src] = 1;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (mat[src][i])
        {
            if (!visited[i])
            {
                dfs(mat, visited, i, src, connectedComponents);
            }
            else if (i != parent)
            {
                iscyclic = 1;
            }
        }
    }
}

void connectedComponents(int mat[100][100], int tester)
{
    int visited[100];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            component++;
            int connectedComponents[100];
            for (int i = 0; i < n; i++)
            {
                connectedComponents[i] = 0;
            }
            dfs(mat, visited, i, -1, connectedComponents);
            if (tester)
            {
                printf("connected component: %d is :", component);
                for (int j = 0; j < n; j++)
                {
                    if (connectedComponents[j])
                    {
                        printf("%d ", j);
                    }
                }
                printf("\n");
            }
        }
    }
}

void tester()
{
    int mat[100][100];
    printf("enter the size of the array\n");
    scanf("%d", &n);
    printf("enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    connectedComponents(mat, 1);
    printf("number of connected components %d", component);
    if (component == 1)
    {
        printf("graph is connected\n");
    }
    else
    {
        printf("graph is not connected\n");
    }
    if (iscyclic == 1)
    {
        printf("graph is cyclic\n");
    }
    else
    {
        printf("graph is not cyclic\n");
    }
}

void plotter()
{
    int mat[100][100];
    FILE *fp = fopen("a7aMine.txt", "w");
    for (int i = 1; i <= 10; i++)
    {
        n = i;

        // Reset the matrix
for (int j = 0; j < i; j++) {
    for (int k = 0; k < i; k++) {
        mat[j][k] = 0;
    }
}
        // best case: sparse graph
        for (int j = 0; j < i-1; j++)
        {
            mat[j][j + 1] = 1;
            mat[j + 1][j] = 1; 
        }
        count = 0;
        connectedComponents(mat, 0);
        fprintf(fp, "%d %d ", i, count);
        // worst case: dense graph
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (j != k)
                {
                    mat[j][k] = 1;
                }
                else
                {
                    mat[j][k] = 0;
                }
            }
        }
        count = 0;
        connectedComponents(mat, 0);
        fprintf(fp, "%d \n", count);
    }
}
int main()
{
    int choice;
    printf("enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        break;
    }
}

