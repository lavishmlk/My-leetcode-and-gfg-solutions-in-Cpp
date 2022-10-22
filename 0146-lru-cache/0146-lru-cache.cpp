//TAIL WLA DUMMY NODE ISLIYE LIYA TAAKI AGAR REMOVE LAST KARE TO TAIL KO SHIFT NA KARNA PADE APNE AAP HI ADUST HO JAE
//for logic see arcit video 7 lINKED LIST after 54:50

//STACK AND QUEUE NOT USED BXCZ IN STACK AND QUEUE ONLY REMOVE ADD FROM TOP AND BACK IS POSSIBLE
//ARRAY NOT USED COZ REMOVAL FROM BETWEEN IS COSTRY I.E O(N) BUT WE HAVE TO REMOVE IN ORDER OF 1 SO LINKEDLIST IS BETTER
//FOR GETTING ELEMMNT FROM A CERTAIN POSITION LL TAKES O(N) TIME THEREFORE ALONG WITH LINKEDLIST MAP IS ALSO USED
//NOW REMOVAL SHOULD BE DONE IN O(1) TIME BUT SINGLY LINKEDLIST TAKE O(N) THEREFORE DOUBLY LL IS USED


class LRUCache {
public:
    
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    
     int cap;
    Node* head;
    Node* tail;
    int size;
     unordered_map < int, Node*> m;
    
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        cap=capacity;
        size=0;
    }
    
    //remove from that location and add at first and return the value
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            Node* curr=m[key];
            
            //remove at
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            
            //add first
             curr->prev=head;  
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
           
             return curr->val;
        }
    }
    
    void put(int key, int value) {
        
        if(m.find(key)==m.end()){
            
              Node* curr=new Node(key,value);
            
            if(size==cap){
                //remove last
                Node* temp=tail->prev;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                m.erase(temp->key);
            }
            else
                size++;
                
            //add first
             curr->prev=head; 
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
             
            m[key]=curr;
        }
        else{
            //iss case me map me value nahi add karenge coz address to same hi rehega agar already present tha to
            Node* curr=m[key];
            
            //remove at
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            
            //add first
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
            curr->prev=head;  
    
               curr->val=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */