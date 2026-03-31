#include<bits/stdc++.h>
using namespace std;

int main(){

    int matrix[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matrix[i][j] = 0;
        }
    }

    int numberOfEdges = 11;
    for(int i = 0; i < numberOfEdges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
        matrix[v][u] = w;
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
