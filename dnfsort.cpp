#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int dnfSort(int arr[], int len){
    int low = 0;
    int mid = 0;
    int high = len-1;

    while(mid<high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;mid++;
        }else if(arr[mid]==1){
            mid++;
        }else { //arr[mid]==2
            swap(arr,mid,high);
            high--;
        }
    }
}

int main(){
    int arr[]={1,1,1,0,0,0,0,2,2,2,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    dnfSort(arr,len);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}