class Solution {
public:
    
    typedef pair<TreeNode*,int>Pair;
    
    struct comp{
        public:
        bool operator()(Pair &a,Pair &b){
         return a.first->val>b.first->val;
        }
    };
    
   
    void width(TreeNode* t,int hl,vector<int>&arr){
        
        if(t==NULL){
            return;
        }
        
       arr[0]=min(arr[0],hl);
         arr[1]=max(arr[1],hl);
            
            width(t->left,hl-1,arr);
        width(t->right,hl+1,arr);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
       
        vector<int>arr(2,0);
       width(root,0,arr);
        int range=arr[1]-arr[0]+1;
        vector<vector<int>>verticalorderarr(range);
         priority_queue<Pair,vector<Pair>,comp>pque;
         priority_queue<Pair,vector<Pair>,comp>cque;
        
        pque.push({root,abs(arr[0])});
        
        while(pque.size()!=0){
            int size=pque.size();
            while(size--){  
            Pair rem=pque.top();
            pque.pop();
            
                verticalorderarr[rem.second].push_back(rem.first->val);
                
            if(rem.first->left){
                cque.push({rem.first->left,rem.second-1});
            }
            if(rem.first->right){
                cque.push({rem.first->right,rem.second+1});
            }
            }
             priority_queue<Pair,vector<Pair>,comp>temp=pque;
            pque=cque;
            cque=temp;
        } 
       
        return verticalorderarr;
    }
  
     
};