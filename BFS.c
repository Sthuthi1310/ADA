#include <stdio.h>
#include <stdlib.h>

int isCycle = 0, components = 0, n, opcount = 0, isTester;

// BFS function to explore a component and detect cycle
void bfs(int mat[100][100], int *vis, int source)
{
    int queue[100], parent[100];
    int rear = -1, front = -1;

    vis[source] = 1;
    queue[++rear] = source;
    parent[rear] = -1;

    while (rear != front)
    {
        int curr = queue[++front];
        int par = parent[front];

        if (isTester)
            printf("%d ", curr);

        for (int i = 0; i < n; i++)
        {
            opcount++;

            if (mat[curr][i])
            {
                if (vis[i] && i != par)
                {
                    isCycle = 1;
                }

                if (!vis[i])
                {
                    vis[i] = 1;
                    queue[++rear] = i;
                    parent[rear] = curr;
                }
            }
        }
    }
}

// Check each connected component using BFS
void checkConnectivity(int mat[100][100])
{
    int vis[100] = {0};
    int k = 1;

    components = 0;
    isCycle = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            components++;
            if (isTester)
                printf("\nConnected component %d: ", k++);
            bfs(mat, vis, i);
        }
    }
}

// Manual input and display
void tester()
{
    isTester = 1;

    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    int adjMat[100][100];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);

    checkConnectivity(adjMat);

    printf("\n\nNumber of connected components: %d", components);
    printf("\nGraph is %sCONNECTED.", components == 1 ? "" : "NOT ");
    printf("\nGraph is %sACYCLIC.\n", isCycle ? "NOT " : "");
}

// Auto-analysis using complete graphs
void plotter()
{
    isTester = 0;

    FILE *f1 = fopen("bfsadjMat.txt", "w");
    if (f1 == NULL)
    {
        printf("File could not be opened.\n");
        return;
    }

    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[100][100];

        // Create complete graph with n vertices
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = (i != j) ? 1 : 0;

        opcount = 0;
        checkConnectivity(adjMat);
        fprintf(f1, "%d\t%d\n", n, opcount);
    }

    fclose(f1);
    printf("Plot data saved to bfsadjMat.txt\n");
}

// Main function with menu
int main()
{
    int choice;
    printf("Enter\n1. Tester\n2. Plotter\nChoice: ");
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
        printf("Invalid choice\n");
    }

    return 0;
}