/*
    Stack Implementation and it's Application.
    1. Stack implementation (push,pop,top,empty) 
    2. reverse the words of a string - using stack
    3. reverse a stack - witout using extra stack (or using one stack only)
    4. prefix evaluation 
    5. postfix evaluation
    6. 
*/
#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;

//below is a stack implementation
#define m 100
class Stack{
    int tos; //top of the stack
    int *arr;
    int n;

    public:
    Stack(){
        arr = new int[m];
        tos=-1;
    }

    Stack(int n){
        this->n = n;
        arr = new int[n];
        tos=-1;
    }

    bool empty(){
        return tos==-1;
    }

    bool full(){
        return tos==(n-1);
    }

    void push(int val){
        if(full()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        tos++;
        arr[tos]=val;
    }

    void pop(){
        if(empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        tos--;
    }

    int top(){
        if(empty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[tos];
    }


};

//Application using stack library

//Reverse a sentence using stack
void reverseSentence(string s){
    stack<string> st;

    for(int i=0; i<s.length(); i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }

        st.push(word);
    }
        
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return;
}

//revrese a stack, without using an extra stack
void insertAtBottom(stack<int> &s, int ele);
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }

    int ele = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, ele);
    return;
}

void insertAtBottom(stack<int> &s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }

    int topele = s.top();
    s.pop();
    insertAtBottom(s,ele);

    s.push(topele);
}

// evalute the a prefix expression
//Note: only single digit operand and binary operator
int prefixEvalution(string s){
    stack<int> st;

    for(int i=s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int val=0;

            switch(s[i]){
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    val = op1 /op2;
                    break;
                case '^':
                    val = pow(op1,op2);
                    break;

            }
            st.push(val);
        }
    }
    return st.top();
}

// evalute the a postfix expression
//Note: only single digit operand and binary operator
//Notice difference from above prefix:
//  - start from beginning to end, instead of end to beginning
//  - for operand case, while popping, order of operand in expression
int postfixEvalution(string s){
    stack<int> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int val=0;

            switch(s[i]){
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    val = op1 / op2;
                    break;
                case '^':
                    val = pow(op1,op2);
                    break;
            }
            st.push(val);
           // cout<<val<<endl;
        }
    }
    int ans = st.top();st.pop();
    if(!st.empty()){
        cout<<"Error expression"<<endl;
        return 0;
    }
    return ans;
}

//convert a infix to postfix
int prec(char ch){
    if(ch=='-' || ch=='+'){
        return 1;
    }else if(ch=='*' || ch=='/'){
        return 2;
    }else if(ch=='^'){
        return 3;
    }else {
        return -1;
    } 
}
string infixToPostfix(string s){
    string res;
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z'){
            res += s[i];    
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();

        }else { //operator
            while(!st.empty() && prec(st.top()) > prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    //s.push(4);
    //cout<<s.top()<<endl;
    s.pop();
    //cout<<s.top()<<endl;

    //Application using STL stack

    //string input = "Hey, How are you doing?";
    //reverseSentence(input);

    /*
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop(); 
    }
    cout<<endl;
    */

   //string prefix="-+7*45+20"; //  7+(4*5)-(2+0)
   //string prefix="-+7*45+29"; //  7+(4*5)-(2+9)
   //cout<<prefixEvalution(prefix)<<endl;

   string postfixs="46+2/5*7+"; //  (4+6)/2 * 5 + 7
   cout<<postfixEvalution(postfixs);
   cout<<endl;

   string infix="(a-b/c)*(a/k-l)";
   cout<<infixToPostfix(infix)<<endl;

    return 0;
}