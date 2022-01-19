#include<iostream>
using namespace std;
int binary_search(int n,int arr[],int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the sorted array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key"<<endl;
    cin>>key;
    int index=binary_search(n,arr,key);
    if(index==-1){
        cout<<"Key is not present in the array\n";
    }
    else{
        cout<<"Key is present at index "<<index<<endl;
    }
    return 0;
}