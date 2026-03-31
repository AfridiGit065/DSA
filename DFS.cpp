#include<iostream>
#include<stack>
using namespace std;


void dfs(int Graph[][100], int source, int V)
{
    stack< int > S;
    int flag[V] = {0};
    int parent[V];

    for(int i=0; i<V; i++)
    {
        parent[i] = i;
    }

    S.push(source);
    flag[source] = 1;

    printf("Visited Sequence: ");

    while(!S.empty())
    {
        int current_node = S.top();
        S.pop();

        printf("%d ", current_node);


        for(int i=0; i<V; i++)
        {
            if(Graph[current_node][i]==1) /// neighbor
            {
                if(flag[i]==0)
                {
                    S.push(i);
                    flag[i] = 1;
                    parent[i] = current_node;
                }
            }
        }
    }

    printf("\n parent array: ");
    for(int i=0; i<V; i++)
    {
        printf("%d -> %d\n", i, parent[i]);
    }


}

int main()
{
    int Graph[100][100];

    int V, E;
    scanf("%d%d", &V, &E);
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            Graph[i][j] = 0;
        }
    }

    for(int i=0; i<E; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        Graph[from][to] = 1;

        /// Graph[to][from] = 1; /// if the path is unidirectional, then remove this line
    }

    /**for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            printf("%d ", Graph[i][j]);
        }
        printf("\n");
    }**/

    printf("Enter the source node: ");
    int source;
    scanf("%d", &source);

    dfs(Graph, source, V);



    return 0;
}

