class Solution {
public:
    
    //cODE EXPLAINER
    //JUST PUSH THE VALUES ROW COL WISE INITIALY THEN
    // SORT-SORT FUNCTION WORKS FOR 1ST VALUE IF FIRST VALUES ARE SAME THEN IT CHECKS FOR 2ND VALUES
    
    // if tgis question didnt had variable length then it could be done like traversal 1 question like
    //row=0 col=0 initially 
    //then if col--  is not available then do row+1
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                ans.push_back({i+j,j,nums[i][j]});
            }
        }
        sort(ans.begin(),ans.end());
        
        vector<int>finalans;
       for(int i=0;i<ans.size();i++){
                finalans.push_back(ans[i][2]);
            }
         return finalans;
        }
   
    };