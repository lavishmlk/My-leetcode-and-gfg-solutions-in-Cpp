// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
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


Node* helper(Node* l1,Node* l2){
    while(l1 && l1->data == 0)
        l1 = l1->next;
        // removing trailing zeroes from l1
    
    while(l2 && l2->data == 0)
        l2 = l2->next;
       
    if(Size(l2)>Size(l1)){
               swap(l1,l2);
        }
        
        if(Size(l1)==Size(l2)){
        Node *t1=l1, *t2=l2;
        while(t1->data == t2->data )
        // finding which number is greater
        {
            t1 = t1->next;
            t2 = t2->next;
            
            if(!t1) return new Node(0);
            // returning zero if both numbers are same
        }
        if(t2->data > t1->data)
            swap(l1,l2);
    }
    
   Node* n1= reverseList(l1);
    Node* n2=reverseList(l2);
    
     Node* dummy=NULL;
   
   
    
    while(n1!=NULL){
       
         int d1=n1->data;
    int small=n2==NULL?0:n2->data;
     if( d1<small )
        {
            n1->next->data = n1->next->data - 1;
            n1->data = n1->data + 10;
            // taking carry
        }
        
        Node* n = new Node( n1->data - small );
        // creating new node for storing difference
       
     n->next = dummy;
        dummy = n;
            n1=n1->next;
        
        if(n2){
            n2=n2->next;
        }
    }
    while(dummy->next && dummy->data==0)
        dummy = dummy->next;

  return dummy;
  
}
Node* subLinkedList(Node* l1, Node* l2)
{  
 return helper(l1,l2);
 
}