
//RECURSIVE DISCUSS SE LIYE-Time : O(size_of_list1 + size_of_list2) = O(n1+n2),O(size of various variables + call stack space) = O(c + n1 + n2) = O(n1+n2)
//FOR ITERATIVE SEE PICHE WLA-USME PEHLE SIZE EQUAL TAK TRAVERSE KIA EK LINKEDLIST ME fir check karte gye
class Solution {
public:
    ListNode* getIntersectionHelper(ListNode* nodeA, ListNode* nodeB, int sizeA, int sizeB){
        if(sizeA==0 || sizeB==0){
            return nullptr;
        }
        
        if(sizeA>sizeB){
            return getIntersectionHelper(nodeA->next, nodeB, sizeA - 1, sizeB);
        }
        else if(sizeA<sizeB){
            return getIntersectionHelper(nodeA, nodeB->next, sizeA, sizeB-1);
        }
        else if(sizeA==sizeB && nodeA==nodeB){
            return nodeA;
        }
        else{
            return getIntersectionHelper(nodeA->next, nodeB->next, sizeA - 1, sizeB - 1);
        }
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* tempA = headA; 
        ListNode* tempB = headB; 
		
		//Evaluate size of first list
        while(tempA!=nullptr){
            sizeA++;
            tempA = tempA->next;
        }
		
		//Evaluate size of second list
        while(tempB!=nullptr){
            sizeB++;
            tempB = tempB->next;
        }
		//Recursive function call where checking actually happens
        return getIntersectionHelper(headA, headB, sizeA, sizeB);
    }
};