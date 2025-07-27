#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];       // Adjacency matrix
int visited[MAX];        // 0 = unvisited, 1 = visiting, 2 = visited
int topo[MAX];           // Stores topological order
int isCyclic = 0;        // Flag for cycle detection
int n, ind= 0;
int count=0;

// Function to perform DFS and topological sort
void dfs(int u) {
    visited[u] = 1; // visiting

    for (int v = 0; v < n; v++) {
        count++;
        if (adj[u][v]) {
            if (visited[v] == 0) {
                dfs(v);
            }
            else if (visited[v] == 1) {
                isCyclic = 1; // Back edge detected
            }
        }
    }

    visited[u] = 2;         // visited
    topo[ind--] = u;      // add to topo order in reverse
}

void topologicalSort() {
    ind= n - 1;  // fill from end

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }

    if (isCyclic) {
        printf("Graph contains a cycle. Topological ordering is not possible.\n");
    } else {
        printf("Graph is acyclic\n");
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
}
void tester()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v) such that there is an edge u → v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();
}
void plotter()
{
    FILE *fp2;
    fp2 = fopen("dfstopcount.txt", "w");
    FILE *fp1=fopen("dfstop.txt","w");
    for(int k = 1; k <= 10; k++)
    {
        count = 0;
        isCyclic = 0;
        ind = k - 1;

        // Reset visited
        for(int i = 0; i < k; i++) 
        visited[i] = 0;

        // Create complete DAG
         for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                adj[i][j] = 0;

        for (int i = 0; i <=k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                adj[i][j] = 1;
            }
        }
        fprintf(fp1,"Matrix %d is \n",k-1);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                fprintf(fp1,"%d ",adj[i][j]);
            }
            fprintf(fp1,"\n");
        }
        fprintf(fp1,"\n");

        n = k;  // set number of nodes
        topologicalSort();
        fprintf(fp2, "%d %d\n", k, count);
    }

    fclose(fp2);
}

int main() {
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