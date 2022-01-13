#include<iostream>
using namespace std;

void swap(int arr[], int l, int r){
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    
    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[], int l, int r){

    if(l < r){
        int p = partition(arr,l,r);

        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
    
}

int main(){

    int arr[]={5,4,3,2,1};

    quicksort(arr,0,4);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //return 0;
}