#include<iostream>
using namespace std;
int linear_search(int arr[],int n,int key){
    int i=0;
    while(i<n){
        if(arr[i]==key){
            return i;
        }
        i++;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the rray"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key"<<endl;
    cin>>key;
    int index=linear_search(arr,n,key);
    if(index==-1){
        cout<<"Key is not present in the array\n";
    }
    else{
        cout<<"Key is present at index "<<index<<endl;
    }
    return 0;
}