#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v){
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

int main(){
    int nodes = 6;
    Node* adjList[6] = {NULL};

    int numberOfEdges = 7;
    for(int i = 0; i < numberOfEdges; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        addEdge(adjList, u, v);
    }

    cout << "The Adjacency List: " << endl;

    for(int i = 0; i < nodes; i++){
        cout << i+1 << ": ";
        Node* temp = adjList[i];
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
