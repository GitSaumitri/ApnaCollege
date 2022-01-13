#include<iostream>
#include<algorithm>
using namespace std;


//quicksort
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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

void QuickSort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr,l,r);
        QuickSort(arr,l,p-1);
        QuickSort(arr,p+1,r);
    }
}

//countsort
void countSort(int arr[], int len){

    //find the highest element
    int m = arr[0];
    for(int i=1; i<len; i++){
        m = max(m,arr[i]);
    }

    //find the occurance of each element
    int count[m+1]={0};
    for(int i=0; i<len; i++){
        count[arr[i]]++;
    }

    for(int i=1; i<=m; i++){
        count[i] += count[i-1];
    }

    //create the sorted array
    int output[len];
    for(int i=len-1; i>=0; i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0; i<len; i++){
        arr[i] = output[i];
    }
    return;
}

//DNF sort
void dnfSort(int arr[], int len){
    int l = 0;
    int r = len-1;
    int m = 0;
    while(m<r){
        if(arr[m]==0){
            swap(arr,l,m);
            l++;m++;
        }else if(arr[m]==1){
            m++;
        }else{ //arr[m]==2
            swap(arr,m,r);
            r--;
        }
    }
}
int main(){

    int arr[]={5,4,5,5,4,3,2,1};
    int a[]={1,2,0,1,1,1,2,2};

    int len = sizeof(arr)/sizeof(arr[0]);
    int l = sizeof(a)/sizeof(a[0]);
    //QuickSort(arr,0,len-1);
    //countSort(arr,len);
    dnfSort(a,l);
    for(int i=0; i<l; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}