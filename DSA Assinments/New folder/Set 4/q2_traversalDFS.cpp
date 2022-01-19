#include<iostream>
using namespace std;

void printDFS(int v, int **edges, bool *visited, int sv){
    cout << sv << " ";
    visited[sv] = true;

    for(int i = 0; i < v; i++){
        if(sv == i)
            continue;

        if(edges[sv][i] == 1 and !visited[i])
            printDFS(v, edges, visited, i);
    }

    // for disconnected graph
    for(int i = 0; i < v; i++){
        if(!visited[i])
            printDFS(v, edges, visited, i);
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    // edge case 
    if(v == 0)
        return 0;

    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }

    // taking input for edges
    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;  
    }

    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }

    printDFS(v, edges, visited, 0);

    for(int i = 0; i < v; i++){
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}