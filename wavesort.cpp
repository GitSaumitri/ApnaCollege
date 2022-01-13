#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void wavesort(int arr[], int len){

    for(int i=1; i<len; i=i+2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }

        if(arr[i]>arr[i+1]){
            swap(arr,i,i+1);
        }
    }
}

int main(){
    int arr[]={2,5,4,3,7,4,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    wavesort(arr,len);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}