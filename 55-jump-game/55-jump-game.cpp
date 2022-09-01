//greedy 
//video 3
//for every i we will check the max reach
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

// dp gives tle therefore use greedy
// class Solution {
// public:
//    //tc-n*jumps
//      bool helper(vector<int>& nums,int src){
           
//            if(src==nums.size()-1){
//                return true;
//            }
//          if(src>nums.size()-1){
//              return false;
//          }
       
//            bool minanswer=false;
//            for(int jump=1;jump<=nums[src];jump++){
               
//                   minanswer=helper(nums,src+jump);
//                    if(minanswer==true){
//                        return true;
//                    }
               
//            }
       
//            return minanswer;
//        }
    
//     bool canJump(vector<int>& nums) {
        
//       return helper(nums,0);
//     }
// };