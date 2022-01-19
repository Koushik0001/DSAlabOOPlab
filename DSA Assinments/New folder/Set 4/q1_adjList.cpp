#include<iostream>
#include<vector>
using namespace std;

class AdjacencyListNode{
    public:
    int data;
    AdjacencyListNode *next;

    AdjacencyListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    int v;
    cout << "Enter the numbers of vertices : ";
    cin >> v;

    AdjacencyListNode **edges = new AdjacencyListNode*[v];
    for(int i = 0; i < v; i++){
        AdjacencyListNode *now = new AdjacencyListNode(-1);
        edges[i] = now;
    }

    int e;
    cout << "Enter the numbers of edges : ";
    cin >> e;

    cout << "Enter the edges : " << endl;
    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        if(edges[f]->data == -1){
            AdjacencyListNode* temp = new AdjacencyListNode(s);
            edges[f] = temp;
        }

        else{
            AdjacencyListNode* now = new AdjacencyListNode(s);
            AdjacencyListNode* temp = edges[f];
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = now;
        }

        if(edges[s]->data == -1){
            AdjacencyListNode* temp = new AdjacencyListNode(f);
            edges[s] = temp;
        }

        else{
            AdjacencyListNode* now = new AdjacencyListNode(f);
            AdjacencyListNode* temp = edges[s];
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = now;
        }
    }

    cout << "Adjancency list is : " << endl;
    for(int i = 0; i < v; i++){
        cout << i << ") : ";
        AdjacencyListNode* temp = edges[i];
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}