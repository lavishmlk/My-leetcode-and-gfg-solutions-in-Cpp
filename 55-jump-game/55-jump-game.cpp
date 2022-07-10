class Solution {
public:
    bool canJump(vector<int>& jump) {
        
        int reach=0;
        
        for(int i=0;i<jump.size();i++){
            
            if(i>reach){
                return false;
            }
            if(reach>=jump.size()-1){
                return true;
            }
            if(i+jump[i]>reach){
                reach=i+jump[i];
            }
        }
        return true;
        
    }
};