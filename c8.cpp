#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX];
int visited[MAX];
int queue[MAX];

void addEdge(int u, int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void BFS(int start, int n) {
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node *temp = adj[current];

        while (temp != NULL) {
            int v = temp->vertex;

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int n, e, u, v, start;

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of friendships: ");
    scanf("%d", &e);

    printf("Enter friendship pairs:\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
        else {
            printf("Invalid user number.\n");
            return 1;
        }
    }

    printf("Enter starting user: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting user.\n");
        return 1;
    }

    BFS(start, n);

    return 0;
}
