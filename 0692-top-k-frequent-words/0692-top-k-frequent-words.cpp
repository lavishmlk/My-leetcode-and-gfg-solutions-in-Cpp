class Solution {
public:
    //tc-O((n + k)logn)
    //similar to top k frequency elements
    //in this mainly comparator is important
    //since heap me last elements pehle pop hota hai therefore see given test case two uske according hume map heap chahiye to 1 2 3 4 aise store karaenge heap me taaki 4 pehle pop ho aur lexicographically ke like see 1st test case hume i pehle chahiye l ke to uske liye min heap will be used to heap me pehle j hoga fir i
    struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words)
            ++cnt[w];
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> Q;
        for (auto it : cnt)
            Q.emplace(it.second, it.first);
        
        vector<string> res;
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};