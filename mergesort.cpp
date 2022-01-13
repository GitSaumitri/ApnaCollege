#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1= m-l+1;
    int n2= r-m;

    //create two temporary arrays to divide
    int t1[n1];
    int t2[n2];

    for(int i=0; i<n1; i++){
        t1[i] = arr[l+i];
    }
    for(int i=0; i<n1; i++){
        t2[i] = arr[m+1+i];
    }

    int i=0;
    int j=0;
    int k=l;
    for(int x=k; x<r; x++){
        if(t1[i]<t2[j]){
            arr[k++]=t1[i++];
        }else {
            arr[k++]=t2[j++];
        }
    }

    while(i<n1){
        arr[k++]=t1[i++];
    }

    while(j<n2){
        arr[k++]=t2[j++];
    }

}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1, r);

        merge(arr,l,mid,r);
    }
}

int main(){

    int arr[]={7,6,5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr,0,len-1);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}