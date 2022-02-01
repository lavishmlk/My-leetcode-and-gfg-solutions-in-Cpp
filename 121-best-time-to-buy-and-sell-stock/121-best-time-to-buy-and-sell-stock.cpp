class Solution {
public:
 int maxProfit(vector<int>& prices) {
        int leastpday=INT_MAX;
        int op=0;
        int profitonday=0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<leastpday){
                leastpday=prices[i];
            }
             profitonday=prices[i]-leastpday;
            if(profitonday>op){
                op= profitonday;
            }
        }
        return op;
    }
};