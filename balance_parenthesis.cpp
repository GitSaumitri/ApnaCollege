// balenced parenthesis using stack
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
    int len = str.size();
    stack<char> st;
    
    for(int i=0; i<len; i++){
        if(str[i]=='{' || str[i]=='(' || str[i]=='['){
            st.push(str[i]);    
        }else if(str[i]=='}'){
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
                return false;
        }else if(str[i]==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                return false;
    
        }else if(str[i]==']'){
            if(!st.empty() && st.top()=='[')
                st.pop();
            else
                return false;
        }
    }

    return st.empty()?true:false;
}
int main(){

    string s="";
    cout<<s<<endl;
    if(isValid(s))
        cout<<"Valid Parenthesis string"<<endl;
    else
        cout<<"Parenthesis are not Valid"<<endl;
}