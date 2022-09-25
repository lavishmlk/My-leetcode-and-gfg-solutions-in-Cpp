class Solution {
public:
    //dp video 13 l1
    //greedy wla easy tha last to last soln
    //first see previous code without space optimization
    //buy ke baad sell hi karna hoga aur sell ke baad buy
    //logic-using dp table: if buying is necessary to sell kare hue profit me buy wla subtract karlo ya fir buy na karo tab pehle se jo profit aa rha hai dono me se jo bhi max hai
    //similar logic for sell
    int maxProfit(vector<int>& prices) {
        
        int buy=-prices[0];
        int sell=0;
        
        for(int i=1;i<prices.size();i++){
            
           int newbuy=max(sell-prices[i],buy);
            int newsell=max(buy+prices[i],sell);
            
            buy=newbuy;
            sell=newsell;
        }
        
        return sell;
    }
};