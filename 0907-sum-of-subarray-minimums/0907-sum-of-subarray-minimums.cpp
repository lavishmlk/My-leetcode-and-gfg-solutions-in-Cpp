class Solution {
public:  
   //Disucss: https://leetcode.com/problems/sum-of-subarray-minimums/discuss/1405264/C%2B%2B-oror-Monotonic-Stack-oror-Detailed-Explanation
    
    //also see extra questions page 8 for dry run
    
    //logic-find range of every element that is kitni window me aa sakta hai wo uske baad wo element kitni baar contribute karega uss range me find that coz wo element minimum hai so har baar uss window ka answer wahi hoga
    
   //somewhat similar to this ques-> https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article 
    
    
    int MOD=1000000007;
    
int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> left(n,-1), right(n,n);
        // for every i find the Next smaller element to left and right
        
        // Left
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        // Right
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            ans+=prod;
            ans%=MOD;
        }
        
        return ans%MOD;
    }
};