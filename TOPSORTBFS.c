#include <stdio.h>
#include <stdlib.h>

int n, opcount = 0;

void topologicalSort(int adj[100][100]) {
    int in_degree[100] = {0};
    int queue[100], front = 0, rear = 0;
    int topo_order[100], idx = 0;

    // Step 1: Compute in-degrees
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            opcount++;
            if (adj[i][j]) {
                in_degree[j]++;
            }
        }
    }

    // Step 2: Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        opcount++;
        if (in_degree[i] == 0)
            queue[rear++] = i;
    }

    // Step 3: Process queue
    while (front < rear) {
        int u = queue[front++];
        topo_order[idx++] = u;

        for (int v = 0; v < n; v++) {
            opcount++;
            if (adj[u][v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (idx != n) {
        printf("The graph has a cycle. Topological sorting not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < idx; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\nTotal operations: %d\n", opcount);
    }
}

void tester() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[100][100];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    opcount = 0;
    topologicalSort(adj);
}

void plotter() {
    FILE *f = fopen("topo_opcount.txt", "w");
    if (!f) {
        printf("Error opening file.\n");
        return;
    }

    for (int size = 1; size <= 10; size++) {
        n = size;
        int adj[100][100] = {0};

        // Creating a linear DAG: 0→1→2→...→n-1
        for (int i = 0; i < n - 1; i++) {
            adj[i][i + 1] = 1;
        }

        opcount = 0;
        topologicalSort(adj);
        fprintf(f, "%d\t%d\n", n, opcount);
    }

    fclose(f);
    printf("Operation count data saved to topo_opcount.txt\n");
}

int main() {
    int choice;
    printf("Enter\n1. Tester\n2. Plotter\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: tester(); break;
        case 2: plotter(); break;
        default: printf("Invalid choice.\n");
    }

    return 0;
}

