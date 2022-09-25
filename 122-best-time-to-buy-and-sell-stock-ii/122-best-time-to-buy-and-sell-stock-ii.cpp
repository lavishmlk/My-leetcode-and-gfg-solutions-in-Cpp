class Solution {
public:
    //greedy-dne by me
 
    int maxProfit(vector<int>& prices) {
        
        int least=prices[0];
        // int Max=INT_MIN;
        int profit=0;
        for(int i=1;i<prices.size();i++){
            
            if(prices[i]<=least){
                least=prices[i];
            }
            else{
                profit=profit+prices[i]-least;
               least=prices[i]; 
            }
        }
        return profit;
    }
};