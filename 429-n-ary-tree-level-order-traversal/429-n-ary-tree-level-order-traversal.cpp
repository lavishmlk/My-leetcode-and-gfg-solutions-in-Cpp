/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //ye method levelorder linewise ki dummy node wla tarika hai in archit video 5 pichla submission size wle method se kiya tha
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue<Node*>q;
        q.push(root);
        
        Node* dummy=new Node(-1);
        q.push(dummy);
       
        vector<int>level;
        
        while(q.size()>1){
            Node* z=q.front();
            q.pop();
            if(z==dummy){
                res.push_back(level);
                q.push(dummy);
              while(level.size()>0){
                  level.pop_back();
              }
            }
            else{
                level.push_back(z->val);
                for(Node* child:z->children){
                    q.push(child);
                }
            }
            
        }
        res.push_back(level);
        return res;
    }
};