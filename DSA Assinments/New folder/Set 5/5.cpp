#include<iostream>
using namespace std;
int partition(int a[],int si,int ei){
    int j=1;
    for(int i=si+1;i<=ei;i++){
        if(a[si]>a[i]){
            int temp=a[si+j];
            a[si+j]=a[i];
            a[i]=temp;
            j++;
        }
    }
    int key = a[si];
    a[si]=a[si+j-1];
    a[si+j-1]=key;    
    return si+j-1;
}
void QuickSort(int a[],int si,int ei){
    if(si>=ei){
        return;
    }
    int c=partition(a,si,ei);
    QuickSort(a,si,c-1);
    QuickSort(a,c+1,ei);
 }
void quick_sort(int a[],int n){
    int si=0;
    int ei=n-1;
    QuickSort(a,si,ei);
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The sorted array is - "<<endl;
    quick_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}