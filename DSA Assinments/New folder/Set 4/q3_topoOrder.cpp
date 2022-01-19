#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void makeTopoOrder(int v, int **edges, vector<bool> &visited, int sv, stack<int> &st){
    visited[sv] = true;

    for(int i = 0; i < v; i++){
        if(!visited[i] and edges[sv][i] == 1){
            makeTopoOrder(v, edges, visited, i, st);
        }
    }

    st.push(sv);
}

vector<int> topoSort(int v, int **edges){
    stack<int> st;
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++)
    {
        if(!visited[i]){
            makeTopoOrder(v, edges, visited, i, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

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

    cout << "Enter the edges of directed graph : " << endl;
    for(int i = 0; i < e; i++){
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
    }

    cout << "One of the possible topological Order is : ";
    vector<int> output = topoSort(v, edges);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}