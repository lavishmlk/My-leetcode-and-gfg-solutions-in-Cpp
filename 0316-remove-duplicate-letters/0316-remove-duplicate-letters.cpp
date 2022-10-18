class Solution {
public:
    //recursive approach from discuss but stack wli is better
    //recursive is very similar to stack wli apprach isme mainly recursion traverse karne ke liye hi use ki hai mainly
    //agar duplicates hai to like agar c do baar aa rha hai to waise to jitna aage wla c mila utna better hai but lexicographic bhi chahiye for eg 1st test case me last c liye but 2nd test case me second last c liya
    //isme hum string traverse karenge aur count -- karte jaenge aur saath saath lowest position bhi store karte jaenge jaise h kisi jagah pe count 0 ho jae break coz wo wla element to aega hi ans me agar count zero hai to, par kai test cases aise bhi ho sakte hai jinme count 0 ho jaega kisi element ka par usse pehle aur chote elements bhi hai like see test case 2 usme count 0 d pe hoga par c bhi to aega a ke baad directly d nahi aega in cases ke liye hum c ki next position se leke d tak d ke liye jo pehle count-- kiya tha wo wapas ++ kar denge
    
    void dfs(string s, string& ans, vector<int>& cnt, vector<int>&vis){
        int len = s.length();
        if(len == 0) return;
        int pos = -1;
        int i;
        for(i = 0; i < len; ++i){
            if(vis[s[i] - 'a']) continue;
            if(pos == -1 || s[pos] > s[i]) pos = i;
            cnt[s[i] - 'a']--;
            if(cnt[s[i] - 'a'] == 0) break;
        }
        if(pos == -1) return;
        for(int j = pos + 1; j <= i; ++j) cnt[s[j] - 'a']++;
        ans += s[pos];
        vis[s[pos] - 'a'] = true;
        dfs(s.substr(pos + 1), ans, cnt, vis);
    }
    string removeDuplicateLetters(string s) {
        string ans;
        int len = s.length();
        vector<int>cnt(26, 0);
        vector<int>vis(26, 0);
        for(int i = 0; i < len; ++i){
            cnt[s[i] - 'a']++;
        }
        dfs(s, ans, cnt, vis);
        return ans;
    }
};