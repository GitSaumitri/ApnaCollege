/* linked list reatated problems
    1. insert at head in a linkedlist
    2. insert at back in a linkedlist
    3. Search in an linkedlist
    4. Deletion from a linkedlist
    5. Reverse a linkedlist by iterative method
    6. Reverse a linkedlist by recurssive method
    7. Reverse alternate k nodes in a linkedlist by recurssive method
        or Reverse nodes in k groups 
    8. Detect and remove a cycle on a linkedlist
        Floyd's Angorithm/ Hare and Tortoise Algorithm
    9. Append last k nodes in the beginning of the linkedlist
   10. Put even position nodes after odd position node

*/
#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class linkedlist{
    //Node *head;

    public:
    void insertAtHead(Node * &head, int val);
    void insertAtTail(Node* &head, int val);
    int search(Node* head, int val);
    void deletion(Node* &head, int val);
    Node * reverse(Node* &head);
    Node * reverseRecurssive(Node * &head);
    Node * reverseKrecurssive(Node* &head, int k);
    void insertCycle(Node* &head, int pos);
    void detectAndRemoveCycle(Node * &head);
    void display(Node *head);
};

//function definations with scope resolution operator ::
void linkedlist::insertAtHead(Node * &head, int val){

    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void linkedlist::insertAtTail(Node* &head, int val){
 
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = n;
}

int linkedlist::search(Node* head, int val){
    Node *temp = head;
    while(temp!=nullptr){
        if(temp->val == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void linkedlist::deletion(Node* &head, int val){
    if(head==nullptr)
        return;

    Node* todelete;
    if(head->val == val){
        todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    Node *temp = head;
    while(temp->next && temp->next->val!=val){
        temp = temp->next;
    }

    if(temp==nullptr)
        return;
    
    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return;
}

Node * linkedlist::reverse(Node* &head){
    Node * prev = nullptr;
    Node * curr = head;
    Node * next;

    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    } 

    return prev;
}

Node * linkedlist::reverseRecurssive(Node * &head){
    
    if(head==nullptr || head->next==nullptr)
        return head;

    Node * newhead = reverseRecurssive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newhead;
}

Node * linkedlist::reverseKrecurssive(Node* &head, int k){
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;
    int count=0;
    while(curr!=nullptr && count < k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }

    if(next!=nullptr){
        head->next = reverseKrecurssive(next,k);
    }

    return prev;
}

void linkedlist::insertCycle(Node* &head, int pos){
    Node *temp = head;
    Node *first;
    int count=1;

    while(temp->next!=NULL){
        
        if(count == pos){
            first = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = first;
}

void linkedlist::detectAndRemoveCycle(Node* &head){
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            //cycle detected
            //cout<<"Cycle Detected"<<endl;
            fast = head;
            while(slow->next!=fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = nullptr;
            //cout<<"Detected Cycle removed"<<endl;
            break;
        }
    }

    return;
}

Node * kappend(Node *head, int num){
    Node *newtail=head;
    Node *newhead;
    Node *tail=head;
    
    //to handle scenario, when num is greater
    //than length we can findout the length
    //first then calculate num = num%length.

    //move tail till num
    while(num){
        tail = tail->next;
        num--;
    }

    //now when tail reaches null, newtail will be ready
    while(tail->next!=nullptr){
        tail=tail->next;
        newtail = newtail->next;
    }

    newhead = newtail->next;
    tail->next = head;
    newtail->next = nullptr;
    
    return newhead;
}

void evenAfterOdd(Node * &head){
    if(head->next == nullptr)
        return;
    
    Node *odd = head;
    Node *even = head->next;
    Node *evenstart = even;

    while(odd->next!=nullptr and even->next!=nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even=even->next;
    }

    if(odd->next==nullptr){
        even->next==nullptr;
        odd->next = evenstart;
    }else{
        odd->next = evenstart;
    }
}

void linkedlist::display(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    linkedlist ll;
    Node *head = nullptr;
    ll.insertAtTail(head, 10);
    ll.insertAtHead(head, 1);
    ll.display(head);
    ll.insertAtTail(head, 2);
    ll.insertAtTail(head, 3);
    ll.insertAtTail(head, 4);
    ll.display(head);
    cout<<ll.search(head,3)<<endl;

    ll.deletion(head,10);
    ll.display(head);
    //ll.deletion(head,1);
    //ll.display(head);
    //ll.deletion(head,4);
    //ll.display(head);

    head = ll.reverse(head);
    ll.display(head);
    head = ll.reverseRecurssive(head);
    ll.display(head);
    
    //cout<<"Reverse K"<<endl;
    //head = ll.reverseKrecurssive(head,2);
    //ll.display(head);
    
    //detect and remove the cycle on a ll
    ll.insertAtTail(head, 5);
    //ll.insertAtTail(head, 6);
    ll.display(head);
    ll.insertCycle(head,4);
    //ll.display(head);

    ll.detectAndRemoveCycle(head);
    ll.display(head);

    //head = kappend(head, 3);
    //ll.display(head);

    evenAfterOdd(head);
    ll.display(head);

    return 0;
}