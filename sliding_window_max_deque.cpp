/*
    Application of Deque: Double ended Queue

    Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
    Sliding window maximum.
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> find_max_in_range(int a[], int len, int interval){
    vector<int> ans;
    deque<int> q;

    for(int i=0; i<interval; i++){
        if(!q.empty() and a[q.back()] < a[i])
            q.pop_back();

        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=interval; i<len; i++){
        if(q.front()==i-interval)
            q.pop_front();

        while(!q.empty() and a[q.back()] < a[i])
            q.pop_back();

        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    return ans;
}

int main(){
    int a[]={1,2,3,4,1,2,5,6};
    int len=sizeof(a)/sizeof(a[0]);
    vector<int> ans;

    for(int i=0; i<len; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    ans = find_max_in_range(a, len, 3);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }    
    cout<<endl;

}