/*
    Largest rectangular area in a histogram - using stack
    
    Find the largest rectangular area possible in a given histogram where 
    the largest rectangle can be made of a number of contiguous bars. For 
    simplicity, assume that all bars have same width and the width is 1 unit. 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largest_area(int arr[], int n){
    int l,max_area=0;
    for(int i=0; i<n; i++){
        int h = INT_MAX;
        for(int j=i; j<n; j++){
            h = min(arr[j],h);
            l = j-i+1;
            max_area = max(max_area,h*l);
            //cout<<" "<<h<<" "<<l<<"  "<<endl;
        }
    }
    return max_area;
}

int largest_area_stack(int arr[], int n){
    int max_area=0;
    stack<int> st;
    int area=0,i=0,h,l;

    while(i < n){
        //this one is higer than tos, push it on stack
        if(st.empty() || arr[st.top()] <= arr[i])
            st.push(i++);
        else {
            //pop it and calculate the area
            h = arr[st.top()]; st.pop();
            l = st.empty()? i: (i-st.top()-1);
            max_area = max(max_area, h * l);
        }
    }

    //there is a increasing list
    while(!st.empty()){
        h = arr[st.top()]; st.pop();
        l = st.empty()? i: (i-st.top()-1);
        max_area = max(max_area, h * l);
    }
    return max_area;
}

int main(){

    int arr1[]={2,4};
    int arr2[]={6,2,5,4,5,1,6};

    cout<<largest_area(arr1,2)<<endl;
    cout<<largest_area_stack(arr1,2)<<endl;

    cout<<largest_area(arr2,7)<<endl;
    cout<<largest_area_stack(arr2,7)<<endl;

    return 0;
}