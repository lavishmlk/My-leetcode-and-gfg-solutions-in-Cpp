// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* left=new Node(-1);
       Node* lefttail=left;
        Node* middle=new Node(-1);
       Node* middletail=middle;
        Node* right=new Node(-1);
       Node* righttail=right;
        Node* temp=head;
      
        while(temp!=NULL){
            if(temp->data==0){
                lefttail->next=temp;
                lefttail=temp;
                temp=temp->next;
            }
            else if(temp->data==1){
                middletail->next=temp;
                middletail=temp;
                temp=temp->next;
            }
            else{
                righttail->next=temp;
                righttail=temp;
                temp=temp->next;
            }
        }
        if(middle==middletail){
            lefttail->next=right->next;
        }
        else{
              lefttail->next=middle->next;
    middletail->next=right->next;
        }
      righttail->next=NULL;
        
        return left->next;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends