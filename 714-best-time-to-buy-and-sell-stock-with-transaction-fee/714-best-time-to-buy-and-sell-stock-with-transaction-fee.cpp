class Solution {
public:
    //just a variation of leetcode 122 but 122 greedy se ho jaega ye nahi hoga coz 122 me agar 1 3 5 se profit dekho to 1 to3 aur 3 se 5 jaane me bhi 4 profit hi aega but iss question me nahi coz transaction fees hai
    int maxProfit(vector<int>& prices, int fee) {

            int buy=-prices[0];
        int sell=0;
        
        for(int i=1;i<prices.size();i++){
            
           int newbuy=max(sell-prices[i],buy);
            int newsell=max(buy+prices[i]-fee,sell);
            
            buy=newbuy;
            sell=newsell;
        }
        
        return sell;
    }
};