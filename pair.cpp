//reuced array - reduce the content of the array keeping the order of elements same
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int myCompare(pair<int,int>a, pair<int,int>b){
    return (a.first < b.first);
}

int main(){
    int arr[]={10,16,7,14,5,3,12,9};

    vector<pair<int,int>>s;

    for(int i=0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        s.push_back(make_pair(arr[i],i));
    }

    sort(s.begin(),s.end(),myCompare);
    
    for(int i=0; i < s.size(); i++){
        arr[s[i].second]=i;
        //cout<<arr[i]<<" ";
    }

     for(int i=0; i < s.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

