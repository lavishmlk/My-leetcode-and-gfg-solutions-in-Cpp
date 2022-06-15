/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL){
            return "NULL,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="NULL,"){
            return NULL;
        }
        
        stack<pair<TreeNode*,char>>stk;
        
//         char cstr[data.size() + 1];
//     strcpy(cstr, data.c_str()); 
        
        vector<string>v;
        
istringstream ss(data);
string token;

while(getline(ss, token, ',')) {
    v.push_back(token);
}
        
        TreeNode* root=NULL;
        
        for(string token:v){
            if(token=="NULL"){
                if(stk.top().second=='l'){
                    pair<TreeNode*,char>s=stk.top();
                    stk.pop();
                    s.second='r';
                    stk.push(s);
                }
                else
                    stk.pop();
            }
            else{
                TreeNode* n=new TreeNode(stoi(token));
                if(stk.size()==0){
                    root=n;
                }
                else{
                       pair<TreeNode*,char>s=stk.top();
                    if(stk.top().second=='l'){
                      
                        stk.pop();
                        s.first->left=n;
                        s.second='r';
                        stk.push(s);
                    }
                    else{
                        // s.pop();
                        // stk.pop();
                        s.first->right=n;
                        stk.pop();
                    }
                    
                }
                stk.push({n,'l'});
            }
        }
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));