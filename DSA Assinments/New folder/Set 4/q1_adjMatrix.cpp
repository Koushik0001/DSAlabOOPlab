#include<iostream>
using namespace std;

int main(){
    int v, e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >> e;

    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }

    cout << "Enter the edges " << endl;
    for(int i = 0; i < e; i++){
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }

    cout << "The given graph using adjacency matrix :" << endl;
    for(int i = 0; i < v; i++){
        cout << i << ") : ";
        for(int j = 0; j < v; j++){
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}