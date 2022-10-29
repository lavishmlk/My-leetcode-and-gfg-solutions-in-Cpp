class Solution {
public:
    string oddString(vector<string>& words) {
     map<vector<int>, vector<string>> m;
for(int i = 0; i < words.size(); i++)
{
vector<int> v;
for(int j=1;j< words[i].size(); j++)
{
v.push_back(words[i][j] - words[i][j-1]);
m[v].push_back(words[i]);
}
}
        
string ans;
for (auto val: m)
{
if(val.second.size() == 1)
{
ans = val. second[0];
}
    }
        return ans;}
};