class Solution {
public:
    //dp video 13 l1
    //greedy wla easy tha last soln
    //buy ke baad sell hi karna hoga aur sell ke baad buy
    //logic-using dp table: if buying is necessary to sell kare hue profit me buy wla subtract karlo ya fir buy na karo tab pehle se jo profit aa rha hai dono me se jo bhi max hai
    //similar logic for sell
    int maxProfit(vector<int>& prices) {
        
        int *buy=new int[prices.size()];
        int *sell=new int[prices.size()];
        
        buy[0]=-prices[0];
        sell[0]=0;
        
        for(int i=1;i<prices.size();i++){
            
            buy[i]=max(sell[i-1]-prices[i],buy[i-1]);
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]);
        }
        
        return sell[prices.size()-1];
    }
};