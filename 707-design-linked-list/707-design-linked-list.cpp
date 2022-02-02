  class Node{
        public:
        int val;
        Node* next;
         Node(int val) {
        this->val=val;
        next=NULL;
    }
    };
class MyLinkedList {
public:
    int size=0;
      Node* head=new Node(0);
    Node* tail=NULL;

    int get(int index) {
        if(size==0){
            return -1;
        }
        else if(index<0 || index>=size){
            return -1;
        }
        else{
            Node* temp=head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
                return temp->val;   
        }
      // if(index>=size) return -1;
      //   Node* temp=head->next;
      //   for(int i=0;i<index;i++) temp=temp->next;
      //   return temp->val;
       
    }
    
    void addAtHead(int val) {
//          Node* n=new Node(val);
//             // n->val=val;
//             // n->next=NULL;
        
//         if(size==0){
//             head=n;
//             tail=n;
//             size++;
//         }
//         else{
//             n->next=head;
//             head=n;
//             size++;
//         }
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
//         Node* n=new Node(val);
//             // n->val=val;
//             // n->next=NULL;
//         if(head==NULL){
//             head=tail=n;
//         }
//         else{
//             tail->next=n;
//             tail=n;
            
//         }
//     size++;
        addAtIndex(size,val);
    }
    
    
    void addAtIndex(int index, int val) {
           Node* temp=head;
               Node* n=new Node(val);
        if(index<0 || index>size){
            return;
        }
        else if(index==0){
            n->next=temp;
            head=n;
        }
     
        else{
       
            // n->val=val;
            // n->next=NULL;
            for(int i=0;i<index-1;i++){
               temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        else if(size==0){
            return;
        }
        else if(index==0){
            // head=tail=NULL;
              Node* nextNode = head->next;
            // Always remember to free memory to prevent memory leak
            delete head;
            head = nextNode;  
            tail=head;
        }
        else{
             Node* temp=head;
              for(int i=0;i<index-1;i++){
               temp=temp->next;
            }
           Node* nextNode =temp->next->next;
              // Always remember to free memory to prevent memory leak
            delete temp->next;
          temp->next=nextNode;
        }
          size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */