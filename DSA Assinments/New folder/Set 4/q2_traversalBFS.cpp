#include<iostream>
#include<queue>
using namespace std;

void printBFS(int v, int **edges, bool *visited, int sv)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        cout << frontNode << " ";

        for(int i = 0; i < v; i++)
        {
            if(frontNode == i)
                continue;

            if(edges[frontNode][i] == 1 and visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }   
    }

    // for disconnected graph
    for(int i = 0; i < v; i++){
        if(!visited[i])
            printBFS(v, edges, visited, i);
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

    printBFS(v, edges, visited, 0);

    for(int i = 0; i < v; i++){
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}