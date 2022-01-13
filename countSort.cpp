#include<iostream>
using namespace std;

void countSort(int arr[], int n){

    int m=arr[0];
    for(int i=1; i<n; i++){
        m = max(arr[i],m);
    }
    //cout<<m<<endl;

    int count[m+1]={0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=1; i<=m; i++){
        count[i] += count[i-1];
    }

    int o[n];
    for(int i=n-1; i>=0; i--){
        o[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i]=o[i];
    }
}

int main(){
    int arr[]={5,5,4,4,4,3,3,2,1};
    int len = (sizeof(arr)/sizeof(arr[0]));
    
    countSort(arr,len);
    for(int i=0; i< len; i++)
        cout<<arr[i]<<" ";

    return 0;
}