// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     int Size(Node* head){
if(head==NULL){
return 0;
}
int size=0;
Node* temp=head;
while(temp->next!=NULL){
size++;
temp=temp->next;

    }
    return size+1;
}

  Node* reverseList(Node* &head) {
    int size=Size(head);
    if(size==0){
        Node* n=NULL;
        return n;
    }
    else if(size==1){
        return head;
    }
    else{
 Node* prev=NULL;
    Node* curr=head;
    Node* ahead=curr->next;
    
    while(curr!=NULL){
        curr->next=prev;
        prev=curr;
        curr=ahead;
        if(ahead!=NULL)
        ahead=ahead->next;
    }
    head=prev;
    return head;
    }
}

   
  Node*  helper(Node* l1, Node* l2){
                if(l1==NULL&&l2==NULL){
            return NULL;
        }
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        int carry=0;
        Node* n=new Node(-1);
        Node* head=n;
        while(l1!=NULL || l2!=NULL || carry>0){
            
            int d1=l1==NULL?0:l1->data;
            int d2=l2==NULL?0:l2->data;
              Node* dummy=new Node(-1);
 
            dummy->data=d1+d2+carry;
             dummy->data= dummy->data%10;
            carry=(carry+d1+d2)/10;
            head->next=dummy;
            head=dummy;
            if(l1!=NULL)
            l1=l1->next;
            if(l2!=NULL)
            l2=l2->next;
         
            
        }
        return n->next;
    }

    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        Node* n1=reverseList(l1);
       Node* n2= reverseList(l2);
    Node* resultantNode=helper(n1,n2);
      return  reverseList(resultantNode);
    }
};


  
 
// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends